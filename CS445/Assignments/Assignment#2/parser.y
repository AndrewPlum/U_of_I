%{
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "scanType.h"
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *msg);

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

%}
%union
{
   struct   TokenData tinfo ;
}
%token   <tinfo>  OP
%token   <tinfo>  MAX MIN
%token   <tinfo>  ADDASS SUBASS MULASS DIVASS
%token   <tinfo>  INC DEC
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
%type <tinfo>  term program
%%
program  :  program term
   |  term  {$$=$1;}
   ;
term  : 
      OP {printToken(yylval.tinfo, "OP");}
   |  MIN {printToken(yylval.tinfo, "MIN");}
   |  MAX {printToken(yylval.tinfo, "MAX");}  
   |  DIVASS {printToken(yylval.tinfo, "DIVASS");}
   |  MULASS {printToken(yylval.tinfo, "MULASS");}
   |  SUBASS {printToken(yylval.tinfo, "SUBASS");}
   |  ADDASS {printToken(yylval.tinfo, "ADDASS");}
   |  DEC {printToken(yylval.tinfo, "DEC");}
   |  INC {printToken(yylval.tinfo, "INC");}
   |  EQ {printToken(yylval.tinfo, "EQ");}
   |  NEQ {printToken(yylval.tinfo, "NEQ");}
   |  GEQ {printToken(yylval.tinfo, "GEQ");}
   |  LEQ {printToken(yylval.tinfo, "LEQ");}
   |  NOT  {printToken(yylval.tinfo, "NOT");}
   |  OR  {printToken(yylval.tinfo, "OR");}
   |  AND {printToken(yylval.tinfo, "AND");}
   |  BREAK {printToken(yylval.tinfo, "BREAK");}
   |  BY  {printToken(yylval.tinfo, "BY");}
   |  TO  {printToken(yylval.tinfo, "TO");}
   |  DO  {printToken(yylval.tinfo, "DO");}
   |  WHILE  {printToken(yylval.tinfo, "WHILE");}
   |  FOR  {printToken(yylval.tinfo, "FOR");}
   |  IF {printToken(yylval.tinfo, "IF");}  
   |  THEN {printToken(yylval.tinfo, "THEN");}
   |  ELSE {printToken(yylval.tinfo, "ELSE");} 
   |  INT {printToken(yylval.tinfo, "INT");} 
   |  BOOL {printToken(yylval.tinfo, "BOOL");} 
   |  CHAR {printToken(yylval.tinfo, "CHAR");} 
   |  STATIC {printToken(yylval.tinfo, "STATIC");}  
   |  RETURN {printToken(yylval.tinfo, "RETURN");} 
   |  PRECOMPILER {printToken(yylval.tinfo, "PRECOMPILER");} 
   |  BOOLCONST {printToken(yylval.tinfo, "BOOLCONST");}   
   |  CHARCONST {printToken(yylval.tinfo, "CHARCONST");} 
   |  STRINGCONST {printToken(yylval.tinfo, "STRINGCONST");} 
   |  NUMCONST {printToken(yylval.tinfo, "NUMCONST");}
   |  ID {printToken(yylval.tinfo, "ID");} 
   |  ERROR    {cout << "ERROR(SCANNER Line " << yylval.tinfo.linenum << "): Invalid input character " << yylval.tinfo.tokenstr << endl; }
   ;
%%

void yyerror (const char *msg)
{ 
   cout << "Error: " <<  msg << endl;
}

int main(int argc, char **argv) {
   yylval.tinfo.linenum = 1;
   int option, index;
   char *file = NULL;
   extern FILE *yyin;
   while ((option = getopt (argc, argv, "")) != -1)
      switch (option)
      {
      default:
         ;
      }
   if ( optind == argc ) yyparse();
   for (index = optind; index < argc; index++) 
   {
      yyin = fopen (argv[index], "r");
      yyparse();
      fclose (yyin);
   }
   return 0;
}

