#include "treeUtils.h"
#include <string.h>
#include "parser.tab.h"
extern char *largerTokens[];

TreeNode *newNodeFun(TreeNode *c0, TreeNode *c1, TreeNode *c2, TokenData *token)
{
    TreeNode *newNode = new TreeNode;
    newNode->child[0] = c0;
    newNode->child[1] = c1;
    newNode->child[2] = c2;
    newNode->sibling = NULL;
    
    newNode->size = 1;
    newNode->isStatic = false;
    newNode->isArray = false;
    newNode->isConst = false;
    newNode->isUsed = false;
    newNode->isAssigned = false;
    
    if(token != NULL)
    {
        newNode->lineno = token->linenum;
        newNode->attr.name = token->svalue;
        newNode->attr.value = token->nvalue;
        newNode->attr.string = strdup(token->svalue);
    }
    
    /*
    // Variables in treeNodes.h
        newNode->child[0] = ;
        newNode->sibling = ;
    newNode->nodenum = ;
        newNode->lineno = ;
        newNode->nodekind = ;
        newNode->kind.decl = ;
    newNode->attr.op = ;
        newNode->attr.value = ;
    newNode->attr.cvalue = ;
    newNode->attr.name = ; // difference in use than attr.string
    newNode->attr.string = ; 
        newNode->type = ;
        newNode->isStatic = ;
        newNode->isArray = ;
        newNode->isConst = ;
        newNode->isUsed = ;
        newNode->isAssigned = ;
        newNode->varKind = ;
    newNode->offset = ;
        newNode->size = ;
    */
    
    return newNode;
}

TreeNode *newDeclNode(DeclKind kind, ExpType type, TokenData *token, TreeNode *c0, TreeNode *c1, TreeNode *c2)
{
    TreeNode *newNode = newNodeFun(c0, c1, c2, token);
    newNode->nodekind = DeclK;
    newNode->kind.decl = kind;
    
    newNode->type = type;
    /*
    TreeNode *newNode = new TreeNode;
    newNode->child[0] = c0;
    newNode->child[1] = c1;
    newNode->child[2] = c2;
    newNode->nodekind = DeclK;
    newNode->kind.decl = kind;
    newNode->type = type;
    
    newNode->lineno = token->linenum;
    newNode->attr.name = token->svalue;
    */
    
    return newNode;
}

TreeNode *newStmtNode(StmtKind kind, TokenData *token, TreeNode *c0, TreeNode *c1, TreeNode *c2)
{
    TreeNode *newNode = newNodeFun(c0, c1, c2, token);
    newNode->nodekind = StmtK;
    newNode->kind.stmt = kind;
    /*
    TreeNode *newNode = new TreeNode;
    newNode->child[0] = c0;
    newNode->child[1] = c1;
    newNode->child[2] = c2;
    //newNode->type = type;
    newNode->nodekind = StmtK;
    newNode->kind.stmt = kind;
    
    newNode->lineno = token->linenum;
    newNode->attr.name = token->svalue;
    */
    
    return newNode;
}

TreeNode *newExpNode(ExpKind kind, TokenData *token, TreeNode *c0, TreeNode *c1, TreeNode *c2)
{
    TreeNode *newNode = newNodeFun(c0, c1, c2, token);
    newNode->nodekind = ExpK;
    newNode->kind.exp = kind;
    
    newNode->attr.op = (OpKind)token->tokenclass;
    /*
    TreeNode *newNode = new TreeNode;
    newNode->child[0] = c0;
    newNode->child[1] = c1;
    newNode->child[2] = c2;
    //newNode->type = type;
    newNode->nodekind = ExpK;
    newNode->kind.exp = kind;
    
    newNode->lineno = token->linenum;
    newNode->attr.name = token->svalue;
    //newNode->attr.op = (int)token->svalue[0];
    //newNode->attr.value = atoi(token->svalue);
    newNode->attr.string = strdup(token->svalue);
    */
    
    return newNode;
}

static void printSpaces(FILE *listing, int depth)
{
    for (int i=0; i<depth; i++) fprintf(listing, ".   ");
}

static char tokenBuffer[16];
char *tokenToStr(int type)
{
    if (type>LASTTERM) {
       return (char *)"UNKNOWN";
    }
    else if (type>256) {
       return largerTokens[type];
    }
    else if ((type<32) || (type>127)) {
       sprintf(tokenBuffer, "Token#%d", type);
    } else {
       tokenBuffer[0] = type;
       tokenBuffer[1] = '\0';
    }
    return tokenBuffer;
}

char *varKindToStr(int kind)
{
    switch (kind){
    case None:
        return (char *)"None";
    case Local:
        return (char *)"Local";
    case Global:
        return (char *)"Global";
    case Parameter:
        return (char *)"Parameter";
    case LocalStatic:
        return (char *)"LocalStatic";
    default:
        return (char *)"unknownVarKind";
    }
}

char expTypeToStrBuffer[80];
char *expTypeToStr(ExpType type, bool isArray, bool isStatic)
{
    char *typeName;

    switch (type){
    case Void:
       typeName = (char *)"type void";
       break;
    case Integer:
       typeName = (char *)"type int";
       break;
    case Boolean:
       typeName = (char *)"type bool";
       break;
    case Char:
       typeName = (char *)"type char";
       break;
    case UndefinedType:
       typeName = (char *)"undefined type";
       break;
    default:
       char *buffer;
       buffer = new char [80];
       sprintf(buffer, "invalid expType: %d", (int)type);
       return buffer;
    }

    // add static and array attributes
    // static type int
    // static array of type int
    sprintf(expTypeToStrBuffer, "%s%s%s",
            (isStatic ? "static " : ""),
            (isArray ? "array of " : ""),
            typeName);

    return strdup(expTypeToStrBuffer); // memory leak
}

