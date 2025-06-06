 /*********************************************
 * Id: plum0598
 *
 * This program uses YACC to make a calculator that has expanded functionality from w04
 *********************************************/

%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h" // generated via yacc -d  
%}

%option noyywrap

%%

[0-9]+(\.[0-9]+)?([eE][0-9]+)?   {yylval.f = atof(yytext); return NUM;}
[-+()*/]                         {return yytext[0];}
[ \t\f\v\n]                      { ; }
[-+()*/#<]                       {return yytext[0];}

%%