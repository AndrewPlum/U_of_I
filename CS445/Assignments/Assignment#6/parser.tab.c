/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "scanType.h"
#include "treeNodes.h"
#include "treeUtils.h"
#include "symbolTable.h"
#include "semantics.h"
#include "codegen.h"
#include "yyerror.h"
using namespace std;

int numErrors;
int numWarnings;

extern bool globalMainFound;
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
        
        TreeNode *curr = t;
        while(curr->sibling != NULL)
        {
            curr = curr->sibling;
        }
        printf("Sibling before new NULL sibling line number: %d\n", curr->lineno);
        printf("Sibling before new NULL sibling name: %s\n", curr->attr.name);
        
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


#line 168 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
#line 103 "parser.y" /* yacc.c:355  */

    //struct   TokenData tinfo ; // this was previously here but I think slides said to remove and add lines below to union
    TokenData *tinfo;
    TreeNode *tree;
    ExpType type; // for passing type spec up the tree

#line 257 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 274 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    10,     2,     2,
      12,    13,     3,     4,    14,     5,     2,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    20,    15,
       7,     8,     9,    11,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    16,     2,    19,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,    18,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   178,   179,   180,   183,   184,   187,   188,
     191,   194,   195,   198,   199,   202,   203,   206,   207,   210,
     211,   212,   215,   216,   217,   218,   219,   220,   223,   224,
     227,   228,   231,   234,   235,   238,   239,   242,   243,   246,
     247,   248,   249,   250,   251,   252,   255,   256,   259,   260,
     261,   262,   265,   266,   267,   270,   273,   274,   277,   278,
     281,   282,   285,   288,   289,   290,   291,   294,   295,   296,
     297,   298,   301,   302,   305,   306,   309,   310,   313,   314,
     317,   318,   319,   320,   321,   322,   325,   326,   329,   330,
     333,   334,   337,   338,   341,   342,   345,   346,   347,   350,
     351,   354,   355,   356,   359,   360,   363,   364,   368,   369,
     370,   371,   374,   375,   378,   379,   382,   383,   384,   387,
     388,   389,   390
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'*'", "'+'", "'-'", "'/'", "'<'", "'='",
  "'>'", "'%'", "'?'", "'('", "')'", "','", "';'", "'['", "'{'", "'}'",
  "']'", "':'", "MAX", "MIN", "ADDASS", "SUBASS", "MULASS", "DIVASS",
  "INC", "DEC", "CHSIGN", "SIZEOF", "EQ", "NEQ", "GEQ", "LEQ", "AND", "OR",
  "NOT", "BREAK", "FOR", "WHILE", "DO", "TO", "BY", "IF", "THEN", "ELSE",
  "INT", "BOOL", "CHAR", "STATIC", "RETURN", "PRECOMPILER", "ID",
  "BOOLCONST", "NUMCONST", "CHARCONST", "STRINGCONST", "ERROR", "LASTTERM",
  "$accept", "program", "precomList", "declList", "decl", "varDecl",
  "scopedVarDecl", "varDeclList", "varDeclInit", "varDeclId", "typeSpec",
  "funDecl", "parms", "parmList", "parmTypeList", "parmIdList", "parmId",
  "stmt", "matched", "iterRange", "unmatched", "expStmt", "compoundStmt",
  "localDecls", "stmtList", "returnStmt", "breakStmt", "exp", "assignop",
  "simpleExp", "andExp", "unaryRelExp", "relExp", "relop", "minmaxExp",
  "minmaxop", "sumExp", "sumop", "mulExp", "mulop", "unaryExp", "unaryop",
  "factor", "mutable", "immutable", "call", "args", "argList", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    42,    43,    45,    47,    60,    61,    62,
      37,    63,    40,    41,    44,    59,    91,   123,   125,    93,
      58,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296
};
# endif

#define YYPACT_NINF -141

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-141)))

