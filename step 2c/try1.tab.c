
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "try1.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	#include<string.h>
	int cnt0=0,cnt1=0,cnt2=0,s=0,j,flag=0;
	extern int num;
	int len=0;
	struct abhishek
	{
		int line_number;
		char symbol_specification[20];
		int data_type;
		char value[40];
		int s;
		int sflag;
		int isarr;
	}symbol_table[100];

	int check_presence(char *id)
    {
        int i;
        for(i=1;i<=len;i++)
        {
            if(strcmp(id,symbol_table[i].symbol_specification)==0)
            return 0;
        }
        return 1;
    }


/* Line 189 of yacc.c  */
#line 105 "try1.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AUTO = 258,
     BREAK = 259,
     CASE = 260,
     CHAR = 261,
     CONST = 262,
     CONTINUE = 263,
     DEFAULT = 264,
     DO = 265,
     DOUBLE = 266,
     ELSE = 267,
     ENUM = 268,
     THREE_DOT = 269,
     EXTERN = 270,
     FLOAT = 271,
     FOR = 272,
     GOTO = 273,
     IF = 274,
     INT = 275,
     LONG = 276,
     REGISTER = 277,
     RETURN = 278,
     SHORT = 279,
     lenOF = 280,
     STATIC = 281,
     STRUCT = 282,
     SWITCH = 283,
     TYPEDEF = 284,
     UNION = 285,
     SIGNED = 286,
     UNSIGNED = 287,
     VOID = 288,
     VOLATILE = 289,
     WHILE = 290,
     DOT = 291,
     OPEN_SQ_BRACKET = 292,
     CLOSE_SQ_BRACKET = 293,
     OPEN_PARANTHESES = 294,
     CLOSE_PARANTHESES = 295,
     OPEN_BRACES = 296,
     CLOSE_BRACES = 297,
     COMMA = 298,
     COLON = 299,
     EQUALS = 300,
     SEMI_COLON = 301,
     HASH = 302,
     SIZEOF = 303,
     DOUBLE_QUOTES = 304,
     NOT = 305,
     NEGATION = 306,
     INCREMENT = 307,
     DECREMENT = 308,
     PLUS = 309,
     MINUS = 310,
     MULTIPLY = 311,
     AND_BIT = 312,
     DIVIDE = 313,
     MODULUS = 314,
     R_SHIFT = 315,
     L_SHIFT = 316,
     LESS_THAN = 317,
     LESS_EQUAL = 318,
     GREATER_THAN = 319,
     GREATER_EQUAL = 320,
     IS_EQUAL_TO = 321,
     NOT_EQUAL = 322,
     XOR = 323,
     OR_BIT = 324,
     AND = 325,
     OR = 326,
     TERNARY = 327,
     ADD_SHORT = 328,
     SUB_SHORT = 329,
     MUL_SHORT = 330,
     DIV_SHORT = 331,
     MOD_SHORT = 332,
     AND_SHORT = 333,
     XOR_SHORT = 334,
     OR_SHORT = 335,
     LSHIFT_SHORT = 336,
     RSHIFT_SHORT = 337,
     LINK = 338,
     IDENTIFIER = 339,
     NUMBER = 340,
     REAL_NUMBER = 341,
     EXP_NUMBER = 342,
     CHAR_CONSTANT = 343,
     STRING_CONSTANT = 344
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 37 "try1.y"

	   int type;
	   struct abhishek entry;
	  


