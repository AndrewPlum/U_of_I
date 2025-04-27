%{
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "scanType.h"
#include "treeNodes.h"
#include "treeUtils.h"
#include "symbolTable.h"
#include "semantics.h"
using namespace std;

int numErrors;
int numWarnings;
extern int line;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *msg);

void printDebug(const char *msg)
{
    if(1 == 1)
    {
        printf("%s\n", msg);
    }
}

void printToken(TokenData myData, string tokenName, int type = 0) {
   cout << "Line: " << myData.linenum << " Type: " << tokenName;
   if(type==0)
     cout << " Token: " << myData.tokenstr;
   if(type==1)
     cout << " Token: " << myData.nvalue;
   if(type==2)
     cout << " Token: " << myData.cvalue;
   cout << endl;
}

TreeNode *addSibling(TreeNode *t, TreeNode *s)
{
    // make sure s is not null. If it is this s a major error. Exit the program!
    if(s == NULL)
    {
        printf("Head line number: %d\n", t->lineno);
        printf("Head name: %s\n", t->attr.name);
        
        printf("addSibling() major error. s is NULL. Exitting program.\n");
        exit(1);
    }
    
    // Make sure t is not null. If it is, just return s
    if(t == NULL)
    {
        //printf("t is NULL. Returning s");
        return s;
    }
    
    // look down t’s sibling list until you fin with with sibblin = null (the end o f the lsit) and add s there.
    TreeNode *curr = t;
    while(curr->sibling != NULL)
    {
        curr = curr->sibling;
    }
    curr->sibling = s;
    
    // end of functurn - return head TreeNode *
    return t;
}

// pass the static and type attribute down the sibling list
void setType(TreeNode *t, ExpType type, bool isStatic)
{
    while(t) // is this the correct condition?
    {
        // set t->type and t->isStatic
        t->type = type;
        t->isStatic = isStatic;
        
        // set t = t->sibling;
        t = t->sibling;
    }
}

// the syntax tree goes here
TreeNode *syntaxTree;

%}
%union
{
    //struct   TokenData tinfo ; // this was previously here but I think slides said to remove and add lines below to union
    TokenData *tinfo;
    TreeNode *tree;
    ExpType type; // for passing type spec up the tree
}
%token   <tinfo>  '*''+''-''/''<''=''>''%''?'
%token   <tinfo>  '('')'','';''[''{''}'']'':'
%type    <tinfo>  assignop minmaxop mulop relop sumop unaryop
%token   <tinfo>  MAX MIN
%token   <tinfo>  ADDASS SUBASS MULASS DIVASS
%token   <tinfo>  INC DEC
%token   <tinfo>  CHSIGN SIZEOF
%token   <tinfo>  EQ NEQ 
%token   <tinfo>  GEQ LEQ
%token   <tinfo>  AND OR NOT
%token   <tinfo>  BREAK
%token   <tinfo>  FOR WHILE DO TO BY
%token   <tinfo>  IF THEN ELSE
%token   <tinfo>  INT BOOL CHAR
%token   <tinfo>  STATIC
%token   <tinfo>  RETURN
%token   <tinfo>  PRECOMPILER
%token   <tinfo>  ID
%token   <tinfo>  BOOLCONST NUMCONST CHARCONST STRINGCONST
%token   <tinfo>  ERROR 

%type   <tree>  program
%type   <tree>  precomList
%type   <tree>  declList
%type   <tree>  decl
%type   <tree>  varDecl
%type   <tree>  scopedVarDecl
%type   <tree>  varDeclList
%type   <tree>  varDeclInit
%type   <tree>  varDeclId
%type   <tree>  funDecl
%type   <tree>  parms
%type   <tree>  parmList
%type   <tree>  parmTypeList
%type   <tree>  parmIdList
%type   <tree>  parmId
%type   <tree>  stmt
%type   <tree>  matched
%type   <tree>  iterRange
%type   <tree>  unmatched
%type   <tree>  expStmt
%type   <tree>  compoundStmt
%type   <tree>  localDecls
%type   <tree>  stmtList
%type   <tree>  returnStmt
%type   <tree>  breakStmt
%type   <tree>  exp
%type   <tree>  simpleExp
%type   <tree>  andExp
%type   <tree>  unaryRelExp
%type   <tree>  relExp
%type   <tree>  minmaxExp
%type   <tree>  sumExp
%type   <tree>  mulExp
%type   <tree>  unaryExp
%type   <tree>  factor
%type   <tree>  mutable
%type   <tree>  immutable
%type   <tree>  call
%type   <tree>  args
%type   <tree>  argList
%type   <tree>  constant

