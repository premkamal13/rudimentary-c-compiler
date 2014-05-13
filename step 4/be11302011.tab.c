
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
#line 1 "be11302011.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	FILE* fptr,*fptrs;
	extern line_num;
	char op_file_name[1001],missing[1001];
	int miss=0;
	char tempssstr[1001];
	char tempsss1tr[1001];
	int cnt=0,scs=0,f=0,tq=0,flag=0;
	int arr[]={0,1,4,16,64,1000,1004,4000,4004,4064,8000,8004,10000,11000,11004,14000,14004,18000,18004,200000};
	char names[][51]={"NONE","CHAR","INT","FLOAT","DOUBLE","SHORT","SHORT INT","LONG","LONG INT","LONG DOUBLE","LONG LONG","LONG LONG INT","SIGNED/UNSIGNED","S/US SHORT","S/US SHORT INT","S/US LONG","S/US LONG INT","S/US LONG LONG","S/US LONG LONG INT","VOID/struct/union"};

	void display()
	{
        int i;
        printf("Data-Types Mapping is as follows:\n");
        for(i=0;i<20;i++)
        {
            printf("%s = %d\n",names[i],arr[i]);
        }
        //printf("NONE = 0\n");
	}

	void spec()
	{
        if(scs==1)
        {
            f=1;
            yyerror();
        }
        scs=1;
	}

    int chk_type();

	int valid(int x)
	{
        int i;
        for(i=0;i<20;i++)
        {
            if(arr[i]==x) return 1;
        }
        return 0;
	}

	void func(int x)
	{
        cnt+=x;
        if(!valid(cnt))
        {
            f=2;
            yyerror();
        }
	}
	char arr1_name[11],var1_name[11],arr2_name[1001];

	int len=0,cur_type=0, equals_seen=0;
	int tt1=0,d1=0,ansid;
	char tempdim[101][101],ans[1001];
	char temp[101];
	char tempstr[101];
	struct lotus
	{
        char name[51];
        int data_type;
        int line_no;
        int sz;
        char val[51];
        char dimension[101];
        int arr_flag;
        int arr_sz;
	}symtab[1001];

	struct ic_lotus
    {
        char result[101];
        char op1[101],op2[101];
        char opname[101];
    }ic_code[10001];

    int idx=0;

    int duplicate(char *s)
    {
        int i;
        //printf("searched\n");
        for(i=1;i<=len;i++)
        {
            //printf("%d %d\n",i,len);
            //printf("%s\n",symtab[i].name);
            if(strcmp(symtab[i].name,s)==0) return 1;
        }
        return 0;
    }

    int present(char *s)//similar work as  duplicate
    {
        int i;
        for(i=1;i<=len;i++)
        {
            if(strcmp(symtab[i].name,s)==0) return 1;
        }
        return 0;
    }

    int found_arr_name=0;

    int is_it_array(char * astr)
    {
        int i;
        for(i=0;i<=len;i++)
        {
            if(strcmp(astr,symtab[i].name)==0)
            {
                return (symtab[i].arr_sz);
            }
        }
        return 0;
    }

    void fill_dimensions()
	{
	    int i,j,m;
	    for(i=0;i<=len;i++)
	    {
	        int dim=symtab[i].arr_sz;
            if(dim>=1)
            {
                //printf("dim>=1 yahan\n");
                if(miss==0)
                {
                    for(j=0;j<4 && j<strlen(symtab[i].val);j++)
                    {
                        if(symtab[i].val[j]==' ') break;
                        missing[m++]=symtab[i].val[j];
                    }
                    missing[m]='\0';
                    if(m!=0) miss=1;
                }
                symtab[i].arr_flag=dim;
                int k=0,l,cnt1=0,vlen=strlen(symtab[i].val);
                l=0;
                while(cnt1<dim)
                {
                    for(;k<vlen;k++)
                    {
                        if(symtab[i].val[k]==' ')
                            break;
                    }
                    k++;
                    //l=0;
                    while(k<vlen && symtab[i].val[k]!=' ')
                    {
                        tempstr[l]=symtab[i].val[k];
                        l++;
                        k++;
                    }
                    tempstr[l++]=' ';
                    cnt1++;
                }
                tempstr[l]='\0';
                strcpy(symtab[i].dimension,tempstr);
            }
            else if(symtab[i].arr_flag>0)
            {
                //printf("dim==0\n");
                symtab[i].sz=0;
                int k,found=0;
                for(k=0;k<strlen(symtab[i].val);k++)
                {
                    if(symtab[i].val[k]==' ')
                        symtab[i].sz++;
                    if(symtab[i].val[k]>47 && symtab[i].val[k]<123) found=1;
                }
                sprintf(symtab[i].dimension,"%d",symtab[i].sz);
                symtab[i].arr_sz=1;
            }
        }
    }

    char varname[1001],vartmp1[101],labelname[1001];

    int i,varcnt=1,labelcnt=1;
    void new_var()
    {
        //namings like L_000001.
        varname[0]='t';
        varname[1]='_';
        varname[2]='0';
        varname[3]='0';
        varname[4]='0';
        varname[5]='0';
        varname[6]='0';
        sprintf(vartmp1,"%d",varcnt);
        int x=strlen(vartmp1);
        for(i=0;i<x;i++) varname[7+i]=vartmp1[i];
        varname[7+i]='\0';
        //printf("%s\n",varname);
        varcnt++;
    }

    void new_label()
    {
        //namings like foo_00_1.// changed to the require format t_000001
        labelname[0]='L';
        labelname[1]='_';
        labelname[2]='0';
        labelname[3]='0';
        labelname[4]='0';
        labelname[5]='0';
        labelname[6]='0';
        sprintf(vartmp1,"%d",labelcnt);
        int x=strlen(vartmp1);
        for(i=0;i<x;i++) labelname[7+i]=vartmp1[i];
        labelname[7+i]='\0';
        //printf("%s\n",varname);
        labelcnt++;
    }


    int nonnum[101],dimfound=0;
    char symtabdim_list[101][101],cur_var[101];
    int calc_value(int dtt)
    {
        if(dtt==1 || dtt==1000) return 1;
        else if(dtt==4) return 4;
        else if(dtt==16) return 4;
        else if(dtt==64) return 8;
        else if(dtt==4000) return 8;
        else if(dtt==8000) return 16;
        return 16;
    }

    void gen_imm_code(int loc)
    {
        int d2=0,d3=0;
        char imm_var1[101],imm_var2[101];
        new_var();
        fprintf(fptr,"%s = 0\n",varname);

        strcpy(ic_code[idx].result,varname);
        strcpy(ic_code[idx].op1,"0");
        strcpy(ic_code[idx].opname,"EQUAL_TO");
        strcpy(ic_code[idx].op2,"NA");
        idx++;

        strcpy(imm_var1,varname);
        //printf("asdfjh %d\n",d1);
        while(d3<d1)
        {
            //printf("in loopwa\n");
            new_var();
            fprintf(fptr,"%s = %s\n",varname,tempdim[d3]);

            strcpy(ic_code[idx].result,varname);
            strcpy(ic_code[idx].op1,tempdim[d3]);
            strcpy(ic_code[idx].opname,"EQUAL_TO");
            strcpy(ic_code[idx].op2,"NA");
            idx++;

            strcpy(imm_var2,varname);
            if(d2<d1)
            {
                int d4=d2+1;
                while(d4<d1)
                {
                    fprintf(fptr,"%s = %s * %s\n",varname,varname,symtabdim_list[d4]);

                    strcpy(ic_code[idx].result,varname);
                    strcpy(ic_code[idx].op1,varname);
                    strcpy(ic_code[idx].opname,"MUL");
                    strcpy(ic_code[idx].op2,symtabdim_list[d4]);
                    idx++;

                    d4++;
                }
            }
            fprintf(fptr,"%s = %s + %s\n",imm_var1,imm_var1,imm_var2);

            strcpy(ic_code[idx].result,imm_var1);
            strcpy(ic_code[idx].op1,imm_var1);
            strcpy(ic_code[idx].opname,"ADD");
            strcpy(ic_code[idx].op2,imm_var2);
            idx++;

            d3++;
            d2++;
        }

        char tempstr2[1001];
        sprintf(tempstr2,"%d",calc_value(symtab[loc].data_type));
        fprintf(fptr,"%s = %s * %s\n",imm_var1,imm_var1,tempstr2);

        strcpy(ic_code[idx].result,imm_var1);
        strcpy(ic_code[idx].op1,imm_var1);
        strcpy(ic_code[idx].opname,"MUL");
        strcpy(ic_code[idx].op2,tempstr2);
        idx++;

        strcpy(cur_var,imm_var1);
    }

    void check_valid_dim(int loc)
    {
        printf(">>>>>>>inside this :%d %d\n",loc,dimfound);
        int i,j;
        if(dimfound) return;
        printf(">>>>>>>inside this :%d %d\n",d1,symtab[loc].arr_sz);
        if(symtab[loc].arr_sz>d1) {}// printf("%d %d\n",symtab[loc].arr_sz,d1);}// yyerror();}
        else if(symtab[loc].arr_sz<d1) {}// printf("%d %d\n",symtab[loc].arr_sz,d1); }//yyerror();}
        else
        {
            printf("#!#!dimension matched\n");
            dimfound=1;
            int tk=0,k1=0;
            //printf(">symtab_dimension %d: %s %d\n",loc,symtab[loc].name,symtab[loc].arr_sz);
            puts(symtab[loc].dimension);
            for(i=0;i<d1;i++)
            {
                nonnum[i]=0;
                int x=strlen(tempdim[i]);
                for(j=0;j<x;j++)
                {
                    if(tempdim[i][j]<'0' || tempdim[i][j]>'9') nonnum[i]=1;
                }
                k1=0;
                while(symtab[loc].dimension[tk]!=' ' && symtab[loc].dimension[tk]!='\0') {tempstr[k1++]= symtab[loc].dimension[tk]; tk++;}
                tempstr[k1]='\0';
                tk++;
                strcpy(symtabdim_list[i],tempstr);
                if(nonnum[i]==0)
                {
                    int dim1= atoi(tempstr);
                    int dim2= atoi(tempdim[i]);
                    //printf(">dim>>> %d %d %d\n",i,dim1,dim2);
                    if(dim1<=dim2) {f=7; yyerror();}
                }
            }
            gen_imm_code(loc);
            d1=0;
        }
        //dimfound=0;
    }


    void if_match_print(char * tmp)
    {
        if(dimfound==1) return;
        i=0;
        for(i=0;i<=len;i++)
        {
            if(strcmp(tmp,symtab[i].name)==0)
            {
                tt1=0;
                check_valid_dim(i);
            }
        }
    }

    char label_stack[1001][101];
    int top=0;

    char filled_up[1001][1001];
    int fu=0;

    char tempiflabel[1001];



/* Line 189 of yacc.c  */
#line 445 "be11302011.tab.c"

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
     EXTERN = 269,
     FLOAT = 270,
     FOR = 271,
     GOTO = 272,
     IF = 273,
     INT = 274,
     LONG = 275,
     REGISTER = 276,
     RETURN = 277,
     SHORT = 278,
     SIGNED = 279,
     SIZEOF = 280,
     STATIC = 281,
     STRUCT = 282,
     SWITCH = 283,
     TYPEDEF = 284,
     UNION = 285,
     UNSIGNED = 286,
     VOID = 287,
     VOLATILE = 288,
     WHILE = 289,
     OPERATOR_PLUS = 290,
     OPERATOR_MINUS = 291,
     OPERATOR_INCREMENTOR = 292,
     OPERATOR_DECREMENTOR = 293,
     OPERATOR_ADDER = 294,
     OPERATOR_SUBTRACTOR = 295,
     OPERATOR_MULTIPLIER = 296,
     OPERATOR_DIVIDER = 297,
     OPERATOR_MULTIPLY = 298,
     OPERATOR_DIVIDE = 299,
     OPERATOR_ASSIGNMENT = 300,
     OPERATOR_SLASH = 301,
     OPERATOR_MODULUS = 302,
     OPERATOR_LESS_THAN = 303,
     OPERATOR_GREATER_THAN = 304,
     OPERATOR_NOT = 305,
     OPERATOR_BITWISE_AND = 306,
     OPERATOR_BITWISE_OR = 307,
     OPERATOR_AND = 308,
     OPERATOR_OR = 309,
     OPERATOR_BITWISE_XOR = 310,
     OPERATOR_TILDE = 311,
     OPERATOR_EQUALITY_CHECKER = 312,
     OPERATOR_AND_ASSIGNMENT = 313,
     OPERATOR_OR_ASSIGNMENT = 314,
     OPERATOR_LESS_OR_EQUAL = 315,
     OPERATOR_GREATER_OR_EQUAL = 316,
     OPERATOR_NOT_EQUAL = 317,
     OPERATOR_LINK = 318,
     OPERATOR_BITWISE_XOR_ASSIGNMENT = 319,
     OPERATOR_RIGHT_SHIFT = 320,
     OPERATOR_LEFT_SHIFT = 321,
     OPERATOR_LEFT_ASSIGNMENT = 322,
     OPERATOR_RIGHT_ASSIGNMENT = 323,
     THREE_DOTS = 324,
     OPERATOR_MOD_ASSIGNMENT = 325,
     DOT = 326,
     SQUARE_BRACKET_BEG = 327,
     SQUARE_BRACKET_END = 328,
     CURLY_BRACKET_BEG = 329,
     CURLY_BRACKET_END = 330,
     PARANTHESIS_BEG = 331,
     PARANTHESIS_END = 332,
     COMMA = 333,
     COLON = 334,
     SEMICOLON = 335,
     SHARP = 336,
     DOUBLE_QUOTES = 337,
     TERNARY = 338,
     NUMBER = 339,
     REAL_NUMBER = 340,
     EXP_NUMBER = 341,
     CHAR_CONSTANT = 342,
     STRING_CONSTANT = 343,
     IDENTIFIER = 344
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 386 "be11302011.y"

        int type;
        struct lotus values;
        char varstr[1001];
      


