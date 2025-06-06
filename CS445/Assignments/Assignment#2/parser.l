%{
#include "scanType.h"
#include "parser.tab.h" // This has to be the last include

using namespace std;

#define YY_DECL extern "C" int yylex()
#define YYSTYPE int

int line=1;
char *lastToken=(char *)"";
//extern int numErrors;

int setValue(int linenum, int tokenClass, char *svalue) {
    yylval.tinfo.tokenclass = tokenClass;
    yylval.tinfo.linenum = linenum;
    yylval.tinfo.tokenstr = strdup(svalue);
    yylval.tinfo.cvalue = svalue[0];
    yylval.tinfo.nvalue = atoi(svalue);
    yylval.tinfo.svalue = strdup(svalue);

    yylval.tinfo.tokenstr = lastToken = strdup(svalue);

    switch (tokenClass) {

    case NUMCONST:
         // yylval.tinfo.nvalue = hmmmm ..... I don't need this yet, but
         break;

    case OP:
         // yylval.tinfo.cvalue = hmmm..... What should I set it to?
         break;
    }


    return tokenClass;
}

%}

%option noyywrap

letter                                      [a-zA-Z]
digit                                       [0-9]
quote                                       [\']
underbar                                    [_]
letdig                                      {digit}|{letter}|{underbar}
charconst                                   \'\\?.\'
limitters                                   [\;\,\(\)\{\}\[\]]
op                                          [\-\+\*\/\%]
whitespace                                  [\ \t]               
%%
[\(\)\[\]\{\}\,\;\:\=\+\-\*\/\%\?\>\<]      { return setValue(line, OP, yytext); } // single char tokens

":<:"                                       { return setValue(line, MIN, yytext); }
":>:"                                       { return setValue(line, MAX, yytext); }

"/="                                        { return setValue(line, DIVASS, yytext); }
"*="                                        { return setValue(line, MULASS, yytext); }
"-="                                        { return setValue(line, SUBASS, yytext); }
"+="                                        { return setValue(line, ADDASS, yytext); }

"--"                                        { return setValue(line, DEC, yytext); }
"++"                                        { return setValue(line, INC, yytext); }

"=="                                        { return setValue(line, EQ, yytext); }
"!="                                        { return setValue(line, NEQ, yytext); }
">="                                        { return setValue(line, GEQ, yytext); }
"<="                                        { return setValue(line, LEQ, yytext); }

"not"                                       { return setValue(line, NOT, yytext); }
"or"                                        { return setValue(line, OR, yytext); }
"and"                                       { return setValue(line, AND, yytext); }

"break"                                     { return setValue(line, BREAK, yytext); }

"by"                                        { return setValue(line, BY, yytext); }
"to"                                        { return setValue(line, TO, yytext); }
"do"                                        { return setValue(line, DO, yytext); }
"while"                                     { return setValue(line, WHILE, yytext); }
"for"                                       { return setValue(line, FOR, yytext); }

"if"                                        { return setValue(line, IF, yytext); }
"then"                                      { return setValue(line, THEN, yytext); }
"else"                                      { return setValue(line, ELSE, yytext); }

"int"                                       { return setValue(line, INT, yytext); }
"bool"                                      { return setValue(line, BOOL, yytext); }
"char"                                      { return setValue(line, CHAR, yytext); }

"static"                                    { return setValue(line, STATIC, yytext); }

"return"                                    { return setValue(line, RETURN, yytext); }

^"#DRBC ".*                                 { return setValue(line, PRECOMPILER, yytext); }
^"#DRBCRUN ".*                              { return setValue(line, PRECOMPILER, yytext); }

"//".*                                      { /* Ignore comment text */ }
"true"|"false"                              { return setValue(line, BOOLCONST, yytext); }
[0-9]+                                      { return setValue(line, NUMCONST, yytext); }
{charconst}                                 { return setValue(line, CHARCONST, yytext); }
["](\\[^\n]|[^\"\\\n])*["]                  { return setValue(line, STRINGCONST, yytext); }
{letter}{letdig}*                           { return setValue(line, ID, yytext); }
\n                                          {  line++; }
{whitespace}+                               ;
.                                           { printf("ERROR(%d): Token error, invalid or misplaced input character: \'%c\'. Character Ignored.\n", line, yytext[0]);}


