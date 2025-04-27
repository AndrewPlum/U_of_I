 /*********************************************
 * Id: plum0598
 *
 * This program uses YACC to make a calculator that has expanded functionality from w04
 *********************************************/

%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

extern int yylex();
void yyerror(char *msg);
%}

%union{
   float f;
}

%token <f> NUM
%type <f> E T F G H

%%
 
S : G         {printf("%f\n", $1);}
  ;
  
G : G '#' E   {$$ = $1 + $3 + 1; printf("%f # %f\n", $1, $3);}
  | E         {$$ = $1; printf("%f\n", $1);}
  ;   
  
E : E '+' T   {$$ = $1 + $3; printf("%f + %f\n", $1, $3);}
  | E '-' T   {$$ = $1 - $3; printf("%f - %f\n", $1, $3);}
  | T         {$$ = $1; printf("%f\n", $1);}
  ;
 
T : T '*' H   {$$ = $1 * $3; printf("%f * %f\n", $1, $3);}
  | T '/' H   {$$ = $1 / $3; printf("%f / %f\n", $1, $3);}
  | H         {$$ = $1; printf("%f\n", $1);}
  ;
  
H : F '<' H   {$$ = powf($1,$3); printf("%f < %f\n", $1, $3);}
  | F		  {$$ = $1; printf("%f\n", $1);}
  ;
  
F : '(' G ')' {$$ = $2; printf("(%f)\n", $2);}
  | '-' F     {$$ = -$2; printf("-%f\n", $2);}
  | NUM       {$$ = $1; printf("%f\n", $1);}
  ;
  
%%

void yyerror(char *msg){
   fprintf(stderr, "%s\n", msg);
   exit(1);
}

int main(){
   yyparse();
   return 0;
}