/* Line 214 of yacc.c  */
#line 578 "be11302011.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 590 "be11302011.tab.c"

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
#define YYLAST   1813

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNRULES -- Number of states.  */
#define YYNSTATES  380

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
     353,   358,   362,   366,   369,   371,   374,   375,   383,   389,
     390,   394,   395,   396,   404,   412,   422,   431,   440,   448,
     457,   465,   473,   480,   481,   485,   488,   491,   495,   498,
     500,   504,   506,   510,   512,   514,   516,   518,   520,   522,
     524,   526,   528,   530,   532,   534,   540,   542,   544,   548,
     550,   554,   556,   560,   562,   566,   568,   572,   574,   578,
     582,   584,   588,   592,   596,   600,   602,   606,   610,   612,
     616,   620,   622,   626,   630,   634,   636,   641,   643,   646,
     649,   652,   655,   660,   662,   664,   666,   668,   670,   672,
     674,   679,   684,   688,   692,   696,   699,   702,   704,   706,
     708,   712,   714,   718,   720,   722,   724
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      91,     0,    -1,    92,    -1,    91,    92,    -1,    93,    -1,
      94,    -1,    96,   112,    95,   128,    -1,   112,    95,   128,
      -1,    96,   112,   128,    -1,   112,   128,    -1,    96,   103,
      80,    -1,    96,    80,    -1,    94,    -1,    95,    94,    -1,
      97,    96,    -1,    97,    -1,    98,    96,    -1,    98,    -1,
      99,    96,    -1,    99,    -1,     3,    -1,    21,    -1,    26,
      -1,    14,    -1,    29,    -1,    32,    -1,     6,    -1,    19,
      -1,    15,    -1,    11,    -1,    23,    -1,    20,    -1,    24,
      -1,    31,    -1,   100,    -1,   109,    -1,     7,    -1,    33,
      -1,   101,    89,    74,   102,    75,    -1,   101,    74,   102,
      75,    -1,   101,    89,    -1,    27,    -1,    30,    -1,   105,
      -1,   102,   105,    -1,   104,    -1,   103,    78,   104,    -1,
     112,    -1,   112,    45,   120,    -1,   106,   107,    80,    -1,
      98,   106,    -1,    98,    -1,    99,   106,    -1,    99,    -1,
     108,    -1,   107,    78,   108,    -1,   112,    -1,   112,    79,
     142,    -1,    79,   142,    -1,    13,    89,    74,   110,    75,
      -1,    13,    74,   110,    75,    -1,    13,    89,    -1,   111,
      -1,   110,    78,   111,    -1,    89,    -1,    89,    45,   142,
      -1,   114,   113,    -1,   113,    -1,    89,    -1,    76,   112,
      77,    -1,   113,    72,   142,    73,    -1,   113,    72,    73,
      -1,   113,    76,   116,    77,    -1,   113,    76,   119,    77,
      -1,   113,    76,    77,    -1,    43,   115,    -1,    43,    -1,
      43,   115,   114,    -1,    43,   114,    -1,    99,    -1,   115,
      99,    -1,   117,    -1,   117,    78,    69,    -1,   118,    -1,
     117,    78,   118,    -1,    96,   112,    -1,    96,   123,    -1,
      96,    -1,    89,    -1,   119,    78,    89,    -1,   139,    -1,
      74,   121,    75,    -1,    74,   121,    78,    75,    -1,   120,
      -1,   121,    78,   120,    -1,   106,   123,    -1,   106,    -1,
     114,    -1,   114,   124,    -1,   124,    -1,    76,   123,    77,
      -1,   124,    72,   142,    73,    -1,    72,   142,    73,    -1,
     124,    72,    73,    -1,    72,    73,    -1,   124,    76,   116,
      77,    -1,    76,   116,    77,    -1,   124,    76,    77,    -1,
      76,    77,    -1,   126,    -1,   127,    -1,   128,    -1,   130,
      -1,   134,    -1,   137,    -1,    89,    79,   125,    -1,     5,
     142,    79,   125,    -1,     9,    79,   125,    -1,   138,    80,
      -1,    80,    -1,    74,    95,   129,    75,    -1,    74,    95,
      75,    -1,    74,   129,    75,    -1,    74,    75,    -1,   125,
      -1,   129,   125,    -1,    -1,    18,    76,   138,    77,   131,
     125,   132,    -1,    28,    76,   138,    77,   125,    -1,    -1,
      12,   133,   125,    -1,    -1,    -1,    34,   136,    76,   138,
      77,   135,   125,    -1,    10,   125,    34,    76,   138,    77,
      80,    -1,    16,    76,   138,    80,   138,    80,   138,    77,
     125,    -1,    16,    76,   138,    80,   138,    80,    77,   125,
      -1,    16,    76,   138,    80,    80,   138,    77,   125,    -1,
      16,    76,   138,    80,    80,    77,   125,    -1,    16,    76,
      80,   138,    80,   138,    77,   125,    -1,    16,    76,    80,
     138,    80,    77,   125,    -1,    16,    76,    80,    80,   138,
      77,   125,    -1,    16,    76,    80,    80,    77,   125,    -1,
      -1,    17,    89,    80,    -1,     8,    80,    -1,     4,    80,
      -1,    22,   138,    80,    -1,    22,    80,    -1,   139,    -1,
     138,    78,   139,    -1,   141,    -1,   154,   140,   139,    -1,
      45,    -1,    41,    -1,    42,    -1,    70,    -1,    39,    -1,
      40,    -1,    67,    -1,    68,    -1,    58,    -1,    64,    -1,
      59,    -1,   143,    -1,   143,    83,   138,    79,   141,    -1,
     141,    -1,   144,    -1,   143,    54,   144,    -1,   145,    -1,
     144,    53,   145,    -1,   146,    -1,   145,    52,   146,    -1,
     147,    -1,   146,    55,   147,    -1,   148,    -1,   147,    51,
     148,    -1,   149,    -1,   148,    57,   149,    -1,   148,    62,
     149,    -1,   150,    -1,   149,    48,   150,    -1,   149,    49,
     150,    -1,   149,    60,   150,    -1,   149,    61,   150,    -1,
     151,    -1,   150,    66,   151,    -1,   150,    65,   151,    -1,
     152,    -1,   151,    35,   152,    -1,   151,    36,   152,    -1,
     153,    -1,   152,    43,   153,    -1,   152,    44,   153,    -1,
     152,    47,   153,    -1,   154,    -1,    76,   122,    77,   153,
      -1,   156,    -1,    37,   154,    -1,    38,   154,    -1,   155,
     153,    -1,    25,   154,    -1,    25,    76,   122,    77,    -1,
      51,    -1,    43,    -1,    35,    -1,    36,    -1,    56,    -1,
      50,    -1,   157,    -1,   156,    72,   138,    73,    -1,   156,
      76,   158,    77,    -1,   156,    76,    77,    -1,   156,    71,
      89,    -1,   156,    63,    89,    -1,   156,    37,    -1,   156,
      38,    -1,    89,    -1,   159,    -1,    88,    -1,    76,   138,
      77,    -1,   139,    -1,   158,    78,   139,    -1,    84,    -1,
      87,    -1,    85,    -1,    86,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   403,   403,   404,   407,   408,   411,   412,   413,   414,
     417,   418,   421,   422,   425,   426,   427,   428,   429,   430,
     433,   434,   435,   436,   437,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   453,   454,   457,   458,
     459,   462,   463,   466,   467,   470,   471,   474,   475,   478,
     485,   486,   487,   488,   491,   492,   494,   495,   496,   499,
     500,   501,   504,   505,   508,   509,   512,   513,   516,   535,
     536,   543,   550,   551,   552,   555,   556,   557,   558,   561,
     562,   565,   566,   569,   570,   573,   574,   575,   578,   579,
     582,   583,   584,   587,   588,   591,   592,   595,   596,   597,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   612,
     613,   614,   615,   616,   617,   620,   621,   622,   625,   626,
     629,   630,   631,   632,   635,   636,   640,   639,   656,   660,
     659,   711,   730,   729,   766,   767,   768,   769,   770,   771,
     772,   773,   774,   777,   791,   792,   793,   794,   795,   798,
     803,   810,   815,   945,   946,   947,   948,   949,   950,   951,
     952,   953,   954,   955,   958,   959,   962,   965,   966,   982,
     983,   999,  1000,  1009,  1010,  1026,  1027,  1042,  1043,  1088,
    1135,  1136,  1181,  1226,  1271,  1318,  1319,  1333,  1349,  1354,
    1368,  1384,  1389,  1403,  1417,  1433,  1434,  1441,  1442,  1455,
    1468,  1482,  1483,  1486,  1487,  1488,  1489,  1490,  1491,  1494,
    1495,  1551,  1552,  1553,  1554,  1555,  1578,  1602,  1614,  1615,
    1620,  1623,  1624,  1627,  1633,  1638,  1643
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INT", "LONG", "REGISTER", "RETURN", "SHORT",
  "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION",
  "UNSIGNED", "VOID", "VOLATILE", "WHILE", "OPERATOR_PLUS",
  "OPERATOR_MINUS", "OPERATOR_INCREMENTOR", "OPERATOR_DECREMENTOR",
  "OPERATOR_ADDER", "OPERATOR_SUBTRACTOR", "OPERATOR_MULTIPLIER",
  "OPERATOR_DIVIDER", "OPERATOR_MULTIPLY", "OPERATOR_DIVIDE",
  "OPERATOR_ASSIGNMENT", "OPERATOR_SLASH", "OPERATOR_MODULUS",
  "OPERATOR_LESS_THAN", "OPERATOR_GREATER_THAN", "OPERATOR_NOT",
  "OPERATOR_BITWISE_AND", "OPERATOR_BITWISE_OR", "OPERATOR_AND",
  "OPERATOR_OR", "OPERATOR_BITWISE_XOR", "OPERATOR_TILDE",
  "OPERATOR_EQUALITY_CHECKER", "OPERATOR_AND_ASSIGNMENT",
  "OPERATOR_OR_ASSIGNMENT", "OPERATOR_LESS_OR_EQUAL",
  "OPERATOR_GREATER_OR_EQUAL", "OPERATOR_NOT_EQUAL", "OPERATOR_LINK",
  "OPERATOR_BITWISE_XOR_ASSIGNMENT", "OPERATOR_RIGHT_SHIFT",
  "OPERATOR_LEFT_SHIFT", "OPERATOR_LEFT_ASSIGNMENT",
  "OPERATOR_RIGHT_ASSIGNMENT", "THREE_DOTS", "OPERATOR_MOD_ASSIGNMENT",
  "DOT", "SQUARE_BRACKET_BEG", "SQUARE_BRACKET_END", "CURLY_BRACKET_BEG",
  "CURLY_BRACKET_END", "PARANTHESIS_BEG", "PARANTHESIS_END", "COMMA",
  "COLON", "SEMICOLON", "SHARP", "DOUBLE_QUOTES", "TERNARY", "NUMBER",
  "REAL_NUMBER", "EXP_NUMBER", "CHAR_CONSTANT", "STRING_CONSTANT",
  "IDENTIFIER", "$accept", "translation_unit", "external_declaration",
  "function_definition", "declaration", "declaration_list",
  "declaration_specifiers", "storage_class_specifier", "type_specifier",
  "type_qualifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "init_declarator_list", "init_declarator",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "declarator", "direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "initializer", "initializer_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "statement", "labeled_statement",
  "expression_statement", "compound_statement", "statement_list",
  "selection_statement", "$@1", "else_selection_statement", "$@2",
  "iteration_statement", "$@3", "print_while", "jump_statement",
  "expression", "assignment_expression", "assignment_operator",
  "conditional_expression", "constant_expression", "logical_OR_expression",
  "logical_AND_expression", "inclusive_OR_expression",
  "exclusive_OR_expression", "AND_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression",
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
     128,   128,   128,   128,   129,   129,   131,   130,   130,   133,
     132,   132,   135,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   136,   137,   137,   137,   137,   137,   138,
     138,   139,   139,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   142,   143,   143,   144,
     144,   145,   145,   146,   146,   147,   147,   148,   148,   148,
     149,   149,   149,   149,   149,   150,   150,   150,   151,   151,
     151,   152,   152,   152,   152,   153,   153,   154,   154,   154,
     154,   154,   154,   155,   155,   155,   155,   155,   155,   156,
     156,   156,   156,   156,   156,   156,   156,   157,   157,   157,
     157,   158,   158,   159,   159,   159,   159
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
       4,     3,     3,     2,     1,     2,     0,     7,     5,     0,
       3,     0,     0,     7,     7,     9,     8,     8,     7,     8,
       7,     7,     6,     0,     3,     2,     2,     3,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     4,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     3,     3,     3,     2,     2,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    26,    36,    29,     0,    23,    28,    27,    31,
      21,    30,    32,    22,    41,    24,    42,    33,    25,    37,
      76,     0,    68,     0,     2,     4,     5,     0,    15,    17,
      19,    34,     0,    35,     0,    67,     0,     0,    61,    79,
      78,    75,     0,     1,     3,    11,     0,    45,    47,    14,
      16,    18,     0,    40,     0,    12,     0,     0,     9,     0,
       0,    66,    64,     0,    62,     0,    80,    77,    69,     0,
      10,     0,     0,     8,    51,    53,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   205,   206,     0,     0,   204,   208,   203,   207,
     123,     0,   119,   223,   225,   226,   224,   219,   217,     0,
     124,   109,   110,   111,     0,   112,   113,   114,     0,   149,
     151,   164,   167,   169,   171,   173,   175,   177,   180,   185,
     188,   191,   195,     0,   197,   209,   218,    13,     7,    47,
      71,   217,   166,     0,   195,    74,    88,    87,     0,    81,
      83,     0,     0,    60,     0,     0,    46,     0,    48,    90,
       6,    50,    52,    39,    44,     0,     0,    54,    56,     0,
     146,     0,   145,     0,     0,     0,     0,     0,   148,     0,
       0,   201,     0,     0,     0,   198,   199,    96,     0,     0,
       0,   121,     0,   122,   125,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   154,   155,
     153,   161,   163,   162,   159,   160,   156,     0,   200,   215,
     216,     0,     0,     0,     0,    70,     0,     0,    85,    97,
      86,    99,    72,     0,    73,     0,    65,    63,    59,    93,
       0,    58,     0,    49,     0,    38,     0,   117,     0,     0,
       0,   144,     0,   147,     0,     0,     0,     0,    97,    95,
       0,   220,   115,   120,   150,   168,     0,   170,   172,   174,
     176,   178,   179,   181,   182,   183,   184,   187,   186,   189,
     190,   192,   193,   194,   152,   214,   213,     0,   212,   221,
       0,   104,     0,   108,     0,     0,    98,     0,     0,    82,
      84,    89,    91,     0,    55,    57,   116,     0,     0,     0,
       0,   126,   202,     0,     0,   196,     0,   210,   211,     0,
     102,   106,   100,   103,     0,   107,     0,    92,    94,     0,
       0,     0,     0,     0,     0,     0,   128,   132,   165,   222,
     101,   105,     0,   142,     0,     0,     0,     0,     0,     0,
     131,     0,   134,   141,   140,     0,   138,     0,     0,     0,
     129,   127,   133,   139,   137,   136,     0,     0,   135,   130
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    55,    56,    57,    28,    29,    30,
      31,    32,    76,    46,    47,    77,    78,   166,   167,    33,
      63,    64,    34,    35,    36,    41,   304,   149,   150,   151,
     158,   250,   188,   305,   241,   110,   111,   112,   113,   114,
     115,   345,   371,   377,   116,   361,   183,   117,   118,   119,
     227,   120,   143,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   300,   136
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -219
static const yytype_int16 yypact[] =
{
     581,  -219,  -219,  -219,  -219,    28,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
      30,    27,  -219,   299,  -219,  -219,  -219,   -24,  1780,  1780,
    1780,  -219,    32,  -219,  1067,   -54,   -51,   -69,   -31,  -219,
    -219,    30,   -45,  -219,  -219,  -219,    14,  -219,  1034,  -219,
    -219,  -219,   744,     1,   376,  -219,  1067,   -24,  -219,  1118,
     340,   -54,    36,    59,  -219,   -69,  -219,  -219,  -219,    27,
    -219,  1173,  1067,  -219,   744,   744,   497,  -219,   -35,   744,
      21,  1621,    40,     4,   796,    72,    54,    94,  1190,  1638,
     112,  -219,  -219,  -219,  1693,  1693,  -219,  -219,  -219,  -219,
    -219,   880,  -219,  -219,  -219,  -219,  -219,  -219,    56,   463,
    -219,  -219,  -219,  -219,   624,  -219,  -219,  -219,    46,  -219,
    -219,   -43,   146,   158,   149,   168,     2,    79,   130,   180,
      86,  -219,   887,  1621,    75,  -219,  -219,  -219,  -219,   187,
    -219,  -219,  -219,   162,  -219,  -219,  -219,     8,   145,   147,
    -219,   140,  1621,  -219,   -69,    67,  -219,  1173,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  1621,   100,  -219,   163,   658,
    -219,   170,  -219,   796,   218,  1246,   176,  1621,  -219,   113,
     880,  -219,  1621,   190,  1621,  -219,  -219,   -10,   191,   143,
     796,  -219,   710,  -219,  -219,  1621,  -219,  1621,  1621,  1621,
    1621,  1621,  1621,  1621,  1621,  1621,  1621,  1621,  1621,  1621,
    1621,  1621,  1621,  1621,  1621,  1621,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  1621,  -219,  -219,
    -219,   181,   194,  1621,  1263,  -219,  1318,   550,  -219,   -15,
    -219,    -4,  -219,  1098,  -219,   197,  -219,  -219,  -219,  -219,
      99,  -219,   -35,  -219,  1621,  -219,   796,  -219,   216,  1342,
     122,  -219,   150,  -219,   227,   152,  1621,   967,    39,  -219,
    1621,  -219,  -219,  -219,  -219,   146,   160,   158,   149,   168,
       2,    79,    79,   130,   130,   130,   130,   180,   180,    86,
      86,  -219,  -219,  -219,  -219,  -219,  -219,    -2,  -219,  -219,
     167,  -219,   234,  -219,   232,   238,    -4,  1398,   998,  -219,
    -219,  -219,  -219,  1101,  -219,  -219,  -219,  1621,  1422,   125,
    1477,  -219,  -219,   796,   177,  -219,  1621,  -219,  -219,  1621,
    -219,  -219,  -219,  -219,   243,  -219,   240,  -219,  -219,   186,
     796,   199,  1494,  1549,   131,   796,  -219,  -219,  -219,  -219,
    -219,  -219,   231,  -219,   796,   796,   203,   796,   211,  1566,
     309,   796,  -219,  -219,  -219,   796,  -219,   796,   796,   213,
    -219,  -219,  -219,  -219,  -219,  -219,   796,   796,  -219,  -219
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,   301,  -219,    13,    71,     0,  -219,     3,   172,
    -219,  -219,   248,  -219,   264,   -70,   -48,  -219,    82,  -219,
     270,   182,   -11,   -33,    -6,  -219,   -55,  -219,    95,  -219,
    -142,  -219,   157,  -138,  -218,   -83,  -219,  -219,   142,   230,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,   -84,   -26,
    -219,   -57,   -42,  -219,   148,   141,   144,   155,   156,    92,
     -21,    88,    89,  -126,   -47,  -219,  -219,  -219,  -219,  -219
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      27,   174,   142,    61,   179,   148,   164,   228,    20,   240,
      42,   197,   144,    26,    40,   249,    48,   189,    59,    20,
      62,   306,    60,    27,   142,    21,   161,   162,    49,    50,
      51,   194,    68,    20,   144,    67,    26,     3,    22,   171,
     198,    21,   181,    65,   165,   159,   139,   185,   186,   269,
     306,    20,    21,   187,    22,    74,    45,   236,   139,   203,
     147,   237,   236,    19,   204,    22,   267,   168,   307,   137,
      20,   327,   308,    20,    22,    79,   195,    74,    74,    74,
     236,   152,    74,   173,   237,   137,   144,   291,   292,   293,
     257,   260,    69,   262,    70,   142,   189,    22,   265,   164,
     189,   170,    37,    21,    74,   144,    52,   272,   142,   194,
     246,   236,   229,   230,   276,   267,    22,    38,   144,    72,
     172,    53,   137,   251,   195,   109,   196,   205,   206,   213,
     214,   159,   187,   215,   153,   190,   238,   154,   231,   207,
     208,   239,   248,   176,   325,   154,   232,   233,   175,   297,
     144,   234,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   274,
     177,   338,    74,   316,   312,   319,    58,   313,   252,   142,
     253,   268,   324,    74,   283,   284,   285,   286,   182,   144,
      73,   195,    39,   263,   302,   209,   210,   142,   138,   199,
     195,   294,   320,   195,   201,   342,    61,   144,   299,   195,
     200,   359,   315,    66,   160,   211,   212,   244,   245,   202,
     271,   195,   242,   144,    75,   243,    42,   321,   195,   323,
     195,   239,    71,   339,   341,   235,   344,   147,   195,   326,
     346,   168,   254,   147,   328,   329,    75,    75,    75,   256,
     142,    75,   258,   336,   347,   195,   261,   353,   356,   358,
     144,   268,   360,   352,   195,   334,   266,   147,   270,   348,
     295,   363,   364,    75,   366,   369,   354,   195,   372,   144,
     365,   195,   373,   296,   374,   375,   311,   159,   367,   195,
     376,   195,   317,   378,   379,   281,   282,   287,   288,    43,
     289,   290,     1,   349,   322,     2,     3,   330,   147,   331,
       4,   362,     5,     6,     7,   332,   350,   351,     8,     9,
      10,   370,    11,    12,    44,    13,    14,   169,    15,    16,
      17,    18,    19,   156,   314,   155,   247,   264,   310,   192,
     277,    75,    20,     1,   278,   275,     2,     3,     0,     0,
       0,     4,    75,     5,     6,     7,   279,     0,   280,     8,
       9,    10,     0,    11,    12,     0,    13,    14,     0,    15,
      16,    17,    18,    19,     0,    21,     0,     0,     0,     1,
      80,    81,     2,     3,    82,    83,    84,     4,    22,     5,
       6,     7,    85,    86,    87,     8,     9,    10,    88,    11,
      12,    89,    13,    14,    90,    15,    16,    17,    18,    19,
      91,    92,    93,    94,    95,     0,     0,   145,     0,    96,
       0,     0,     0,     0,     0,     0,    97,    98,     0,   146,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,   100,   101,     0,     0,     0,   102,     0,     0,     0,
     103,   104,   105,   106,   107,   108,     1,    80,    81,     2,
       3,    82,    83,    84,     4,     0,     5,     6,     7,    85,
      86,    87,     8,     9,    10,    88,    11,    12,    89,    13,
      14,    90,    15,    16,    17,    18,    19,    91,    92,    93,
      94,    95,     0,     2,     3,     0,    96,     0,     4,     0,
       5,     0,     7,    97,    98,     0,     8,     9,     0,    99,
      11,    12,     0,     0,    14,     0,     0,    16,    17,    18,
      19,     0,     0,     0,     0,     0,     0,    54,   191,   101,
       0,     0,     0,   102,     0,     0,     0,   103,   104,   105,
     106,   107,   108,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,   163,    11,    12,     0,    13,    14,     0,    15,
      16,    17,    18,    19,     1,     0,     0,     2,     3,     0,
       0,     0,     4,    20,     5,     6,     7,     0,     0,     0,
       8,     9,    10,     0,    11,    12,     0,    13,    14,     0,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    20,     0,   237,   303,    80,    81,
       0,     0,    82,    83,    84,     0,     0,     0,     0,    22,
      85,    86,    87,     0,     0,     0,    88,     0,     0,    89,
       0,     0,    90,     0,     0,     0,     0,    21,    91,    92,
      93,    94,    95,     0,     2,     3,     0,    96,     0,     4,
      22,     5,     0,     7,    97,    98,     0,     8,     9,     0,
      99,    11,    12,     0,     0,    14,     0,     0,    16,    17,
      18,    19,     0,     0,     0,     0,     0,     0,    54,   193,
     101,     0,     0,     0,   102,     0,     0,     0,   103,   104,
     105,   106,   107,   108,    80,    81,     0,     0,    82,    83,
      84,     0,     0,     0,     0,     0,    85,    86,    87,     0,
       0,     0,    88,   255,     0,    89,     0,     0,    90,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,     0,
       2,     3,     0,    96,     0,     4,     0,     5,     0,     7,
      97,    98,     0,     8,     9,     0,    99,    11,    12,     0,
       0,    14,     0,     0,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,    54,   273,   101,     0,     0,     0,
     102,     0,     0,     0,   103,   104,   105,   106,   107,   108,
      80,    81,     0,     0,    82,    83,    84,     0,     0,     0,
       0,     0,    85,    86,    87,     0,     0,     0,    88,     0,
       0,    89,     0,     0,    90,     0,     0,     0,     0,     0,
      91,    92,    93,    94,    95,     0,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,   101,     0,     0,     0,   102,     0,     0,     0,
     103,   104,   105,   106,   107,   108,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     7,     0,     0,     0,     8,
       9,     0,     0,    11,    12,    89,     0,    14,     0,     0,
      16,    17,    18,    19,     0,    92,    93,    94,    95,     0,
       0,     0,     0,    96,     0,     0,   216,   217,   218,   219,
      97,    98,   220,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,   221,   222,     0,     0,     0,
       0,   223,     0,     0,   224,   225,   101,   226,     0,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   141,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,     0,
      11,    12,     0,    13,    14,     0,    15,    16,    17,    18,
      19,     1,     0,     0,     2,     3,     0,     0,     0,     4,
      20,     5,     6,     7,     0,     0,     0,     8,     9,    10,
       0,    11,    12,     0,    13,    14,     0,    15,    16,    17,
      18,    19,     0,     0,     0,     0,     0,     1,     0,   236,
       2,     3,     0,   267,   303,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,     0,    11,    12,     0,
      13,    14,     0,    15,    16,    17,    18,    19,     0,     0,
       1,     0,     0,     2,     3,   335,     0,     0,     4,    71,
       5,     6,     7,     0,     0,     0,     8,     9,    10,     0,
      11,    12,     0,    13,    14,     0,    15,    16,    17,    18,
      19,     1,     0,     0,     2,     3,     0,     0,    54,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
       0,    11,    12,     0,    13,    14,    89,    15,    16,    17,
      18,    19,     0,     0,     0,     0,    92,    93,    94,    95,
       0,    54,     0,    89,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    92,    93,    94,    95,    99,     0,     0,
       0,    96,     0,     0,     0,     0,     0,   309,    97,    98,
       0,     0,     0,     0,    99,   157,   337,   101,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     141,   140,     0,     0,   101,     0,     0,     0,    89,     0,
       0,     0,   103,   104,   105,   106,   107,   141,    92,    93,
      94,    95,     0,     0,     0,    89,    96,     0,     0,     0,
       0,     0,     0,    97,    98,    92,    93,    94,    95,    99,
       0,     0,     0,    96,     0,     0,     0,     0,     0,     0,
      97,    98,     0,     0,     0,     0,    99,   157,     0,   101,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   141,     0,     0,     0,   101,     0,     0,     0,
     178,    89,     0,     0,   103,   104,   105,   106,   107,   141,
       0,    92,    93,    94,    95,     0,     0,     0,    89,    96,
       0,     0,     0,     0,     0,     0,    97,    98,    92,    93,
      94,    95,    99,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,    99,
       0,     0,   101,     0,     0,     0,   259,     0,     0,     0,
     103,   104,   105,   106,   107,   141,     0,     0,     0,   101,
     298,     0,     0,    89,     0,     0,     0,   103,   104,   105,
     106,   107,   141,    92,    93,    94,    95,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,    89,    97,    98,
       0,     0,     0,     0,    99,     0,     0,    92,    93,    94,
      95,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,   301,    97,    98,   101,     0,     0,     0,    99,     0,
       0,     0,   103,   104,   105,   106,   107,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,     0,
       0,     0,   318,    89,     0,     0,   103,   104,   105,   106,
     107,   141,     0,    92,    93,    94,    95,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,    89,    97,    98,
       0,     0,     0,     0,    99,     0,     0,    92,    93,    94,
      95,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,   333,    97,    98,   101,     0,     0,     0,    99,     0,
       0,     0,   103,   104,   105,   106,   107,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   340,
       0,     0,    89,     0,     0,     0,   103,   104,   105,   106,
     107,   141,    92,    93,    94,    95,     0,     0,     0,    89,
      96,     0,     0,     0,     0,     0,     0,    97,    98,    92,
      93,    94,    95,    99,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,    97,    98,     0,     0,     0,     0,
      99,     0,     0,   101,     0,     0,     0,   343,     0,     0,
       0,   103,   104,   105,   106,   107,   141,     0,     0,     0,
     101,   355,     0,     0,    89,     0,     0,     0,   103,   104,
     105,   106,   107,   141,    92,    93,    94,    95,     0,     0,
       0,    89,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    92,    93,    94,    95,    99,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,    99,     0,     0,   101,   357,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   141,     0,
       0,     0,   101,   368,     0,     0,    89,     0,     0,     0,
     103,   104,   105,   106,   107,   141,    92,    93,    94,    95,
       0,     0,     0,    89,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    92,    93,    94,    95,    99,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,    99,     0,     0,   101,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     141,     0,     0,     0,   180,     0,     0,     0,    89,     0,
       0,     0,   103,   104,   105,   106,   107,   141,    92,    93,
      94,    95,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   184,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   141,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,     0,    11,    12,     0,    13,    14,     0,    15,
      16,    17,    18,    19
};

