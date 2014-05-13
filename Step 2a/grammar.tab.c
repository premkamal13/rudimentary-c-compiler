
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
#line 1 "grammar.y"

#include<stdio.h>


/* Line 189 of yacc.c  */
#line 78 "grammar.tab.c"

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
     WHILE = 265,
     DO = 266,
     DOUBLE = 267,
     ELSE = 268,
     ENUM = 269,
     EXTERN = 270,
     FLOAT = 271,
     FOR = 272,
     GOTO = 273,
     VOLATILE = 274,
     INT = 275,
     LONG = 276,
     REGISTER = 277,
     RETURN = 278,
     SHORT = 279,
     SIGNED = 280,
     SIZEOF = 281,
     IF = 282,
     STATIC = 283,
     STRUCT = 284,
     SWITCH = 285,
     TYPEDEF = 286,
     UNION = 287,
     UNSIGNED = 288,
     VOID = 289,
     COMMA = 290,
     COLON = 291,
     SEMICOLON = 292,
     SHARP = 293,
     DOUBLE_QUOTES = 294,
     TERNARY = 295,
     OP_RIGHT_SHIFT = 296,
     OP_LEFT_SHIFT = 297,
     OP_LEFT_ASSIGNMENT = 298,
     OP_RIGHT_ASSIGNMENT = 299,
     THREE_DOTS = 300,
     OP_MOD_ASSIGNMENT = 301,
     DOT = 302,
     SQUARE_BRACKET_BEG = 303,
     SQUARE_BRACKET_END = 304,
     CURLY_BRACKET_BEG = 305,
     CURLY_BRACKET_END = 306,
     PARANTHESIS_BEG = 307,
     PARANTHESIS_END = 308,
     NUMBER = 309,
     REAL_NUMBER = 310,
     EXP_NUMBER = 311,
     CHAR_CONSTANT = 312,
     STRING_CONSTANT = 313,
     IDENTIFIER = 314,
     OP_PLUS = 315,
     OP_MINUS = 316,
     OP_INCREMENTOR = 317,
     OP_DECREMENTOR = 318,
     OP_ADDER = 319,
     OP_SUBTRACTOR = 320,
     OP_MULTIPLIER = 321,
     OP_DIVIDER = 322,
     OP_MULTIPLY = 323,
     OP_DIVIDE = 324,
     OP_ASSIGNMENT = 325,
     OP_SLASH = 326,
     OP_MODULUS = 327,
     OP_LESS_THAN = 328,
     OP_GREATER_THAN = 329,
     OP_NOT = 330,
     OP_BITWISE_AND = 331,
     OP_BITWISE_OR = 332,
     OP_AND = 333,
     OP_OR = 334,
     OP_BITWISE_XOR = 335,
     OP_TILDE = 336,
     OP_EQUALITY_CHECKER = 337,
     OP_AND_ASSIGNMENT = 338,
     OP_OR_ASSIGNMENT = 339,
     OP_LESS_OR_EQUAL = 340,
     OP_GREATER_OR_EQUAL = 341,
     OP_NOT_EQUAL = 342,
     OP_LINK = 343,
     OP_BITWISE_XOR_ASSIGNMENT = 344
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 209 "grammar.tab.c"

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
#define YYLAST   1808

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
      37,    -1,    96,    37,    -1,    94,    -1,    95,    94,    -1,
      97,    96,    -1,    97,    -1,    98,    96,    -1,    98,    -1,
      99,    96,    -1,    99,    -1,     3,    -1,    22,    -1,    28,
      -1,    15,    -1,    31,    -1,    34,    -1,     6,    -1,    24,
      -1,    20,    -1,    21,    -1,    16,    -1,    12,    -1,    25,
      -1,    33,    -1,   100,    -1,   109,    -1,     7,    -1,    19,
      -1,   101,    59,    50,   102,    51,    -1,   101,    50,   102,
      51,    -1,   101,    59,    -1,    29,    -1,    32,    -1,   105,
      -1,   102,   105,    -1,   104,    -1,   103,    35,   104,    -1,
     112,    -1,   112,    70,   120,    -1,   106,   107,    37,    -1,
      98,   106,    -1,    98,    -1,    99,   106,    -1,    99,    -1,
     108,    -1,   107,    35,   108,    -1,   112,    -1,   112,    36,
     137,    -1,    36,   137,    -1,    14,    59,    50,   110,    51,
      -1,    14,    50,   110,    51,    -1,    14,    59,    -1,   111,
      -1,   110,    35,   111,    -1,    59,    -1,    59,    70,   137,
      -1,   114,   113,    -1,   113,    -1,    59,    -1,    52,   112,
      53,    -1,   113,    48,   137,    49,    -1,   113,    48,    49,
      -1,   113,    52,   116,    53,    -1,   113,    52,   119,    53,
      -1,   113,    52,    53,    -1,    68,   115,    -1,    68,    -1,
      68,   115,   114,    -1,    68,   114,    -1,    99,    -1,   115,
      99,    -1,   117,    -1,   117,    35,    45,    -1,   118,    -1,
     117,    35,   118,    -1,    96,   112,    -1,    96,   123,    -1,
      96,    -1,    59,    -1,   119,    35,    59,    -1,   134,    -1,
      50,   121,    51,    -1,    50,   121,    35,    51,    -1,   120,
      -1,   121,    35,   120,    -1,   106,   123,    -1,   106,    -1,
     114,    -1,   114,   124,    -1,   124,    -1,    52,   123,    53,
      -1,   124,    48,   137,    49,    -1,    48,   137,    49,    -1,
     124,    48,    49,    -1,    48,    49,    -1,   124,    52,   116,
      53,    -1,    52,   116,    53,    -1,   124,    52,    53,    -1,
      52,    53,    -1,   126,    -1,   127,    -1,   128,    -1,   130,
      -1,   131,    -1,   132,    -1,    59,    36,   125,    -1,     5,
     137,    36,   125,    -1,     9,    36,   125,    -1,   133,    37,
      -1,    37,    -1,    50,    95,   129,    51,    -1,    50,    95,
      51,    -1,    50,   129,    51,    -1,    50,    51,    -1,   125,
      -1,   129,   125,    -1,    27,    52,   133,    53,   125,    -1,
      27,    52,   133,    53,   125,    13,   125,    -1,    30,    52,
     133,    53,   125,    -1,    10,    52,   133,    53,   125,    -1,
      11,   125,    10,    52,   133,    53,    37,    -1,    17,    52,
     133,    37,   133,    37,   133,    53,   125,    -1,    17,    52,
     133,    37,   133,    37,    53,   125,    -1,    17,    52,   133,
      37,    37,   133,    53,   125,    -1,    17,    52,   133,    37,
      37,    53,   125,    -1,    17,    52,    37,   133,    37,   133,
      53,   125,    -1,    17,    52,    37,   133,    37,    53,   125,
      -1,    17,    52,    37,    37,   133,    53,   125,    -1,    17,
      52,    37,    37,    53,   125,    -1,    18,    59,    37,    -1,
       8,    37,    -1,     4,    37,    -1,    23,   133,    37,    -1,
      23,    37,    -1,   134,    -1,   133,    35,   134,    -1,   136,
      -1,   149,   135,   134,    -1,    70,    -1,    66,    -1,    67,
      -1,    46,    -1,    64,    -1,    65,    -1,    43,    -1,    44,
      -1,    83,    -1,    89,    -1,    84,    -1,   138,    -1,   138,
      40,   133,    36,   136,    -1,   136,    -1,   139,    -1,   138,
      79,   139,    -1,   140,    -1,   139,    78,   140,    -1,   141,
      -1,   140,    77,   141,    -1,   142,    -1,   141,    80,   142,
      -1,   143,    -1,   142,    76,   143,    -1,   144,    -1,   143,
      82,   144,    -1,   143,    87,   144,    -1,   145,    -1,   144,
      73,   145,    -1,   144,    74,   145,    -1,   144,    85,   145,
      -1,   144,    86,   145,    -1,   146,    -1,   145,    42,   146,
      -1,   145,    41,   146,    -1,   147,    -1,   146,    60,   147,
      -1,   146,    61,   147,    -1,   148,    -1,   147,    68,   148,
      -1,   147,    69,   148,    -1,   147,    72,   148,    -1,   149,
      -1,    52,   122,    53,   148,    -1,   151,    -1,    62,   149,
      -1,    63,   149,    -1,   150,   148,    -1,    26,   149,    -1,
      26,    52,   122,    53,    -1,    76,    -1,    68,    -1,    60,
      -1,    61,    -1,    81,    -1,    75,    -1,   152,    -1,   151,
      48,   133,    49,    -1,   151,    52,   153,    53,    -1,   151,
      52,    53,    -1,   151,    47,    59,    -1,   151,    88,    59,
      -1,   151,    62,    -1,   151,    63,    -1,    59,    -1,   154,
      -1,    58,    -1,    52,   133,    53,    -1,   134,    -1,   153,
      35,   134,    -1,    54,    -1,    57,    -1,    55,    -1,    56,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    20,    20,    21,    24,    25,    28,    29,    30,    31,
      34,    35,    38,    39,    42,    43,    44,    45,    46,    47,
      50,    51,    52,    53,    54,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    70,    71,    74,    75,
      76,    79,    80,    83,    84,    87,    88,    91,    92,    95,
      98,    99,   100,   101,   104,   105,   107,   108,   109,   112,
     113,   114,   117,   118,   121,   122,   125,   126,   129,   130,
     131,   132,   133,   134,   135,   138,   139,   140,   141,   144,
     145,   148,   149,   152,   153,   156,   157,   158,   161,   162,
     165,   166,   167,   170,   171,   174,   175,   178,   179,   180,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   195,
     196,   197,   198,   199,   200,   203,   204,   205,   208,   209,
     212,   213,   214,   215,   218,   219,   222,   223,   224,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   239,
     240,   241,   242,   243,   246,   247,   250,   251,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   267,
     268,   271,   274,   275,   278,   279,   282,   283,   286,   287,
     290,   291,   293,   294,   295,   298,   299,   300,   301,   302,
     305,   306,   307,   310,   311,   312,   315,   316,   317,   318,
     321,   322,   325,   326,   327,   328,   329,   330,   333,   334,
     335,   336,   337,   338,   341,   342,   343,   344,   345,   346,
     347,   348,   351,   352,   353,   354,   357,   358,   361,   362,
     363,   364
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "WHILE", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN",
  "FLOAT", "FOR", "GOTO", "VOLATILE", "INT", "LONG", "REGISTER", "RETURN",
  "SHORT", "SIGNED", "SIZEOF", "IF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "COMMA", "COLON", "SEMICOLON",
  "SHARP", "DOUBLE_QUOTES", "TERNARY", "OP_RIGHT_SHIFT", "OP_LEFT_SHIFT",
  "OP_LEFT_ASSIGNMENT", "OP_RIGHT_ASSIGNMENT", "THREE_DOTS",
  "OP_MOD_ASSIGNMENT", "DOT", "SQUARE_BRACKET_BEG", "SQUARE_BRACKET_END",
  "CURLY_BRACKET_BEG", "CURLY_BRACKET_END", "PARANTHESIS_BEG",
  "PARANTHESIS_END", "NUMBER", "REAL_NUMBER", "EXP_NUMBER",
  "CHAR_CONSTANT", "STRING_CONSTANT", "IDENTIFIER", "OP_PLUS", "OP_MINUS",
  "OP_INCREMENTOR", "OP_DECREMENTOR", "OP_ADDER", "OP_SUBTRACTOR",
  "OP_MULTIPLIER", "OP_DIVIDER", "OP_MULTIPLY", "OP_DIVIDE",
  "OP_ASSIGNMENT", "OP_SLASH", "OP_MODULUS", "OP_LESS_THAN",
  "OP_GREATER_THAN", "OP_NOT", "OP_BITWISE_AND", "OP_BITWISE_OR", "OP_AND",
  "OP_OR", "OP_BITWISE_XOR", "OP_TILDE", "OP_EQUALITY_CHECKER",
  "OP_AND_ASSIGNMENT", "OP_OR_ASSIGNMENT", "OP_LESS_OR_EQUAL",
  "OP_GREATER_OR_EQUAL", "OP_NOT_EQUAL", "OP_LINK",
  "OP_BITWISE_XOR_ASSIGNMENT", "$accept", "translation_unit",
  "external_declaration", "function_definition", "declaration",
  "declaration_list", "declaration_specifiers", "storage_class_specifier",
  "type_specifier", "type_qualifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "init_declarator_list",
  "init_declarator", "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "declarator", "direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "initializer", "initializer_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "statement", "labeled_statement",
  "expression_statement", "compound_statement", "statement_list",
  "selection_statement", "iteration_statement", "jump_statement",
  "expression", "assignment_expression", "assignment_OP",
  "conditional_expression", "constant_expression", "logical_OR_expression",
  "logical_AND_expression", "inclusive_OR_expression",
  "exclusive_OR_expression", "AND_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "unary_OP", "postfix_expression", "primary_expression",
  "argument_expression_list", "constant", 0
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
       0,    20,    26,    36,    31,     0,    23,    30,    37,    28,
      29,    21,    27,    32,    22,    41,    24,    42,    33,    25,
       0,    68,    76,     0,     2,     4,     5,     0,    15,    17,
      19,    34,     0,    35,     0,    67,     0,     0,    61,     0,
      79,    78,    75,     1,     3,    11,     0,    45,    47,    14,
      16,    18,     0,    40,     0,    12,     0,     0,     9,     0,
       0,    66,    64,     0,    62,     0,    69,    80,    77,     0,
      10,     0,     0,     8,    51,    53,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   123,     0,   218,   220,   221,   219,   214,
     212,   200,   201,     0,     0,   199,   203,   198,   202,     0,
     124,   109,   110,   111,     0,   112,   113,   114,     0,   144,
     146,   159,   162,   164,   166,   168,   170,   172,   175,   180,
     183,   186,   190,     0,   192,   204,   213,    13,     7,    47,
      71,   212,   161,     0,   190,    74,    88,    87,     0,    81,
      83,     0,     0,     0,    60,     0,    46,     0,    48,    90,
       6,    50,    52,    39,    44,     0,     0,    54,    56,     0,
     141,     0,   140,     0,     0,     0,     0,     0,   143,     0,
       0,   196,     0,     0,    96,     0,     0,     0,     0,   193,
     194,   121,     0,   122,   125,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   155,   151,   152,
     153,   149,   150,   148,   156,   158,   157,     0,   195,     0,
       0,     0,   210,   211,     0,    70,     0,     0,    85,    97,
      86,    99,    72,     0,     0,    73,    65,    63,    59,    93,
       0,    58,     0,    49,     0,    38,     0,   117,     0,     0,
       0,     0,   139,   142,     0,     0,     0,     0,    97,    95,
       0,   215,   115,   120,   145,     0,   163,   165,   167,   169,
     171,   173,   174,   176,   177,   178,   179,   182,   181,   184,
     185,   187,   188,   189,   147,   208,     0,   207,   216,     0,
     209,   104,     0,   108,     0,     0,    98,     0,     0,    82,
      84,    89,     0,    91,    55,    57,   116,     0,     0,     0,
       0,     0,   197,     0,     0,   191,     0,   205,     0,   206,
     102,   106,   100,   103,     0,   107,     0,    92,    94,   129,
       0,     0,     0,     0,     0,     0,   126,   128,   160,   217,
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
#define YYPACT_NINF -219
static const yytype_int16 yypact[] =
{
     874,  -219,  -219,  -219,  -219,    12,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
     162,  -219,    -1,   699,  -219,  -219,  -219,    21,  1745,  1745,
    1745,  -219,    52,  -219,  1624,   136,    86,   -54,    31,    15,
    -219,  -219,    -1,  -219,  -219,  -219,   -13,  -219,   740,  -219,
    -219,  -219,  1774,    57,   308,  -219,  1624,    21,  -219,   940,
     915,   136,    46,   -16,  -219,   -54,  -219,  -219,  -219,   162,
    -219,   978,  1624,  -219,  1774,  1774,  1656,  -219,    89,  1774,
      16,  1442,   105,   128,   139,   570,   187,    94,  1018,  1480,
     203,   211,  -219,  -219,   628,  -219,  -219,  -219,  -219,  -219,
     230,  -219,  -219,  1518,  1518,  -219,  -219,  -219,  -219,   387,
    -219,  -219,  -219,  -219,   448,  -219,  -219,  -219,   181,  -219,
    -219,   -32,   192,   196,   200,   212,    98,    92,   140,   172,
     118,  -219,   999,  1442,    71,  -219,  -219,  -219,  -219,   215,
    -219,  -219,  -219,   237,  -219,  -219,  -219,    87,   234,   254,
    -219,    -2,  1442,   -54,  -219,    24,  -219,   978,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  1442,   191,  -219,   256,  1680,
    -219,   257,  -219,   570,  1442,   284,  1058,   258,  -219,   201,
     628,  -219,  1442,  1442,    18,   243,    11,   570,  1442,  -219,
    -219,  -219,   509,  -219,  -219,  1442,  -219,  1442,  1442,  1442,
    1442,  1442,  1442,  1442,  1442,  1442,  1442,  1442,  1442,  1442,
    1442,  1442,  1442,  1442,  1442,  1442,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  1442,  -219,   238,
    1442,  1096,  -219,  -219,   239,  -219,  1134,   772,  -219,    65,
    -219,   165,  -219,  1713,   240,  -219,  -219,  -219,  -219,  -219,
      37,  -219,    89,  -219,  1442,  -219,   570,  -219,    39,   248,
    1174,   209,  -219,  -219,   250,    48,    68,   823,   167,  -219,
    1442,  -219,  -219,  -219,  -219,   224,   192,   196,   200,   212,
      98,    92,    92,   140,   140,   140,   140,   172,   172,   118,
     118,  -219,  -219,  -219,  -219,  -219,    56,  -219,  -219,    91,
    -219,  -219,   255,  -219,   252,   253,   165,  1212,  1589,  -219,
    -219,  -219,   902,  -219,  -219,  -219,  -219,   570,  1442,  1250,
     210,  1290,  -219,   570,   570,  -219,  1442,  -219,  1442,  -219,
    -219,  -219,  -219,  -219,   260,  -219,   290,  -219,  -219,  -219,
     101,   570,   115,  1328,  1366,   219,   294,  -219,  -219,  -219,
    -219,  -219,   273,  -219,   570,   570,   117,   570,   123,  1404,
     570,  -219,  -219,  -219,   570,  -219,   570,   570,   126,  -219,
    -219,  -219,  -219,   570,  -219
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,   321,  -219,    13,   121,     0,  -219,   -37,     3,
    -219,  -219,   267,  -219,   278,   -59,   -31,  -219,    96,  -219,
     285,   198,   -17,   -27,   -10,  -219,   -56,  -219,   106,  -219,
    -156,  -219,   173,  -136,  -218,   -83,  -219,  -219,    -7,   245,
    -219,  -219,  -219,   -68,   -64,  -219,   -25,   -65,  -219,   154,
     156,   157,   155,   159,    58,    17,    59,    67,  -119,    -5,
    -219,  -219,  -219,  -219,  -219
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      27,   249,   175,    39,   148,    62,     3,   159,   197,    61,
      48,   240,    41,    26,   228,    74,   171,   164,     8,   153,
     179,   306,    69,    27,    70,    40,   186,    58,    49,    50,
      51,   194,    68,   244,   142,   154,    26,    74,    74,    74,
     139,    73,    74,   161,   162,    67,   195,   198,   269,   138,
     306,   245,   139,   170,   144,    75,   142,    74,    45,   153,
     147,   168,    37,   184,   271,   160,   236,    22,    66,   137,
     267,    38,   312,    20,   195,   248,   144,    75,    75,    75,
      21,    65,    75,   195,   181,   137,    22,   246,   313,    22,
     257,   195,   317,   159,   291,   292,   293,    75,   189,   190,
     251,   323,    52,   195,   272,   327,   258,    79,   261,   194,
     164,    53,   186,   236,   265,   266,   152,   237,   229,   230,
     186,   324,   137,   231,    21,   165,   328,   142,   144,   275,
     238,   274,    74,   232,   233,   236,   195,   239,    20,   237,
     142,    20,   172,    74,   329,    21,    21,   144,    21,   184,
     195,   325,   195,   177,   352,    22,   338,    22,   195,   234,
     144,   195,   296,   294,   173,   205,   206,   298,   354,    72,
     364,   302,    75,   316,   268,   109,   366,   207,   208,   373,
     203,   209,   210,    75,    59,   204,   213,   214,    60,   315,
     215,   174,   320,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   142,    61,   307,    20,   236,   195,   308,   196,   267,
      39,    21,   283,   284,   285,   286,   252,   239,   253,   142,
      22,   144,   211,   212,   339,   168,   195,   147,   263,   176,
     346,   347,   334,   147,   195,   195,   321,   343,   159,   144,
     340,   342,   336,   345,   195,   182,   359,   268,   353,   195,
     326,   281,   282,   183,   349,   144,   187,   147,   287,   288,
     199,   362,   363,   200,   365,   356,   358,   369,   289,   290,
     201,   370,   142,   371,   372,    71,   235,   242,   202,   243,
     374,   368,   254,   256,   259,   262,   270,   295,   300,   311,
     318,   348,   144,   322,   330,   331,   332,   360,   147,   350,
     361,     1,    80,    81,     2,     3,    82,    83,    84,    85,
       4,   144,     5,     6,     7,    86,    87,     8,     9,    10,
      11,    88,    12,    13,    89,    90,    14,    15,    91,    16,
      17,    18,    19,   351,    44,    92,   169,   156,   314,   310,
     155,   247,   276,   264,   192,   277,   279,   278,    54,    93,
      94,   280,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
       1,    80,    81,     2,     3,    82,    83,    84,    85,     4,
       0,     5,     6,     7,    86,    87,     8,     9,    10,    11,
      88,    12,    13,    89,    90,    14,    15,    91,    16,    17,
      18,    19,     0,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,   191,    94,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,    80,    81,     0,   105,    82,    83,    84,    85,
       0,     0,   106,   107,     0,    86,    87,     0,   108,     0,
       0,    88,     0,     0,    89,    90,     0,     0,    91,     0,
       0,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,   193,
      94,     0,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,    80,    81,     0,   105,    82,    83,    84,
      85,     0,     0,   106,   107,     0,    86,    87,     0,   108,
       0,     0,    88,     0,     0,    89,    90,     0,     0,    91,
       0,     0,     0,     0,     0,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
     273,    94,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,    80,    81,     0,   105,    82,    83,
      84,    85,     0,     0,   106,   107,     0,    86,    87,     0,
     108,     0,     0,    88,     0,     0,    89,    90,     0,     0,
      91,     0,     0,     0,     0,     0,     0,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,    94,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     2,     3,     0,     0,   105,     0,
       4,     0,     5,     0,     7,   106,   107,     8,     9,    10,
       0,   108,    12,    13,    89,     0,     0,    15,     0,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,    95,    96,    97,    98,    99,   141,   101,   102,
     103,   104,     0,     0,     0,     0,   105,     0,     0,    43,
       0,     0,     1,   106,   107,     2,     3,     0,     0,   108,
       0,     4,     0,     5,     6,     7,     0,     0,     8,     9,
      10,    11,     0,    12,    13,     0,     0,    14,    15,     0,
      16,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     2,     3,     0,     0,
       0,    20,     4,     0,     5,     6,     7,     0,    21,     8,
       9,    10,    11,     0,    12,    13,     0,    22,    14,    15,
       0,    16,    17,    18,    19,     1,     0,     0,     2,     3,
       0,     0,     0,     0,     4,     0,     5,     6,     7,     0,
      54,     8,     9,    10,    11,     0,    12,    13,     0,     0,
      14,    15,     0,    16,    17,    18,    19,     0,     0,     0,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,   237,   303,     1,     0,     0,     2,
       3,    21,     0,     0,     0,     4,     0,     5,     6,     7,
      22,     0,     8,     9,    10,    11,     0,    12,    13,     0,
       0,    14,    15,     0,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   267,   303,     1,     0,     0,
       2,     3,     0,     0,     0,     0,     4,     0,     5,     6,
       7,    22,     0,     8,     9,    10,    11,     0,    12,    13,
       0,     0,    14,    15,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     2,     3,     0,     0,     0,    20,     4,    89,     5,
       6,     7,     0,    21,     8,     9,    10,    11,     0,    12,
      13,     0,    22,    14,    15,     0,    16,    17,    18,    19,
       0,     0,   157,   337,    94,     0,    95,    96,    97,    98,
      99,   141,   101,   102,   103,   104,    89,     0,   145,     0,
     105,     0,     0,     0,   146,     0,     0,   106,   107,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,   140,
       0,     0,    94,     0,    95,    96,    97,    98,    99,   141,
     101,   102,   103,   104,    89,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,   157,     0,
      94,     0,    95,    96,    97,    98,    99,   141,   101,   102,
     103,   104,   216,   217,    89,   218,   105,     0,     0,     0,
       0,     0,     0,   106,   107,   178,     0,     0,     0,   108,
       0,     0,     0,   219,   220,   221,   222,     0,     0,   223,
      94,     0,    95,    96,    97,    98,    99,   141,   101,   102,
     103,   104,   224,   225,    89,     0,   105,     0,   226,     0,
       0,     0,     0,   106,   107,   260,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,    95,    96,    97,    98,    99,   141,   101,   102,
     103,   104,    89,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,    94,   297,
      95,    96,    97,    98,    99,   141,   101,   102,   103,   104,
      89,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,   301,     0,     0,    94,     0,    95,    96,
      97,    98,    99,   141,   101,   102,   103,   104,     0,     0,
      89,     0,   105,     0,     0,     0,     0,     0,     0,   106,
     107,   319,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,     0,    95,    96,
      97,    98,    99,   141,   101,   102,   103,   104,    89,     0,
       0,     0,   105,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,   333,     0,     0,    94,     0,    95,    96,    97,    98,
      99,   141,   101,   102,   103,   104,    89,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,    94,   341,    95,    96,    97,    98,    99,   141,
     101,   102,   103,   104,     0,     0,    89,     0,   105,     0,
       0,     0,     0,     0,     0,   106,   107,   344,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,    95,    96,    97,    98,    99,   141,
     101,   102,   103,   104,    89,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      94,   355,    95,    96,    97,    98,    99,   141,   101,   102,
     103,   104,    89,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,    94,   357,
      95,    96,    97,    98,    99,   141,   101,   102,   103,   104,
      89,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,    94,   367,    95,    96,
      97,    98,    99,   141,   101,   102,   103,   104,    89,     0,
       0,     0,   105,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,    94,     0,    95,    96,    97,    98,
      99,   141,   101,   102,   103,   104,    89,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,   180,     0,    95,    96,    97,    98,    99,   141,
     101,   102,   103,   104,    89,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
     188,     0,    95,    96,    97,    98,    99,   141,   101,   102,
     103,   104,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     1,   106,   107,     2,     3,     0,     0,   108,
       0,     4,     0,     5,     6,     7,     0,     0,     8,     9,
      10,    11,     0,    12,    13,     0,     0,    14,    15,     0,
      16,    17,    18,    19,     0,     0,     0,     1,     0,     0,
       2,     3,     0,     0,     0,     0,     4,     0,     5,     6,
       7,     0,   335,     8,     9,    10,    11,     0,    12,    13,
       0,     0,    14,    15,     0,    16,    17,    18,    19,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     4,     0,
       5,     0,     7,     0,    54,     8,     9,    10,     0,     0,
      12,    13,     0,     0,     0,    15,     2,     3,    17,    18,
      19,     0,     4,     0,     5,     0,     7,     0,     0,     8,
       9,    10,     0,     0,    12,    13,     0,   163,     0,    15,
       0,     0,    17,    18,    19,     0,     1,     0,     0,     2,
       3,     0,     0,     0,     0,     4,     0,     5,     6,     7,
       0,   255,     8,     9,    10,    11,     0,    12,    13,     0,
       0,    14,    15,     0,    16,    17,    18,    19,     1,     0,
       0,     2,     3,     0,     0,     0,     0,     4,   309,     5,
       6,     7,     0,     0,     8,     9,    10,    11,     0,    12,
      13,     0,     0,    14,    15,     0,    16,    17,    18,    19,
       2,     3,     0,     0,     0,     0,     4,     0,     5,     0,
       7,     0,     0,     8,     9,    10,     0,     0,    12,    13,
       0,     0,     0,    15,     0,     0,    17,    18,    19
};