#define YYTABLE_NINF -116

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -48,  -141,     6,   152,  -141,  -141,  -141,  -141,  -141,    14,
      59,  -141,  -141,     9,  -141,    37,  -141,  -141,    89,    61,
    -141,    16,  -141,   -29,    31,    52,  -141,    79,    54,    25,
    -141,    40,   106,   111,  -141,   205,   130,  -141,   124,   120,
     114,  -141,  -141,  -141,  -141,    99,    40,   104,  -141,  -141,
    -141,  -141,   105,   115,  -141,  -141,   150,    94,    13,  -141,
     221,  -141,  -141,  -141,  -141,  -141,   127,   -29,  -141,  -141,
     143,   107,    40,    40,   216,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,    12,   105,   240,  -141,    17,  -141,  -141,   149,
    -141,    78,    40,    40,    40,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,   221,   221,  -141,  -141,   221,  -141,  -141,
    -141,   221,  -141,  -141,  -141,   117,  -141,   160,    46,   -15,
    -141,   165,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,    40,  -141,  -141,  -141,   176,  -141,   190,   192,   188,
     115,  -141,    96,    94,    13,  -141,   130,  -141,    25,   158,
      40,   205,   205,  -141,  -141,  -141,  -141,   137,  -141,    25,
     171,  -141,  -141,   177,    23,  -141,  -141,  -141,   179,  -141,
    -141,   173,  -141,   205,    40,   205,  -141,  -141,  -141,     4,
    -141,  -141,    40,   105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     4,     0,     0,     1,    19,    20,    21,     3,     0,
       2,     7,     8,     0,     9,     0,     6,    24,    17,     0,
      14,    15,    26,     0,     0,    28,    31,     0,     0,     0,
      10,     0,    35,    32,    34,     0,     0,    25,     0,     0,
      17,    13,   102,   101,   103,     0,     0,   106,   122,   119,
     120,   121,    16,    73,    75,    77,    79,    87,    91,    95,
       0,   100,   105,   104,   109,   110,     0,     0,    53,    57,
       0,     0,     0,     0,     0,    23,    37,    38,    42,    43,
      44,    45,     0,    66,   105,    30,     0,    18,   111,     0,
      76,     0,     0,     0,     0,    81,    82,    88,    89,    84,
      85,    83,    80,     0,     0,    92,    93,     0,    96,    97,
      98,     0,    99,    36,    33,    59,    62,     0,     0,     0,
      60,     0,    54,    52,    67,    68,    69,    70,    71,    64,
      65,     0,    27,    22,   108,     0,   117,     0,   114,     0,
      72,    74,    78,    86,    90,    94,     0,    56,     0,     0,
       0,     0,     0,    61,    63,   113,   112,     0,   107,     0,
       0,    55,    58,     0,     0,    40,    50,    48,    37,   118,
     116,     0,    12,     0,     0,     0,    11,    41,    51,    46,
      39,    49,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,   213,  -141,  -141,  -134,   200,  -141,
      -2,  -141,   203,  -141,   198,  -141,   168,   -83,  -140,  -141,
    -136,  -141,  -141,  -141,  -141,  -141,  -141,   -43,  -141,   -31,
     144,   -41,  -141,  -141,   133,  -141,   134,  -141,   132,  -141,
     -51,  -141,  -141,   -28,  -141,  -141,  -141,  -141,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,   147,    19,    20,    21,
      23,    14,    24,    25,    26,    33,    34,    75,    76,   163,
      77,    78,    79,   115,   149,    80,    81,    82,   131,    83,
      53,    54,    55,   103,    56,   104,    57,   107,    58,   111,
      59,    60,    61,    62,    63,    64,   137,   138,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    13,    89,   133,     1,    90,     4,    84,    13,   112,
      17,   165,   168,   122,   160,   166,   108,    84,   132,   109,
      42,    93,    43,   110,    32,   171,    15,   123,    44,    45,
     152,   121,    68,   177,    69,   180,    31,   178,    22,   181,
      93,   118,   119,    42,    35,    43,    84,   182,   136,   139,
     -29,    44,    45,   141,    46,    70,    71,    72,    84,    93,
     145,    73,    18,    84,    84,   174,   162,    36,    74,   167,
      47,    48,    49,    50,    51,    29,    30,    46,    40,   135,
      37,    42,    93,    43,     5,     6,     7,   151,   154,    44,
      45,  -115,   -29,    47,    48,    49,    50,    51,   105,   106,
      88,    27,    42,    84,    43,    28,     5,     6,     7,    39,
      44,    45,     9,   148,   170,    46,    91,    97,    98,   164,
      92,    84,    66,    84,    84,    67,     5,     6,     7,    84,
      28,    47,    48,    49,    50,    51,    46,    86,   169,    87,
      42,    93,    43,   179,   159,    84,   113,    84,    44,    45,
      94,   183,    47,    48,    49,    50,    51,    95,   116,    96,
     117,    42,   134,    43,     5,     6,     7,   146,   150,    44,
      45,    97,    98,    68,    46,    69,   161,     5,     6,     7,
     153,    99,   100,   101,   102,    29,   172,    29,   176,   155,
      47,    48,    49,    50,    51,    46,    70,    71,    72,     5,
       6,     7,    73,   156,     8,     9,   157,   158,    42,    74,
      43,    47,    48,    49,    50,    51,    44,    45,   173,    42,
      68,    43,    69,    16,    42,   175,    43,    44,    45,    41,
      38,   120,    44,    45,    85,   114,   142,   140,   143,   144,
       0,     0,    46,    70,    71,    72,     0,     0,   124,    73,
       0,     0,     0,    46,     0,     0,    74,     0,    47,    48,
      49,    50,    51,   125,   126,   127,   128,   129,   130,    47,
      48,    49,    50,    51,    47,    48,    49,    50,    51
};