/* Line 214 of yacc.c  */
#line 237 "try1.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 249 "try1.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1666

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNRULES -- Number of states.  */
#define YYNSTATES  375

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   344

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    17,    21,    25,
      28,    32,    35,    37,    40,    43,    45,    48,    50,    53,
      55,    57,    59,    61,    63,    65,    67,    69,    71,    73,
      75,    77,    79,    81,    83,    85,    87,    89,    91,    97,
     102,   105,   107,   109,   111,   114,   116,   120,   122,   126,
     130,   133,   135,   138,   140,   142,   146,   148,   152,   155,
     161,   166,   169,   171,   175,   177,   181,   184,   186,   188,
     192,   197,   201,   206,   211,   215,   218,   220,   224,   227,
     229,   232,   234,   238,   240,   244,   247,   250,   252,   254,
     258,   260,   264,   269,   271,   275,   278,   280,   282,   285,
     287,   291,   296,   300,   304,   307,   312,   316,   320,   323,
     325,   327,   329,   331,   333,   335,   339,   344,   348,   351,
     353,   358,   362,   366,   369,   371,   374,   380,   388,   394,
     400,   408,   418,   427,   436,   444,   453,   461,   469,   476,
     480,   483,   486,   490,   493,   495,   499,   501,   505,   507,
     509,   511,   513,   515,   517,   519,   521,   523,   525,   527,
     529,   535,   537,   539,   543,   545,   549,   551,   555,   557,
     561,   563,   567,   569,   573,   577,   579,   583,   587,   591,
     595,   597,   601,   605,   607,   611,   615,   617,   621,   625,
     629,   631,   636,   638,   641,   644,   647,   650,   655,   657,
     659,   661,   663,   665,   667,   669,   674,   679,   683,   687,
     691,   694,   697,   699,   701,   703,   707,   709,   713,   715,
     717,   719
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      91,     0,    -1,    92,    -1,    91,    92,    -1,    93,    -1,
      94,    -1,    96,   112,    95,   128,    -1,   112,    95,   128,
      -1,    96,   112,   128,    -1,   112,   128,    -1,    96,   103,
      46,    -1,    96,    46,    -1,    94,    -1,    95,    94,    -1,
      97,    96,    -1,    97,    -1,    98,    96,    -1,    98,    -1,
      99,    96,    -1,    99,    -1,     3,    -1,    22,    -1,    26,
      -1,    15,    -1,    29,    -1,    33,    -1,     6,    -1,    24,
      -1,    20,    -1,    21,    -1,    16,    -1,    11,    -1,    31,
      -1,    32,    -1,   100,    -1,   109,    -1,     7,    -1,    34,
      -1,   101,    84,    41,   102,    42,    -1,   101,    41,   102,
      42,    -1,   101,    84,    -1,    27,    -1,    30,    -1,   105,
      -1,   102,   105,    -1,   104,    -1,   103,    43,   104,    -1,
     112,    -1,   112,    45,   120,    -1,   106,   107,    46,    -1,
      98,   106,    -1,    98,    -1,    99,   106,    -1,    99,    -1,
     108,    -1,   107,    43,   108,    -1,   112,    -1,   112,    44,
     137,    -1,    44,   137,    -1,    13,    84,    41,   110,    42,
      -1,    13,    41,   110,    42,    -1,    13,    84,    -1,   111,
      -1,   110,    43,   111,    -1,    84,    -1,    84,    45,   137,
      -1,   114,   113,    -1,   113,    -1,    84,    -1,    39,   112,
      40,    -1,   113,    37,   137,    38,    -1,   113,    37,    38,
      -1,   113,    39,   116,    40,    -1,   113,    39,   119,    40,
      -1,   113,    39,    40,    -1,    56,   115,    -1,    56,    -1,
      56,   115,   114,    -1,    56,   114,    -1,    99,    -1,   115,
      99,    -1,   117,    -1,   117,    43,    14,    -1,   118,    -1,
     117,    43,   118,    -1,    96,   112,    -1,    96,   123,    -1,
      96,    -1,    84,    -1,   119,    43,    84,    -1,   134,    -1,
      41,   121,    42,    -1,    41,   121,    43,    42,    -1,   120,
      -1,   121,    43,   120,    -1,   106,   123,    -1,   106,    -1,
     114,    -1,   114,   124,    -1,   124,    -1,    39,   123,    40,
      -1,   124,    37,   137,    38,    -1,    37,   137,    38,    -1,
     124,    37,    38,    -1,    37,    38,    -1,   124,    39,   116,
      40,    -1,    39,   116,    40,    -1,   124,    39,    40,    -1,
      39,    40,    -1,   126,    -1,   127,    -1,   128,    -1,   130,
      -1,   131,    -1,   132,    -1,    84,    44,   125,    -1,     5,
     137,    44,   125,    -1,     9,    44,   125,    -1,   133,    46,
      -1,    46,    -1,    41,    95,   129,    42,    -1,    41,    95,
      42,    -1,    41,   129,    42,    -1,    41,    42,    -1,   125,
      -1,   129,   125,    -1,    19,    39,   133,    40,   125,    -1,
      19,    39,   133,    40,   125,    12,   125,    -1,    28,    39,
     133,    40,   125,    -1,    35,    39,   133,    40,   125,    -1,
      10,   125,    35,    39,   133,    40,    46,    -1,    17,    39,
     133,    46,   133,    46,   133,    40,   125,    -1,    17,    39,
     133,    46,   133,    46,    40,   125,    -1,    17,    39,   133,
      46,    46,   133,    40,   125,    -1,    17,    39,   133,    46,
      46,    40,   125,    -1,    17,    39,    46,   133,    46,   133,
      40,   125,    -1,    17,    39,    46,   133,    46,    40,   125,
      -1,    17,    39,    46,    46,   133,    40,   125,    -1,    17,
      39,    46,    46,    40,   125,    -1,    18,    84,    46,    -1,
       8,    46,    -1,     4,    46,    -1,    23,   133,    46,    -1,
      23,    46,    -1,   134,    -1,   133,    43,   134,    -1,   136,
      -1,   149,   135,   134,    -1,    45,    -1,    75,    -1,    76,
      -1,    77,    -1,    73,    -1,    74,    -1,    81,    -1,    82,
      -1,    78,    -1,    79,    -1,    80,    -1,   138,    -1,   138,
      72,   133,    44,   136,    -1,   136,    -1,   139,    -1,   138,
      71,   139,    -1,   140,    -1,   139,    70,   140,    -1,   141,
      -1,   140,    69,   141,    -1,   142,    -1,   141,    68,   142,
      -1,   143,    -1,   142,    57,   143,    -1,   144,    -1,   143,
      66,   144,    -1,   143,    67,   144,    -1,   145,    -1,   144,
      62,   145,    -1,   144,    64,   145,    -1,   144,    63,   145,
      -1,   144,    65,   145,    -1,   146,    -1,   145,    61,   146,
      -1,   145,    60,   146,    -1,   147,    -1,   146,    54,   147,
      -1,   146,    55,   147,    -1,   148,    -1,   147,    56,   148,
      -1,   147,    58,   148,    -1,   147,    59,   148,    -1,   149,
      -1,    39,   122,    40,   148,    -1,   151,    -1,    52,   149,
      -1,    53,   149,    -1,   150,   148,    -1,    25,   149,    -1,
      25,    39,   122,    40,    -1,    57,    -1,    56,    -1,    54,
      -1,    55,    -1,    51,    -1,    50,    -1,   152,    -1,   151,
      37,   133,    38,    -1,   151,    39,   153,    40,    -1,   151,
      39,    40,    -1,   151,    36,    84,    -1,   151,    83,    84,
      -1,   151,    52,    -1,   151,    53,    -1,    84,    -1,   154,
      -1,    89,    -1,    39,   133,    40,    -1,   134,    -1,   153,
      43,   134,    -1,    85,    -1,    88,    -1,    86,    -1,    87,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    46,    49,    50,    53,    54,    55,    56,
      59,    72,    75,    76,    79,    80,    81,    82,    83,    84,
      87,    88,    89,    90,    91,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   107,   108,   111,   112,
     113,   116,   117,   120,   121,   124,   125,   128,   129,   132,
     135,   136,   137,   138,   141,   142,   144,   145,   146,   149,
     150,   151,   154,   155,   158,   159,   162,   163,   166,   181,
     182,   183,   184,   185,   186,   189,   190,   191,   192,   195,
     196,   199,   200,   203,   204,   207,   208,   209,   212,   213,
     216,   217,   218,   221,   222,   225,   226,   229,   230,   231,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   246,
     247,   248,   249,   250,   251,   254,   255,   256,   259,   260,
     263,   264,   265,   266,   269,   270,   273,   274,   275,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   290,
     291,   292,   293,   294,   297,   298,   301,   302,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   318,
     319,   322,   325,   326,   329,   330,   333,   334,   337,   338,
     341,   342,   344,   345,   346,   349,   350,   351,   352,   353,
     356,   357,   358,   361,   362,   363,   366,   367,   368,   369,
     372,   373,   376,   377,   378,   379,   380,   381,   384,   385,
     386,   387,   388,   389,   392,   393,   394,   395,   396,   397,
     398,   399,   402,   410,   411,   413,   416,   417,   420,   422,
     424,   426
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "THREE_DOT",
  "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "INT", "LONG", "REGISTER",
  "RETURN", "SHORT", "lenOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF",
  "UNION", "SIGNED", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "DOT",
  "OPEN_SQ_BRACKET", "CLOSE_SQ_BRACKET", "OPEN_PARANTHESES",
  "CLOSE_PARANTHESES", "OPEN_BRACES", "CLOSE_BRACES", "COMMA", "COLON",
  "EQUALS", "SEMI_COLON", "HASH", "SIZEOF", "DOUBLE_QUOTES", "NOT",
  "NEGATION", "INCREMENT", "DECREMENT", "PLUS", "MINUS", "MULTIPLY",
  "AND_BIT", "DIVIDE", "MODULUS", "R_SHIFT", "L_SHIFT", "LESS_THAN",
  "LESS_EQUAL", "GREATER_THAN", "GREATER_EQUAL", "IS_EQUAL_TO",
  "NOT_EQUAL", "XOR", "OR_BIT", "AND", "OR", "TERNARY", "ADD_SHORT",
  "SUB_SHORT", "MUL_SHORT", "DIV_SHORT", "MOD_SHORT", "AND_SHORT",
  "XOR_SHORT", "OR_SHORT", "LSHIFT_SHORT", "RSHIFT_SHORT", "LINK",
  "IDENTIFIER", "NUMBER", "REAL_NUMBER", "EXP_NUMBER", "CHAR_CONSTANT",
  "STRING_CONSTANT", "$accept", "translation_unit", "external_declaration",
  "function_definition", "declaration", "declaration_list",
  "declaration_specifiers", "storage_class_specifier", "type_specifier",
  "type_qualifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "init_declarator_list", "init_declarator",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "declarator", "direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "initializer", "initializer_list", "type_symbol_specification",
  "abstract_declarator", "direct_abstract_declarator", "statement",
  "labeled_statement", "expression_statement", "compound_statement",
  "statement_list", "selection_statement", "iteration_statement",
  "jump_statement", "expression", "assignment_expression",
  "assignment_operator", "conditional_expression", "constant_expression",
  "logical_OR_expression", "logical_AND_expression",
  "inclusive_OR_expression", "exclusive_OR_expression", "AND_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "unary_operator", "postfix_expression",
  "primary_expression", "argument_expression_list", "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    92,    92,    93,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    99,    99,   100,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     106,   106,   106,   106,   107,   107,   108,   108,   108,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   113,   114,   114,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   118,   119,   119,
     120,   120,   120,   121,   121,   122,   122,   123,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   125,   125,   125,   126,   126,   126,   127,   127,
     128,   128,   128,   128,   129,   129,   130,   130,   130,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   132,
     132,   132,   132,   132,   133,   133,   134,   134,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   136,
     136,   137,   138,   138,   139,   139,   140,   140,   141,   141,
     142,   142,   143,   143,   143,   144,   144,   144,   144,   144,
     145,   145,   145,   146,   146,   146,   147,   147,   147,   147,
     148,   148,   149,   149,   149,   149,   149,   149,   150,   150,
     150,   150,   150,   150,   151,   151,   151,   151,   151,   151,
     151,   151,   152,   152,   152,   152,   153,   153,   154,   154,
     154,   154
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     4,     3,     3,     2,
       3,     2,     1,     2,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       2,     1,     1,     1,     2,     1,     3,     1,     3,     3,
       2,     1,     2,     1,     1,     3,     1,     3,     2,     5,
       4,     2,     1,     3,     1,     3,     2,     1,     1,     3,
       4,     3,     4,     4,     3,     2,     1,     3,     2,     1,
       2,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       1,     3,     4,     1,     3,     2,     1,     1,     2,     1,
       3,     4,     3,     3,     2,     4,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     1,
       4,     3,     3,     2,     1,     2,     5,     7,     5,     5,
       7,     9,     8,     8,     7,     8,     7,     7,     6,     3,
       2,     2,     3,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     4,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     3,     3,
       2,     2,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    26,    36,    31,     0,    23,    30,    28,    29,
      21,    27,    22,    41,    24,    42,    32,    33,    25,    37,
       0,    76,    68,     0,     2,     4,     5,     0,    15,    17,
      19,    34,     0,    35,     0,    67,     0,     0,    61,     0,
      79,    78,    75,     1,     3,    11,     0,    45,    47,    14,
      16,    18,     0,    40,     0,    12,     0,     0,     9,     0,
       0,    66,    64,     0,    62,     0,    69,    80,    77,     0,
      10,     0,     0,     8,    51,    53,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,   119,   203,   202,     0,     0,   200,
     201,   199,   198,   212,   218,   220,   221,   219,   214,     0,
     124,   109,   110,   111,     0,   112,   113,   114,     0,   144,
     146,   159,   162,   164,   166,   168,   170,   172,   175,   180,
     183,   186,   190,     0,   192,   204,   213,    13,     7,    47,
      71,   212,   161,     0,   190,    74,    88,    87,     0,    81,
      83,     0,     0,    60,     0,     0,    46,     0,    48,    90,
       6,    50,    52,    39,    44,     0,     0,    54,    56,     0,
     141,     0,   140,     0,     0,     0,     0,     0,   143,     0,
       0,   196,     0,     0,    96,     0,     0,     0,   193,   194,
       0,   121,     0,   122,   125,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   152,   153,   149,
     150,   151,   156,   157,   158,   154,   155,     0,   195,     0,
       0,     0,   210,   211,     0,    70,     0,     0,    85,    97,
      86,    99,    72,     0,    73,     0,    65,    63,    59,    93,
       0,    58,     0,    49,     0,    38,     0,   117,     0,     0,
       0,   139,     0,   142,     0,     0,     0,     0,    97,    95,
       0,   215,   115,   120,   145,   163,     0,   165,   167,   169,
     171,   173,   174,   176,   178,   177,   179,   182,   181,   184,
     185,   187,   188,   189,   147,   208,     0,   207,   216,     0,
     209,   104,     0,   108,     0,     0,    98,     0,     0,    82,
      84,    89,    91,     0,    55,    57,   116,     0,     0,     0,
       0,     0,   197,     0,     0,   191,     0,   205,   206,     0,
     102,   106,   100,   103,     0,   107,     0,    92,    94,     0,
       0,     0,     0,     0,     0,   126,   128,   129,   160,   217,
     101,   105,     0,   138,     0,     0,     0,     0,     0,     0,
       0,   130,   137,   136,     0,   134,     0,     0,     0,   127,
     135,   133,   132,     0,   131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    55,    56,    57,    28,    29,    30,
      31,    32,    76,    46,    47,    77,    78,   166,   167,    33,
      63,    64,    34,    35,    36,    42,   304,   149,   150,   151,
     158,   250,   185,   305,   241,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   227,   120,   143,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   299,   136
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -182
static const yytype_int16 yypact[] =
{
     798,  -182,  -182,  -182,  -182,   -22,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
     142,    10,  -182,   636,  -182,  -182,  -182,   132,  1603,  1603,
    1603,  -182,   -20,  -182,  1447,   110,   -30,   -66,    -3,     3,
    -182,  -182,    10,  -182,  -182,  -182,   -21,  -182,  1414,  -182,
    -182,  -182,  1632,    15,   294,  -182,  1447,   132,  -182,   846,
     835,   110,    18,    70,  -182,   -66,  -182,  -182,  -182,   142,
    -182,   903,  1447,  -182,  1632,  1632,  1509,  -182,    -7,  1632,
      24,  1224,    74,    38,   546,    62,    43,    98,   922,  1266,
     104,   112,   673,  -182,  -182,  -182,  -182,  1289,  1289,  -182,
    -182,  -182,  -182,   133,  -182,  -182,  -182,  -182,  -182,   381,
    -182,  -182,  -182,  -182,   436,  -182,  -182,  -182,    85,  -182,
    -182,   214,   121,   113,   128,   147,   221,    71,   231,   239,
      82,  -182,   285,  1224,    36,  -182,  -182,  -182,  -182,   164,
    -182,  -182,  -182,   179,  -182,  -182,  -182,    55,   173,   184,
    -182,   105,  1224,  -182,   -66,   253,  -182,   903,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  1224,   140,  -182,   187,  1539,
    -182,   207,  -182,   546,   220,   973,   218,  1224,  -182,   141,
     673,  -182,  1224,  1224,     9,   226,   150,  1224,  -182,  -182,
     546,  -182,   491,  -182,  -182,  1224,  -182,  1224,  1224,  1224,
    1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,
    1224,  1224,  1224,  1224,  1224,  1224,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  1224,  -182,   186,
    1224,   992,  -182,  -182,   192,  -182,  1013,   760,  -182,    16,
    -182,   217,  -182,  1571,  -182,   198,  -182,  -182,  -182,  -182,
     289,  -182,    -7,  -182,  1224,  -182,   546,  -182,   229,  1057,
     149,  -182,   163,  -182,   233,   165,   171,  1376,   224,  -182,
    1224,  -182,  -182,  -182,  -182,   121,   295,   113,   128,   147,
     221,    71,    71,   231,   231,   231,   231,   239,   239,    82,
      82,  -182,  -182,  -182,  -182,  -182,    33,  -182,  -182,   175,
    -182,  -182,   242,  -182,   249,   266,   217,  1066,  1479,  -182,
    -182,  -182,  -182,   838,  -182,  -182,  -182,  1224,  1108,   178,
    1131,   546,  -182,   546,   546,  -182,  1224,  -182,  -182,  1224,
    -182,  -182,  -182,  -182,   296,  -182,   297,  -182,  -182,   185,
     546,   189,  1150,  1173,   196,   331,  -182,  -182,  -182,  -182,
    -182,  -182,   308,  -182,   546,   546,   204,   546,   205,  1215,
     546,  -182,  -182,  -182,   546,  -182,   546,   546,   206,  -182,
    -182,  -182,  -182,   546,  -182
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,   334,  -182,    13,    20,     0,  -182,    50,     5,
    -182,  -182,   290,  -182,   299,   -65,   -59,  -182,   118,  -182,
     306,   219,   -17,   -29,   -15,  -182,   -55,  -182,   129,  -182,
    -143,  -182,   194,  -106,  -181,   -83,  -182,  -182,    11,   267,
    -182,  -182,  -182,   -84,   -51,  -182,   -57,   -42,  -182,   180,
     176,   193,   216,   222,   138,    -6,   143,   144,   -98,   -47,
    -182,  -182,  -182,  -182,  -182
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      27,   174,   142,    39,   179,   148,    41,    61,   186,    20,
      48,   164,   144,    26,   249,   161,   162,     3,    62,    37,
     159,    52,    69,    27,   142,    70,    40,    68,    49,    50,
      51,   194,    20,   184,   144,   228,    26,   165,    65,   171,
     139,   240,   181,    66,    19,    58,   236,    67,   267,    21,
     188,   189,   139,   236,    22,   237,    79,    75,   306,    73,
     147,   168,    38,   152,    53,    21,    21,   138,    72,   137,
     170,   327,   229,   230,   109,   231,   195,    22,   269,    75,
      75,    75,   173,   160,    75,   137,   144,   306,   232,   233,
     257,   260,   236,   262,   237,   142,   186,    75,   265,   266,
      22,   175,    74,   186,   164,   144,   159,   272,   142,   194,
     246,    21,   153,   154,   276,   291,   292,   293,   144,   234,
     172,   184,   137,   251,    74,    74,    74,   176,   195,    74,
     238,   196,   239,   205,   206,   207,   208,   177,   213,    22,
     214,   215,    74,   182,   274,   244,   296,    59,   245,    60,
     144,   183,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   268,
     338,    20,   325,   316,    75,   319,   294,   190,    45,   142,
     298,    20,   200,   252,   195,    75,   253,   263,    21,   144,
     271,   199,   195,   195,   302,   320,   201,   142,    21,   283,
     284,   285,   286,   321,   202,   323,   195,   144,   195,    71,
      61,   324,   315,   242,   195,   328,    22,   235,   329,    74,
      39,   195,   239,   144,   342,   352,    22,   243,   195,   354,
      74,   254,   195,   339,   341,   168,   344,   147,   345,   195,
     346,   347,   359,   147,   364,   366,   373,   195,   195,   195,
     142,   256,   268,   336,   307,   258,   308,   353,   356,   358,
     144,   236,   159,   267,   261,   334,   270,   147,   317,   348,
     295,   362,   363,   322,   365,   368,   300,   369,   349,   144,
     330,   370,   311,   371,   372,   197,   198,   203,   204,   331,
     374,   209,   210,   211,   212,   248,   154,     1,    80,    81,
       2,     3,    82,    83,    84,     4,   332,     5,   147,     6,
       7,    85,    86,    87,     8,     9,    10,    88,    11,    89,
      12,    13,    90,    14,    15,    16,    17,    18,    19,    91,
     216,   312,   313,    92,   350,    54,    93,   351,   195,   326,
      94,   281,   282,   360,    95,    96,    97,    98,    99,   100,
     101,   102,   287,   288,   361,   289,   290,    44,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   156,   169,
     314,   155,   310,   247,   264,   277,   192,   275,   103,   104,
     105,   106,   107,   108,     1,    80,    81,     2,     3,    82,
      83,    84,     4,   278,     5,     0,     6,     7,    85,    86,
      87,     8,     9,    10,    88,    11,    89,    12,    13,    90,
      14,    15,    16,    17,    18,    19,    91,   279,     0,     0,
      92,     0,    54,   191,   280,     0,     0,    94,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,     0,
      80,    81,     0,     0,    82,    83,    84,     0,     0,     0,
       0,     0,     0,    85,    86,    87,     0,     0,     0,    88,
       0,    89,     0,     0,    90,   103,   104,   105,   106,   107,
     108,    91,     0,     0,     0,    92,     0,    54,   193,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,     0,    80,    81,     0,     0,    82,
      83,    84,     0,     0,     0,     0,     0,     0,    85,    86,
      87,     0,     0,     0,    88,     0,    89,     0,     0,    90,
     103,   104,   105,   106,   107,   108,    91,     0,     0,     0,
      92,     0,    54,   273,     0,     0,     0,    94,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,     0,
      80,    81,     0,     0,    82,    83,    84,     0,     0,     0,
       0,     0,     0,    85,    86,    87,     0,     0,     0,    88,
       0,    89,     0,     0,    90,   103,   104,   105,   106,   107,
     108,    91,     0,     0,     0,    92,     0,    54,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,    43,     0,     0,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       0,     6,     7,     0,     0,     0,     8,     9,    10,     0,
      11,     0,    12,    13,     0,    14,    15,    16,    17,    18,
      19,     0,     0,     0,     0,    20,     0,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     0,     0,     7,
       0,     0,    21,     8,     9,     0,     0,    11,    89,     0,
      13,     0,     0,    15,    16,    17,    18,    19,     0,     0,
       0,     0,    92,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   104,   105,
     106,   107,   108,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     6,     7,     0,     0,     0,
       8,     9,    10,     0,    11,     0,    12,    13,     0,    14,
      15,    16,    17,    18,    19,     0,     0,   236,     0,   237,
     303,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     0,     6,     7,     0,    21,     0,     8,     9,
      10,     0,    11,     0,    12,    13,     0,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,    20,     1,     0,
       0,     2,     3,     0,    22,     0,     4,     0,     5,     0,
       6,     7,     0,     0,    21,     8,     9,    10,     0,    11,
       0,    12,    13,    89,    14,    15,    16,    17,    18,    19,
       0,    89,     0,     0,     0,   145,     0,    92,     0,   157,
     337,     0,    22,     0,   140,    92,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
       0,     0,   141,   104,   105,   106,   107,   108,    89,     0,
     141,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,    92,     0,   157,     0,     0,    89,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,   101,
     102,    92,     0,     0,     0,     0,     0,     0,   178,     0,
       0,     0,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,   141,   104,   105,
     106,   107,   108,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,   141,   104,   105,   106,
     107,   108,    92,     0,     0,     0,     0,    89,     0,   259,
       0,     0,     0,    95,    96,    97,    98,    99,   100,   101,
     102,    92,   297,     0,     0,     0,     0,     0,    89,     0,
       0,     0,    95,    96,    97,    98,    99,   100,   101,   102,
       0,   301,    92,     0,     0,     0,     0,   141,   104,   105,
     106,   107,   108,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,   141,   104,   105,   106,
     107,   108,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,    92,   141,   104,   105,
     106,   107,   108,   318,   333,    92,     0,    95,    96,    97,
      98,    99,   100,   101,   102,     0,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,   141,   104,   105,   106,   107,   108,    92,   340,     0,
     141,   104,   105,   106,   107,   108,    89,     0,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,     0,
      92,     0,     0,     0,     0,    89,     0,   343,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,    92,
     355,     0,   141,   104,   105,   106,   107,   108,    89,     0,
      95,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,    92,   357,     0,   141,   104,   105,   106,   107,
     108,     0,     0,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   141,   104,   105,   106,   107,   108,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,    92,   367,     0,   141,   104,   105,
     106,   107,   108,    92,     0,    95,    96,    97,    98,    99,
     100,   101,   102,     0,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,   141,
     104,   105,   106,   107,   108,   180,     0,     0,   141,   104,
     105,   106,   107,   108,    89,     0,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     141,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   104,   105,   106,   107,   108,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       0,     6,     7,     0,     0,     0,     8,     9,    10,     0,
      11,     0,    12,    13,     0,    14,    15,    16,    17,    18,
      19,     0,     0,   236,     0,   267,   303,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,     0,     6,
       7,     0,    21,     0,     8,     9,    10,     0,    11,     0,
      12,    13,     0,    14,    15,    16,    17,    18,    19,     0,
       1,     0,     0,     2,     3,    54,     0,     0,     4,    71,
       5,     0,     6,     7,     0,     0,     0,     8,     9,    10,
       0,    11,     0,    12,    13,     0,    14,    15,    16,    17,
      18,    19,     1,     0,     0,     2,     3,     0,    54,     0,
       4,     0,     5,     0,     6,     7,     0,     0,     0,     8,
       9,    10,     0,    11,     0,    12,    13,     0,    14,    15,
      16,    17,    18,    19,     0,     2,     3,     0,     0,   335,
       4,     0,     5,     0,     0,     7,     0,     0,     0,     8,
       9,     0,     0,    11,     0,     0,    13,     0,     0,    15,
      16,    17,    18,    19,     0,     2,     3,     0,     0,     0,
       4,   163,     5,     0,     0,     7,     0,     0,     0,     8,
       9,     0,     0,    11,     0,     0,    13,     0,     0,    15,
      16,    17,    18,    19,     1,     0,     0,     2,     3,     0,
       0,   255,     4,     0,     5,   309,     6,     7,     0,     0,
       0,     8,     9,    10,     0,    11,     0,    12,    13,     0,
      14,    15,    16,    17,    18,    19,     1,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     0,     6,     7,
       0,     0,     0,     8,     9,    10,     0,    11,     0,    12,
      13,     0,    14,    15,    16,    17,    18,    19,     2,     3,
       0,     0,     0,     4,     0,     5,     0,     0,     7,     0,
       0,     0,     8,     9,     0,     0,    11,     0,     0,    13,
       0,     0,    15,    16,    17,    18,    19
};