static const yytype_int16 yycheck[] =
{
       0,    84,    59,    36,    88,    60,    76,   133,    43,   147,
      21,    54,    59,     0,    20,   157,    27,   101,    72,    43,
      89,   239,    76,    23,    81,    76,    74,    75,    28,    29,
      30,   114,    77,    43,    81,    41,    23,     7,    89,    81,
      83,    76,    89,    74,    79,    71,    57,    94,    95,   187,
     268,    43,    76,   101,    89,    52,    80,    72,    69,    57,
      60,    76,    72,    33,    62,    89,    76,    78,    72,    56,
      43,    73,    76,    43,    89,    74,    78,    74,    75,    76,
      72,    45,    79,    79,    76,    72,   133,   213,   214,   215,
     173,   175,    78,   177,    80,   152,   180,    89,   182,   169,
     184,    80,    74,    76,   101,   152,    74,   190,   165,   192,
     152,    72,    37,    38,   198,    76,    89,    89,   165,    48,
      80,    89,   109,   165,    78,    54,    80,    48,    49,    43,
      44,   157,   180,    47,    75,    79,   147,    78,    63,    60,
      61,   147,    75,    89,   270,    78,    71,    72,    76,   233,
     197,    76,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   195,
      76,   313,   169,   256,    75,   259,    34,    78,    78,   236,
      80,   187,   266,   180,   205,   206,   207,   208,    76,   236,
      48,    78,    20,    80,   236,    65,    66,   254,    56,    53,
      78,   227,    80,    78,    55,    80,   239,   254,   234,    78,
      52,    80,   254,    41,    72,    35,    36,    77,    78,    51,
      77,    78,    77,   270,    52,    78,   237,    77,    78,    77,
      78,   237,    45,   317,   318,    73,   320,   237,    78,    79,
     323,   252,    79,   243,    77,    78,    74,    75,    76,    79,
     307,    79,    34,   308,    77,    78,    80,   340,   342,   343,
     307,   267,   345,    77,    78,   307,    76,   267,    77,   326,
      89,   354,   355,   101,   357,   359,    77,    78,   361,   326,
      77,    78,   365,    89,   367,   368,    89,   313,    77,    78,
      77,    78,    76,   376,   377,   203,   204,   209,   210,     0,
     211,   212,     3,   329,    77,     6,     7,    73,   308,    77,
      11,    80,    13,    14,    15,    77,    73,    77,    19,    20,
      21,    12,    23,    24,    23,    26,    27,    79,    29,    30,
      31,    32,    33,    69,   252,    65,   154,   180,   243,   109,
     199,   169,    43,     3,   200,   197,     6,     7,    -1,    -1,
      -1,    11,   180,    13,    14,    15,   201,    -1,   202,    19,
      20,    21,    -1,    23,    24,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    -1,    76,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    89,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    77,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    89,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,     6,     7,    -1,    43,    -1,    11,    -1,
      13,    -1,    15,    50,    51,    -1,    19,    20,    -1,    56,
      23,    24,    -1,    -1,    27,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    75,    23,    24,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    43,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    -1,    23,    24,    -1,    26,    27,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    43,    -1,    76,    77,     4,     5,
      -1,    -1,     8,     9,    10,    -1,    -1,    -1,    -1,    89,
      16,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    76,    34,    35,
      36,    37,    38,    -1,     6,     7,    -1,    43,    -1,    11,
      89,    13,    -1,    15,    50,    51,    -1,    19,    20,    -1,
      56,    23,    24,    -1,    -1,    27,    -1,    -1,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
      76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,     4,     5,    -1,    -1,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    75,    -1,    25,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    -1,
       6,     7,    -1,    43,    -1,    11,    -1,    13,    -1,    15,
      50,    51,    -1,    19,    20,    -1,    56,    23,    24,    -1,
      -1,    27,    -1,    -1,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
       4,     5,    -1,    -1,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,    19,
      20,    -1,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    39,    40,    41,    42,
      50,    51,    45,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    67,    68,    76,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    -1,
      23,    24,    -1,    26,    27,    -1,    29,    30,    31,    32,
      33,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      43,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      -1,    23,    24,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,     3,    -1,    72,
       6,     7,    -1,    76,    77,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    -1,    23,    24,    -1,
      26,    27,    -1,    29,    30,    31,    32,    33,    -1,    -1,
       3,    -1,    -1,     6,     7,    77,    -1,    -1,    11,    45,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    -1,
      23,    24,    -1,    26,    27,    -1,    29,    30,    31,    32,
      33,     3,    -1,    -1,     6,     7,    -1,    -1,    74,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      -1,    23,    24,    -1,    26,    27,    25,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      -1,    74,    -1,    25,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    35,    36,    37,    38,    56,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    69,    50,    51,
      -1,    -1,    -1,    -1,    56,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    73,    -1,    -1,    76,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    35,    36,
      37,    38,    -1,    -1,    -1,    25,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    35,    36,    37,    38,    56,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,    -1,    56,    74,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    25,    -1,    -1,    84,    85,    86,    87,    88,    89,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,    25,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    35,    36,
      37,    38,    56,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    -1,    -1,    -1,    76,
      77,    -1,    -1,    25,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    25,    50,    51,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    73,    50,    51,    76,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    25,    -1,    -1,    84,    85,    86,    87,
      88,    89,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    25,    50,    51,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    73,    50,    51,    76,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      -1,    -1,    25,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    35,    36,    37,    38,    -1,    -1,    -1,    25,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    35,
      36,    37,    38,    56,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      76,    77,    -1,    -1,    25,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    35,    36,    37,    38,    -1,    -1,
      -1,    25,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    35,    36,    37,    38,    56,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    76,    77,    -1,    -1,    25,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    35,    36,    37,    38,
      -1,    -1,    -1,    25,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    35,    36,    37,    38,    56,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    76,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    -1,    23,    24,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    23,    24,    26,    27,    29,    30,    31,    32,    33,
      43,    76,    89,    91,    92,    93,    94,    96,    97,    98,
      99,   100,   101,   109,   112,   113,   114,    74,    89,    99,
     114,   115,   112,     0,    92,    80,   103,   104,   112,    96,
      96,    96,    74,    89,    74,    94,    95,    96,   128,    72,
      76,   113,    89,   110,   111,    74,    99,   114,    77,    78,
      80,    45,    95,   128,    98,    99,   102,   105,   106,    74,
       4,     5,     8,     9,    10,    16,    17,    18,    22,    25,
      28,    34,    35,    36,    37,    38,    43,    50,    51,    56,
      75,    76,    80,    84,    85,    86,    87,    88,    89,    95,
     125,   126,   127,   128,   129,   130,   134,   137,   138,   139,
     141,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   159,    94,   128,   112,
      73,    89,   141,   142,   154,    77,    89,    96,   116,   117,
     118,   119,    45,    75,    78,   110,   104,    74,   120,   139,
     128,   106,   106,    75,   105,    79,   107,   108,   112,   102,
      80,   142,    80,    79,   125,    76,    89,    76,    80,   138,
      76,   154,    76,   136,    76,   154,   154,   106,   122,   138,
      79,    75,   129,    75,   125,    78,    80,    54,    83,    53,
      52,    55,    51,    57,    62,    48,    49,    60,    61,    65,
      66,    35,    36,    43,    44,    47,    39,    40,    41,    42,
      45,    58,    59,    64,    67,    68,    70,   140,   153,    37,
      38,    63,    71,    72,    76,    73,    72,    76,   112,   114,
     123,   124,    77,    78,    77,    78,   142,   111,    75,   120,
     121,   142,    78,    80,    79,    75,    79,   125,    34,    80,
     138,    80,   138,    80,   122,   138,    76,    76,   114,   123,
      77,    77,   125,    75,   139,   144,   138,   145,   146,   147,
     148,   149,   149,   150,   150,   150,   150,   151,   151,   152,
     152,   153,   153,   153,   139,    89,    89,   138,    77,   139,
     158,    73,   142,    77,   116,   123,   124,    72,    76,    69,
     118,    89,    75,    78,   108,   142,   125,    76,    80,   138,
      80,    77,    77,    77,   138,   153,    79,    73,    77,    78,
      73,    77,    77,    73,   142,    77,   116,    75,   120,   138,
      77,   138,    80,    80,   138,   131,   125,    77,   141,   139,
      73,    77,    77,   125,    77,    77,   138,    77,   138,    80,
     125,   135,    80,   125,   125,    77,   125,    77,    77,   138,
      12,   132,   125,   125,   125,   125,    77,   133,   125,   125
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
#line 403 "be11302011.y"
    {printf("\tReduced : translation_unit -> external_declaration\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 404 "be11302011.y"
    {printf("\tReduced : translation_unit -> translation_unit external_declaration\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 407 "be11302011.y"
    {printf("\tReduced : external_declaration -> function_definition\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 408 "be11302011.y"
    {printf("\tReduced : external_declaration -> declaration\n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 411 "be11302011.y"
    {printf("\tReduced : function_definition -> declaration_specifiers declarator declaration_list compound_statement\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 412 "be11302011.y"
    {printf("\tReduced : function_definition -> declarator declaration_list compound_statement\n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 413 "be11302011.y"
    {printf("\tReduced : function_definition -> declaration_specifiers declarator compound_statement\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 414 "be11302011.y"
    {printf("\tReduced : function_definition -> declarator compound_statement\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 417 "be11302011.y"
    {flag=0; cnt=0; scs=0; tq=0; printf("\tReduced : declaration -> declaration_specifiers init_declarator_list SEMICOLON\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 418 "be11302011.y"
    {cnt=0; scs=0; tq=0; printf("\tReduced : declaration -> declaration_specifiers SEMICOLON\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 421 "be11302011.y"
    {printf("\tReduced : declaration_list -> declaration\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 422 "be11302011.y"
    {printf("\tReduced : declaration_list -> declaration_list declaration\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 425 "be11302011.y"
    { printf("\tReduced : declaration_specifiers -> storage_class_specifier declaration_specifiers\n");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 426 "be11302011.y"
    { printf("\tReduced : declaration_specifiers -> storage_class_specifier\n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 427 "be11302011.y"
    {printf("\tReduced : declaration_specifiers -> type_specifier declaration_specifiers\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 428 "be11302011.y"
    {printf("\tReduced : declaration_specifiers -> type_specifier\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 429 "be11302011.y"
    {printf("\tReduced : declaration_specifiers -> type_qualifier declaration_specifiers\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 430 "be11302011.y"
    {printf("\tReduced : declaration_specifiers -> type_qualifier\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 433 "be11302011.y"
    { spec(); printf("\tReduced : storage_class_specifier -> AUTO \n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 434 "be11302011.y"
    {spec(); printf("\tReduced : storage_class_specifier -> REGISTER\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 435 "be11302011.y"
    {spec(); printf("\tReduced : storage_class_specifier -> STATIC\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 436 "be11302011.y"
    {spec(); printf("\tReduced : storage_class_specifier -> EXTERN\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 437 "be11302011.y"
    {spec(); printf("\tReduced : storage_class_specifier -> TYPEDEF\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 440 "be11302011.y"
    { func(200000); printf("\tReduced : type_specifier -> VOID\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 441 "be11302011.y"
    { func(1); printf("\tReduced : type_specifier -> CHAR\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 442 "be11302011.y"
    { func(4); printf("\tReduced : type_specifier -> INT\n");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 443 "be11302011.y"
    { func(16); printf("\tReduced : type_specifier -> FLOAT\n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 444 "be11302011.y"
    { func(64); printf("\tReduced : type_specifier -> DOUBLE\n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 445 "be11302011.y"
    { func(1000); printf("\tReduced : type_specifier -> SHORT\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 446 "be11302011.y"
    { func(4000); printf("\tReduced : type_specifier -> LONG\n");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 447 "be11302011.y"
    { func(10000); printf("\tReduced : type_specifier -> SIGNED\n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 448 "be11302011.y"
    { func(10000); printf("\tReduced : type_specifier -> UNSIGNED\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 449 "be11302011.y"
    { func(200000); printf("\tReduced : type_specifier -> struct_or_union_specifier\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 450 "be11302011.y"
    { func(200000); printf("\tReduced : type_specifier -> enum_specifier\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 453 "be11302011.y"
    { printf("\tReduced : type_qualifier -> CONST\n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 454 "be11302011.y"
    { printf("\tReduced : type_qualifier -> VOLATILE\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 457 "be11302011.y"
    {printf("\tReduced : struct_or_union_specifier -> struct_or_union IDENTIFIER CURLY_BRACKET_BEG struct_declaration_list CURLY_BRACKET_END\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 458 "be11302011.y"
    {printf("\tReduced : struct_or_union_specifier -> struct_or_union CURLY_BRACKET_BEG struct_declaration_list CURLY_BRACKET_END\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 459 "be11302011.y"
    {printf("\tReduced : struct_or_union_specifier -> struct_or_union IDENTIFIER\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 462 "be11302011.y"
    {printf("\tReduced : struct_or_union -> STRUCT\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 463 "be11302011.y"
    {printf("\tReduced : struct_or_union -> UNION\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 466 "be11302011.y"
    {printf("\tReduced : struct_declaration_list -> struct_declaration\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 467 "be11302011.y"
    {printf("\tReduced : struct_declaration_list -> struct_declaration_list struct_declaration\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 470 "be11302011.y"
    {printf("\tReduced : init_declarator_list -> init_declarator\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 471 "be11302011.y"
    {printf("\tReduced : init_declarator_list -> init_declarator_list COMMA init_declarator\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 474 "be11302011.y"
    {printf("\tReduced : init_declarator -> declarator\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 475 "be11302011.y"
    {printf("\tReduced : init_declarator -> declarator OPERATOR_ASSIGNMENT initializer\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 479 "be11302011.y"
    {
                        printf("\tReduced : struct_declaration -> specifier_qualifier_list struct_declarator_list SEMICOLON\n");
                        fill_dimensions();
                    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 485 "be11302011.y"
    {printf("\tReduced : specifier_qualifier_list -> type_specifier specifier_qualifier_list\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 486 "be11302011.y"
    {printf("\tReduced : specifier_qualifier_list -> type_specifier\n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 487 "be11302011.y"
    {printf("\tReduced : specifier_qualifier_list -> type_qualifier specifier_qualifier_list\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 488 "be11302011.y"
    {printf("\tReduced : specifier_qualifier_list -> type_qualifier\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 491 "be11302011.y"
    {printf("\tReduced : struct_declarator_list -> struct_declarator\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 492 "be11302011.y"
    {printf("\tReduced : struct_declarator_list -> struct_declarator_list COMMA struct_declarator\n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 494 "be11302011.y"
    {printf("\tReduced : struct_declarator -> declarator\n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 495 "be11302011.y"
    {printf("\tReduced : struct_declarator -> declarator COLON constant_expression\n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 496 "be11302011.y"
    {printf("\tReduced : struct_declarator -> COLON constant_expression\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 499 "be11302011.y"
    {printf("\tReduced : enum_specifier -> ENUM IDENTIFIER CURLY_BRACKET_BEG enumerator_list CURLY_BRACKET_END\n");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 500 "be11302011.y"
    {printf("\tReduced : enum_specifier -> ENUM CURLY_BRACKET_BEG enumerator_list CURLY_BRACKET_END\n");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 501 "be11302011.y"
    {printf("\tReduced : enum_specifier -> ENUM IDENTIFIER\n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 504 "be11302011.y"
    {printf("\tReduced : enumerator_list -> enumerator\n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 505 "be11302011.y"
    {printf("\tReduced : enumerator_list -> enumerator_list COMMA enumerator\n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 508 "be11302011.y"
    {printf("\tReduced : enumerator -> IDENTIFIER\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 509 "be11302011.y"
    {printf("\tReduced : enumerator -> IDENTIFIER OPERATOR_ASSIGNMENT constant_expression\n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 512 "be11302011.y"
    {printf("\tReduced : declarator -> pointer direct_declarator\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 513 "be11302011.y"
    {printf("\tReduced : declarator -> direct_declarator\n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 516 "be11302011.y"
    { flag=1; printf("\tReduced : direct_declarator -> IDENTIFIER\n");
                                if(duplicate((yyvsp[(1) - (1)].values).name))
                                {
                                    f=5;
                                    //printf("Problem is in table\n");
                                    strcpy(temp,(yyvsp[(1) - (1)].values).name);
                                    yyerror();
                                }
                                else
                                {
                                    //printf("start");
                                    len++;
                                    strcpy(symtab[len].name,(yyvsp[(1) - (1)].values).name);
                                    symtab[len].data_type=cnt;
                                    symtab[len].line_no=line_num;
                                    symtab[len].arr_flag=0;
                                    //symtab[len].val=" ";
                                }
                             ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 535 "be11302011.y"
    {printf("\tReduced : direct_declarator -> PARANTHESIS_BEG declarator PARANTHESIS_END\n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 537 "be11302011.y"
    {
				     printf("\tReduced : direct_declarator -> direct_declarator SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END\n");
				     symtab[len].arr_flag=1;
				     symtab[len].arr_sz++;
				     fill_dimensions();
                 ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 544 "be11302011.y"
    {
				     printf("\tReduced : direct_declarator -> direct_declarator SQUARE_BRACKET_BEG SQUARE_BRACKET_END\n");
                     symtab[len].arr_flag=1;
                     symtab[len].arr_sz++;
                     //fill_dimensions();
				 ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 550 "be11302011.y"
    {printf("\tReduced : direct_declarator -> direct_declarator PARANTHESIS_BEG parameter_type_list PARANTHESIS_END\n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 551 "be11302011.y"
    {printf("\tReduced : direct_declarator -> direct_declarator PARANTHESIS_BEG identifier_list PARANTHESIS_END\n");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 552 "be11302011.y"
    {printf("\tReduced : direct_declarator -> direct_declarator PARANTHESIS_BEG PARANTHESIS_END\n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 555 "be11302011.y"
    {printf("\tReduced : pointer -> OPERATOR_MULTIPLY type_qualifier_list\n");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 556 "be11302011.y"
    {printf("\tReduced : pointer -> OPERATOR_MULTIPLY\n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 557 "be11302011.y"
    {printf("\tReduced : pointer -> OPERATOR_MULTIPLY type_qualifier_list pointer\n");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 558 "be11302011.y"
    {printf("\tReduced : pointer -> OPERATOR_MULTIPLY pointer\n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 561 "be11302011.y"
    {printf("\tReduced : type_qualifier_list -> type_qualifier\n");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 562 "be11302011.y"
    {printf("\tReduced : type_qualifier_list -> type_qualifier_list type_qualifier\n");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 565 "be11302011.y"
    {printf("\tReduced : parameter_type_list -> parameter_list\n");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 566 "be11302011.y"
    {printf("\tReduced : parameter_type_list -> parameter_list COMMA THREE_DOTS\n");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 569 "be11302011.y"
    {printf("\tReduced : parameter_list -> parameter_declaration\n");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 570 "be11302011.y"
    {printf("\tReduced : parameter_list -> parameter_list COMMA parameter_declaration\n");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 573 "be11302011.y"
    {printf("\tReduced : parameter_declaration -> declaration_specifiers declarator\n");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 574 "be11302011.y"
    {printf("\tReduced : parameter_declaration -> declaration_specifiers abstract_declarator\n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 575 "be11302011.y"
    {printf("\tReduced : parameter_declaration -> declaration_specifiers\n");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 578 "be11302011.y"
    {printf("\tReduced : identifier_list -> IDENTIFIER\n");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 579 "be11302011.y"
    {printf("\tReduced : identifier_list -> identifier_list COMMA IDENTIFIER\n");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 582 "be11302011.y"
    {printf("\tReduced : initializer -> assignment_expression\n");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 583 "be11302011.y"
    {printf("\tReduced : initializer -> CURLY_BRACKET_BEG initializer_list CURLY_BRACKET_END\n");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 584 "be11302011.y"
    {printf("\tReduced : initializer -> CURLY_BRACKET_BEG initializer_list COMMA CURLY_BRACKET_END\n");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 587 "be11302011.y"
    {printf("\tReduced : initializer_list -> initializer\n");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 588 "be11302011.y"
    {printf("\tReduced : initializer_list -> initializer_list COMMA initializer\n");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 591 "be11302011.y"
    {printf("\tReduced : type_name -> specifier_qualifier_list abstract_declarator\n");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 592 "be11302011.y"
    {printf("\tReduced : type_name -> specifier_qualifier_list\n");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 595 "be11302011.y"
    {printf("\tReduced : abstract_declarator ->  pointer\n");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 596 "be11302011.y"
    {printf("\tReduced : abstract_declarator ->  pointer direct_abstract_declarator\n");;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 597 "be11302011.y"
    {printf("\tReduced : abstract_declarator -> direct_abstract_declarator\n");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 600 "be11302011.y"
    {printf("\tReduced : direct_abstract_declarator -> PARANTHESIS_BEG abstract_declarator PARANTHESIS_END\n");;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 601 "be11302011.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END\n");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 602 "be11302011.y"
    {printf("\tReduced : direct_abstract_declarator -> SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END\n");;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 603 "be11302011.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator SQUARE_BRACKET_BEG SQUARE_BRACKET_END\n");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 604 "be11302011.y"
    {printf("\tReduced : direct_abstract_declarator -> SQUARE_BRACKET_BEG SQUARE_BRACKET_END\n");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 605 "be11302011.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator PARANTHESIS_BEG parameter_type_list PARANTHESIS_END\n");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 606 "be11302011.y"
    {printf("\tReduced : direct_abstract_declarator -> PARANTHESIS_BEG parameter_type_list PARANTHESIS_END\n");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 607 "be11302011.y"
    {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator PARANTHESIS_BEG PARANTHESIS_END\n");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 608 "be11302011.y"
    {printf("\tReduced : direct_abstract_declarator -> PARANTHESIS_BEG PARANTHESIS_END\n");;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 612 "be11302011.y"
    {printf("\tReduced : statement -> labeled_statement\n");;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 613 "be11302011.y"
    {printf("\tReduced : statement -> expression_statement\n");;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 614 "be11302011.y"
    {printf("\tReduced : statement -> compound_statement\n");;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 615 "be11302011.y"
    {printf("\tReduced : statement -> selection_statement\n");;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 616 "be11302011.y"
    {printf("\tReduced : statement -> iteration_statement\n");;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 617 "be11302011.y"
    {printf("\tReduced : statement -> jump_statement\n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 620 "be11302011.y"
    {printf("\tReduced : labeled_statement -> IDENTIFIER COLON statement\n");;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 621 "be11302011.y"
    {printf("\tReduced : labeled_statement -> CASE constant_expression COLON statement\n");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 622 "be11302011.y"
    {printf("\tReduced : labeled_statement -> DEFAULT COLON statement\n");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 625 "be11302011.y"
    { if(found_arr_name>0) {f=9;yyerror();} found_arr_name=0;equals_seen=0; printf("\tReduced : expression_statement -> expression SEMICOLON\n");;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 626 "be11302011.y"
    { if(found_arr_name>0) {f=9;yyerror();} found_arr_name=0;equals_seen=0; printf("\tReduced : expression_statement -> SEMICOLON\n");;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 629 "be11302011.y"
    {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG declaration_list statement_list CURLY_BRACKET_END\n");;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 630 "be11302011.y"
    {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG declaration_list CURLY_BRACKET_END\n");;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 631 "be11302011.y"
    {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG statement_list CURLY_BRACKET_END\n");;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 632 "be11302011.y"
    {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG CURLY_BRACKET_END\n");;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 635 "be11302011.y"
    {printf("\tReduced : statement_list -> statement\n");;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 636 "be11302011.y"
    {printf("\tReduced : statement_list -> statement_list statement\n");;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 640 "be11302011.y"
    {
                        new_label();
                        fprintf(fptr,"IF FALSE %s, goto %s\n",(yyvsp[(3) - (4)].varstr),labelname);

                        strcpy(ic_code[idx].result,"goto");// storing the label to go to in $3
                        strcpy(ic_code[idx].op1,(yyvsp[(3) - (4)].varstr));
                        strcpy(ic_code[idx].opname,"IF_FALSE");
                        strcpy(ic_code[idx].op2,labelname);
                        idx++;

                        strcpy(label_stack[top++],labelname);
                    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 653 "be11302011.y"
    {
                        printf("\tReduced : selection_statement -> IF PARANTHESIS_BEG expression PARANTHESIS_END statement else_selection_statement\n");
                    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 656 "be11302011.y"
    {printf("\tReduced : selection_statement -> SWITCH PARANTHESIS_BEG expression PARANTHESIS_END statement\n");;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 660 "be11302011.y"
    {
                              if(top<=0)
                              {
                                  f=10; yyerror();
                              }
                              else
                              {
                                  top--;
                                  char temp_st_var[101];
                                  strcpy(temp_st_var,label_stack[top]);
                                  new_label();
                                  fprintf(fptr,"goto %s\n",labelname);

                                  strcpy(ic_code[idx].result,"goto");
                                  strcpy(ic_code[idx].op1,"NA");
                                  strcpy(ic_code[idx].opname,"NA");
                                  strcpy(ic_code[idx].op2,labelname);
                                  idx++;

                                  strcpy(label_stack[top++],labelname);
                                  fprintf(fptr,"%s :\n",temp_st_var);

                                  strcpy(ic_code[idx].result,temp_st_var);
                                  strcpy(ic_code[idx].op1,"NA");
                                  strcpy(ic_code[idx].opname,"NA");
                                  strcpy(ic_code[idx].op2,"NA");
                                  idx++;

                              }
                          ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 691 "be11302011.y"
    {
                              if(top<=0)
                              {
                                  f=10; yyerror();
                              }
                              else
                              {
                                  top--;
                                  fprintf(fptr,"%s :\n",label_stack[top]);

                                  strcpy(ic_code[idx].result,label_stack[top]);
                                  strcpy(ic_code[idx].op1,"NA");
                                  strcpy(ic_code[idx].opname,"NA");
                                  strcpy(ic_code[idx].op2,"NA");
                                  idx++;

                              }
                              printf("\tReduced : else_selection_statement -> ELSE statement\n");
                          ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 711 "be11302011.y"
    {
                              if(top<=0)
                              {
                                  f=10; yyerror();
                              }
                              else
                              {
                                  top--;
                                  fprintf(fptr,"%s :\n",label_stack[top]);
                                  strcpy(ic_code[idx].result,label_stack[top]);
                                  strcpy(ic_code[idx].op1,"NA");
                                  strcpy(ic_code[idx].opname,"NA");
                                  strcpy(ic_code[idx].op2,"NA");
                                  idx++;
                              }
                          ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 730 "be11302011.y"
    {
                        new_label();
                        fprintf(fptr,"IF FALSE %s, goto %s\n",(yyvsp[(4) - (5)].varstr),labelname);

                        strcpy(ic_code[idx].result,"goto");
                        strcpy(ic_code[idx].op1,(yyvsp[(4) - (5)].varstr));
                        strcpy(ic_code[idx].opname,"IF_FALSE");
                        strcpy(ic_code[idx].op2,labelname);
                        idx++;

                        strcpy(label_stack[top++],labelname);
                    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 743 "be11302011.y"
    {
                        char temp_st_var[101];
                        --top;
                        strcpy(temp_st_var,label_stack[top]);
                        --top;
                        fprintf(fptr,"goto %s\n",label_stack[top]);

                        strcpy(ic_code[idx].result,"goto");
                        strcpy(ic_code[idx].op1,"NA");
                        strcpy(ic_code[idx].opname,"NA");
                        strcpy(ic_code[idx].op2,label_stack[top]);
                        idx++;

                        fprintf(fptr,"%s:\n",temp_st_var);

                        strcpy(ic_code[idx].result,temp_st_var);
                        strcpy(ic_code[idx].op1,"NA");
                        strcpy(ic_code[idx].opname,"NA");
                        strcpy(ic_code[idx].op2,"NA");
                        idx++;

                        printf("\tReduced : iteration_statement -> WHILE PARANTHESIS_BEG expression PARANTHESIS_END statement\n");
                    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 766 "be11302011.y"
    {printf("\tReduced : iteration_statement -> DO statement WHILE PARANTHESIS_BEG expression PARANTHESIS_END SEMICOLON\n");;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 767 "be11302011.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON expression SEMICOLON expression PARANTHESIS_END statement\n");;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 768 "be11302011.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON expression SEMICOLON PARANTHESIS_END statement\n");;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 769 "be11302011.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON SEMICOLON expression PARANTHESIS_END statement\n");;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 770 "be11302011.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON SEMICOLON PARANTHESIS_END statement\n");;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 771 "be11302011.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON expression SEMICOLON expression PARANTHESIS_END statement\n");;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 772 "be11302011.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON expression SEMICOLON PARANTHESIS_END statement\n");;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 773 "be11302011.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON SEMICOLON expression PARANTHESIS_END statement\n");;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 774 "be11302011.y"
    {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON SEMICOLON PARANTHESIS_END statement\n");;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 777 "be11302011.y"
    {
                 new_label();
                 strcpy(label_stack[top++],labelname);
                 fprintf(fptr,"%s:\n",labelname);

                 strcpy(ic_code[idx].result,labelname);
                 strcpy(ic_code[idx].op1,"NA");
                 strcpy(ic_code[idx].opname,"NA");
                 strcpy(ic_code[idx].op2,"NA");
                 idx++;

            ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 791 "be11302011.y"
    {printf("\tReduced : jump_statement -> GOTO IDENTIFIER SEMICOLON\n");;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 792 "be11302011.y"
    {printf("\tReduced : jump_statement -> CONTINUE SEMICOLON\n");;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 793 "be11302011.y"
    {printf("\tReduced : jump_statement -> BREAK SEMICOLON\n");;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 794 "be11302011.y"
    {printf("\tReduced : jump_statement -> RETURN expression SEMICOLON\n");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 795 "be11302011.y"
    {printf("\tReduced : jump_statement -> RETURN SEMICOLON\n");;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 799 "be11302011.y"
    {
                printf("\tReduced : expression -> assignment_expression\n");
                strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));
            ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 804 "be11302011.y"
    {
                printf("\tReduced : expression -> expression COMMA assignment_expression\n");
                strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
            ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 811 "be11302011.y"
    {
                        printf("\tReduced : assignment_expression -> conditional_expression\n");
                        strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));
                    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 816 "be11302011.y"
    {
					     dimfound=0;
					     d1=0;
					     printf("\tReduced : assignment_expression -> unary_expression assignment_operator assignment_expression\n");
					     //fprintf(fptr,"%s %s %s %s\n",$$,$1,$2,$3);
					     if(strcmp((yyvsp[(2) - (3)].varstr),"=")==0)
					     {
					         //new_var();
					         fprintf(fptr,"%s = %s\n",(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].op1,(yyvsp[(3) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"EQUAL_TO");
                             strcpy(ic_code[idx].op2,"NA");
                             idx++;

					         strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
					     }
					     else if(strcmp((yyvsp[(2) - (3)].varstr),"*=")==0)
					     {
					         fprintf(fptr,"%s = %s * %s\n",(yyvsp[(1) - (3)].varstr),(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"MUL");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

					         strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
					     }
					     else if(strcmp((yyvsp[(2) - (3)].varstr),"/=")==0)
					     {
					         fprintf(fptr,"%s = %s / %s\n",(yyvsp[(1) - (3)].varstr),(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"DIV");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

					         strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
					     }
					     else if(strcmp((yyvsp[(2) - (3)].varstr),"+=")==0)
					     {
					         fprintf(fptr,"%s = %s + %s\n",(yyvsp[(1) - (3)].varstr),(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"ADD");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

					         strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
					     }
					     else if(strcmp((yyvsp[(2) - (3)].varstr),"-=")==0)
					     {
					         fprintf(fptr,"%s = %s - %s\n",(yyvsp[(1) - (3)].varstr),(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"SUB");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

					         strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
					     }
					     else if(strcmp((yyvsp[(2) - (3)].varstr),"<<=")==0)
					     {
					         fprintf(fptr,"%s = %s LS %s\n",(yyvsp[(1) - (3)].varstr),(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"LSHIFT");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

					         strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
					     }
					     else if(strcmp((yyvsp[(2) - (3)].varstr),">>=")==0)
					     {
					         fprintf(fptr,"%s = %s RS %s\n",(yyvsp[(1) - (3)].varstr),(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"RSHIFT");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

					         strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
					     }
					     else if(strcmp((yyvsp[(2) - (3)].varstr),"&=")==0)
					     {
					         fprintf(fptr,"%s = %s B_AND %s\n",(yyvsp[(1) - (3)].varstr),(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"B_AND");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

					         strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
					     }
					     else if(strcmp((yyvsp[(2) - (3)].varstr),"^=")==0)
					     {
					         fprintf(fptr,"%s = %s XOR %s\n",(yyvsp[(1) - (3)].varstr),(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"XOR");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

					         strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
					     }
					     else if(strcmp((yyvsp[(2) - (3)].varstr),"|=")==0)
					     {
					         fprintf(fptr,"%s = %s B_OR %s\n",(yyvsp[(1) - (3)].varstr),(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"B_OR");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

					         strcpy((yyval.varstr),(yyvsp[(1) - (3)].varstr));
					     }
                    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 945 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_ASSIGNMENT\n");strcpy((yyval.varstr),"=");equals_seen=1;;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 946 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_MULTIPLIER\n");strcpy((yyval.varstr),"*=");;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 947 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_DIVIDER\n");strcpy((yyval.varstr),"/=");;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 948 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_MOD_ASSIGNMENT\n");strcpy((yyval.varstr),"%=");;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 949 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_ADDER\n");strcpy((yyval.varstr),"+=");;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 950 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_SUBTRACTOR\n");strcpy((yyval.varstr),"-=");;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 951 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_LEFT_ASSIGNMENT\n");strcpy((yyval.varstr),"<<=");;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 952 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_RIGHT_ASSIGNMENT\n");strcpy((yyval.varstr),">>=");;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 953 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_AND_ASSIGNMENT\n");strcpy((yyval.varstr),"&=");;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 954 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_BITWISE_XOR_ASSIGNMENT\n");strcpy((yyval.varstr),"^=");;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 955 "be11302011.y"
    {printf("\tReduced : assignment_operator -> OPERATOR_OR_ASSIGNMENT\n");strcpy((yyval.varstr),"|=");;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 958 "be11302011.y"
    {printf("\tReduced : conditional_expression -> logical_OR_expression\n");strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 959 "be11302011.y"
    {printf("\tReduced : conditional_expression -> logical_OR_expression TERNARY expression COLON conditional_expression\n");;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 962 "be11302011.y"
    {printf("\tReduced : constant_expression -> conditional_expression\n");strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 965 "be11302011.y"
    {printf("\tReduced : logical_OR_expression -> logical_AND_expression\n");strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 967 "be11302011.y"
    {
					     printf("\tReduced : logical_OR_expression -> logical_OR_expression OPERATOR_OR logical_AND_expression\n");
					     new_var();
					     fprintf(fptr,"%s = %s OR %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					     strcpy(ic_code[idx].result,varname);
                         strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                         strcpy(ic_code[idx].opname,"OR");
                         strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                         idx++;

					     strcpy((yyval.varstr),varname);
                     ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 982 "be11302011.y"
    {printf("\tReduced : logical_AND_expression -> inclusive_OR_expression\n");strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 984 "be11302011.y"
    {
					      printf("\tReduced : logical_AND_expression -> logical_AND_expression OPERATOR_AND inclusive_OR_expression\n");
					      new_var();
					      fprintf(fptr,"%s = %s AND %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					      strcpy(ic_code[idx].result,varname);
                          strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                          strcpy(ic_code[idx].opname,"AND");
                          strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                          idx++;

					      strcpy((yyval.varstr),varname);
                      ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 999 "be11302011.y"
    {printf("\tReduced : inclusive_OR_expression -> exclusive_OR_expression\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1001 "be11302011.y"
    {
					       printf("\tReduced : inclusive_OR_expression -> inclusive_OR_expression OPERATOR_BITWISE_OR exclusive_OR_expression\n");
					       new_var();
					       fprintf(fptr,"%s = %s B_OR %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));
					       strcpy((yyval.varstr),varname);
                       ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1009 "be11302011.y"
    {printf("\tReduced : exclusive_OR_expression -> AND_expression\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1011 "be11302011.y"
    {
					       printf("\tReduced : exclusive_OR_expression -> exclusive_OR_expression OPERATOR_BITWISE_XOR AND_expression\n");
					       new_var();
					       fprintf(fptr,"%s = %s XOR %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					       strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"XOR");
                           strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                           idx++;

					       strcpy((yyval.varstr),varname);
                       ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1026 "be11302011.y"
    {printf("\tReduced : AND_expression -> equality_expression\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1028 "be11302011.y"
    {
			      printf("\tReduced : AND_expression -> AND_expression OPERATOR_BITWISE_AND equality_expression\n");
			      new_var();
                  fprintf(fptr,"%s = %s B_AND %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

                  strcpy(ic_code[idx].result,varname);
                  strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                  strcpy(ic_code[idx].opname,"B_AND");
                  strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                  idx++;

                  strcpy((yyval.varstr),varname);
              ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1042 "be11302011.y"
    {printf("\tReduced : equality_expression -> relational_expression\n");strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1044 "be11302011.y"
    {
				       printf("\tReduced : equality_expression -> equality_expression OPERATOR_EQUALITY_CHECKER relational_expression\n");
                       if(chk_type((yyvsp[(1) - (3)].varstr))==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(1) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type((yyvsp[(3) - (3)].varstr))==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(3) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(3) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,(yyvsp[(3) - (3)].varstr));
                           new_var();
                           fprintf(fptr,"%s = %s EQ %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"EQ");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s EQ %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                       strcpy(ic_code[idx].opname,"EQ");
                       strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                       idx++;}

					     strcpy((yyval.varstr),varname);
                     ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1089 "be11302011.y"
    {
				       printf("\tReduced : equality_expression -> equality_expression OPERATOR_NOT_EQUAL relational_expression\n");
				       if(chk_type((yyvsp[(1) - (3)].varstr))==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(1) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type((yyvsp[(3) - (3)].varstr))==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(3) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(3) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,(yyvsp[(3) - (3)].varstr));
                           new_var();
                           fprintf(fptr,"%s = %s NE %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"NE");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s NE %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                       strcpy(ic_code[idx].opname,"NE");
                       strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                       idx++;}

					     strcpy((yyval.varstr),varname);
                     ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1135 "be11302011.y"
    {printf("\tReduced : relational_expression -> shift_expression\n");strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1137 "be11302011.y"
    {
					     printf("\tReduced : relational_expression -> relational_expression OPERATOR_LESS_THAN shift_expression\n");
					     if(chk_type((yyvsp[(1) - (3)].varstr))==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(1) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type((yyvsp[(3) - (3)].varstr))==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(3) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(3) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,(yyvsp[(3) - (3)].varstr));
                           new_var();
                           fprintf(fptr,"%s = %s LT %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"LT");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s LT %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                       strcpy(ic_code[idx].opname,"LT");
                       strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                       idx++;}

					     strcpy((yyval.varstr),varname);
                     ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1182 "be11302011.y"
    {
					     printf("\tReduced : relational_expression -> relational_expression OPERATOR_GREATER_THAN shift_expression\n");
					     if(chk_type((yyvsp[(1) - (3)].varstr))==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(1) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type((yyvsp[(3) - (3)].varstr))==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(3) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(3) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,(yyvsp[(3) - (3)].varstr));
                           new_var();
                           fprintf(fptr,"%s = %s GT %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"GT");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s GT %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                       strcpy(ic_code[idx].opname,"GT");
                       strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                       idx++;}

					     strcpy((yyval.varstr),varname);
                     ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1227 "be11302011.y"
    {
					     printf("\tReduced : relational_expression -> relational_expression OPERATOR_LESS_OR_EQUAL shift_expression\n");
					     if(chk_type((yyvsp[(1) - (3)].varstr))==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(1) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type((yyvsp[(3) - (3)].varstr))==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(3) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(3) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,(yyvsp[(3) - (3)].varstr));
                           new_var();
                           fprintf(fptr,"%s = %s LE %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"LE");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s LE %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                       strcpy(ic_code[idx].opname,"LE");
                       strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                       idx++;}

					     strcpy((yyval.varstr),varname);
                     ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1272 "be11302011.y"
    {
					     printf("\tReduced : relational_expression -> relational_expression OPERATOR_GREATER_OR_EQUAL shift_expression\n");
					     if(chk_type((yyvsp[(1) - (3)].varstr))==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(1) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type((yyvsp[(3) - (3)].varstr))==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,(yyvsp[(3) - (3)].varstr));

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,(yyvsp[(3) - (3)].varstr));
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,(yyvsp[(3) - (3)].varstr));
                           new_var();
                           fprintf(fptr,"%s = %s GE %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"GE");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s GE %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                       strcpy(ic_code[idx].opname,"GE");
                       strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                       idx++;}

					     strcpy((yyval.varstr),varname);
                     ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1318 "be11302011.y"
    {printf("\tReduced : shift_expression -> additive_expression\n");strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1320 "be11302011.y"
    {
			        printf("\tReduced : shift_expression -> shift_expression OPERATOR_LEFT_SHIFT additive_expression\n");
			        new_var();
                    fprintf(fptr,"%s = %s LS %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

                    strcpy(ic_code[idx].result,varname);
                    strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                    strcpy(ic_code[idx].opname,"LSHIFT");
                    strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                    idx++;

					strcpy((yyval.varstr),varname);
                ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1334 "be11302011.y"
    {
				    printf("\tReduced : shift_expression -> shift_expression OPERATOR_RIGHT_SHIFT additive_expression\n");
				    new_var();
                    fprintf(fptr,"%s = %s RS %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

                    strcpy(ic_code[idx].result,varname);
                    strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                    strcpy(ic_code[idx].opname,"RSHIFT");
                    strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                    idx++;

					strcpy((yyval.varstr),varname);
                ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1350 "be11302011.y"
    {
                        printf("\tReduced : additive_expression -> multiplicative_expression\n");
                        strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));
                    ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1355 "be11302011.y"
    {
				       printf("\tReduced : additive_expression -> additive_expression OPERATOR_PLUS multiplicative_expression\n");
				       new_var();
				       fprintf(fptr,"%s = %s + %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

				       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                       strcpy(ic_code[idx].opname,"ADD");
                       strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                       idx++;

				       strcpy((yyval.varstr),varname);
                    ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1369 "be11302011.y"
    {
				       printf("\tReduced : additive_expression -> additive_expression OPERATOR_MINUS multiplicative_expression\n");
				       new_var();
				       fprintf(fptr,"%s = %s - %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

				       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                       strcpy(ic_code[idx].opname,"SUB");
                       strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                       idx++;

				       strcpy((yyval.varstr),varname);
                   ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1385 "be11302011.y"
    {
                            printf("\tReduced : multiplicative_expression -> cast_expression\n");
                            strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));
                         ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1390 "be11302011.y"
    {
						     printf("\tReduced : multiplicative_expression -> multiplicative_expression OPERATOR_MULTIPLY cast_expression\n");
						     new_var();
                             fprintf(fptr,"%s = %s * %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

                             strcpy(ic_code[idx].result,varname);
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"MUL");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

                             strcpy((yyval.varstr),varname);
                         ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1404 "be11302011.y"
    {
						     printf("\tReduced : multiplicative_expression -> multiplicative_expression OPERATOR_DIVIDE cast_expression\n");
						     new_var();
                             fprintf(fptr,"%s = %s / %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

                             strcpy(ic_code[idx].result,varname);
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"DIV");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

                             strcpy((yyval.varstr),varname);
                         ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1418 "be11302011.y"
    {
						     printf("\tReduced : multiplicative_expression -> multiplicative_expression OPERATOR_MODULUS cast_expression\n");
						     new_var();
					         fprintf(fptr,"%s = %s % %s\n",varname,(yyvsp[(1) - (3)].varstr),(yyvsp[(3) - (3)].varstr));

					         strcpy(ic_code[idx].result,varname);
                             strcpy(ic_code[idx].op1,(yyvsp[(1) - (3)].varstr));
                             strcpy(ic_code[idx].opname,"MOD");
                             strcpy(ic_code[idx].op2,(yyvsp[(3) - (3)].varstr));
                             idx++;

					         strcpy((yyval.varstr),varname);
                         ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1433 "be11302011.y"
    {printf("\tReduced : cast_expression -> unary_expression\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1435 "be11302011.y"
    {
			       printf("\tReduced : cast_expression -> PARANTHESIS_BEG type_name PARANTHESIS_END cast_expression\n");
			       //strcpy($$,$2);
               ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1441 "be11302011.y"
    { printf("#### %s\n",(yyvsp[(1) - (1)].varstr));printf("\tReduced : unary_expression -> postfix_expression\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1443 "be11302011.y"
    {
				    printf("\tReduced : unary_expression -> OPERATOR_INCREMENTOR unary_expression\n");
				    fprintf(fptr,"%s = %s + 1\n",(yyvsp[(2) - (2)].varstr),(yyvsp[(2) - (2)].varstr));

				    strcpy(ic_code[idx].result,(yyvsp[(2) - (2)].varstr));
                    strcpy(ic_code[idx].op1,(yyvsp[(2) - (2)].varstr));
                    strcpy(ic_code[idx].opname,"ADD");
                    strcpy(ic_code[idx].op2,"1");
                    idx++;

				    strcpy((yyval.varstr),(yyvsp[(2) - (2)].varstr));
                ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1456 "be11302011.y"
    {
				    printf("\tReduced : unary_expression -> OPERATOR_DECREMENTOR unary_expression\n");
				    fprintf(fptr,"%s = %s - 1\n",(yyvsp[(2) - (2)].varstr),(yyvsp[(2) - (2)].varstr));

				    strcpy(ic_code[idx].result,(yyvsp[(2) - (2)].varstr));
                    strcpy(ic_code[idx].op1,(yyvsp[(2) - (2)].varstr));
                    strcpy(ic_code[idx].opname,"SUB");
                    strcpy(ic_code[idx].op2,"1");
                    idx++;

				    strcpy((yyval.varstr),(yyvsp[(2) - (2)].varstr));
                ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1469 "be11302011.y"
    {
				    printf("\tReduced : unary_expression -> unary_operator cast_expression\n");
				    new_var();
				    fprintf(fptr,"%s = -%s\n",varname,(yyvsp[(2) - (2)].varstr));

				    strcpy(ic_code[idx].result,(yyvsp[(2) - (2)].varstr));
                    strcpy(ic_code[idx].op1,(yyvsp[(2) - (2)].varstr));
                    strcpy(ic_code[idx].opname,"NEG");
                    strcpy(ic_code[idx].op2,"NA");
                    idx++;

				    strcpy((yyval.varstr),varname);
                ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1482 "be11302011.y"
    {printf("\tReduced : unary_expression -> SIZEOF unary_expression\n");;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1483 "be11302011.y"
    {printf("\tReduced : unary_expression -> SIZEOF PARANTHESIS_BEG type_name PARANTHESIS_END\n");;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1486 "be11302011.y"
    {printf("\tReduced : unary_operator -> OPERATR_BITWISE_AND\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1487 "be11302011.y"
    {printf("\tReduced : unary_operator -> OPERATOR_MULTIPLY\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1488 "be11302011.y"
    {printf("\tReduced : unary_operator -> OPERATOR_PLUS\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1489 "be11302011.y"
    {printf("\tReduced : unary_operator -> OPERATOR_MINUS\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1490 "be11302011.y"
    {printf("\tReduced : unary_operator -> OPERATOR_TILDE\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1491 "be11302011.y"
    {printf("\tReduced : unary_operator -> OPERATOR_NOT\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1494 "be11302011.y"
    {printf("\tReduced : postfix_expression -> primary_expression\n");;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1496 "be11302011.y"
    {
				      printf("\tReduced : postfix_expression -> postfix_expression SQUARE_BRACKET_BEG expression SQUARE_BRACKET_END\n");
				      //new_var();
				      strcpy(tempdim[d1++],(yyvsp[(3) - (4)].varstr));
				      found_arr_name--;
				      //printf(">>>>>>>found_arr_name %d\n",found_arr_name);
				      //printf("<<<<<<<<<<<<<<<< %s %s %s\n",$$,$1,$3);
				      //printf(">>>>>>%s\n",$1);
				      if_match_print((yyvsp[(1) - (4)].varstr));

				      /*if(dimfound=1)
				      {
				          new_var();
				          fprintf(fptr,"%s = %s[%s]\n",varname,$1,cur_var);
				          strcpy($$,varname);
				      }*/
				      //printf("<<<<<<< %d\n",dimfound);
				      if(dimfound==1 )
				      {
				            if(equals_seen==1)
                            {
                                //printf("><>< %d %s\n",equals_seen,cur_var);
                                new_var();
                                fprintf(fptr,"%s = %s[%s]\n",varname,(yyvsp[(1) - (4)].varstr),cur_var);
                                char tempsstr[101];
                                strcpy(tempsstr,(yyvsp[(1) - (4)].varstr));
                                strcat(tempsstr,"[");
                                strcat(tempsstr,cur_var);
                                strcat(tempsstr,"]");
                                strcpy(ic_code[idx].result,varname);
                                strcpy(ic_code[idx].op1,tempsstr);
                                strcpy(ic_code[idx].opname,"EQUAL_TO");
                                strcpy(ic_code[idx].op2,"NA");
                                idx++;

                                strcpy((yyval.varstr),varname);
                            }
                            else
                            {
                                char tempor1[101];
                                //tempor1[0]='\0';
                                //printf("%s\n",cur_var);
                                strcpy(tempor1,(yyvsp[(1) - (4)].varstr));
                                strcat(tempor1,"[");
                                strcat(tempor1,cur_var);
                                strcat(tempor1,"]");
                                //strcpy(tempor1,strcat($1,strcat("[",strcat(cur_var,"]"))));
                                printf(">>><<<%s\n",tempor1);
                                strcpy((yyval.varstr),tempor1);
                            }
                            dimfound=0;
				      }
				      else strcpy((yyval.varstr),(yyvsp[(1) - (4)].varstr));
				      //dimfound=0;
                  ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1551 "be11302011.y"
    {printf("\tReduced : postfix_expression -> postfix_expression PARANTHESIS_BEG argument_expression_list PARANTHESIS_END\n");;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1552 "be11302011.y"
    {printf("\tReduced : postfix_expression -> postfix_expression PARANTHESIS_BEG PARANTHESIS_END\n");;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1553 "be11302011.y"
    {printf("\tReduced : postfix_expression -> postfix_expression DOT IDENTIFIER\n");;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1554 "be11302011.y"
    {printf("\tReduced : postfix_expression -> postfix_expression OPERATOR_LINK IDENTIFIER\n");;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1556 "be11302011.y"
    {
				      printf("\tReduced : postfix_expression -> postfix_expression OPERATOR_INCREMENTOR\n");
				      new_var();
				      fprintf(fptr,"%s = %s\n",varname,(yyvsp[(1) - (2)].varstr));

				      strcpy(ic_code[idx].result,varname);
                      strcpy(ic_code[idx].op1,(yyvsp[(1) - (2)].varstr));
                      strcpy(ic_code[idx].opname,"NA");
                      strcpy(ic_code[idx].op2,"NA");
                      idx++;

				      fprintf(fptr,"%s = %s + 1\n",(yyvsp[(1) - (2)].varstr),(yyvsp[(1) - (2)].varstr));

				      strcpy(ic_code[idx].result,(yyvsp[(1) - (2)].varstr));
                      strcpy(ic_code[idx].op1,(yyvsp[(1) - (2)].varstr));
                      strcpy(ic_code[idx].opname,"ADD");
                      strcpy(ic_code[idx].op2,"1");
                      idx++;

				      strcpy((yyval.varstr),varname);

                  ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1579 "be11302011.y"
    {
				      printf("\tReduced : postfix_expression -> postfix_expression OPERATOR_DECREMENTOR\n");
				      new_var();
				      fprintf(fptr,"%s = %s\n",varname,(yyvsp[(1) - (2)].varstr));

				      strcpy(ic_code[idx].result,varname);
                      strcpy(ic_code[idx].op1,(yyvsp[(1) - (2)].varstr));
                      strcpy(ic_code[idx].opname,"NA");
                      strcpy(ic_code[idx].op2,"NA");
                      idx++;

				      fprintf(fptr,"%s = %s - 1\n",(yyvsp[(1) - (2)].varstr),(yyvsp[(1) - (2)].varstr));

				      strcpy(ic_code[idx].result,(yyvsp[(1) - (2)].varstr));
                      strcpy(ic_code[idx].op1,(yyvsp[(1) - (2)].varstr));
                      strcpy(ic_code[idx].opname,"SUB");
                      strcpy(ic_code[idx].op2,"1");
                      idx++;

				      strcpy((yyval.varstr),varname);
                  ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1602 "be11302011.y"
    { printf("\tReduced : primary_expression -> IDENTIFIER\n");
                                    int temp_found_arr=is_it_array((yyvsp[(1) - (1)].values).name);
                                    if(temp_found_arr>0) found_arr_name=temp_found_arr;
                                    //printf("~~~~~~~~~ %d\n",found_arr_name);
                                    if(!present((yyvsp[(1) - (1)].values).name))
                                    {
                                        f=6;
                                        strcpy(temp,(yyvsp[(1) - (1)].values).name);
                                        yyerror();
                                    }
                                    strcpy((yyval.varstr),(yyvsp[(1) - (1)].values).name);
                              ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1614 "be11302011.y"
    {printf("\tReduced : primary_expression -> constant\n"); strcpy((yyval.varstr),(yyvsp[(1) - (1)].varstr));;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1615 "be11302011.y"
    { printf("\tReduced : primary_expression -> STRING_CONSTANT\n");
                                        if(flag)strcat(symtab[len].val," ");
                                        if(flag)strcat(symtab[len].val,(yyvsp[(1) - (1)].values).val);
                                        strcpy((yyval.varstr),(yyvsp[(1) - (1)].values).name);
                                   ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1620 "be11302011.y"
    {printf("\tReduced : primary_expression -> PARANTHESIS_BEG expression PARANTHESIS_END\n"); strcpy((yyval.varstr),(yyvsp[(2) - (3)].varstr));;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1623 "be11302011.y"
    {printf("\tReduced : argument_expression_list -> assignment_expression\n");;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1624 "be11302011.y"
    {printf("\tReduced : argument_expression_list -> argument_expression_list COMMA assignment_expression\n");;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1627 "be11302011.y"
    { printf("\tReduced : constant -> NUMBER\n");
                            if(flag)strcat(symtab[len].val," ");
                            if(flag)strcat(symtab[len].val,(yyvsp[(1) - (1)].values).val);
                            printf("%s\n",(yyvsp[(1) - (1)].values).val);
                            strcpy((yyval.varstr),(yyvsp[(1) - (1)].values).val);
                ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1633 "be11302011.y"
    { printf("\tReduced : constant -> CHAR_CONSTANT\n");
                            if(flag)strcat(symtab[len].val," ");
                            if(flag)strcat(symtab[len].val,(yyvsp[(1) - (1)].values).val);
                            strcpy((yyval.varstr),(yyvsp[(1) - (1)].values).val);
                       ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1638 "be11302011.y"
    { printf("\tReduced : constant -> REAL_NUMBER\n");
                            if(flag)strcat(symtab[len].val," ");
                            if(flag)strcat(symtab[len].val,(yyvsp[(1) - (1)].values).val);
                            strcpy((yyval.varstr),(yyvsp[(1) - (1)].values).val);
                     ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1643 "be11302011.y"
    { printf("\tReduced : constant -> EXP_NUMBER\n");
                            if(flag)strcat(symtab[len].val," ");
                            if(flag)strcat(symtab[len].val,(yyvsp[(1) - (1)].values).val);
                            strcpy((yyval.varstr),(yyvsp[(1) - (1)].values).val);
                    ;}
    break;



/* Line 1455 of yacc.c  */
#line 4897 "be11302011.tab.c"
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
#line 1650 "be11302011.y"


#include "lex.yy.c"

int yyerror()
{
    fclose(fptr);
    fptr=fopen(op_file_name,"w");
    printf("\nERROR:");
	printf("\t(LINE NO. %d) of the input file\nDescription:",line_num);
	fprintf(fptr,"ERROR:");
	fprintf(fptr,"\t(LINE NO. %d) of the input file\nDescription:",line_num);
	if(f==1)
	{
        printf("More than one storage_class_specifier in one assignment\n");
        fprintf(fptr,"More than one storage_class_specifier in one assignment\n");
	}
	else if(f==2)
	{
        printf("Invalid data type encountered\n");
        fprintf(fptr,"Invalid data type encountered\n");
	}
	else if(f==5)
	{
        printf("Redeclaration of %s\n", temp);
	}
	else if(f==6)
	{
        printf("Unknown variable %s\n", temp);
        fprintf(fptr,"Unknown variable %s\n", temp);
	}
	else if(f==7)
	{
        printf("Greater Size of dimensions\n");
        fprintf(fptr,"Greater Size of dimensions\n");
	}
	else if(f==8)
	{
        printf("Incorrect dimesions values\n");
        fprintf(fptr,"Incorrect dimesions values\n");
	}
	else if(f==9)
	{
	    printf("%d\n",found_arr_name);
	    printf("This array assignment is not allowed\n");
	    fprintf(fptr,"This array assignment is not allowed\n");
	}
	else if(f==10)
	{
	    printf("Dangling else: an else without an if\n\n");
	    fprintf(fptr,"Dangling else: an else without an if\n\n");
	}
	else
	{
        printf("Invalid Syntax\n");
        fprintf(fptr,"Invalid Syntax\n");
	}
	printf("\t(The further execution of program is being terminated!!!)\n");
	fprintf(fptr,"\t(The further execution of program is being terminated!!!)\n");
	fclose(fptr);
	exit(0);
}

void print_ic_code();
void generate_code();

int main(int argc,char *argv[])
{
        if(argc<4)
        {
                printf("Correct format is <.exe><inp-file><op-file.i><op-file.s>\n");
                return -1;
        }
        strcpy(op_file_name,argv[2]);
        yyin = fopen(argv[1],"r");
        fptr=fopen(argv[2],"w");
        fptrs=fopen(argv[3],"w");

        yyparse();
        printf("\n# Number of entries in symbol table : %d\n",len);
        display();
        printf("\n~~~~~~~~~~~~~~~~~SYMBOL TABLE~~~~~~~~~~~~~~\n\n");

        printf("\nline    ID     type  is_array  n-d_arr init_val (dimensions)\n");
        int i;
        for(i=1;i<=len;i++)
        {
            printf("  %d\t%s\t%d\t",symtab[i].line_no, symtab[i].name, symtab[i].data_type);
            //if(symtab[i].data_type && symtab[i].arr_flag==0)
            //{
            //    symtab[i].arr_flag=-1;
            //    printf("%d\t",-1);
            //}
            //else
            printf(" %d\t",symtab[i].arr_flag>0);
            if(symtab[i].arr_flag>0)
            {
                if(symtab[i].arr_sz==1)
                {
                    int k,l,vlen=strlen(symtab[i].val);
                    for(k=1;k<vlen;k++)
                    {
                        if(symtab[i].val[k]==' ')
                            break;
                    }
                    for(l=0;l<k;l++)
                    {
                        tempstr[l]=symtab[i].val[l];
                    }
                    tempstr[l]='\0';
                    symtab[i].sz=atoi(tempstr);
                    printf("%d-d\t",symtab[i].arr_sz);
                    int p1=0,found=0;
                    for(l=k;l<strlen(symtab[i].val);l++)
                    {
                        tempstr[p1++]=symtab[i].val[l];
                        if(symtab[i].val[l]>47 && symtab[i].val[l]<123) found=1;
                    }
                    tempstr[p1]='\0';
                    strcpy(symtab[i].val,tempstr);
                    if(found && symtab[i].data_type!=0) printf("%s\n",symtab[i].val);
                    else printf(" ---\t%d\n",symtab[i].sz);
                }
                else if(symtab[i].arr_sz>1)
                {
                    int dim=symtab[i].arr_sz;
                    symtab[i].arr_flag=dim;
                    int k=0,l,cnt1=0,vlen=strlen(symtab[i].val);
                    l=0;
                    while(cnt1<dim)
                    {
                        for(;k<vlen;k++)
                        {
                            if(symtab[i].val[k]==' ')
                                break;
                        }
                        k++;
                        //l=0;
                        while(k<vlen && symtab[i].val[k]!=' ')
                        {
                            tempstr[l]=symtab[i].val[k];
                            l++;
                            k++;
                        }
                        tempstr[l++]=' ';
                        cnt1++;
                    }
                    tempstr[l]='\0';
                    strcpy(symtab[i].dimension,tempstr);
                    //symtab[i].sz=atoi(tempstr);
                    printf("%d-d\t",symtab[i].arr_sz);
                    int p1=0,found=0;
                    for(l=k;l<strlen(symtab[i].val);l++)
                    {
                        tempstr[p1++]=symtab[i].val[l];
                        if(symtab[i].val[l]>47 && symtab[i].val[l]<123) found=1;
                    }
                    tempstr[p1]='\0';
                    strcpy(symtab[i].val,tempstr);
                    if(found  && symtab[i].data_type!=0) printf("%s",symtab[i].val);
                    else printf(" ---");
                    printf("   \t%s\n",symtab[i].dimension);
                }
                else
                {
                    symtab[i].sz=0;
                    int k,found=0;
					for(k=0;k<strlen(symtab[i].val);k++)
					{
						if(symtab[i].val[k]==' ')
							symtab[i].sz++;
                        if(symtab[i].val[k]>47 && symtab[i].val[k]<123) found=1;
					}
					sprintf(symtab[i].dimension,"%d",symtab[i].sz);
					printf("1(%d)\t",symtab[i].sz);
					//if(symtab[i].sz<1 || ((symtab[i].sz==1) && symtab[i].val[0]=='\0')) printf("---\n");
					//else
					if (found) printf("%s\n",symtab[i].val);
                    else printf(" ---\n");
                }
            }
            else
            {
                int k,x=strlen(symtab[i].val),found=0;
                for(k=0;k<x;k++)
                {
                    if(symtab[i].val[k]>47 && symtab[i].val[k]<123) found=1;
                }
                printf("---\t");
                if(found  && symtab[i].data_type!=0) printf("%s\n",symtab[i].val);
                else printf(" ---\t---\n");
            }
        }
        //print_ic_code();
        generate_code();
        fclose(yyin);
        return 0;
}

/* Assignment 4: Code Generation */

void print_ic_code()
{
    int ik;
    for(ik=0;ik<idx;ik++)
    {
        fprintf(fptrs,"%s \t",ic_code[ik].result);
        fprintf(fptrs,"%s \t",ic_code[ik].op1);
        fprintf(fptrs,"%s \t",ic_code[ik].opname);
        fprintf(fptrs,"%s \n",ic_code[ik].op2);
    }
}

void print_header() //3.1
{
    fprintf(fptrs,".text\n.globl _main\n_main:\n\tpushl	%%ebp\n\tmovl\t%%esp, %%ebp\n\tandl\t$-16, %%esp\n\n");
}
int iflabelcnt=0;

void if_label()
{
    //namings like foo_00_1.// changed to the require format t_000001
    labelname[0]='L';
    labelname[1]='_';
    labelname[2]='1';
    labelname[3]='1';
    labelname[4]='1';
    labelname[5]='1';
    labelname[6]='1';
    sprintf(vartmp1,"%d",iflabelcnt);
    int x=strlen(vartmp1);
    for(i=0;i<x;i++) labelname[7+i]=vartmp1[i];
    labelname[7+i]='\0';
    //printf("%s\n",varname);
    iflabelcnt++;
}


int chk_type( char * strrt) //const=0, var=1, arr=2
{
    int i=0;
    if(strrt[0]>47 && strrt[0]<59) return 0;
    for(i=0;i<strlen(strrt);i++)
    {
        if(strrt[i]=='[') return 2;
    }
    return 1;
}

void generate_tac() //3.2
{
    //fprintf(fptrs,"//******Beginning of the TAC generated code\n");
    int i,ic1,ic2,icr,icv1;
    for(i=0;i<idx;i++)
    {
        //printf("%d****\n",i);
        if(strcmp(ic_code[i].opname,"ADD")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);

            fprintf(fptrs,"\tmovl\t%%edx, %%ecx\n\taddl\t%%eax, %%ecx\n\tmovl\t%%ecx, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"SUB")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);

            fprintf(fptrs,"\tmovl\t%%edx, %%ecx\n\tsubl\t%%eax, %%ecx\n\tmovl\t%%ecx, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"MUL")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);

            fprintf(fptrs,"\timull\t%%edx, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"DIV")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op2);

            fprintf(fptrs,"\tmovl\t%%edx, %%ecx\n\tcltd\n\tidivl\t%%ecx\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"MOD")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op2);

            fprintf(fptrs,"\tmovl\t%%edx, %%ecx\n\tcltd\n\tidivl\t%%ecx\tmovl\t%%edx, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"LSHIFT")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);

            fprintf(fptrs,"\tmovl\t%%edx, %%ebx\n\tmovb\t%%al, %%cl\n\tsall\t%%cl, %%ebx\n\tmovl\t%%ebx, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"RSHIFT")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);

            fprintf(fptrs,"\tmovl\t%%edx, %%ebx\n\tmovb\t%%al, %%cl\n\tsarl\t%%cl, %%ebx\n\tmovl\t%%ebx, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"XOR")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);

            fprintf(fptrs,"\txorl\t%%edx, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"B_OR")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);

            fprintf(fptrs,"\torl\t%%edx, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"B_AND")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);

            fprintf(fptrs,"\txandl\t%%edx, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"EQUAL_TO")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            icr=chk_type(ic_code[i].result);
            //printf("%d %d %d %s %s\n",i,icr,ic1,ic_code[i].result,ic_code[i].op1);
            if(ic1==2 || icr==2)
            {
                if(icr==2)
                {
                    //printf("res-> %s\n",ic_code[i].result);

                    strcpy(arr1_name,ic_code[i].result);
                    //strcpy(arr2_name,ic_code[i].result);
                    //printf("$$$$$ %s\n",arr2_name);
                    int t1=0,t2=0;
                    while(arr1_name[t1]!='[' && arr1_name[t1]!='\0') t1++;
                    arr1_name[t1]='\0';
                    //printf(">>>%s %d\n",arr1_name,t1);
                    t1++;
                    //printf("$$$$$ %s %c %c\n",arr2_name,t1,arr2_name[t1],arr2_name[t1+1]);
                    while(arr1_name[t1]!=']' && arr1_name[t1]!='\0') {var1_name[t2]=arr1_name[t1]; t2++; t1++; }
                    var1_name[t2]='\0';
                    //printf("<<< %s\n",var1_name);
                    //ic1=is_const(ic_code[i].op1);
                    icv1=chk_type(var1_name);
                    if(ic1==1)
                    {
                        if(icv1==1)
                        {
                            fprintf(fptrs,"\tmovl\t%s, %%eax\n\tmovl\t%s, %%edx\n\tmovl\t%%edx, %s(,%%eax,1)\n",var1_name,ic_code[i].op1,arr1_name);
                        }
                        else fprintf(fptrs,"\tmovl\t$%s, %%eax\n\tmovl\t%s, %%edx\n\tmovl\t%%edx, %s(,%%eax,1)\n",var1_name,ic_code[i].op1,arr1_name);
                    }
                    else
                    {
                        if(icv1==1) fprintf(fptrs,"\tmovl\t%s, %%eax\n\tmovl\t$%s, %%edx\n\tmovl\t%%edx, %s(,%%eax,1)\n",var1_name,ic_code[i].op1,arr1_name);
                        else fprintf(fptrs,"\tmovl\t$%s, %%eax\n\tmovl\t$%s, %%edx\n\tmovl\t%%edx, %s(,%%eax,1)\n",var1_name,ic_code[i].op1,arr1_name);
                    }
                }
                else
                {
                    //char arr1_name[11],var1_name[11];
                    strcpy(arr1_name,ic_code[i].op1);
                    //printf("op1= %s\n",ic_code[i].op1);
                    int t1=0,t2=0;
                    while(arr1_name[t1]!='[' && arr1_name[t1]!='\0') t1++;
                    arr1_name[t1]='\0';
                    //printf("*** %s\n",arr1_name);
                    t1++;
                    while(arr1_name[t1]!=']' && arr1_name[t1]!='\0') {var1_name[t2]=arr1_name[t1]; t2++; t1++;}
                    var1_name[t2]='\0';
                    icv1=chk_type(var1_name);
                    //printf("<<<in 2 <<< %s\n",var1_name);
                    if(icv1==1) fprintf(fptrs,"\tmovl\t%s, %%eax\n\tmovl\t%s(,%%eax,1), %%eax\n\tmovl\t%%eax, %s\n",var1_name,arr1_name,ic_code[i].result);
                    else fprintf(fptrs,"\tmovl\t$%s, %%eax\n\tmovl\t%s(,%%eax,1), %%eax\n\tmovl\t%%eax, %s\n",var1_name,arr1_name,ic_code[i].result);
                }
            }
            else if(ic1>=1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op1);
                fprintf(fptrs,"\tmovl\t%%eax, %s\n",ic_code[i].result);
            }
            else
            {
                fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op1);
                fprintf(fptrs,"\tmovl\t%%eax, %s\n",ic_code[i].result);
            }
        }
        else if(strcmp(ic_code[i].opname,"AND")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op1);

            if_label();
            fprintf(fptrs,"\ttestl\t%%eax, %%eax\n\tje\t%s\n",labelname);

            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);

            fprintf(fptrs,"\ttestl\t%%eax, %%eax\n\tje\t%s\n",labelname);
            strcpy(tempiflabel,labelname);
            if_label();
            fprintf(fptrs,"\tmovl	$1, %%eax\n\tjmp\t%s\n",labelname);
            fprintf(fptrs,"%s:\n\tmovl\t$0, %%eax\n",tempiflabel);
            fprintf(fptrs,"%s:\n\tmovl\t%%eax, %s\n",labelname,ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"OR")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op1);

            if_label();
            fprintf(fptrs,"\ttestl\t%%eax, %%eax\n\tjne\t%s\n",labelname);

            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);
            strcpy(tempiflabel,labelname);
            if_label();
            fprintf(fptrs,"\ttestl\t%%eax, %%eax\n\tje\t%s\n%s:\n",labelname,tempiflabel);
            strcpy(tempiflabel,labelname);
            if_label();
            fprintf(fptrs,"\tmovl\t$1, %%eax\n\tjmp	%s\n",labelname);
            fprintf(fptrs,"%s:\n\tmovl\t$0, %%eax\n",tempiflabel);
            fprintf(fptrs,"%s:\n\tmovl\t%%eax, %s\n",labelname,ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"LT")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);
            fprintf(fptrs,"\tcmpl\t%%eax, %%edx\n\tsetl\t%%al\n\tmovzbl\t%%al, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"GT")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);
            fprintf(fptrs,"\tcmpl\t%%eax, %%edx\n\tsetg\t%%al\n\tmovzbl\t%%al, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"LE")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);
            fprintf(fptrs,"\tcmpl\t%%eax, %%edx\n\tsetle\t%%al\n\tmovzbl\t%%al, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"GE")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);
            fprintf(fptrs,"\tcmpl\t%%eax, %%edx\n\tsetge\t%%al\n\tmovzbl\t%%al, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"EQ")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);
            fprintf(fptrs,"\tcmpl\t%%eax, %%edx\n\tsete\t%%al\n\tmovzbl\t%%al, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].opname,"NE")==0)
        {
            ic1=chk_type(ic_code[i].op1);
            ic2=chk_type(ic_code[i].op2);
            if(ic1==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%edx\n",ic_code[i].op1);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%edx\n",ic_code[i].op1);
            if(ic2==1)
            {
                fprintf(fptrs,"\tmovl\t%s, %%eax\n",ic_code[i].op2);
            }
            else fprintf(fptrs,"\tmovl\t$%s, %%eax\n",ic_code[i].op2);
            fprintf(fptrs,"\tcmpl\t%%eax, %%edx\n\tsetne\t%%al\n\tmovzbl\t%%al, %%eax\n\tmovl\t%%eax, %s\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].op2,"NA")==0)
        {
             fprintf(fptrs,"%s:\n",ic_code[i].result);
        }
        else if(strcmp(ic_code[i].result,"goto")==0)
        {
            if(strcmp(ic_code[i].opname,"NA")==0)
            {
                fprintf(fptrs,"\tjmp %s\n",ic_code[i].op2);
            }
            else
            {
                fprintf(fptrs,"\tmovl\t$0, %%edx\n\tmovl\t%s, %%eax\n\tcmpl\t%%eax,%%edx\n\tje %s\n",ic_code[i].op1,ic_code[i].op2);
            }
        }
       // printf("%d %d\n",i,idx);
    }
    //printf("loop se bahar\n");
    //fprintf(fptrs,"//******End of the TAC generated code\n");
}

void print_result() //3.3,3.4
{
    fprintf(fptrs,"\tmovl\tresult, %%eax\n\tmovl\t%%eax, 4(%%esp)\n\tmovl\t$printtext1, %%eax\n\tmovl\t%%eax, (%%esp)\n\tcall	_printf\n\n");
    fprintf(fptrs,"\tmovl\tsize, %%eax\n\tmovl\t%%eax, 4(%%esp)\n\tmovl\t$printtext2, %%eax\n\tmovl\t%%eax, (%%esp)\n\tcall\t_printf\n\n\tmovl\t$printtext3, %%eax\n\tmovl\t%%eax, (%%esp)\n\tmovl\t$0, %%ecx\n");
    fprintf(fptrs,"print_a:\n\tcmpl\t%%ecx, size\n\tjz \texit\n\tmovl\ta(,%%ecx,4), %%eax\n\tmovl\t%%eax, 4(%%esp)\n\tmovl\t%%ecx, temp_count\n\tcall\t_printf\n\tmovl\ttemp_count, %%ecx\n\taddl\t$1, %%ecx\n\tjmp\tprint_a\n");
    fprintf(fptrs,"exit:\n\tmovl %%ebp, %%esp\n\tpopl %%ebp\n\tret\n\n");
}

void generate_data() //3.5
{
    int i,j,found,kk,pp,arr_szt;
    fu=0;
    fprintf(fptrs,".data\nprinttext1: .ascii \"result = %%d\\n\\0\"\nprinttext2: .ascii \"size = %%d\\n\\0\"\nprinttext3: .ascii \"%%d, \\0\"\ntemp_count: .long 0\n\n");
    for(i=1;i<=len;i++)
    {
        if(symtab[i].arr_flag>0)
        {
            fprintf(fptrs,"%s: .long ",symtab[i].name);
            pp=strlen(symtab[i].val);
            kk=0;
            //if(symtab[i].sz)
            fprintf(fptrs,"%d, ",symtab[i].sz);
            int cntk;
            cntk=0;
            while(kk<pp)
            {
                if(symtab[i].val[kk]!=' ') fprintf(fptrs,"%c",symtab[i].val[kk]);
                else if(cntk==0) cntk=1;
                else fprintf(fptrs,", ");
                kk++;
            }
            fprintf(fptrs,"\n");
            strcpy(filled_up[fu],symtab[i].name);
            fu++;
        }
        else if(symtab[i].data_type!=0)
        {
            if(symtab[i].val[0]!='\0')
            {
                if(symtab[i].arr_flag>0)
                {
                    fprintf(fptrs,"%s: .long \n",symtab[i].name);
                    pp=strlen(symtab[i].val);
                    kk=0;
                    while(kk<pp-1)
                    {
                        if(symtab[i].val[kk]!=' ') fprintf(fptrs,"%c",symtab[i].val[kk]);
                        else fprintf(fptrs,",");
                        kk++;
                    }
                    fprintf(fptrs,"\n");
                }
                else fprintf(fptrs,"%s: .long %s\n",symtab[i].name,symtab[i].val);
            }
            else
            {
                fprintf(fptrs,"%s: .long 0\n",symtab[i].name);
            }
            strcpy(filled_up[fu],symtab[i].name);
            fu++;
        }
    }
    for(i=0;i<idx;i++)
    {
        found=0;
        for(j=0;j<fu;j++)
        {
            if(strcmp(filled_up[j],ic_code[i].result)==0)
            {
                found=1;
                break;
            }
        }
        if(found==0 && ic_code[i].result[0]=='t')
        {
            fprintf(fptrs,"%s: .long 0\n",ic_code[i].result);
            strcpy(filled_up[fu],ic_code[i].result);
            fu++;
        }
    }
}

void generate_code()
{
    print_header();
    generate_tac();
    print_result();
    generate_data();
}