static const yytype_int16 yycheck[] =
{
      31,     3,    45,    86,    52,    46,     0,    35,    10,    60,
       1,   151,   152,     1,   148,   151,     3,    45,     1,     6,
       3,    36,     5,    10,    53,   159,    12,    15,    11,    12,
      45,    74,    15,   173,    17,   175,    20,   173,     1,   175,
      36,    72,    73,     3,    13,     5,    74,    43,    91,    92,
      13,    11,    12,    94,    37,    38,    39,    40,    86,    36,
     111,    44,    53,    91,    92,    42,   149,    15,    51,   152,
      53,    54,    55,    56,    57,    14,    15,    37,    53,     1,
       1,     3,    36,     5,    47,    48,    49,    41,   131,    11,
      12,    13,    13,    53,    54,    55,    56,    57,     4,     5,
       1,    12,     3,   131,     5,    16,    47,    48,    49,    55,
      11,    12,    53,   115,   157,    37,    12,    21,    22,   150,
      16,   149,    16,   151,   152,    14,    47,    48,    49,   157,
      16,    53,    54,    55,    56,    57,    37,    13,     1,    19,
       3,    36,     5,   174,   146,   173,    19,   175,    11,    12,
      35,   182,    53,    54,    55,    56,    57,     7,    15,     9,
      53,     3,    13,     5,    47,    48,    49,    50,     8,    11,
      12,    21,    22,    15,    37,    17,    18,    47,    48,    49,
      15,    31,    32,    33,    34,    14,    15,    14,    15,    13,
      53,    54,    55,    56,    57,    37,    38,    39,    40,    47,
      48,    49,    44,    13,    52,    53,    14,    19,     3,    51,
       5,    53,    54,    55,    56,    57,    11,    12,    41,     3,
      15,     5,    17,    10,     3,    46,     5,    11,    12,    29,
      27,    15,    11,    12,    36,    67,   103,    93,   104,   107,
      -1,    -1,    37,    38,    39,    40,    -1,    -1,     8,    44,
      -1,    -1,    -1,    37,    -1,    -1,    51,    -1,    53,    54,
      55,    56,    57,    23,    24,    25,    26,    27,    28,    53,
      54,    55,    56,    57,    53,    54,    55,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,    61,    62,     0,    47,    48,    49,    52,    53,
      63,    64,    65,    70,    71,    12,    64,     1,    53,    67,
      68,    69,     1,    70,    72,    73,    74,    12,    16,    14,
      15,    20,    53,    75,    76,    13,    15,     1,    72,    55,
      53,    68,     3,     5,    11,    12,    37,    53,    54,    55,
      56,    57,    89,    90,    91,    92,    94,    96,    98,   100,
     101,   102,   103,   104,   105,   108,    16,    14,    15,    17,
      38,    39,    40,    44,    51,    77,    78,    80,    81,    82,
      85,    86,    87,    89,   103,    74,    13,    19,     1,    87,
      91,    12,    16,    36,    35,     7,     9,    21,    22,    31,
      32,    33,    34,    93,    95,     4,     5,    97,     3,     6,
      10,    99,   100,    19,    76,    83,    15,    53,    89,    89,
      15,    87,     1,    15,     8,    23,    24,    25,    26,    27,
      28,    88,     1,    77,    13,     1,    87,   106,   107,    87,
      90,    91,    94,    96,    98,   100,    50,    66,    70,    84,
       8,    41,    45,    15,    87,    13,    13,    14,    19,    70,
      67,    18,    77,    79,    89,    78,    80,    77,    78,     1,
      87,    67,    15,    41,    42,    46,    15,    78,    80,    89,
      78,    80,    43,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    63,    63,    64,    64,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      73,    73,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    81,    82,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,    99,   100,
     100,   101,   101,   101,   102,   102,   103,   103,   104,   104,
     104,   104,   105,   105,   106,   106,   107,   107,   107,   108,
     108,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     2,     1,     1,     1,
       3,     4,     3,     3,     1,     1,     3,     1,     4,     1,
       1,     1,     6,     5,     2,     4,     3,     6,     1,     0,
       3,     1,     2,     3,     1,     1,     3,     1,     1,     6,
       4,     6,     1,     1,     1,     1,     3,     5,     4,     6,
       4,     6,     2,     1,     2,     4,     2,     0,     2,     0,
       2,     3,     2,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       1,     2,     4,     4,     1,     0,     3,     1,     3,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 175 "parser.y" /* yacc.c:1646  */
    {syntaxTree = (yyvsp[0].tree);}
#line 1513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL; printf("%s\n", yylval.tinfo->tokenstr);}
#line 1519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL; printf("%s\n", yylval.tinfo->tokenstr);}
#line 1525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = addSibling((yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 187 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 191 "parser.y" /* yacc.c:1646  */
    {setType((yyvsp[-1].tree), (yyvsp[-2].type), false); (yyval.tree) = (yyvsp[-1].tree);}
#line 1561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 194 "parser.y" /* yacc.c:1646  */
    {setType((yyvsp[-1].tree), (yyvsp[-2].type), true); (yyval.tree) = (yyvsp[-1].tree);}
#line 1567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 195 "parser.y" /* yacc.c:1646  */
    {setType((yyvsp[-1].tree), (yyvsp[-2].type), false); (yyval.tree) = (yyvsp[-1].tree);}
#line 1573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-2].tree); if ((yyval.tree) != NULL) (yyval.tree)->child[0] = (yyvsp[0].tree);}
#line 1597 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(VarK, UndefinedType, (yyvsp[0].tinfo), NULL, NULL, NULL);}
#line 1603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(VarK, UndefinedType, (yyvsp[-3].tinfo), NULL, NULL, NULL); (yyval.tree)->isArray = true; (yyval.tree)->size = (yyvsp[-1].tinfo)->nvalue + 1; }
#line 1609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = Integer; /*CHECK*/}
#line 1615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = Boolean;}
#line 1621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 212 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = Char;}
#line 1627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(FuncK, (yyvsp[-5].type), (yyvsp[-4].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 1633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(FuncK, Void, (yyvsp[-4].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 1639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 219 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 220 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 223 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 227 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 231 "parser.y" /* yacc.c:1646  */
    {setType((yyvsp[0].tree), (yyvsp[-1].type), false); (yyval.tree) = (yyvsp[0].tree);}
#line 1693 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 234 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 235 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 238 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(ParamK, UndefinedType, (yyvsp[0].tinfo));}
#line 1711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 239 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(ParamK, UndefinedType, (yyvsp[-2].tinfo)); (yyval.tree)->isArray = true;}
#line 1717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 242 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tinfo), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 1741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 248 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tinfo), newDeclNode(VarK, Integer, (yyvsp[-4].tinfo)), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)->child[0]->attr.name = (yyvsp[-4].tinfo)->svalue;}
#line 1747 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 249 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 251 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 255 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(RangeK, (yyvsp[-1].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 1777 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 256 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(RangeK, (yyvsp[-3].tinfo), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 259 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(IfK, (yyvsp[-3].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 1789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tinfo), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 261 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 1801 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tinfo), newDeclNode(VarK, Integer, (yyvsp[-4].tinfo)), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)->child[0]->attr.name = (yyvsp[-4].tinfo)->svalue;}
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree);}
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 267 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(CompoundK, (yyvsp[-3].tinfo), (yyvsp[-2].tree), (yyvsp[-1].tree), NULL); /* CHECK */}
#line 1831 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = addSibling((yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1837 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 277 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0].tree) != NULL) (yyval.tree) = addSibling((yyvsp[-1].tree), (yyvsp[0].tree)); else (yyval.tree) = (yyvsp[-1].tree);}
#line 1849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1855 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 281 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(ReturnK, (yyvsp[-1].tinfo), NULL, NULL, NULL);}
#line 1861 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 282 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(ReturnK, (yyvsp[-2].tinfo), (yyvsp[-1].tree), NULL, NULL);}
#line 1867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 285 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(BreakK, (yyvsp[-1].tinfo), NULL, NULL, NULL);}
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(AssignK, (yyvsp[-1].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 1879 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 289 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(AssignK, (yyvsp[0].tinfo), (yyvsp[-1].tree), NULL, NULL);}
#line 1885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 290 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(AssignK, (yyvsp[0].tinfo), (yyvsp[-1].tree), NULL, NULL);}
#line 1891 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 291 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1897 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 294 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 1903 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 295 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 1909 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 1915 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 1921 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 1927 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 301 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 1933 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1939 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 305 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 1945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 306 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1951 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tinfo), (yyvsp[0].tree), NULL, NULL);}
#line 1957 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 310 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1963 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 313 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 1969 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1975 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 317 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 1981 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 1987 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 319 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 1993 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 320 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 1999 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 321 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2005 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 322 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2011 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 325 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 2017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 326 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2023 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 329 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2029 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 330 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2035 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 333 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 334 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2047 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 337 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2053 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 338 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 341 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tinfo), (yyvsp[-2].tree), (yyvsp[0].tree), NULL);}
#line 2065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 342 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2071 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 345 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 346 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 347 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 350 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tinfo), (yyvsp[0].tree), NULL, NULL);}
#line 2095 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 351 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2101 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 354 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].tinfo)->tokenclass = CHSIGN; (yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2107 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 355 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].tinfo)->tokenclass = SIZEOF; (yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2113 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 356 "parser.y" /* yacc.c:1646  */
    {(yyval.tinfo) = (yyvsp[0].tinfo);}
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 359 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2125 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 360 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2131 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 363 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(IdK, (yyvsp[0].tinfo), NULL, NULL); (yyval.tree)->attr.name = (yyvsp[0].tinfo)->svalue;}
#line 2137 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 364 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-2].tinfo), newExpNode(IdK, (yyvsp[-3].tinfo)), (yyvsp[-1].tree)); 
                                                     (yyval.tree)->child[0]->attr.name = (yyvsp[-3].tinfo)->svalue;}
