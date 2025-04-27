/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAX = 258,
    MIN = 259,
    ADDASS = 260,
    SUBASS = 261,
    MULASS = 262,
    DIVASS = 263,
    INC = 264,
    DEC = 265,
    CHSIGN = 266,
    SIZEOF = 267,
    EQ = 268,
    NEQ = 269,
    GEQ = 270,
    LEQ = 271,
    AND = 272,
    OR = 273,
    NOT = 274,
    BREAK = 275,
    FOR = 276,
    WHILE = 277,
    DO = 278,
    TO = 279,
    BY = 280,
    IF = 281,
    THEN = 282,
    ELSE = 283,
    INT = 284,
    BOOL = 285,
    CHAR = 286,
    STATIC = 287,
    RETURN = 288,
    PRECOMPILER = 289,
    ID = 290,
    BOOLCONST = 291,
    NUMCONST = 292,
    CHARCONST = 293,
    STRINGCONST = 294,
    ERROR = 295,
    LASTTERM = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 91 "parser.y" /* yacc.c:1909  */

    //struct   TokenData tinfo ; // this was previously here but I think slides said to remove and add lines below to union
    TokenData *tinfo;
    TreeNode *tree;
    ExpType type; // for passing type spec up the tree

#line 103 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