%type   <type>  typeSpec 
%token  <tinfo> LASTTERM
%%
program  :  precomList declList                     {syntaxTree = $2;}
    ;
   
precomList : precomList PRECOMPILER                 {$$ = NULL; printf("%s\n", yylval.tinfo->tokenstr);}
    | PRECOMPILER                                   {$$ = NULL; printf("%s\n", yylval.tinfo->tokenstr);}
    | /* empty */                                   {$$ = NULL;}
    ;
           
declList : declList decl                            {$$ = addSibling($1, $2);}
    | decl                                          {$$ = $1;}
    ;
    
decl : varDecl                                      {$$ = $1;}
    | funDecl                                       {$$ = $1;}
    ;
    
varDecl : typeSpec varDeclList ';'                  {setType($2, $1, false); $$ = $2;}
    ;
    
scopedVarDecl : STATIC typeSpec varDeclList ';'     {setType($3, $2, true); $$ = $3;}
    | typeSpec varDeclList ';'                      {setType($2, $1, false); $$ = $2;}
    ;
    
varDeclList : varDeclList ',' varDeclInit           {$$ = addSibling($1, $3);}
    | varDeclInit                                   {$$ = $1;}
    ;
    
varDeclInit : varDeclId                             {$$ = $1;}
    | varDeclId ':' simpleExp                       {$$ = $1; if ($$ != NULL) $$->child[0] = $3;}
    ;
    
varDeclId : ID                                      {$$ = newDeclNode(VarK, UndefinedType, $1, NULL, NULL, NULL);}
    | ID '[' NUMCONST ']'                           {$$ = newDeclNode(VarK, UndefinedType, $1, NULL, NULL, NULL); $$->isArray = true; $$->size = $3->nvalue + 1; }
    ;
    
typeSpec : INT                                      {$$ = Integer; /*CHECK*/}
    | BOOL                                          {$$ = Boolean;}
    | CHAR                                          {$$ = Char;}
    ;
    
funDecl : typeSpec ID '(' parms ')' stmt            {$$ = newDeclNode(FuncK, $1, $2, $4, $6, NULL);}
    | ID '(' parms ')' stmt                         {$$ = newDeclNode(FuncK, Void, $1, $3, $5, NULL);}
    ;
    
parms : parmList                                    {$$ = $1;}
    | /* empty */                                   {$$ = NULL;}
    ;
    
parmList : parmList ';' parmTypeList                {$$ = addSibling($1, $3);}
    | parmTypeList                                  {$$ = $1;}
    ;
    
parmTypeList : typeSpec parmIdList                  {setType($2, $1, false); $$ = $2;}
    ;
    
parmIdList : parmIdList ',' parmId                  {$$ = addSibling($1, $3);}
    | parmId                                        {$$ = $1;}
    ;
    
parmId : ID                                         {$$ = newDeclNode(ParamK, UndefinedType, $1);}
    | ID '[' ']'                                    {$$ = newDeclNode(ParamK, UndefinedType, $1); $$->isArray = true;}
    ;
    
stmt : matched                                      {$$ = $1;}
    | unmatched                                     {$$ = $1;}
    ;
    
matched : IF simpleExp THEN matched ELSE matched    {$$ = newStmtNode(IfK, $1, $2, $4, $6);}
    | WHILE simpleExp DO matched                    {$$ = newStmtNode(WhileK, $1, $2, $4, NULL);}
    | FOR ID '=' iterRange DO matched               {$$ = newStmtNode(ForK, $1, newDeclNode(VarK, Integer, $2), $4, $6);}
    | expStmt                                       {$$ = $1;}
    | compoundStmt                                  {$$ = $1;}
    | returnStmt                                    {$$ = $1;}
    | breakStmt                                     {$$ = $1;}
    ;
    
iterRange : simpleExp TO simpleExp                  {$$ = newStmtNode(RangeK, $2, $1, $3, NULL);}
    | simpleExp TO simpleExp BY simpleExp           {$$ = newStmtNode(RangeK, $2, $1, $3, $5);}
    ;
    
unmatched : IF simpleExp THEN stmt                  {$$ = newStmtNode(IfK, $1, $2, $4, NULL);}
    | IF simpleExp THEN matched ELSE unmatched      {$$ = newStmtNode(IfK, $1, $2, $4, $6);}
    | WHILE simpleExp DO unmatched                  {$$ = newStmtNode(WhileK, $1, $2, $4, NULL);}
    | FOR ID '=' iterRange DO unmatched             {$$ = newStmtNode(ForK, $1, newDeclNode(VarK, Integer, $2), $4, $6);}
    ;
    