static const yytype_int16 yycheck[] =
{
       0,   157,    85,    20,    60,    59,     7,    71,    40,    36,
      27,   147,    22,     0,   133,    52,    81,    76,    19,    35,
      88,   239,    35,    23,    37,    22,    94,    34,    28,    29,
      30,   114,    42,    35,    59,    51,    23,    74,    75,    76,
      57,    48,    79,    74,    75,    42,    35,    79,   184,    56,
     268,    53,    69,    37,    59,    52,    81,    94,    37,    35,
      60,    78,    50,    94,    53,    72,    48,    68,    53,    56,
      52,    59,    35,    52,    35,    51,    81,    74,    75,    76,
      59,    50,    79,    35,    89,    72,    68,   152,    51,    68,
     173,    35,    53,   157,   213,   214,   215,    94,   103,   104,
     165,    53,    50,    35,   187,    49,   174,    50,   176,   192,
     169,    59,   180,    48,   182,   183,    70,    52,    47,    48,
     188,    53,   109,    52,    59,    36,    35,   152,   133,   197,
     147,   195,   169,    62,    63,    48,    35,   147,    52,    52,
     165,    52,    37,   180,    53,    59,    59,   152,    59,   180,
      35,   270,    35,    59,    53,    68,   312,    68,    35,    88,
     165,    35,   230,   227,    36,    73,    74,   231,    53,    48,
      53,   236,   169,   256,   184,    54,    53,    85,    86,    53,
      82,    41,    42,   180,    48,    87,    68,    69,    52,   254,
      72,    52,   260,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   236,   239,    48,    52,    48,    35,    52,    37,    52,
     237,    59,   205,   206,   207,   208,    35,   237,    37,   254,
      68,   236,    60,    61,   317,   252,    35,   237,    37,    52,
     323,   324,   307,   243,    35,    35,    37,    37,   312,   254,
     318,   319,   308,   321,    35,    52,    37,   267,   341,    35,
      36,   203,   204,    52,   328,   270,    36,   267,   209,   210,
      78,   354,   355,    77,   357,   343,   344,   360,   211,   212,
      80,   364,   307,   366,   367,    70,    49,    53,    76,    35,
     373,   359,    36,    36,    10,    37,    53,    59,    59,    59,
      52,   326,   307,    53,    49,    53,    53,    13,   308,    49,
      37,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   326,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    53,    23,    37,    79,    69,   252,   243,
      65,   153,   198,   180,   109,   199,   201,   200,    50,    51,
      52,   202,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,     4,     5,    -1,    68,     8,     9,    10,    11,
      -1,    -1,    75,    76,    -1,    17,    18,    -1,    81,    -1,
      -1,    23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,     4,     5,    -1,    68,     8,     9,    10,
      11,    -1,    -1,    75,    76,    -1,    17,    18,    -1,    81,
      -1,    -1,    23,    -1,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,     4,     5,    -1,    68,     8,     9,
      10,    11,    -1,    -1,    75,    76,    -1,    17,    18,    -1,
      81,    -1,    -1,    23,    -1,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     6,     7,    -1,    -1,    68,    -1,
      12,    -1,    14,    -1,    16,    75,    76,    19,    20,    21,
      -1,    81,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,     0,
      -1,    -1,     3,    75,    76,     6,     7,    -1,    -1,    81,
      -1,    12,    -1,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,    -1,    -1,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    52,    12,    -1,    14,    15,    16,    -1,    59,    19,
      20,    21,    22,    -1,    24,    25,    -1,    68,    28,    29,
      -1,    31,    32,    33,    34,     3,    -1,    -1,     6,     7,
      -1,    -1,    -1,    -1,    12,    -1,    14,    15,    16,    -1,
      50,    19,    20,    21,    22,    -1,    24,    25,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    52,    53,     3,    -1,    -1,     6,
       7,    59,    -1,    -1,    -1,    12,    -1,    14,    15,    16,
      68,    -1,    19,    20,    21,    22,    -1,    24,    25,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    52,    53,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    14,    15,
      16,    68,    -1,    19,    20,    21,    22,    -1,    24,    25,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,     6,     7,    -1,    -1,    -1,    52,    12,    26,    14,
      15,    16,    -1,    59,    19,    20,    21,    22,    -1,    24,
      25,    -1,    68,    28,    29,    -1,    31,    32,    33,    34,
      -1,    -1,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    26,    -1,    53,    -1,
      68,    -1,    -1,    -1,    59,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    26,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    43,    44,    26,    46,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    37,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    64,    65,    66,    67,    -1,    -1,    70,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    83,    84,    26,    -1,    68,    -1,    89,    -1,
      -1,    -1,    -1,    75,    76,    37,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    26,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      26,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      26,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    37,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    26,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    26,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    26,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    37,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    26,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    26,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      26,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    26,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    26,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    26,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,     3,    75,    76,     6,     7,    -1,    -1,    81,
      -1,    12,    -1,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,    -1,    -1,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    14,    15,
      16,    -1,    53,    19,    20,    21,    22,    -1,    24,    25,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    -1,
      -1,    -1,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,
      14,    -1,    16,    -1,    50,    19,    20,    21,    -1,    -1,
      24,    25,    -1,    -1,    -1,    29,     6,     7,    32,    33,
      34,    -1,    12,    -1,    14,    -1,    16,    -1,    -1,    19,
      20,    21,    -1,    -1,    24,    25,    -1,    51,    -1,    29,
      -1,    -1,    32,    33,    34,    -1,     3,    -1,    -1,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    14,    15,    16,
      -1,    51,    19,    20,    21,    22,    -1,    24,    25,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,     3,    -1,
      -1,     6,     7,    -1,    -1,    -1,    -1,    12,    45,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    -1,    24,
      25,    -1,    -1,    28,    29,    -1,    31,    32,    33,    34,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    14,    -1,
      16,    -1,    -1,    19,    20,    21,    -1,    -1,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    12,    14,    15,    16,    19,    20,
      21,    22,    24,    25,    28,    29,    31,    32,    33,    34,
      52,    59,    68,    91,    92,    93,    94,    96,    97,    98,
      99,   100,   101,   109,   112,   113,   114,    50,    59,   112,
      99,   114,   115,     0,    92,    37,   103,   104,   112,    96,
      96,    96,    50,    59,    50,    94,    95,    96,   128,    48,
      52,   113,    59,   110,   111,    50,    53,    99,   114,    35,
      37,    70,    95,   128,    98,    99,   102,   105,   106,    50,
       4,     5,     8,     9,    10,    11,    17,    18,    23,    26,
      27,    30,    37,    51,    52,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    68,    75,    76,    81,    95,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     136,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   154,    94,   128,   112,
      49,    59,   136,   137,   149,    53,    59,    96,   116,   117,
     118,   119,    70,    35,    51,   110,   104,    50,   120,   134,
     128,   106,   106,    51,   105,    36,   107,   108,   112,   102,
      37,   137,    37,    36,    52,   125,    52,    59,    37,   133,
      52,   149,    52,    52,   106,   122,   133,    36,    52,   149,
     149,    51,   129,    51,   125,    35,    37,    40,    79,    78,
      77,    80,    76,    82,    87,    73,    74,    85,    86,    41,
      42,    60,    61,    68,    69,    72,    43,    44,    46,    64,
      65,    66,    67,    70,    83,    84,    89,   135,   148,    47,
      48,    52,    62,    63,    88,    49,    48,    52,   112,   114,
     123,   124,    53,    35,    35,    53,   137,   111,    51,   120,
     121,   137,    35,    37,    36,    51,    36,   125,   133,    10,
      37,   133,    37,    37,   122,   133,   133,    52,   114,   123,
      53,    53,   125,    51,   134,   133,   139,   140,   141,   142,
     143,   144,   144,   145,   145,   145,   145,   146,   146,   147,
     147,   148,   148,   148,   134,    59,   133,    53,   134,   153,
      59,    49,   137,    53,   116,   123,   124,    48,    52,    45,
     118,    59,    35,    51,   108,   137,   125,    53,    52,    37,
     133,    37,    53,    53,    53,   148,    36,    49,    35,    53,
      49,    53,    53,    49,   137,    53,   116,    51,   120,   125,
     133,    53,   133,    37,    37,   133,   125,   125,   136,   134,
      49,    53,    53,   125,    53,    53,   133,    53,   133,    37,
      13,    37,   125,   125,    53,   125,    53,    53,   133,   125,
     125,   125,   125,    53,   125
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
#line 20 "grammar.y"
    {printf("\tReduced : translation_unit -> external_declaration\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 21 "grammar.y"
    {printf("\tReduced : translation_unit -> translation_unit external_declaration\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 24 "grammar.y"
    {printf("\tReduced : external_declaration -> function_definition\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 25 "grammar.y"
    {printf("\tReduced : external_declaration -> declaration\n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 28 "grammar.y"
    {printf("\tReduced : function_definition -> declaration_specifiers declarator declaration_list compound_statement\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 29 "grammar.y"
    {printf("\tReduced : function_definition -> declarator declaration_list compound_statement\n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 30 "grammar.y"
    {printf("\tReduced : function_definition -> declaration_specifiers declarator compound_statement\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 31 "grammar.y"
    {printf("\tReduced : function_definition -> declarator compound_statement\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 34 "grammar.y"
    {printf("\tReduced : declaration -> declaration_specifiers init_declarator_list SEMICOLON\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 35 "grammar.y"
    {printf("\tReduced : declaration -> declaration_specifiers SEMICOLON\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 38 "grammar.y"
    {printf("\tReduced : declaration_list -> declaration\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 39 "grammar.y"
    {printf("\tReduced : declaration_list -> declaration_list declaration\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 42 "grammar.y"
    {printf("\tReduced : declaration_specifiers -> storage_class_specifier declaration_specifiers\n");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 43 "grammar.y"
    {printf("\tReduced : declaration_specifiers -> storage_class_specifier\n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 44 "grammar.y"
    {printf("\tReduced : declaration_specifiers -> type_specifier declaration_specifiers\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 45 "grammar.y"
    {printf("\tReduced : declaration_specifiers -> type_specifier\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 46 "grammar.y"
    {printf("\tReduced : declaration_specifiers -> type_qualifier declaration_specifiers\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 47 "grammar.y"
    {printf("\tReduced : declaration_specifiers -> type_qualifier\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 50 "grammar.y"
    {printf("\tReduced : storage_class_specifier -> AUTO \n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 51 "grammar.y"
    {printf("\tReduced : storage_class_specifier -> REGISTER\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 52 "grammar.y"
    {printf("\tReduced : storage_class_specifier -> STATIC\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 53 "grammar.y"
    {printf("\tReduced : storage_class_specifier -> EXTERN\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 54 "grammar.y"
    {printf("\tReduced : storage_class_specifier -> TYPEDEF\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 57 "grammar.y"
    {printf("\tReduced : type_specifier -> VOID\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 58 "grammar.y"
    {printf("\tReduced : type_specifier -> CHAR\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 59 "grammar.y"
    {printf("\tReduced : type_specifier -> SHORT\n");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 60 "grammar.y"
    {printf("\tReduced : type_specifier -> INT\n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 61 "grammar.y"
    {printf("\tReduced : type_specifier -> LONG\n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 62 "grammar.y"
    {printf("\tReduced : type_specifier -> FLOAT\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 63 "grammar.y"
    {printf("\tReduced : type_specifier -> DOUBLE\n");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 64 "grammar.y"
    {printf("\tReduced : type_specifier -> SIGNED\n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 65 "grammar.y"
    {printf("\tReduced : type_specifier -> UNSIGNED\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 66 "grammar.y"
    {printf("\tReduced : type_specifier -> struct_or_union_specifier\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 67 "grammar.y"
    {printf("\tReduced : type_specifier -> enum_specifier\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 70 "grammar.y"
    {printf("\tReduced : type_qualifier -> CONST\n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 71 "grammar.y"
    {printf("\tReduced : type_qualifier -> VOLATILE\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 74 "grammar.y"
    {printf("\tReduced : struct_or_union_specifier -> struct_or_union IDENTIFIER CURLY_BRACKET_BEG struct_declaration_list CURLY_BRACKET_END\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 75 "grammar.y"
    {printf("\tReduced : struct_or_union_specifier -> struct_or_union CURLY_BRACKET_BEG struct_declaration_list CURLY_BRACKET_END\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 76 "grammar.y"
    {printf("\tReduced : struct_or_union_specifier -> struct_or_union IDENTIFIER\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 79 "grammar.y"
    {printf("\tReduced : struct_or_union -> STRUCT\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 80 "grammar.y"
    {printf("\tReduced : struct_or_union -> UNION\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 83 "grammar.y"
    {printf("\tReduced : struct_declaration_list -> struct_declaration\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 84 "grammar.y"
    {printf("\tReduced : struct_declaration_list -> struct_declaration_list struct_declaration\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 87 "grammar.y"
    {printf("\tReduced : init_declarator_list -> init_declarator\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 88 "grammar.y"
    {printf("\tReduced : init_declarator_list -> init_declarator_list COMMA init_declarator\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 91 "grammar.y"
    {printf("\tReduced : init_declarator -> declarator\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 92 "grammar.y"
    {printf("\tReduced : init_declarator -> declarator OP_ASSIGNMENT initializer\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 95 "grammar.y"
    {printf("\tReduced : struct_declaration -> specifier_qualifier_list struct_declarator_list SEMICOLON\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 98 "grammar.y"
    {printf("\tReduced : specifier_qualifier_list -> type_specifier specifier_qualifier_list\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 99 "grammar.y"
    {printf("\tReduced : specifier_qualifier_list -> type_specifier\n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 100 "grammar.y"
    {printf("\tReduced : specifier_qualifier_list -> type_qualifier specifier_qualifier_list\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 101 "grammar.y"
    {printf("\tReduced : specifier_qualifier_list -> type_qualifier\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 104 "grammar.y"
    {printf("\tReduced : struct_declarator_list -> struct_declarator\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 105 "grammar.y"
    {printf("\tReduced : struct_declarator_list -> struct_declarator_list COMMA struct_declarator\n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 107 "grammar.y"
    {printf("\tReduced : struct_declarator -> declarator\n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 108 "grammar.y"
    {printf("\tReduced : struct_declarator -> declarator COLON constant_expression\n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 109 "grammar.y"
    {printf("\tReduced : struct_declarator -> COLON constant_expression\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 112 "grammar.y"
    {printf("\tReduced : enum_specifier -> ENUM IDENTIFIER CURLY_BRACKET_BEG enumerator_list CURLY_BRACKET_END\n");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 113 "grammar.y"
    {printf("\tReduced : enum_specifier -> ENUM CURLY_BRACKET_BEG enumerator_list CURLY_BRACKET_END\n");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 114 "grammar.y"
    {printf("\tReduced : enum_specifier -> ENUM IDENTIFIER\n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 117 "grammar.y"
    {printf("\tReduced : enumerator_list -> enumerator\n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 118 "grammar.y"
    {printf("\tReduced : enumerator_list -> enumerator_list COMMA enumerator\n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 121 "grammar.y"
    {printf("\tReduced : enumerator -> IDENTIFIER\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 122 "grammar.y"
    {printf("\tReduced : enumerator -> IDENTIFIER OP_ASSIGNMENT constant_expression\n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 125 "grammar.y"
    {printf("\tReduced : declarator -> pointer direct_declarator\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 126 "grammar.y"
    {printf("\tReduced : declarator -> direct_declarator\n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 129 "grammar.y"
    {printf("\tReduced : direct_declarator -> IDENTIFIER\n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 130 "grammar.y"
    {printf("\tReduced : direct_declarator -> PARANTHESIS_BEG declarator PARANTHESIS_END\n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 131 "grammar.y"
    {printf("\tReduced : direct_declarator -> direct_declarator SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END\n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 132 "grammar.y"
    {printf("\tReduced : direct_declarator -> direct_declarator SQUARE_BRACKET_BEG SQUARE_BRACKET_END\n");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 133 "grammar.y"
    {printf("\tReduced : direct_declarator -> direct_declarator PARANTHESIS_BEG parameter_type_list PARANTHESIS_END\n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 134 "grammar.y"
    {printf("\tReduced : direct_declarator -> direct_declarator PARANTHESIS_BEG identifier_list PARANTHESIS_END\n");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 135 "grammar.y"
    {printf("\tReduced : direct_declarator -> direct_declarator PARANTHESIS_BEG PARANTHESIS_END\n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 138 "grammar.y"
    {printf("\tReduced : pointer -> OP_MULTIPLY type_qualifier_list\n");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 139 "grammar.y"
    {printf("\tReduced : pointer -> OP_MULTIPLY\n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 140 "grammar.y"
    {printf("\tReduced : pointer -> OP_MULTIPLY type_qualifier_list pointer\n");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 141 "grammar.y"
    {printf("\tReduced : pointer -> OP_MULTIPLY pointer\n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 144 "grammar.y"
    {printf("\tReduced : type_qualifier_list -> type_qualifier\n");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 145 "grammar.y"
    {printf("\tReduced : type_qualifier_list -> type_qualifier_list type_qualifier\n");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 148 "grammar.y"
    {printf("\tReduced : parameter_type_list -> parameter_list\n");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 149 "grammar.y"
    {printf("\tReduced : parameter_type_list -> parameter_list COMMA THREE_DOTS\n");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 152 "grammar.y"
    {printf("\tReduced : parameter_list -> parameter_declaration\n");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 153 "grammar.y"
    {printf("\tReduced : parameter_list -> parameter_list COMMA parameter_declaration\n");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 156 "grammar.y"
    {printf("\tReduced : parameter_declaration -> declaration_specifiers declarator\n");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 157 "grammar.y"
    {printf("\tReduced : parameter_declaration -> declaration_specifiers abstract_declarator\n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 158 "grammar.y"
    {printf("\tReduced : parameter_declaration -> declaration_specifiers\n");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 161 "grammar.y"
    {printf("\tReduced : identifier_list -> IDENTIFIER\n");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 162 "grammar.y"
    {printf("\tReduced : identifier_list -> identifier_list COMMA IDENTIFIER\n");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 165 "grammar.y"
    {printf("\tReduced : initializer -> assignment_expression\n");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 166 "grammar.y"
    {printf("\tReduced : initializer -> CURLY_BRACKET_BEG initializer_list CURLY_BRACKET_END\n");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 167 "grammar.y"
    {printf("\tReduced : initializer -> CURLY_BRACKET_BEG initializer_list COMMA CURLY_BRACKET_END\n");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 170 "grammar.y"
    {printf("\tReduced : initializer_list -> initializer\n");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 171 "grammar.y"
    {printf("\tReduced : initializer_list -> initializer_list COMMA initializer\n");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 174 "grammar.y"
    {printf("\tReduced : type_name -> specifier_qualifier_list abstract_declarator\n");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 175 "grammar.y"
    {printf("\tReduced : type_name -> specifier_qualifier_list\n");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 178 "grammar.y"
    {printf("\tReduced : abstract_declarator ->  pointer\n");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 179 "grammar.y"
    {printf("\tReduced : abstract_declarator ->  pointer direct_abstract_declarator\n");;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 180 "grammar.y"
    {printf("\tReduced : abstract_declarator -> direct_abstract_declarator\n");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 183 "grammar.y"
    {printf("\tReduced : direct_abstract_declarator -> PARANTHESIS_BEG abstract_declarator PARANTHESIS_END\n");;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 184 "grammar.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END\n");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 185 "grammar.y"
    {printf("\tReduced : direct_abstract_declarator -> SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END\n");;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 186 "grammar.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator SQUARE_BRACKET_BEG SQUARE_BRACKET_END\n");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 187 "grammar.y"
    {printf("\tReduced : direct_abstract_declarator -> SQUARE_BRACKET_BEG SQUARE_BRACKET_END\n");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 188 "grammar.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator PARANTHESIS_BEG parameter_type_list PARANTHESIS_END\n");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 189 "grammar.y"
    {printf("\tReduced : direct_abstract_declarator -> PARANTHESIS_BEG parameter_type_list PARANTHESIS_END\n");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 190 "grammar.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator PARANTHESIS_BEG PARANTHESIS_END\n");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 191 "grammar.y"
    {printf("\tReduced : direct_abstract_declarator -> PARANTHESIS_BEG PARANTHESIS_END\n");;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 195 "grammar.y"
    {printf("\tReduced : statement -> labeled_statement\n");;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 196 "grammar.y"
    {printf("\tReduced : statement -> expression_statement\n");;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 197 "grammar.y"
    {printf("\tReduced : statement -> compound_statement\n");;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 198 "grammar.y"
    {printf("\tReduced : statement -> selection_statement\n");;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 199 "grammar.y"
    {printf("\tReduced : statement -> iteration_statement\n");;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 200 "grammar.y"
    {printf("\tReduced : statement -> jump_statement\n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 203 "grammar.y"
    {printf("\tReduced : labeled_statement -> IDENTIFIER COLON statement\n");;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 204 "grammar.y"
    {printf("\tReduced : labeled_statement -> CASE constant_expression COLON statement\n");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 205 "grammar.y"
    {printf("\tReduced : labeled_statement -> DEFAULT COLON statement\n");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 208 "grammar.y"
    {printf("\tReduced : expression_statement -> expression SEMICOLON\n");;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 209 "grammar.y"
    {printf("\tReduced : expression_statement -> SEMICOLON\n");;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 212 "grammar.y"
    {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG declaration_list statement_list CURLY_BRACKET_END\n");;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 213 "grammar.y"
    {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG declaration_list CURLY_BRACKET_END\n");;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 214 "grammar.y"
    {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG statement_list CURLY_BRACKET_END\n");;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 215 "grammar.y"
    {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG CURLY_BRACKET_END\n");;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 218 "grammar.y"
    {printf("\tReduced : statement_list -> statement\n");;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 219 "grammar.y"
    {printf("\tReduced : statement_list -> statement_list statement\n");;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 222 "grammar.y"
    {printf("\tReduced : selection_statement -> IF PARANTHESIS_BEG expression PARANTHESIS_END statement\n");;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 223 "grammar.y"
    {printf("\tReduced : selection_statement -> IF PARANTHESIS_BEG expression PARANTHESIS_END statement ELSE statement\n");;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 224 "grammar.y"
    {printf("\tReduced : selection_statement -> SWITCH PARANTHESIS_BEG expression PARANTHESIS_END statement\n");;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 227 "grammar.y"
    {printf("\tReduced : iteration_statement -> WHILE PARANTHESIS_BEG expression PARANTHESIS_END statement\n");;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 228 "grammar.y"
    {printf("\tReduced : iteration_statement -> DO statement WHILE PARANTHESIS_BEG expression PARANTHESIS_END SEMICOLON\n");;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 229 "grammar.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON expression SEMICOLON expression PARANTHESIS_END statement\n");;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 230 "grammar.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON expression SEMICOLON PARANTHESIS_END statement\n");;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 231 "grammar.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON SEMICOLON expression PARANTHESIS_END statement\n");;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 232 "grammar.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON SEMICOLON PARANTHESIS_END statement\n");;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 233 "grammar.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON expression SEMICOLON expression PARANTHESIS_END statement\n");;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 234 "grammar.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON expression SEMICOLON PARANTHESIS_END statement\n");;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 235 "grammar.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON SEMICOLON expression PARANTHESIS_END statement\n");;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 236 "grammar.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON SEMICOLON PARANTHESIS_END statement\n");;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 239 "grammar.y"
    {printf("\tReduced : jump_statement -> GOTO IDENTIFIER SEMICOLON\n");;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 240 "grammar.y"
    {printf("\tReduced : jump_statement -> CONTINUE SEMICOLON\n");;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 241 "grammar.y"
    {printf("\tReduced : jump_statement -> BREAK SEMICOLON\n");;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 242 "grammar.y"
    {printf("\tReduced : jump_statement -> RETURN expression SEMICOLON\n");;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 243 "grammar.y"
    {printf("\tReduced : jump_statement -> RETURN SEMICOLON\n");;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 246 "grammar.y"
    {printf("\tReduced : expression -> assignment_expression\n");;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 247 "grammar.y"
    {printf("\tReduced : expression -> expression COMMA assignment_expression\n");;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 250 "grammar.y"
    {printf("\tReduced : assignment_expression -> conditional_expression\n");;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 251 "grammar.y"
    {printf("\tReduced : assignment_expression -> unary_expression assignment_OP assignment_expression\n");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 254 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_ASSIGNMENT\n");;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 255 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_MULTIPLIER\n");;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 256 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_DIVIDER\n");;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 257 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_MOD_ASSIGNMENT\n");;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 258 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_ADDER\n");;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 259 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_SUBTRACTOR\n");;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 260 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_LEFT_ASSIGNMENT\n");;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 261 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_RIGHT_ASSIGNMENT\n");;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 262 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_AND_ASSIGNMENT\n");;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 263 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_BITWISE_XOR_ASSIGNMENT\n");;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 264 "grammar.y"
    {printf("\tReduced : assignment_OP -> OP_OR_ASSIGNMENT\n");;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 267 "grammar.y"
    {printf("\tReduced : conditional_expression -> logical_OR_expression\n");;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 268 "grammar.y"
    {printf("\tReduced : conditional_expression -> logical_OR_expression TERNARY expression COLON conditional_expression\n");;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 271 "grammar.y"
    {printf("\tReduced : constant_expression -> conditional_expression\n");;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 274 "grammar.y"
    {printf("\tReduced : logical_OR_expression -> logical_AND_expression\n");;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 275 "grammar.y"
    {printf("\tReduced : logical_OR_expression -> logical_OR_expression OP_OR logical_AND_expression\n");;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 278 "grammar.y"
    {printf("\tReduced : logical_AND_expression -> inclusive_OR_expression\n");;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 279 "grammar.y"
    {printf("\tReduced : logical_AND_expression -> logical_AND_expression OP_AND inclusive_OR_expression\n");;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 282 "grammar.y"
    {printf("\tReduced : inclusive_OR_expression -> exclusive_OR_expression\n");;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 283 "grammar.y"
    {printf("\tReduced : inclusive_OR_expression -> inclusive_OR_expression OP_BITWISE_OR exclusive_OR_expression\n");;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 286 "grammar.y"
    {printf("\tReduced : exclusive_OR_expression -> AND_expression\n");;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 287 "grammar.y"
    {printf("\tReduced : exclusive_OR_expression -> exclusive_OR_expression OP_BITWISE_XOR AND_expression\n");;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 290 "grammar.y"
    {printf("\tReduced : AND_expression -> equality_expression\n");;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 291 "grammar.y"
    {printf("\tReduced : AND_expression -> AND_expression OP_BITWISE_AND equality_expression\n");;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 293 "grammar.y"
    {printf("\tReduced : equality_expression -> relational_expression\n");;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 294 "grammar.y"
    {printf("\tReduced : equality_expression -> equality_expression OP_EQUALITY_CHECKER relational_expression\n");;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 295 "grammar.y"
    {printf("\tReduced : equality_expression -> equality_expression OP_NOT_EQUAL relational_expression\n");;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 298 "grammar.y"
    {printf("\tReduced : relational_expression -> shift_expression\n");;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 299 "grammar.y"
    {printf("\tReduced : relational_expression -> relational_expression OP_LESS_THAN shift_expression\n");;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 300 "grammar.y"
    {printf("\tReduced : relational_expression -> relational_expression OP_GREATER_THAN shift_expression\n");;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 301 "grammar.y"
    {printf("\tReduced : relational_expression -> relational_expression OP_LESS_OR_EQUAL shift_expression\n");;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 302 "grammar.y"
    {printf("\tReduced : relational_expression -> relational_expression OP_GREATER_OR_EQUAL shift_expression\n");;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 305 "grammar.y"
    {printf("\tReduced : shift_expression -> additive_expression\n");;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 306 "grammar.y"
    {printf("\tReduced : shift_expression -> shift_expression OP_LEFT_SHIFT additive_expression\n");;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 307 "grammar.y"
    {printf("\tReduced : shift_expression -> shift_expression OP_RIGHT_SHIFT additive_expression\n");;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 310 "grammar.y"
    {printf("\tReduced : additive_expression -> multiplicative_expression\n");;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 311 "grammar.y"
    {printf("\tReduced : additive_expression -> additive_expression OP_PLUS multiplicative_expression\n");;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 312 "grammar.y"
    {printf("\tReduced : additive_expression -> additive_expression OP_MINUS multiplicative_expression\n");;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 315 "grammar.y"
    {printf("\tReduced : multiplicative_expression -> cast_expression\n");;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 316 "grammar.y"
    {printf("\tReduced : multiplicative_expression -> multiplicative_expression OP_MULTIPLY cast_expression\n");;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 317 "grammar.y"
    {printf("\tReduced : multiplicative_expression -> multiplicative_expression OP_DIVIDE cast_expression\n");;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 318 "grammar.y"
    {printf("\tReduced : multiplicative_expression -> multiplicative_expression OP_MODULUS cast_expression\n");;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 321 "grammar.y"
    {printf("\tReduced : cast_expression -> unary_expression\n");;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 322 "grammar.y"
    {printf("\tReduced : cast_expression -> PARANTHESIS_BEG type_name PARANTHESIS_END cast_expression\n");;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 325 "grammar.y"
    {printf("\tReduced : unary_expression -> postfix_expression\n");;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 326 "grammar.y"
    {printf("\tReduced : unary_expression -> OP_INCREMENTOR unary_expression\n");;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 327 "grammar.y"
    {printf("\tReduced : unary_expression -> OP_DECREMENTOR unary_expression\n");;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 328 "grammar.y"
    {printf("\tReduced : unary_expression -> unary_OP cast_expression\n");;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 329 "grammar.y"
    {printf("\tReduced : unary_expression -> SIZEOF unary_expression\n");;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 330 "grammar.y"
    {printf("\tReduced : unary_expression -> SIZEOF PARANTHESIS_BEG type_name PARANTHESIS_END\n");;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 333 "grammar.y"
    {printf("\tReduced : unary_OP -> OPERATR_BITWISE_AND\n");;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 334 "grammar.y"
    {printf("\tReduced : unary_OP -> OP_MULTIPLY\n");;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 335 "grammar.y"
    {printf("\tReduced : unary_OP -> OP_PLUS\n");;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 336 "grammar.y"
    {printf("\tReduced : unary_OP -> OP_MINUS\n");;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 337 "grammar.y"
    {printf("\tReduced : unary_OP -> OP_TILDE\n");;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 338 "grammar.y"
    {printf("\tReduced : unary_OP -> OP_NOT\n");;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 341 "grammar.y"
    {printf("\tReduced : postfix_expression -> primary_expression\n");;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 342 "grammar.y"
    {printf("\tReduced : postfix_expression -> postfix_expression SQUARE_BRACKET_BEG expression SQUARE_BRACKET_END\n");;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 343 "grammar.y"
    {printf("\tReduced : postfix_expression -> postfix_expression PARANTHESIS_BEG argument_expression_list PARANTHESIS_END\n");;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 344 "grammar.y"
    {printf("\tReduced : postfix_expression -> postfix_expression PARANTHESIS_BEG PARANTHESIS_END\n");;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 345 "grammar.y"
    {printf("\tReduced : postfix_expression -> postfix_expression DOT IDENTIFIER\n");;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 346 "grammar.y"
    {printf("\tReduced : postfix_expression -> postfix_expression OP_LINK IDENTIFIER\n");;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 347 "grammar.y"
    {printf("\tReduced : postfix_expression -> postfix_expression OP_INCREMENTOR\n");;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 348 "grammar.y"
    {printf("\tReduced : postfix_expression -> postfix_expression OP_DECREMENTOR\n");;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 351 "grammar.y"
    {printf("\tReduced : primary_expression -> IDENTIFIER\n");;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 352 "grammar.y"
    {printf("\tReduced : primary_expression -> constant\n");;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 353 "grammar.y"
    {printf("\tReduced : primary_expression -> STRING_constANT\n");;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 354 "grammar.y"
    {printf("\tReduced : primary_expression -> PARANTHESIS_BEG expression PARANTHESIS_END\n");;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 357 "grammar.y"
    {printf("\tReduced : argument_expression_list -> assignment_expression\n");;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 358 "grammar.y"
    {printf("\tReduced : argument_expression_list -> argument_expression_list COMMA assignment_expression\n");;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 361 "grammar.y"
    {printf("\tReduced : constant -> NUMBER\n");;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 362 "grammar.y"
    {printf("\tReduced : constant -> CHAR _CONSTANT\n");;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 363 "grammar.y"
    {printf("\tReduced : constant -> REAL_NUMBER\n");;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 364 "grammar.y"
    {printf("\tReduced : constant -> EXP_NUMBER\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 3624 "grammar.tab.c"
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
#line 367 "grammar.y"


#include "lex.yy.c"
int yyerror()
{
    printf("\nERROR occurred\n");
}
int main(int argc,char *argv[])
{
        if(argc<2)
        {
                printf("Wrong input\n");
                return -1;
        }
        yyin = fopen(argv[1],"r");
        yyparse();
        fclose(yyin);
        return 0;
}