static const yytype_int16 yycheck[] =
{
       0,    84,    59,    20,    88,    60,    21,    36,    92,    39,
      27,    76,    59,     0,   157,    74,    75,     7,    84,    41,
      71,    41,    43,    23,    81,    46,    21,    42,    28,    29,
      30,   114,    39,    92,    81,   133,    23,    44,    41,    81,
      57,   147,    89,    40,    34,    34,    37,    42,    39,    56,
      97,    98,    69,    37,    84,    39,    41,    52,   239,    48,
      60,    78,    84,    45,    84,    56,    56,    56,    48,    56,
      46,    38,    36,    37,    54,    39,    43,    84,   184,    74,
      75,    76,    44,    72,    79,    72,   133,   268,    52,    53,
     173,   175,    37,   177,    39,   152,   180,    92,   182,   183,
      84,    39,    52,   187,   169,   152,   157,   190,   165,   192,
     152,    56,    42,    43,   198,   213,   214,   215,   165,    83,
      46,   180,   109,   165,    74,    75,    76,    84,    43,    79,
     147,    46,   147,    62,    63,    64,    65,    39,    56,    84,
      58,    59,    92,    39,   195,    40,   230,    37,    43,    39,
     197,    39,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   184,
     313,    39,   270,   256,   169,   259,   227,    44,    46,   236,
     231,    39,    69,    43,    43,   180,    46,    46,    56,   236,
      40,    70,    43,    43,   236,    46,    68,   254,    56,   205,
     206,   207,   208,    40,    57,    40,    43,   254,    43,    45,
     239,    40,   254,    40,    43,    40,    84,    38,    43,   169,
     237,    43,   237,   270,    46,    40,    84,    43,    43,    40,
     180,    44,    43,   317,   318,   252,   320,   237,   321,    43,
     323,   324,    46,   243,    40,    40,    40,    43,    43,    43,
     307,    44,   267,   308,    37,    35,    39,   340,   342,   343,
     307,    37,   313,    39,    46,   307,    40,   267,    39,   326,
      84,   354,   355,    40,   357,   359,    84,   360,   329,   326,
      38,   364,    84,   366,   367,    71,    72,    66,    67,    40,
     373,    60,    61,    54,    55,    42,    43,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    40,    13,   308,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      45,    42,    43,    39,    38,    41,    42,    40,    43,    44,
      46,   203,   204,    12,    50,    51,    52,    53,    54,    55,
      56,    57,   209,   210,    46,   211,   212,    23,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    69,    79,
     252,    65,   243,   154,   180,   199,   109,   197,    84,    85,
      86,    87,    88,    89,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   200,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   201,    -1,    -1,
      39,    -1,    41,    42,   202,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
       4,     5,    -1,    -1,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,    23,
      -1,    25,    -1,    -1,    28,    84,    85,    86,    87,    88,
      89,    35,    -1,    -1,    -1,    39,    -1,    41,    42,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,     4,     5,    -1,    -1,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    -1,    -1,    -1,    23,    -1,    25,    -1,    -1,    28,
      84,    85,    86,    87,    88,    89,    35,    -1,    -1,    -1,
      39,    -1,    41,    42,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
       4,     5,    -1,    -1,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,    23,
      -1,    25,    -1,    -1,    28,    84,    85,    86,    87,    88,
      89,    35,    -1,    -1,    -1,    39,    -1,    41,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,     0,    -1,    -1,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      -1,    15,    16,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    -1,    -1,    16,
      -1,    -1,    56,    20,    21,    -1,    -1,    24,    25,    -1,
      27,    -1,    -1,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    -1,    15,    16,    -1,    -1,    -1,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    -1,    -1,    37,    -1,    39,
      40,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    -1,    15,    16,    -1,    56,    -1,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,     3,    -1,
      -1,     6,     7,    -1,    84,    -1,    11,    -1,    13,    -1,
      15,    16,    -1,    -1,    56,    20,    21,    22,    -1,    24,
      -1,    26,    27,    25,    29,    30,    31,    32,    33,    34,
      -1,    25,    -1,    -1,    -1,    40,    -1,    39,    -1,    41,
      42,    -1,    84,    -1,    38,    39,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    84,    85,    86,    87,    88,    89,    25,    -1,
      84,    85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    41,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    39,    -1,    -1,    -1,    -1,    25,    -1,    46,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    39,    40,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    38,    39,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    39,    84,    85,    86,
      87,    88,    89,    46,    38,    39,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    39,    40,    -1,
      84,    85,    86,    87,    88,    89,    25,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    25,    -1,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    39,
      40,    -1,    84,    85,    86,    87,    88,    89,    25,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    39,    40,    -1,    84,    85,    86,    87,    88,
      89,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    39,    40,    -1,    84,    85,    86,
      87,    88,    89,    39,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    39,    -1,    -1,    84,    85,
      86,    87,    88,    89,    25,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      -1,    15,    16,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    37,    -1,    39,    40,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    -1,    15,
      16,    -1,    56,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    -1,
       3,    -1,    -1,     6,     7,    41,    -1,    -1,    11,    45,
      13,    -1,    15,    16,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,     3,    -1,    -1,     6,     7,    -1,    41,    -1,
      11,    -1,    13,    -1,    15,    16,    -1,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    -1,     6,     7,    -1,    -1,    40,
      11,    -1,    13,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    -1,    -1,    24,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    33,    34,    -1,     6,     7,    -1,    -1,    -1,
      11,    42,    13,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    -1,    -1,    24,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    33,    34,     3,    -1,    -1,     6,     7,    -1,
      -1,    42,    11,    -1,    13,    14,    15,    16,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,     3,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    -1,    15,    16,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,    27,
      -1,    -1,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    15,    16,    20,    21,
      22,    24,    26,    27,    29,    30,    31,    32,    33,    34,
      39,    56,    84,    91,    92,    93,    94,    96,    97,    98,
      99,   100,   101,   109,   112,   113,   114,    41,    84,   112,
      99,   114,   115,     0,    92,    46,   103,   104,   112,    96,
      96,    96,    41,    84,    41,    94,    95,    96,   128,    37,
      39,   113,    84,   110,   111,    41,    40,    99,   114,    43,
      46,    45,    95,   128,    98,    99,   102,   105,   106,    41,
       4,     5,     8,     9,    10,    17,    18,    19,    23,    25,
      28,    35,    39,    42,    46,    50,    51,    52,    53,    54,
      55,    56,    57,    84,    85,    86,    87,    88,    89,    95,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     136,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   154,    94,   128,   112,
      38,    84,   136,   137,   149,    40,    84,    96,   116,   117,
     118,   119,    45,    42,    43,   110,   104,    41,   120,   134,
     128,   106,   106,    42,   105,    44,   107,   108,   112,   102,
      46,   137,    46,    44,   125,    39,    84,    39,    46,   133,
      39,   149,    39,    39,   106,   122,   133,    39,   149,   149,
      44,    42,   129,    42,   125,    43,    46,    71,    72,    70,
      69,    68,    57,    66,    67,    62,    63,    64,    65,    60,
      61,    54,    55,    56,    58,    59,    45,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   135,   148,    36,
      37,    39,    52,    53,    83,    38,    37,    39,   112,   114,
     123,   124,    40,    43,    40,    43,   137,   111,    42,   120,
     121,   137,    43,    46,    44,    42,    44,   125,    35,    46,
     133,    46,   133,    46,   122,   133,   133,    39,   114,   123,
      40,    40,   125,    42,   134,   139,   133,   140,   141,   142,
     143,   144,   144,   145,   145,   145,   145,   146,   146,   147,
     147,   148,   148,   148,   134,    84,   133,    40,   134,   153,
      84,    38,   137,    40,   116,   123,   124,    37,    39,    14,
     118,    84,    42,    43,   108,   137,   125,    39,    46,   133,
      46,    40,    40,    40,    40,   148,    44,    38,    40,    43,
      38,    40,    40,    38,   137,    40,   116,    42,   120,   133,
      40,   133,    46,    46,   133,   125,   125,   125,   136,   134,
      38,    40,    40,   125,    40,    40,   133,    40,   133,    46,
      12,    46,   125,   125,    40,   125,    40,    40,   133,   125,
     125,   125,   125,    40,   125
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 45 "try1.y"
    {printf("\tReduced : translation_unit -> external_declaration\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 46 "try1.y"
    {printf("\tReduced : translation_unit -> translation_unit external_declaration\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 49 "try1.y"
    {printf("\tReduced : external_declaration -> function_definition\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 50 "try1.y"
    {printf("\tReduced : external_declaration -> declaration\n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 53 "try1.y"
    {printf("\tReduced : function_definition -> declaration_specifiers declarator declaration_list compound_statement\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 54 "try1.y"
    {printf("\tReduced : function_definition -> declarator declaration_list compound_statement\n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 55 "try1.y"
    {printf("\tReduced : function_definition -> declaration_specifiers declarator compound_statement\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 56 "try1.y"
    {printf("\tReduced : function_definition -> declarator compound_statement\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 59 "try1.y"
    {flag=0;printf("\tReduced : declaration -> declaration_specifiers init_declarator_list SEMI_COLON\n");s=cnt2*100+cnt1*10+cnt0;
																	if((s==4)||(s==-20)||(s==10)||(s==-2)||(s==-10)||(s==100)||(s==102)||(s==8)||(s==2)||(s==1)||(s==-9)||(s==-19)||(s==11)||(s==101)||(s==110)||(s==90)||(s==80)||(s==91)||(s==81)||(s==111))
																	{cnt0=cnt1=cnt2=0;
																	for(j=len;j>0;j--)
																	{
																		if(symbol_table[j].data_type!=-1)
																			break;
																		else
																			symbol_table[j].data_type=s;
																	}
																	}
																	else
																	yyerror();;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 72 "try1.y"
    {printf("\tReduced : declaration -> declaration_specifiers SEMI_COLON\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 75 "try1.y"
    {printf("\tReduced : declaration_list -> declaration\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 76 "try1.y"
    {printf("\tReduced : declaration_list -> declaration_list declaration\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 79 "try1.y"
    {printf("\tReduced : declaration_specifiers -> storage_class_specifier declaration_specifiers\n");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 80 "try1.y"
    {printf("\tReduced : declaration_specifiers -> storage_class_specifier\n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 81 "try1.y"
    {printf("\tReduced : declaration_specifiers -> type_specifier declaration_specifiers\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 82 "try1.y"
    {printf("\tReduced : declaration_specifiers -> type_specifier\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 83 "try1.y"
    {printf("\tReduced : declaration_specifiers -> type_qualifier declaration_specifiers\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 84 "try1.y"
    {printf("\tReduced : declaration_specifiers -> type_qualifier\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 87 "try1.y"
    {printf("\tReduced : storage_class_specifier -> AUTO\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 88 "try1.y"
    {printf("\tReduced : storage_class_specifier -> REGISTER\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 89 "try1.y"
    {printf("\tReduced : storage_class_specifier -> STATIC\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 90 "try1.y"
    {printf("\tReduced : storage_class_specifier -> EXTERN\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 91 "try1.y"
    {printf("\tReduced : storage_class_specifier -> TYPEDEF\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 94 "try1.y"
    {printf("\tReduced : type_specifier -> VOID\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 95 "try1.y"
    {printf("\tReduced : type_specifier -> CHAR\n");if(cnt0==0) cnt0+=2; else yyerror();;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 96 "try1.y"
    {printf("\tReduced : type_specifier -> SHORT\n");if(cnt1==0) cnt1++; else yyerror();;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 97 "try1.y"
    {printf("\tReduced : type_specifier -> INT\n");if(cnt0==0) cnt0++; else yyerror();;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 98 "try1.y"
    {printf("\tReduced : type_specifier -> LONG\n");if(cnt1==0 || cnt1==-1) cnt1--; else yyerror();;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 99 "try1.y"
    {printf("\tReduced : type_specifier -> FLOAT\n");if(cnt0==0) cnt0+=4; else yyerror();;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 100 "try1.y"
    {printf("\tReduced : type_specifier -> DOUBLE\n");if(cnt0==0) cnt0+=8; else yyerror();;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 101 "try1.y"
    {printf("\tReduced : type_specifier -> SIGNED\n");if(cnt2==0) cnt2++; else yyerror();;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 102 "try1.y"
    {printf("\tReduced : type_specifier -> UNSIGNED\n");if(cnt2==0) cnt2++; else yyerror();;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 103 "try1.y"
    {printf("\tReduced : type_specifier -> struct_or_union_specifier\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 104 "try1.y"
    {printf("\tReduced : type_specifier -> enum_specifier\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 107 "try1.y"
    {printf("\tReduced : type_qualifier -> CONST\n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 108 "try1.y"
    {printf("\tReduced : type_qualifier -> VOLATILE\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 111 "try1.y"
    {printf("\tReduced : struct_or_union_specifier -> struct_or_union IDENTIFIER OPEN_BRACES struct_declaration_list CLOSE_BRACES\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 112 "try1.y"
    {printf("\tReduced : struct_or_union_specifier -> struct_or_union OPEN_BRACES struct_declaration_list CLOSE_BRACES\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 113 "try1.y"
    {printf("\tReduced : struct_or_union_specifier -> struct_or_union IDENTIFIER\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 116 "try1.y"
    {printf("\tReduced : struct_or_union -> STRUCT\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 117 "try1.y"
    {printf("\tReduced : struct_or_union -> UNION\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 120 "try1.y"
    {printf("\tReduced : struct_declaration_list -> struct_declaration\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 121 "try1.y"
    {printf("\tReduced : struct_declaration_list -> struct_declaration_list struct_declaration\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 124 "try1.y"
    {printf("\tReduced : init_declarator_list -> init_declarator\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 125 "try1.y"
    {printf("\tReduced : init_declarator_list -> init_declarator_list COMMA init_declarator\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 128 "try1.y"
    {printf("\tReduced : init_declarator -> declarator\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 129 "try1.y"
    {printf("\tReduced : init_declarator -> declarator EQUALS initializer\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 132 "try1.y"
    {printf("\tReduced : struct_declaration -> specifier_qualifier_list struct_declarator_list SEMI_COLON\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 135 "try1.y"
    {printf("\tReduced : specifier_qualifier_list -> type_specifier specifier_qualifier_list\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 136 "try1.y"
    {printf("\tReduced : specifier_qualifier_list -> type_specifier\n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 137 "try1.y"
    {printf("\tReduced : specifier_qualifier_list -> type_qualifier specifier_qualifier_list\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 138 "try1.y"
    {printf("\tReduced : specifier_qualifier_list -> type_qualifier\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 141 "try1.y"
    {printf("\tReduced : struct_declarator_list -> struct_declarator\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 142 "try1.y"
    {printf("\tReduced : struct_declarator_list -> struct_declarator_list COMMA struct_declarator\n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 144 "try1.y"
    {printf("\tReduced : struct_declarator -> declarator\n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 145 "try1.y"
    {printf("\tReduced : struct_declarator -> declarator COLON constant_expression\n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 146 "try1.y"
    {printf("\tReduced : struct_declarator -> COLON constant_expression\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 149 "try1.y"
    {printf("\tReduced : enum_specifier -> ENUM IDENTIFIER OPEN_BRACES enumerator_list CLOSE_BRACES\n");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 150 "try1.y"
    {printf("\tReduced : enum_specifier -> ENUM OPEN_BRACES enumerator_list CLOSE_BRACES\n");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 151 "try1.y"
    {printf("\tReduced : enum_specifier -> ENUM IDENTIFIER\n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 154 "try1.y"
    {printf("\tReduced : enumerator_list -> enumerator\n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 155 "try1.y"
    {printf("\tReduced : enumerator_list -> enumerator_list COMMA enumerator\n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 158 "try1.y"
    {printf("\tReduced : enumerator -> IDENTIFIER\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 159 "try1.y"
    {printf("\tReduced : enumerator -> IDENTIFIER EQUALS constant_expression\n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 162 "try1.y"
    {printf("\tReduced : declarator -> pointer direct_declarator\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 163 "try1.y"
    {printf("\tReduced : declarator -> direct_declarator\n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 166 "try1.y"
    {flag=1;printf("\tReduced : direct_declarator -> IDENTIFIER\n");if(check_presence((yyvsp[(1) - (1)].entry).symbol_specification))
																						{
																							len++;
																							strcpy(symbol_table[len].symbol_specification,(yyvsp[(1) - (1)].entry).symbol_specification);
																							symbol_table[len].line_number=num;
																							symbol_table[len].data_type=-1;
																							symbol_table[len].sflag=0;
																							symbol_table[len].isarr=0;
																						}
																						else
																						{
																							printf("Already declared %s\n",(yyvsp[(1) - (1)].entry).symbol_specification);
																							yyerror();
																						}
							 ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 181 "try1.y"
    {printf("\tReduced : direct_declarator -> OPEN_PARANTHESES declarator CLOSE_PARANTHESES\n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 182 "try1.y"
    {printf("\tReduced : direct_declarator -> direct_declarator OPEN_SQ_BRACKET constant_expression CLOSE_SQ_BRACKET\n");symbol_table[len].sflag=1;symbol_table[len].isarr=1;;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 183 "try1.y"
    {printf("\tReduced : direct_declarator -> direct_declarator OPEN_SQ_BRACKET CLOSE_SQ_BRACKET\n");symbol_table[len].isarr=1;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 184 "try1.y"
    {printf("\tReduced : direct_declarator -> direct_declarator OPEN_PARANTHESES parameter_type_list CLOSE_PARANTHESES\n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 185 "try1.y"
    {printf("\tReduced : direct_declarator -> direct_declarator OPEN_PARANTHESES identifier_list CLOSE_PARANTHESES\n");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 186 "try1.y"
    {printf("\tReduced : direct_declarator -> direct_declarator OPEN_PARANTHESES CLOSE_PARANTHESES\n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 189 "try1.y"
    {printf("\tReduced : pointer -> MULTIPLY type_qualifier_list\n");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 190 "try1.y"
    {printf("\tReduced : pointer -> MULTIPLY\n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 191 "try1.y"
    {printf("\tReduced : pointer -> MULTIPLY type_qualifier_list pointer\n");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 192 "try1.y"
    {printf("\tReduced : pointer -> MULTIPLY pointer\n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 195 "try1.y"
    {printf("\tReduced : type_qualifier_list -> type_qualifier\n");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 196 "try1.y"
    {printf("\tReduced : type_qualifier_list -> type_qualifier_list type_qualifier\n");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 199 "try1.y"
    {printf("\tReduced : parameter_type_list -> parameter_list\n");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 200 "try1.y"
    {printf("\tReduced : parameter_type_list -> parameter_list COMMA THREE_DOT\n");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 203 "try1.y"
    {printf("\tReduced : parameter_list -> parameter_declaration\n");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 204 "try1.y"
    {printf("\tReduced : parameter_list -> parameter_list COMMA parameter_declaration\n");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 207 "try1.y"
    {printf("\tReduced : parameter_declaration -> declaration_specifiers declarator\n");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 208 "try1.y"
    {printf("\tReduced : parameter_declaration -> declaration_specifiers abstract_declarator\n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 209 "try1.y"
    {printf("\tReduced : parameter_declaration -> declaration_specifiers\n");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 212 "try1.y"
    {printf("\tReduced : identifier_list -> IDENTIFIER\n");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 213 "try1.y"
    {printf("\tReduced : identifier_list -> identifier_list COMMA IDENTIFIER\n");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 216 "try1.y"
    {printf("\tReduced : initializer -> assignment_expression\n");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 217 "try1.y"
    {printf("\tReduced : initializer -> OPEN_BRACES initializer_list CLOSE_BRACES\n");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 218 "try1.y"
    {printf("\tReduced : initializer -> OPEN_BRACES initializer_list COMMA CLOSE_BRACES\n");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 221 "try1.y"
    {printf("\tReduced : initializer_list -> initializer\n");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 222 "try1.y"
    {printf("\tReduced : initializer_list -> initializer_list COMMA initializer\n");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 225 "try1.y"
    {printf("\tReduced : type_symbol_specification -> specifier_qualifier_list abstract_declarator\n");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 226 "try1.y"
    {printf("\tReduced : type_symbol_specification -> specifier_qualifier_list\n");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 229 "try1.y"
    {printf("\tReduced : abstract_declarator ->  pointer\n");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 230 "try1.y"
    {printf("\tReduced : abstract_declarator ->  pointer direct_abstract_declarator\n");;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 231 "try1.y"
    {printf("\tReduced : abstract_declarator -> direct_abstract_declarator\n");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 234 "try1.y"
    {printf("\tReduced : direct_abstract_declarator -> OPEN_PARANTHESES abstract_declarator CLOSE_PARANTHESES\n");;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 235 "try1.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator OPEN_SQ_BRACKET constant_expression CLOSE_SQ_BRACKET\n");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 236 "try1.y"
    {printf("\tReduced : direct_abstract_declarator -> OPEN_SQ_BRACKET constant_expression CLOSE_SQ_BRACKET\n");;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 237 "try1.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator OPEN_SQ_BRACKET CLOSE_SQ_BRACKET\n");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 238 "try1.y"
    {printf("\tReduced : direct_abstract_declarator -> OPEN_SQ_BRACKET CLOSE_SQ_BRACKET\n");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 239 "try1.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator OPEN_PARANTHESES parameter_type_list CLOSE_PARANTHESES\n");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 240 "try1.y"
    {printf("\tReduced : direct_abstract_declarator -> OPEN_PARANTHESES parameter_type_list CLOSE_PARANTHESES\n");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 241 "try1.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator OPEN_PARANTHESES CLOSE_PARANTHESES\n");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 242 "try1.y"
    {printf("\tReduced : direct_abstract_declarator -> OPEN_PARANTHESES CLOSE_PARANTHESES\n");;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 246 "try1.y"
    {printf("\tReduced : statement -> labeled_statement\n");;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 247 "try1.y"
    {printf("\tReduced : statement -> expression_statement\n");;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 248 "try1.y"
    {printf("\tReduced : statement -> compound_statement\n");;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 249 "try1.y"
    {printf("\tReduced : statement -> selection_statement\n");;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 250 "try1.y"
    {printf("\tReduced : statement -> iteration_statement\n");;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 251 "try1.y"
    {printf("\tReduced : statement -> jump_statement\n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 254 "try1.y"
    {printf("\tReduced : labeled_statement -> IDENTIFIER COLON statement\n");;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 255 "try1.y"
    {printf("\tReduced : labeled_statement -> CASE constant_expression COLON statement\n");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 256 "try1.y"
    {printf("\tReduced : labeled_statement -> DEFAULT COLON statement\n");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 259 "try1.y"
    {printf("\tReduced : expression_statement -> expression SEMI_COLON\n");;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 260 "try1.y"
    {printf("\tReduced : expression_statement -> SEMI_COLON\n");;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 263 "try1.y"
    {printf("\tReduced : compound_statement -> OPEN_BRACES declaration_list statement_list CLOSE_BRACES\n");;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 264 "try1.y"
    {printf("\tReduced : compound_statement -> OPEN_BRACES declaration_list CLOSE_BRACES\n");;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 265 "try1.y"
    {printf("\tReduced : compound_statement -> OPEN_BRACES statement_list CLOSE_BRACES\n");;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 266 "try1.y"
    {printf("\tReduced : compound_statement -> OPEN_BRACES CLOSE_BRACES\n");;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 269 "try1.y"
    {printf("\tReduced : statement_list -> statement\n");;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 270 "try1.y"
    {printf("\tReduced : statement_list -> statement_list statement\n");;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 273 "try1.y"
    {printf("\tReduced : selection_statement -> IF OPEN_PARANTHESES expression CLOSE_PARANTHESES statement\n");;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 274 "try1.y"
    {printf("\tReduced : selection_statement -> IF OPEN_PARANTHESES expression CLOSE_PARANTHESES statement ELSE statement\n");;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 275 "try1.y"
    {printf("\tReduced : selection_statement -> SWITCH OPEN_PARANTHESES expression CLOSE_PARANTHESES statement\n");;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 278 "try1.y"
    {printf("\tReduced : iteration_statement -> WHILE OPEN_PARANTHESES expression CLOSE_PARANTHESES statement\n");;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 279 "try1.y"
    {printf("\tReduced : iteration_statement -> DO statement WHILE OPEN_PARANTHESES expression CLOSE_PARANTHESES SEMI_COLON\n");;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 280 "try1.y"
    {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES expression SEMI_COLON expression SEMI_COLON expression CLOSE_PARANTHESES statement\n");;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 281 "try1.y"
    {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES expression SEMI_COLON expression SEMI_COLON CLOSE_PARANTHESES statement\n");;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 282 "try1.y"
    {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES expression SEMI_COLON SEMI_COLON expression CLOSE_PARANTHESES statement\n");;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 283 "try1.y"
    {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES expression SEMI_COLON SEMI_COLON CLOSE_PARANTHESES statement\n");;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 284 "try1.y"
    {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES SEMI_COLON expression SEMI_COLON expression CLOSE_PARANTHESES statement\n");;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 285 "try1.y"
    {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES SEMI_COLON expression SEMI_COLON CLOSE_PARANTHESES statement\n");;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 286 "try1.y"
    {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES SEMI_COLON SEMI_COLON expression CLOSE_PARANTHESES statement\n");;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 287 "try1.y"
    {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES SEMI_COLON SEMI_COLON CLOSE_PARANTHESES statement\n");;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 290 "try1.y"
    {printf("\tReduced : jump_statement -> GOTO IDENTIFIER SEMI_COLON\n");;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 291 "try1.y"
    {printf("\tReduced : jump_statement -> CONTINUE SEMI_COLON\n");;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 292 "try1.y"
    {printf("\tReduced : jump_statement -> BREAK SEMI_COLON\n");;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 293 "try1.y"
    {printf("\tReduced : jump_statement -> RETURN expression SEMI_COLON\n");;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 294 "try1.y"
    {printf("\tReduced : jump_statement -> RETURN SEMI_COLON\n");;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 297 "try1.y"
    {printf("\tReduced : expression -> assignment_expression\n");;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 298 "try1.y"
    {printf("\tReduced : expression -> expression COMMA assignment_expression\n");;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 301 "try1.y"
    {printf("\tReduced : assignment_expression -> conditional_expression\n");;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 302 "try1.y"
    {printf("\tReduced : assignment_expression -> unary_expression assignment_operator assignment_expression\n");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 305 "try1.y"
    {printf("\tReduced : assignment_operator -> EQUALS\n");;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 306 "try1.y"
    {printf("\tReduced : assignment_operator -> MUL_SHORT\n");;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 307 "try1.y"
    {printf("\tReduced : assignment_operator -> DIV_SHORT\n");;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 308 "try1.y"
    {printf("\tReduced : assignment_operator -> MOD_SHORT\n");;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 309 "try1.y"
    {printf("\tReduced : assignment_operator -> ADD_SHORT\n");;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 310 "try1.y"
    {printf("\tReduced : assignment_operator -> SUB_SHORT\n");;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 311 "try1.y"
    {printf("\tReduced : assignment_operator -> LSHIFT_SHORT\n");;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 312 "try1.y"
    {printf("\tReduced : assignment_operator -> RSHIFT_SHORT\n");;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 313 "try1.y"
    {printf("\tReduced : assignment_operator -> AND_SHORT\n");;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 314 "try1.y"
    {printf("\tReduced : assignment_operator -> XOR_SHORT\n");;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 315 "try1.y"
    {printf("\tReduced : assignment_operator -> OR_SHORT\n");;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 318 "try1.y"
    {printf("\tReduced : conditional_expression -> logical_OR_expression\n");;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 319 "try1.y"
    {printf("\tReduced : conditional_expression -> logical_OR_expression TERNARY expression COLON conditional_expression\n");;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 322 "try1.y"
    {printf("\tReduced : constant_expression -> conditional_expression\n");;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 325 "try1.y"
    {printf("\tReduced : logical_OR_expression -> logical_AND_expression\n");;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 326 "try1.y"
    {printf("\tReduced : logical_OR_expression -> logical_OR_expression OR logical_AND_expression\n");;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 329 "try1.y"
    {printf("\tReduced : logical_AND_expression -> inclusive_OR_expression\n");;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 330 "try1.y"
    {printf("\tReduced : logical_AND_expression -> logical_AND_expression AND inclusive_OR_expression\n");;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 333 "try1.y"
    {printf("\tReduced : inclusive_OR_expression -> exclusive_OR_expression\n");;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 334 "try1.y"
    {printf("\tReduced : inclusive_OR_expression -> inclusive_OR_expression OR_BIT exclusive_OR_expression\n");;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 337 "try1.y"
    {printf("\tReduced : exclusive_OR_expression -> AND_expression\n");;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 338 "try1.y"
    {printf("\tReduced : exclusive_OR_expression -> exclusive_OR_expression XOR AND_expression\n");;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 341 "try1.y"
    {printf("\tReduced : AND_expression -> equality_expression\n");;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 342 "try1.y"
    {printf("\tReduced : AND_expression -> AND_expression AND_BIT equality_expression\n");;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 344 "try1.y"
    {printf("\tReduced : equality_expression -> relational_expression\n");;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 345 "try1.y"
    {printf("\tReduced : equality_expression -> equality_expression IS_EQUAL_TO relational_expression\n");;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 346 "try1.y"
    {printf("\tReduced : equality_expression -> equality_expression NOT_EQUAL relational_expression\n");;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 349 "try1.y"
    {printf("\tReduced : relational_expression -> shift_expression\n");;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 350 "try1.y"
    {printf("\tReduced : relational_expression -> relational_expression LESS_THAN shift_expression\n");;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 351 "try1.y"
    {printf("\tReduced : relational_expression -> relational_expression GREATER_THAN shift_expression\n");;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 352 "try1.y"
    {printf("\tReduced : relational_expression -> relational_expression LESS_EQUAL shift_expression\n");;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 353 "try1.y"
    {printf("\tReduced : relational_expression -> relational_expression GREATER_EQUAL shift_expression\n");;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 356 "try1.y"
    {printf("\tReduced : shift_expression -> additive_expression\n");;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 357 "try1.y"
    {printf("\tReduced : shift_expression -> shift_expression L_SHIFT additive_expression\n");;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 358 "try1.y"
    {printf("\tReduced : shift_expression -> shift_expression R_SHIFT additive_expression\n");;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 361 "try1.y"
    {printf("\tReduced : additive_expression -> multiplicative_expression\n");;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 362 "try1.y"
    {printf("\tReduced : additive_expression -> additive_expression PLUS multiplicative_expression\n");;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 363 "try1.y"
    {printf("\tReduced : additive_expression -> additive_expression MINUS multiplicative_expression\n");;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 366 "try1.y"
    {printf("\tReduced : multiplicative_expression -> cast_expression\n");;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 367 "try1.y"
    {printf("\tReduced : multiplicative_expression -> multiplicative_expression MULTIPLY cast_expression\n");;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 368 "try1.y"
    {printf("\tReduced : multiplicative_expression -> multiplicative_expression DIVIDE cast_expression\n");;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 369 "try1.y"
    {printf("\tReduced : multiplicative_expression -> multiplicative_expression MODULUS cast_expression\n");;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 372 "try1.y"
    {printf("\tReduced : cast_expression -> unary_expression\n");;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 373 "try1.y"
    {printf("\tReduced : cast_expression -> OPEN_PARANTHESES type_symbol_specification CLOSE_PARANTHESES cast_expression\n");;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 376 "try1.y"
    {printf("\tReduced : unary_expression -> postfix_expression\n");;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 377 "try1.y"
    {printf("\tReduced : unary_expression -> INCREMENT unary_expression\n");;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 378 "try1.y"
    {printf("\tReduced : unary_expression -> DECREMENT unary_expression\n");;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 379 "try1.y"
    {printf("\tReduced : unary_expression -> unary_operator cast_expression\n");;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 380 "try1.y"
    {printf("\tReduced : unary_expression -> lenOF unary_expression\n");;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 381 "try1.y"
    {printf("\tReduced : unary_expression -> lenOF OPEN_PARANTHESES type_symbol_specification CLOSE_PARANTHESES\n");;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 384 "try1.y"
    {printf("\tReduced : unary_operator -> AND_BIT\n");;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 385 "try1.y"
    {printf("\tReduced : unary_operator -> MULTIPLY\n");;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 386 "try1.y"
    {printf("\tReduced : unary_operator -> PLUS\n");;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 387 "try1.y"
    {printf("\tReduced : unary_operator -> MINUS\n");;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 388 "try1.y"
    {printf("\tReduced : unary_operator -> NEGATION\n");;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 389 "try1.y"
    {printf("\tReduced : unary_operator -> NOT\n");;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 392 "try1.y"
    {printf("\tReduced : postfix_expression -> primary_expression\n");;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 393 "try1.y"
    {printf("\tReduced : postfix_expression -> postfix_expression OPEN_SQ_BRACKET expression CLOSE_SQ_BRACKET\n");;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 394 "try1.y"
    {printf("\tReduced : postfix_expression -> postfix_expression OPEN_PARANTHESES argument_expression_list CLOSE_PARANTHESES\n");;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 395 "try1.y"
    {printf("\tReduced : postfix_expression -> postfix_expression OPEN_PARANTHESES CLOSE_PARANTHESES\n");;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 396 "try1.y"
    {printf("\tReduced : postfix_expression -> postfix_expression DOT IDENTIFIER\n");;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 397 "try1.y"
    {printf("\tReduced : postfix_expression -> postfix_expression LINK IDENTIFIER\n");;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 398 "try1.y"
    {printf("\tReduced : postfix_expression -> postfix_expression INCREMENT\n");;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 399 "try1.y"
    {printf("\tReduced : postfix_expression -> postfix_expression DECREMENT\n");;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 402 "try1.y"
    {printf("\tReduced : primary_expression -> IDENTIFIER\n");for(j=1;j<=len;j++)
																						{if(!check_presence((yyvsp[(1) - (1)].entry).symbol_specification))
																							break;
																						else
																						{
																							printf("Yet not declared %s\n",(yyvsp[(1) - (1)].entry).symbol_specification);
																							yyerror();
																						}};}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 410 "try1.y"
    {printf("\tReduced : primary_expression -> constant\n");;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 411 "try1.y"
    {printf("\tReduced : primary_expression -> STRING_CONSTANT\n");if(flag==1)
																strcpy(symbol_table[len].value,strcat(strcat(symbol_table[len].value," "),(yyvsp[(1) - (1)].entry).value));;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 413 "try1.y"
    {printf("\tReduced : primary_expression -> OPEN_PARANTHESES expression CLOSE_PARANTHESES\n");;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 416 "try1.y"
    {printf("\tReduced : argument_expression_list -> assignment_expression\n");;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 417 "try1.y"
    {printf("\tReduced : argument_expression_list -> argument_expression_list COMMA assignment_expression\n");;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 420 "try1.y"
    {printf("\tReduced : constant -> NUMBER\n");if(flag==1)
																strcpy(symbol_table[len].value,strcat(strcat(symbol_table[len].value," "),(yyvsp[(1) - (1)].entry).value));;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 422 "try1.y"
    {printf("\tReduced : constant -> CHAR_CONSTANT\n");if(flag==1)
																strcpy(symbol_table[len].value,strcat(strcat(symbol_table[len].value," "),(yyvsp[(1) - (1)].entry).value));;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 424 "try1.y"
    {printf("\tReduced : constant -> REAL_NUMBER\n");if(flag==1)
																strcpy(symbol_table[len].value,strcat(strcat(symbol_table[len].value," "),(yyvsp[(1) - (1)].entry).value));;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 426 "try1.y"
    {printf("\tReduced : constant -> EXP_NUMBER\n");if(flag==1)
																strcpy(symbol_table[len].value,strcat(strcat(symbol_table[len].value," "),(yyvsp[(1) - (1)].entry).value));;}
    break;



/* Line 1455 of yacc.c  */
#line 3671 "try1.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 430 "try1.y"


#include "lex.yy.c"

int yyerror()
{
	printf("ERROR occurred: terminating\n");
	exit(0);
}

int main(int argc,char *argv[])
{
        int k,l;
		char temp[20];
		if(argc<2)
        {
                printf("Error in argument entry\n\n");
                return -1;
        }
        yyin = fopen(argv[1],"r");
        yyparse();

		printf("\n***No. of entries in symbol table = %d\n",len);

		printf("\n************THE SYMBOL TABLE***********\n\n");
		printf("line_no\tname\tdata\tis_arr\tsize\tinit_val\n\n");
		for(j=1;j<=len;j++)
		{
			printf("%d\t%s\t%d\t%d\t",symbol_table[j].line_number,symbol_table[j].symbol_specification,symbol_table[j].data_type,symbol_table[j].isarr);
			if(symbol_table[j].sflag==0)
			{
				if(symbol_table[j].isarr==0)
					printf("----\t");
				else
				{
					symbol_table[j].s=0;
					for(k=0;k<strlen(symbol_table[j].value);k++)
					{
						if(symbol_table[j].value[k]==' ')
							symbol_table[j].s++;
					}
					printf("%d\t",symbol_table[j].s);
				}
				printf("%s\n",symbol_table[j].value);
			}
			else
			{
				for(k=1;k<strlen(symbol_table[j].value);k++)
				{
					if(symbol_table[j].value[k]==' ')
						break;
				}
				for(l=0;l<k;l++)
					temp[l]=symbol_table[j].value[l];
				temp[l]='\0';
				symbol_table[j].s=atoi(temp);
				printf("%d\t",symbol_table[j].s);
				for(l=k;l<strlen(symbol_table[j].value);l++)
					temp[l-k]=symbol_table[j].value[l];
				temp[l-k]='\0';
				strcpy(symbol_table[j].value,temp);
				printf("%s\t\n",symbol_table[j].value);
			}
		}
        fclose(yyin);
        return 0;
}