expStmt : exp ';'                                   {$$ = $1;}
    | ';'                                           {$$ = NULL;}
    ;
    
compoundStmt : '{' localDecls stmtList '}'          {$$ = newStmtNode(CompoundK, $1, $2, $3, NULL); /* CHECK */}
    ;
    
localDecls : localDecls scopedVarDecl               {$$ = addSibling($1, $2);}
    | /* empty */                                   {$$ = NULL;}
    ;
    
stmtList : stmtList stmt                            {if($2 != NULL) $$ = addSibling($1, $2); else $$ = $1;}
    | /* empty */                                   {$$ = NULL;}
    ;
    
returnStmt : RETURN ';'                             {$$ = newStmtNode(ReturnK, $1, NULL, NULL, NULL);}
    | RETURN exp ';'                                {$$ = newStmtNode(ReturnK, $1, $2, NULL, NULL);}
    ;
    
breakStmt : BREAK ';'                               {$$ = newStmtNode(BreakK, $1, NULL, NULL, NULL);}
    ;
    
exp : mutable assignop exp                          {$$ = newExpNode(AssignK, $2, $1, $3, NULL);}
    | mutable INC                                   {$$ = newExpNode(AssignK, $2, $1, NULL, NULL);}
    | mutable DEC                                   {$$ = newExpNode(AssignK, $2, $1, NULL, NULL);}
    | simpleExp                                     {$$ = $1;}
    ;
    
assignop : '='                                      {$$ = $1;}
    | ADDASS                                        {$$ = $1;}
    | SUBASS                                        {$$ = $1;}
    | MULASS                                        {$$ = $1;}
    | DIVASS                                        {$$ = $1;}
    ;
    
simpleExp : simpleExp OR andExp                     {$$ = newExpNode(OpK, $2, $1, $3, NULL);}
    | andExp                                        {$$ = $1;}
    ;
    
andExp : andExp AND unaryRelExp                     {$$ = newExpNode(OpK, $2, $1, $3, NULL);}
    | unaryRelExp                                   {$$ = $1;}
    ;
    
unaryRelExp : NOT unaryRelExp                       {$$ = newExpNode(OpK, $1, $2, NULL, NULL);}
    | relExp                                        {$$ = $1;}
    ;
    
relExp : minmaxExp relop minmaxExp                  {$$ = newExpNode(OpK, $2, $1, $3, NULL);}
    | minmaxExp                                     {$$ = $1;}
    ;
    
relop : LEQ                                         {$$ = $1;}
    | '<'                                           {$$ = $1;}
    | '>'                                           {$$ = $1;}
    | GEQ                                           {$$ = $1;}
    | EQ                                            {$$ = $1;}
    | NEQ                                           {$$ = $1;}
    ;
    
minmaxExp : minmaxExp minmaxop sumExp               {$$ = newExpNode(OpK, $2, $1, $3, NULL);}
    | sumExp                                        {$$ = $1;}
    ;
    
minmaxop : MAX                                      {$$ = $1;}
    | MIN                                           {$$ = $1;}
    ;
    
sumExp : sumExp sumop mulExp                        {$$ = newExpNode(OpK, $2, $1, $3, NULL);}
    | mulExp                                        {$$ = $1;}
    ;
    
sumop : '+'                                         {$$ = $1;}
    | '-'                                           {$$ = $1;}
    ;
    
mulExp : mulExp mulop unaryExp                      {$$ = newExpNode(OpK, $2, $1, $3, NULL);}
    | unaryExp                                      {$$ = $1;}
    ;
    
mulop : '*'                                         {$$ = $1;}
    | '/'                                           {$$ = $1;}
    | '%'                                           {$$ = $1;}
    ;
    
unaryExp : unaryop unaryExp                         {$$ = newExpNode(OpK, $1, $2, NULL, NULL);}
    | factor                                        {$$ = $1;}
    ;
    
unaryop : '-'                                       {$1->tokenclass = CHSIGN; $$ = $1;}
    | '*'                                           {$1->tokenclass = SIZEOF; $$ = $1;}
    | '?'                                           {$$ = $1;}
    ;
    
factor : immutable                                  {$$ = $1;}
    | mutable                                       {$$ = $1;}
    ;
    
mutable : ID                                        {$$ = newExpNode(IdK, $1, NULL, NULL);}
    | ID '[' exp ']'                                {$$ = newExpNode(OpK, $2, newExpNode(IdK, $1), $3);}
    ;
    