void showAllocationFun(TreeNode *theNode, FILE *out){
    fprintf(out, " [mem: %s loc: %d size: %d]", varKindToStr(theNode->varKind), theNode->offset, theNode->size);
}

// modify
void printTreeNode(FILE *listing,
                   TreeNode *tree,
                   bool showExpType,
                   bool showAllocation)
{
    // should I have a default case?
    if(tree->nodekind == DeclK){ 
        switch(tree->kind.decl) 
        {
            case VarK:
                fprintf(listing, "Var: %s of %s", tree->attr.name, expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                showAllocationFun(tree, listing);
                break;
            case FuncK:
                fprintf(listing, "Func: %s returns %s", tree->attr.name, expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                showAllocationFun(tree, listing);
                break;
            case ParamK:
                fprintf(listing, "Parm: %s of %s", tree->attr.name, expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                showAllocationFun(tree, listing);
                break;
        }
    }
    else if(tree->nodekind == StmtK){
        switch(tree->kind.stmt)
        {
            case IfK:
                fprintf(listing, "If");
                break;
            case WhileK:
                fprintf(listing, "While");
                break;
            case ForK:
                fprintf(listing, "For");
                showAllocationFun(tree, listing);
                break;
            case CompoundK:
                fprintf(listing, "Compound");
                showAllocationFun(tree, listing);
                break;
            case ReturnK:
                fprintf(listing, "Return");
                break;
            case BreakK:
                fprintf(listing, "Break");
                break;
            case RangeK:
                fprintf(listing, "Range");
                break;
        }
    }
    else if(tree->nodekind == ExpK){
        switch(tree->kind.exp)
        {
            case AssignK:
                //fprintf(listing, "Assign: %s", tokenToStr(tree->attr.op)); // wrong? printing: Token#0 . '=' is 61
                fprintf(listing, "Assign: %s of %s", tree->attr.name, expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                break;
            case CallK:
                fprintf(listing, "Call: %s of %s", tree->attr.name, expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                break;
            case ConstantK:
                // Can't get to print as any child
                //fprintf(listing, "Const");
                //fprintf(listing, "Const %s", tree->attr.value);
                ///*
                switch(tree->type){
                    /*
                    case Void: // Not necessary?
                        //fprintf(listing, "Const %s", tree->attr.value);
                        break;
                    */
                    case Integer:
                        fprintf(listing, "Const %d of %s", tree->attr.value, expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                        break;
                    case Boolean: // check
                        if(tree->attr.value != 0) // should true only be 1?
                        {
                            fprintf(listing, "Const true of %s", expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                        }
                        else
                        {
                            fprintf(listing, "Const false of %s", expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                        }
                        break;
                    case Char: // would this handle both chars and strings?
                        int i = 0;
                        //while(tree->attr.string[i] != tree->attr.string[tree->size - 1]) // this should also work?
                        /*
                        while(tree->attr.string[i] != '\0')
                        {
                            fprintf(listing, "Const %c", tree->attr.string[i]);
                            i++;
                        }
                        */
                        if(tree->isArray)
                        {
                            fprintf(listing, "Const \"%s\" of %s", tree->attr.string, expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                            showAllocationFun(tree, listing);
                        }
                        else
                        {
                            fprintf(listing, "Const '%c' of %s", tree->attr.cvalue, expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                        }
                        break;
                    /*
                    case UndefinedType: // Not necessary?
                        //fprintf(listing, "Const %s", tree->attr.value);
                        break;
                    */
                }
                //*/
                break;
            case IdK:
                fprintf(listing, "Id: %s of %s", tree->attr.name, expTypeToStr(tree->type, tree->isArray, tree->isStatic)); // prints null when it worked for VarK
                showAllocationFun(tree, listing);
                break;
            case OpK:
                fprintf(listing, "Op: %s of %s", tokenToStr(tree->attr.op), expTypeToStr(tree->type, tree->isArray, tree->isStatic));
                break;
        }
    }
    printf(" [line: %d]", tree->lineno);
}

// stable
void printTreeRec(FILE *listing, int depth, int siblingCnt, TreeNode *tree, bool showExpType, bool showAllocation)
{
   int childCnt;
   if (tree!=NULL) {
      // print self
      printTreeNode(listing, tree, showExpType, showAllocation);
      fprintf(listing, "\n");

      // print children
      for (childCnt = 0; childCnt<MAXCHILDREN; childCnt++) {
         if (tree->child[childCnt]) {
            printSpaces(listing, depth);
            fprintf(listing, "Child: %d  ", childCnt);
            printTreeRec(listing, depth+1, 1, tree->child[childCnt], showExpType, showAllocation);
         }
      }
   }
   // print sibling
   tree = tree->sibling;
   if (tree!=NULL) {
      if (depth) {
         printSpaces(listing, depth-1);
         fprintf(listing, "Sibling: %d  ", siblingCnt);
      }
      printTreeRec(listing, depth, siblingCnt+1, tree, showExpType, showAllocation);
   }
   fflush(listing);
}

//stable
void printTree(FILE *listing, TreeNode *tree, bool showExpType, bool showAllocation)
{
   if(tree == NULL){
      printf("NULL tree\n");
      return;
   }
   printTreeRec(listing, 1, 1, tree, showExpType, showAllocation);
}