#line 2144 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 368 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree);}
#line 2150 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 369 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2156 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 370 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2162 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 371 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 2168 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 374 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(CallK, (yyvsp[-3].tinfo), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)->attr.name = (yyvsp[-3].tinfo)->svalue;}
#line 2174 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 375 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 2180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 378 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2186 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 379 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 2192 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 382 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 2198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 383 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 384 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 2210 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 387 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tinfo), NULL, NULL, NULL); (yyval.tree)->attr.value = (yyvsp[0].tinfo)->nvalue; (yyval.tree)->type = Integer; /* CHECK Should I use ENUM ExpType instead of $1 */ }
#line 2216 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 388 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tinfo), NULL, NULL, NULL); (yyval.tree)->attr.cvalue = (yyvsp[0].tinfo)->cvalue; (yyval.tree)->type = Char;}
#line 2222 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 389 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tinfo), NULL, NULL, NULL); (yyval.tree)->attr.string = (yyvsp[0].tinfo)->svalue; (yyval.tree)->type = Char; (yyval.tree)->isArray = true; (yyval.tree)->size = (yyvsp[0].tinfo)->nvalue + 1;}
#line 2228 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 390 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tinfo), NULL, NULL, NULL); (yyval.tree)->attr.value = (yyvsp[0].tinfo)->nvalue; (yyval.tree)->type = Boolean;}
#line 2234 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2238 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 393 "parser.y" /* yacc.c:1906  */


/*
void yyerror (const char *msg)
{ 
   cout << "Error: " <<  msg << endl;
   //numErrors++; // should this be global or pass by reference?
}
*/

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
   //numErrors = 0;
   //numWarnings = 0;
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
   initErrorProcessing();
   
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
        
        if(globalMainFound == false) // error to check if a main function was defined
        {
            printf("LINKER ERROR: A function named 'main' with no parameters must be defined.\n");
            numErrors++;
        }   
   }
   //printf("Num errors before codegen: %d\n", numErrors);
   if(numErrors == 0){
        //printTree(stdout, syntaxTree, false, false); // set to true, true for assignment 4
        codegen(stdout, (char *)argv[1], syntaxTree, symtab, globalOffset, false);
   }
   printf("Number of warnings: %d\n", numWarnings);
   printf("Number of errors: %d\n", numErrors);
   return 0;
}