immutable : '(' exp ')'                             {$$ = $2;}
    | call                                          {$$ = $1;}
    | constant                                      {$$ = $1;}
    ;
    
call : ID '(' args ')'                              {$$ = newExpNode(CallK, $1, $3, NULL, NULL);}
    ;
    
args : argList                                      {$$ = $1;}
    | /* empty */                                   {$$ = NULL;}
    ;
    
argList : argList ',' exp                           {$$ = addSibling($1, $3);}
    | exp                                           {$$ = $1;}
    ;
    
constant : NUMCONST                                 {$$ = newExpNode(ConstantK, $1, NULL, NULL, NULL); $$->attr.value = $1->nvalue; $$->type = Integer; /* CHECK Should I use ENUM ExpType instead of $1 */ }
    | CHARCONST                                     {$$ = newExpNode(ConstantK, $1, NULL, NULL, NULL); $$->attr.cvalue = $1->cvalue; $$->type = Char;}
    | STRINGCONST                                   {$$ = newExpNode(ConstantK, $1, NULL, NULL, NULL); $$->attr.string = $1->svalue; $$->type = Char; $$->isArray = true; $$->size = $1->nvalue + 1;}
    | BOOLCONST                                     {$$ = newExpNode(ConstantK, $1, NULL, NULL, NULL); $$->attr.value = $1->nvalue; $$->type = Boolean;}
    ;
   
%%

void yyerror (const char *msg)
{ 
   cout << "Error: " <<  msg << endl;
   //numErrors++; // should this be global or pass by reference?
}

char *largerTokens[LASTTERM+1]; // used in the utils.cpp file printing routines
// create a mapping from token class enum to a printable name in a
// way that makes it easy to keep the mapping straight.
void initTokenStrings()
{
largerTokens[ADDASS] = (char *)"+=";
largerTokens[AND] = (char *)"and";
largerTokens[BOOL] = (char *)"bool";
largerTokens[BOOLCONST] = (char *)"boolconst";
largerTokens[BREAK] = (char *)"break";
largerTokens[BY] = (char *)"by";
largerTokens[CHAR] = (char *)"char";
largerTokens[CHARCONST] = (char *)"charconst";
largerTokens[CHSIGN] = (char *)"chsign";
largerTokens[DEC] = (char *)"--";
largerTokens[DIVASS] = (char *)"/=";
largerTokens[DO] = (char *)"do";
largerTokens[ELSE] = (char *)"else";
largerTokens[EQ] = (char *)"==";
largerTokens[FOR] = (char *)"for";
largerTokens[GEQ] = (char *)">=";
largerTokens[ID] = (char *)"id";
largerTokens[IF] = (char *)"if";
largerTokens[INC] = (char *)"++";
largerTokens[INT] = (char *)"int";
largerTokens[LEQ] = (char *)"<=";
largerTokens[MAX] = (char *)":>:";
largerTokens[MIN] = (char *)":<:";
largerTokens[MULASS] = (char *)"*=";
largerTokens[NEQ] = (char *)"!=";
largerTokens[NOT] = (char *)"not";
largerTokens[NUMCONST] = (char *)"numconst";
largerTokens[OR] = (char *)"or";
largerTokens[RETURN] = (char *)"return";
largerTokens[SIZEOF] = (char *)"sizeof";
largerTokens[STATIC] = (char *)"static";
largerTokens[STRINGCONST] = (char *)"stringconst";
largerTokens[SUBASS] = (char *)"-=";
largerTokens[THEN] = (char *)"then";
largerTokens[TO] = (char *)"to";
largerTokens[WHILE] = (char *)"while";
largerTokens[LASTTERM] = (char *)"lastterm";
}

int main(int argc, char **argv) {
   int option, index;
   numErrors = 0;
   numWarnings = 0;
   char *file = NULL;
   extern FILE *yyin;
   SymbolTable * symtab;
   symtab = new SymbolTable;
   symtab->debug(false);
   int globalOffset;
   while ((option = getopt (argc, argv, "")) != -1)
      switch (option)
      {
      default:
         ;
      }
   initTokenStrings();
   if ( optind == argc ) yyparse();
   for (index = optind; index < argc; index++) 
   {
      yyin = fopen (argv[index], "r");
      yyparse();
      fclose (yyin);
   }
   if(numErrors == 0)
   {
        syntaxTree = semanticAnalysis(syntaxTree, symtab, globalOffset);
   }
   if(numErrors == 0){
        printTree(stdout, syntaxTree, false, false); // set to true, true for assignment 4
   }
   printf("Number of warnings: %d\n", numWarnings);
   printf("Number of errors: %d\n", numErrors);
   return 0;
}

