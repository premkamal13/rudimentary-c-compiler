%{
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

%}

%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INT
%token LONG REGISTER RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE

%token OPERATOR_PLUS OPERATOR_MINUS OPERATOR_INCREMENTOR OPERATOR_DECREMENTOR OPERATOR_ADDER OPERATOR_SUBTRACTOR
%token OPERATOR_MULTIPLIER OPERATOR_DIVIDER OPERATOR_MULTIPLY OPERATOR_DIVIDE OPERATOR_ASSIGNMENT OPERATOR_SLASH
%token OPERATOR_MODULUS OPERATOR_LESS_THAN OPERATOR_GREATER_THAN OPERATOR_NOT OPERATOR_BITWISE_AND OPERATOR_BITWISE_OR OPERATOR_AND
%token OPERATOR_OR OPERATOR_BITWISE_XOR OPERATOR_TILDE OPERATOR_EQUALITY_CHECKER OPERATOR_AND_ASSIGNMENT OPERATOR_OR_ASSIGNMENT
%token OPERATOR_LESS_OR_EQUAL OPERATOR_GREATER_OR_EQUAL OPERATOR_NOT_EQUAL OPERATOR_LINK OPERATOR_BITWISE_XOR_ASSIGNMENT
%token OPERATOR_RIGHT_SHIFT OPERATOR_LEFT_SHIFT OPERATOR_LEFT_ASSIGNMENT OPERATOR_RIGHT_ASSIGNMENT THREE_DOTS OPERATOR_MOD_ASSIGNMENT

%token DOT SQUARE_BRACKET_BEG SQUARE_BRACKET_END CURLY_BRACKET_BEG CURLY_BRACKET_END PARANTHESIS_BEG PARANTHESIS_END COMMA COLON SEMICOLON SHARP DOUBLE_QUOTES TERNARY

%token NUMBER REAL_NUMBER EXP_NUMBER CHAR_CONSTANT STRING_CONSTANT IDENTIFIER

%union{
        int type;
        struct lotus values;
        char varstr[1001];
      }

%type<values> IDENTIFIER NUMBER REAL_NUMBER EXP_NUMBER CHAR_CONSTANT STRING_CONSTANT
%type<varstr> assignment_expression conditional_expression unary_expression assignment_operator
%type<varstr> OPERATOR_ASSIGNMENT OPERATOR_MULTIPLIER OPERATOR_DIVIDER OPERATOR_MOD_ASSIGNMENT OPERATOR_ADDER OPERATOR_SUBTRACTOR
%type<varstr> OPERATOR_LEFT_ASSIGNMENT OPERATOR_RIGHT_ASSIGNMENT OPERATOR_AND_ASSIGNMENT OPERATOR_BITWISE_XOR_ASSIGNMENT OPERATOR_OR_ASSIGNMENT
%type<varstr> logical_OR_expression constant_expression logical_AND_expression inclusive_OR_expression exclusive_OR_expression
%type<varstr> AND_expression equality_expression relational_expression shift_expression additive_expression multiplicative_expression cast_expression
%type<varstr> type_name postfix_expression OPERATOR_BITWISE_AND OPERATOR_BITWISE_OR OPERATOR_MULTIPLY OPERATOR_PLUS OPERATOR_MINUS OPERATOR_TILDE OPERATOR_NOT
%type<varstr> primary_expression constant expression SQUARE_BRACKET_BEG SQUARE_BRACKET_END unary_operator selection_statement iteration_statement

%%

translation_unit:external_declaration {printf("\tReduced : translation_unit -> external_declaration\n");}
				|translation_unit external_declaration {printf("\tReduced : translation_unit -> translation_unit external_declaration\n");}
				;

external_declaration:function_definition {printf("\tReduced : external_declaration -> function_definition\n");}
					|declaration {printf("\tReduced : external_declaration -> declaration\n");}
					;

function_definition:declaration_specifiers declarator declaration_list compound_statement {printf("\tReduced : function_definition -> declaration_specifiers declarator declaration_list compound_statement\n");}
				   |declarator declaration_list compound_statement {printf("\tReduced : function_definition -> declarator declaration_list compound_statement\n");}
				   |declaration_specifiers declarator compound_statement {printf("\tReduced : function_definition -> declaration_specifiers declarator compound_statement\n");}
				   |declarator compound_statement {printf("\tReduced : function_definition -> declarator compound_statement\n");}
				   ;

declaration:declaration_specifiers init_declarator_list SEMICOLON {flag=0; cnt=0; scs=0; tq=0; printf("\tReduced : declaration -> declaration_specifiers init_declarator_list SEMICOLON\n");}
		   |declaration_specifiers SEMICOLON {cnt=0; scs=0; tq=0; printf("\tReduced : declaration -> declaration_specifiers SEMICOLON\n");}
		   ;

declaration_list:declaration {printf("\tReduced : declaration_list -> declaration\n");}
				|declaration_list declaration {printf("\tReduced : declaration_list -> declaration_list declaration\n");}
				;

declaration_specifiers:storage_class_specifier declaration_specifiers { printf("\tReduced : declaration_specifiers -> storage_class_specifier declaration_specifiers\n");}
					  |storage_class_specifier { printf("\tReduced : declaration_specifiers -> storage_class_specifier\n");}
					  |type_specifier declaration_specifiers {printf("\tReduced : declaration_specifiers -> type_specifier declaration_specifiers\n");}
					  |type_specifier {printf("\tReduced : declaration_specifiers -> type_specifier\n");}
					  |type_qualifier declaration_specifiers {printf("\tReduced : declaration_specifiers -> type_qualifier declaration_specifiers\n");}
					  |type_qualifier {printf("\tReduced : declaration_specifiers -> type_qualifier\n");}
					  ;

storage_class_specifier:AUTO { spec(); printf("\tReduced : storage_class_specifier -> AUTO \n");}
					   |REGISTER {spec(); printf("\tReduced : storage_class_specifier -> REGISTER\n");}
					   |STATIC {spec(); printf("\tReduced : storage_class_specifier -> STATIC\n");}
					   |EXTERN {spec(); printf("\tReduced : storage_class_specifier -> EXTERN\n");}
					   |TYPEDEF {spec(); printf("\tReduced : storage_class_specifier -> TYPEDEF\n");}
					   ;

type_specifier:VOID { func(200000); printf("\tReduced : type_specifier -> VOID\n");}
			  |CHAR { func(1); printf("\tReduced : type_specifier -> CHAR\n");}
			  |INT { func(4); printf("\tReduced : type_specifier -> INT\n");}
			  |FLOAT { func(16); printf("\tReduced : type_specifier -> FLOAT\n");}
			  |DOUBLE { func(64); printf("\tReduced : type_specifier -> DOUBLE\n");}
			  |SHORT { func(1000); printf("\tReduced : type_specifier -> SHORT\n");}
			  |LONG { func(4000); printf("\tReduced : type_specifier -> LONG\n");}
			  |SIGNED { func(10000); printf("\tReduced : type_specifier -> SIGNED\n");}
			  |UNSIGNED { func(10000); printf("\tReduced : type_specifier -> UNSIGNED\n");}
			  |struct_or_union_specifier { func(200000); printf("\tReduced : type_specifier -> struct_or_union_specifier\n");}
			  |enum_specifier { func(200000); printf("\tReduced : type_specifier -> enum_specifier\n");}
			  ;

type_qualifier:CONST { printf("\tReduced : type_qualifier -> CONST\n");}
			  |VOLATILE { printf("\tReduced : type_qualifier -> VOLATILE\n");}
			  ;

struct_or_union_specifier:struct_or_union IDENTIFIER CURLY_BRACKET_BEG struct_declaration_list CURLY_BRACKET_END {printf("\tReduced : struct_or_union_specifier -> struct_or_union IDENTIFIER CURLY_BRACKET_BEG struct_declaration_list CURLY_BRACKET_END\n");}
						 |struct_or_union CURLY_BRACKET_BEG struct_declaration_list CURLY_BRACKET_END {printf("\tReduced : struct_or_union_specifier -> struct_or_union CURLY_BRACKET_BEG struct_declaration_list CURLY_BRACKET_END\n");}
						 |struct_or_union IDENTIFIER {printf("\tReduced : struct_or_union_specifier -> struct_or_union IDENTIFIER\n");}
						 ;

struct_or_union:STRUCT {printf("\tReduced : struct_or_union -> STRUCT\n");}
			   |UNION {printf("\tReduced : struct_or_union -> UNION\n");}
			   ;

struct_declaration_list:struct_declaration {printf("\tReduced : struct_declaration_list -> struct_declaration\n");}
					   |struct_declaration_list struct_declaration {printf("\tReduced : struct_declaration_list -> struct_declaration_list struct_declaration\n");}
					   ;

init_declarator_list:init_declarator {printf("\tReduced : init_declarator_list -> init_declarator\n");}
					|init_declarator_list COMMA init_declarator {printf("\tReduced : init_declarator_list -> init_declarator_list COMMA init_declarator\n");}
					;

init_declarator:declarator {printf("\tReduced : init_declarator -> declarator\n");}
			   |declarator OPERATOR_ASSIGNMENT initializer {printf("\tReduced : init_declarator -> declarator OPERATOR_ASSIGNMENT initializer\n");}
			   ;

struct_declaration:specifier_qualifier_list struct_declarator_list SEMICOLON
                    {
                        printf("\tReduced : struct_declaration -> specifier_qualifier_list struct_declarator_list SEMICOLON\n");
                        fill_dimensions();
                    }
                  ;

specifier_qualifier_list:type_specifier specifier_qualifier_list {printf("\tReduced : specifier_qualifier_list -> type_specifier specifier_qualifier_list\n");}
						|type_specifier {printf("\tReduced : specifier_qualifier_list -> type_specifier\n");}
						|type_qualifier specifier_qualifier_list {printf("\tReduced : specifier_qualifier_list -> type_qualifier specifier_qualifier_list\n");}
						|type_qualifier {printf("\tReduced : specifier_qualifier_list -> type_qualifier\n");}
						;

struct_declarator_list:struct_declarator {printf("\tReduced : struct_declarator_list -> struct_declarator\n");}
					  |struct_declarator_list COMMA struct_declarator {printf("\tReduced : struct_declarator_list -> struct_declarator_list COMMA struct_declarator\n");}

struct_declarator:declarator {printf("\tReduced : struct_declarator -> declarator\n");}
				 |declarator COLON constant_expression {printf("\tReduced : struct_declarator -> declarator COLON constant_expression\n");}
				 |COLON constant_expression {printf("\tReduced : struct_declarator -> COLON constant_expression\n");}
				 ;

enum_specifier:ENUM IDENTIFIER CURLY_BRACKET_BEG enumerator_list CURLY_BRACKET_END {printf("\tReduced : enum_specifier -> ENUM IDENTIFIER CURLY_BRACKET_BEG enumerator_list CURLY_BRACKET_END\n");}
			  |ENUM CURLY_BRACKET_BEG enumerator_list CURLY_BRACKET_END {printf("\tReduced : enum_specifier -> ENUM CURLY_BRACKET_BEG enumerator_list CURLY_BRACKET_END\n");}
			  |ENUM IDENTIFIER {printf("\tReduced : enum_specifier -> ENUM IDENTIFIER\n");}
			  ;

enumerator_list:enumerator {printf("\tReduced : enumerator_list -> enumerator\n");}
			   |enumerator_list COMMA enumerator {printf("\tReduced : enumerator_list -> enumerator_list COMMA enumerator\n");}
			   ;

enumerator:IDENTIFIER {printf("\tReduced : enumerator -> IDENTIFIER\n");}
		  |IDENTIFIER OPERATOR_ASSIGNMENT constant_expression {printf("\tReduced : enumerator -> IDENTIFIER OPERATOR_ASSIGNMENT constant_expression\n");}
		  ;

declarator:pointer direct_declarator {printf("\tReduced : declarator -> pointer direct_declarator\n");}
		  |direct_declarator {printf("\tReduced : declarator -> direct_declarator\n");}
		  ;

direct_declarator:IDENTIFIER { flag=1; printf("\tReduced : direct_declarator -> IDENTIFIER\n");
                                if(duplicate($1.name))
                                {
                                    f=5;
                                    //printf("Problem is in table\n");
                                    strcpy(temp,$1.name);
                                    yyerror();
                                }
                                else
                                {
                                    //printf("start");
                                    len++;
                                    strcpy(symtab[len].name,$1.name);
                                    symtab[len].data_type=cnt;
                                    symtab[len].line_no=line_num;
                                    symtab[len].arr_flag=0;
                                    //symtab[len].val=" ";
                                }
                             }
				 |PARANTHESIS_BEG declarator PARANTHESIS_END {printf("\tReduced : direct_declarator -> PARANTHESIS_BEG declarator PARANTHESIS_END\n");}
				 |direct_declarator SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END
				 {
				     printf("\tReduced : direct_declarator -> direct_declarator SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END\n");
				     symtab[len].arr_flag=1;
				     symtab[len].arr_sz++;
				     fill_dimensions();
                 }
				 |direct_declarator SQUARE_BRACKET_BEG SQUARE_BRACKET_END
				 {
				     printf("\tReduced : direct_declarator -> direct_declarator SQUARE_BRACKET_BEG SQUARE_BRACKET_END\n");
                     symtab[len].arr_flag=1;
                     symtab[len].arr_sz++;
                     //fill_dimensions();
				 }
				 |direct_declarator PARANTHESIS_BEG parameter_type_list PARANTHESIS_END {printf("\tReduced : direct_declarator -> direct_declarator PARANTHESIS_BEG parameter_type_list PARANTHESIS_END\n");}
				 |direct_declarator PARANTHESIS_BEG identifier_list PARANTHESIS_END {printf("\tReduced : direct_declarator -> direct_declarator PARANTHESIS_BEG identifier_list PARANTHESIS_END\n");}
				 |direct_declarator PARANTHESIS_BEG PARANTHESIS_END {printf("\tReduced : direct_declarator -> direct_declarator PARANTHESIS_BEG PARANTHESIS_END\n");}
				 ;

pointer:OPERATOR_MULTIPLY type_qualifier_list {printf("\tReduced : pointer -> OPERATOR_MULTIPLY type_qualifier_list\n");}
	   |OPERATOR_MULTIPLY {printf("\tReduced : pointer -> OPERATOR_MULTIPLY\n");}
	   |OPERATOR_MULTIPLY type_qualifier_list pointer {printf("\tReduced : pointer -> OPERATOR_MULTIPLY type_qualifier_list pointer\n");}
	   |OPERATOR_MULTIPLY pointer {printf("\tReduced : pointer -> OPERATOR_MULTIPLY pointer\n");}
	   ;

type_qualifier_list:type_qualifier {printf("\tReduced : type_qualifier_list -> type_qualifier\n");}
				   |type_qualifier_list type_qualifier {printf("\tReduced : type_qualifier_list -> type_qualifier_list type_qualifier\n");}
				   ;

parameter_type_list:parameter_list {printf("\tReduced : parameter_type_list -> parameter_list\n");}
				   |parameter_list COMMA THREE_DOTS {printf("\tReduced : parameter_type_list -> parameter_list COMMA THREE_DOTS\n");}
				   ;

parameter_list:parameter_declaration {printf("\tReduced : parameter_list -> parameter_declaration\n");}
			  |parameter_list COMMA parameter_declaration {printf("\tReduced : parameter_list -> parameter_list COMMA parameter_declaration\n");}
			  ;

parameter_declaration:declaration_specifiers declarator {printf("\tReduced : parameter_declaration -> declaration_specifiers declarator\n");}
					 |declaration_specifiers abstract_declarator {printf("\tReduced : parameter_declaration -> declaration_specifiers abstract_declarator\n");}
					 |declaration_specifiers {printf("\tReduced : parameter_declaration -> declaration_specifiers\n");}
					 ;

identifier_list:IDENTIFIER {printf("\tReduced : identifier_list -> IDENTIFIER\n");}
			   |identifier_list COMMA IDENTIFIER {printf("\tReduced : identifier_list -> identifier_list COMMA IDENTIFIER\n");}
			   ;

initializer:assignment_expression {printf("\tReduced : initializer -> assignment_expression\n");}
		   |CURLY_BRACKET_BEG initializer_list CURLY_BRACKET_END {printf("\tReduced : initializer -> CURLY_BRACKET_BEG initializer_list CURLY_BRACKET_END\n");}
		   |CURLY_BRACKET_BEG initializer_list COMMA CURLY_BRACKET_END {printf("\tReduced : initializer -> CURLY_BRACKET_BEG initializer_list COMMA CURLY_BRACKET_END\n");}
		   ;

initializer_list:initializer {printf("\tReduced : initializer_list -> initializer\n");}
				|initializer_list COMMA initializer {printf("\tReduced : initializer_list -> initializer_list COMMA initializer\n");}
				;

type_name:specifier_qualifier_list abstract_declarator {printf("\tReduced : type_name -> specifier_qualifier_list abstract_declarator\n");}
		 |specifier_qualifier_list {printf("\tReduced : type_name -> specifier_qualifier_list\n");}
		 ;

abstract_declarator:pointer {printf("\tReduced : abstract_declarator ->  pointer\n");}
				   |pointer direct_abstract_declarator {printf("\tReduced : abstract_declarator ->  pointer direct_abstract_declarator\n");}
				   |direct_abstract_declarator {printf("\tReduced : abstract_declarator -> direct_abstract_declarator\n");}
				   ;

direct_abstract_declarator:PARANTHESIS_BEG abstract_declarator PARANTHESIS_END {printf("\tReduced : direct_abstract_declarator -> PARANTHESIS_BEG abstract_declarator PARANTHESIS_END\n");}
						  |direct_abstract_declarator SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END\n");}
						  |SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END {printf("\tReduced : direct_abstract_declarator -> SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END\n");}
						  |direct_abstract_declarator SQUARE_BRACKET_BEG SQUARE_BRACKET_END {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator SQUARE_BRACKET_BEG SQUARE_BRACKET_END\n");}
						  |SQUARE_BRACKET_BEG SQUARE_BRACKET_END {printf("\tReduced : direct_abstract_declarator -> SQUARE_BRACKET_BEG SQUARE_BRACKET_END\n");}
						  |direct_abstract_declarator PARANTHESIS_BEG parameter_type_list PARANTHESIS_END {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator PARANTHESIS_BEG parameter_type_list PARANTHESIS_END\n");}
						  |PARANTHESIS_BEG parameter_type_list PARANTHESIS_END {printf("\tReduced : direct_abstract_declarator -> PARANTHESIS_BEG parameter_type_list PARANTHESIS_END\n");}
						  |direct_abstract_declarator PARANTHESIS_BEG PARANTHESIS_END {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator PARANTHESIS_BEG PARANTHESIS_END\n");}
						  |PARANTHESIS_BEG PARANTHESIS_END {printf("\tReduced : direct_abstract_declarator -> PARANTHESIS_BEG PARANTHESIS_END\n");}
						  ;


statement:labeled_statement {printf("\tReduced : statement -> labeled_statement\n");}
		 |expression_statement {printf("\tReduced : statement -> expression_statement\n");}
		 |compound_statement {printf("\tReduced : statement -> compound_statement\n");}
		 |selection_statement {printf("\tReduced : statement -> selection_statement\n");}
		 |iteration_statement {printf("\tReduced : statement -> iteration_statement\n");}
		 |jump_statement {printf("\tReduced : statement -> jump_statement\n");}
		 ;

labeled_statement:IDENTIFIER COLON statement {printf("\tReduced : labeled_statement -> IDENTIFIER COLON statement\n");}
				 |CASE constant_expression COLON statement {printf("\tReduced : labeled_statement -> CASE constant_expression COLON statement\n");}
				 |DEFAULT COLON statement {printf("\tReduced : labeled_statement -> DEFAULT COLON statement\n");}
				 ;

expression_statement:expression SEMICOLON { if(found_arr_name>0) {f=9;yyerror();} found_arr_name=0;equals_seen=0; printf("\tReduced : expression_statement -> expression SEMICOLON\n");}
					|SEMICOLON { if(found_arr_name>0) {f=9;yyerror();} found_arr_name=0;equals_seen=0; printf("\tReduced : expression_statement -> SEMICOLON\n");}
					;

compound_statement:CURLY_BRACKET_BEG declaration_list statement_list CURLY_BRACKET_END {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG declaration_list statement_list CURLY_BRACKET_END\n");}
				  |CURLY_BRACKET_BEG declaration_list CURLY_BRACKET_END {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG declaration_list CURLY_BRACKET_END\n");}
				  |CURLY_BRACKET_BEG statement_list CURLY_BRACKET_END {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG statement_list CURLY_BRACKET_END\n");}
				  |CURLY_BRACKET_BEG CURLY_BRACKET_END {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG CURLY_BRACKET_END\n");}
				  ;

statement_list:statement {printf("\tReduced : statement_list -> statement\n");}
			  |statement_list statement {printf("\tReduced : statement_list -> statement_list statement\n");}
			  ;

selection_statement:IF PARANTHESIS_BEG expression PARANTHESIS_END
                    {
                        new_label();
                        fprintf(fptr,"IF FALSE %s, goto %s\n",$3,labelname);

                        strcpy(ic_code[idx].result,"goto");// storing the label to go to in $3
                        strcpy(ic_code[idx].op1,$3);
                        strcpy(ic_code[idx].opname,"IF_FALSE");
                        strcpy(ic_code[idx].op2,labelname);
                        idx++;

                        strcpy(label_stack[top++],labelname);
                    }
                    statement else_selection_statement
                    {
                        printf("\tReduced : selection_statement -> IF PARANTHESIS_BEG expression PARANTHESIS_END statement else_selection_statement\n");
                    }
				   |SWITCH PARANTHESIS_BEG expression PARANTHESIS_END statement {printf("\tReduced : selection_statement -> SWITCH PARANTHESIS_BEG expression PARANTHESIS_END statement\n");}
				   ;

else_selection_statement: ELSE
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
                          }
                          statement
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
                          }
                        |
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
                          }
                        ;

iteration_statement:WHILE print_while PARANTHESIS_BEG expression PARANTHESIS_END
                    {
                        new_label();
                        fprintf(fptr,"IF FALSE %s, goto %s\n",$4,labelname);

                        strcpy(ic_code[idx].result,"goto");
                        strcpy(ic_code[idx].op1,$4);
                        strcpy(ic_code[idx].opname,"IF_FALSE");
                        strcpy(ic_code[idx].op2,labelname);
                        idx++;

                        strcpy(label_stack[top++],labelname);
                    }
                    statement
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
                    }
				   |DO statement WHILE PARANTHESIS_BEG expression PARANTHESIS_END SEMICOLON {printf("\tReduced : iteration_statement -> DO statement WHILE PARANTHESIS_BEG expression PARANTHESIS_END SEMICOLON\n");}
				   |FOR PARANTHESIS_BEG expression SEMICOLON expression SEMICOLON expression PARANTHESIS_END statement {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON expression SEMICOLON expression PARANTHESIS_END statement\n");}
				   |FOR PARANTHESIS_BEG expression SEMICOLON expression SEMICOLON PARANTHESIS_END statement {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON expression SEMICOLON PARANTHESIS_END statement\n");}
				   |FOR PARANTHESIS_BEG expression SEMICOLON SEMICOLON expression PARANTHESIS_END statement {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON SEMICOLON expression PARANTHESIS_END statement\n");}
				   |FOR PARANTHESIS_BEG expression SEMICOLON SEMICOLON PARANTHESIS_END statement {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG expression SEMICOLON SEMICOLON PARANTHESIS_END statement\n");}
				   |FOR PARANTHESIS_BEG SEMICOLON expression SEMICOLON expression PARANTHESIS_END statement {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON expression SEMICOLON expression PARANTHESIS_END statement\n");}
				   |FOR PARANTHESIS_BEG SEMICOLON expression SEMICOLON PARANTHESIS_END statement {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON expression SEMICOLON PARANTHESIS_END statement\n");}
				   |FOR PARANTHESIS_BEG SEMICOLON SEMICOLON expression PARANTHESIS_END statement {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON SEMICOLON expression PARANTHESIS_END statement\n");}
				   |FOR PARANTHESIS_BEG SEMICOLON SEMICOLON PARANTHESIS_END statement {printf("\tReduced : iteration_statement -> FOR PARANTHESIS_BEG SEMICOLON SEMICOLON PARANTHESIS_END statement\n");}
				   ;

print_while:{
                 new_label();
                 strcpy(label_stack[top++],labelname);
                 fprintf(fptr,"%s:\n",labelname);

                 strcpy(ic_code[idx].result,labelname);
                 strcpy(ic_code[idx].op1,"NA");
                 strcpy(ic_code[idx].opname,"NA");
                 strcpy(ic_code[idx].op2,"NA");
                 idx++;

            }
            ;

jump_statement:GOTO IDENTIFIER SEMICOLON {printf("\tReduced : jump_statement -> GOTO IDENTIFIER SEMICOLON\n");}
			  |CONTINUE SEMICOLON {printf("\tReduced : jump_statement -> CONTINUE SEMICOLON\n");}
			  |BREAK SEMICOLON {printf("\tReduced : jump_statement -> BREAK SEMICOLON\n");}
			  |RETURN expression SEMICOLON {printf("\tReduced : jump_statement -> RETURN expression SEMICOLON\n");}
			  |RETURN SEMICOLON {printf("\tReduced : jump_statement -> RETURN SEMICOLON\n");}
			  ;

expression:assignment_expression
            {
                printf("\tReduced : expression -> assignment_expression\n");
                strcpy($$,$1);
            }
		  |expression COMMA assignment_expression
            {
                printf("\tReduced : expression -> expression COMMA assignment_expression\n");
                strcpy($$,$1);
            }
		  ;

assignment_expression:conditional_expression
                    {
                        printf("\tReduced : assignment_expression -> conditional_expression\n");
                        strcpy($$,$1);
                    }
					 |unary_expression assignment_operator assignment_expression
					 {
					     dimfound=0;
					     d1=0;
					     printf("\tReduced : assignment_expression -> unary_expression assignment_operator assignment_expression\n");
					     //fprintf(fptr,"%s %s %s %s\n",$$,$1,$2,$3);
					     if(strcmp($2,"=")==0)
					     {
					         //new_var();
					         fprintf(fptr,"%s = %s\n",$1,$3);

					         strcpy(ic_code[idx].result,$1);
                             strcpy(ic_code[idx].op1,$3);
                             strcpy(ic_code[idx].opname,"EQUAL_TO");
                             strcpy(ic_code[idx].op2,"NA");
                             idx++;

					         strcpy($$,$1);
					     }
					     else if(strcmp($2,"*=")==0)
					     {
					         fprintf(fptr,"%s = %s * %s\n",$1,$1,$3);

					         strcpy(ic_code[idx].result,$1);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"MUL");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

					         strcpy($$,$1);
					     }
					     else if(strcmp($2,"/=")==0)
					     {
					         fprintf(fptr,"%s = %s / %s\n",$1,$1,$3);

					         strcpy(ic_code[idx].result,$1);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"DIV");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

					         strcpy($$,$1);
					     }
					     else if(strcmp($2,"+=")==0)
					     {
					         fprintf(fptr,"%s = %s + %s\n",$1,$1,$3);

					         strcpy(ic_code[idx].result,$1);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"ADD");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

					         strcpy($$,$1);
					     }
					     else if(strcmp($2,"-=")==0)
					     {
					         fprintf(fptr,"%s = %s - %s\n",$1,$1,$3);

					         strcpy(ic_code[idx].result,$1);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"SUB");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

					         strcpy($$,$1);
					     }
					     else if(strcmp($2,"<<=")==0)
					     {
					         fprintf(fptr,"%s = %s LS %s\n",$1,$1,$3);

					         strcpy(ic_code[idx].result,$1);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"LSHIFT");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

					         strcpy($$,$1);
					     }
					     else if(strcmp($2,">>=")==0)
					     {
					         fprintf(fptr,"%s = %s RS %s\n",$1,$1,$3);

					         strcpy(ic_code[idx].result,$1);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"RSHIFT");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

					         strcpy($$,$1);
					     }
					     else if(strcmp($2,"&=")==0)
					     {
					         fprintf(fptr,"%s = %s B_AND %s\n",$1,$1,$3);

					         strcpy(ic_code[idx].result,$1);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"B_AND");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

					         strcpy($$,$1);
					     }
					     else if(strcmp($2,"^=")==0)
					     {
					         fprintf(fptr,"%s = %s XOR %s\n",$1,$1,$3);

					         strcpy(ic_code[idx].result,$1);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"XOR");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

					         strcpy($$,$1);
					     }
					     else if(strcmp($2,"|=")==0)
					     {
					         fprintf(fptr,"%s = %s B_OR %s\n",$1,$1,$3);

					         strcpy(ic_code[idx].result,$1);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"B_OR");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

					         strcpy($$,$1);
					     }
                    }
					 ;

assignment_operator:OPERATOR_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_ASSIGNMENT\n");strcpy($$,"=");equals_seen=1;}//;dimfound=0;}
				   |OPERATOR_MULTIPLIER {printf("\tReduced : assignment_operator -> OPERATOR_MULTIPLIER\n");strcpy($$,"*=");}
				   |OPERATOR_DIVIDER {printf("\tReduced : assignment_operator -> OPERATOR_DIVIDER\n");strcpy($$,"/=");}
				   |OPERATOR_MOD_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_MOD_ASSIGNMENT\n");strcpy($$,"%=");}
				   |OPERATOR_ADDER {printf("\tReduced : assignment_operator -> OPERATOR_ADDER\n");strcpy($$,"+=");}
				   |OPERATOR_SUBTRACTOR {printf("\tReduced : assignment_operator -> OPERATOR_SUBTRACTOR\n");strcpy($$,"-=");}
				   |OPERATOR_LEFT_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_LEFT_ASSIGNMENT\n");strcpy($$,"<<=");}
				   |OPERATOR_RIGHT_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_RIGHT_ASSIGNMENT\n");strcpy($$,">>=");}
				   |OPERATOR_AND_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_AND_ASSIGNMENT\n");strcpy($$,"&=");}
				   |OPERATOR_BITWISE_XOR_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_BITWISE_XOR_ASSIGNMENT\n");strcpy($$,"^=");}
				   |OPERATOR_OR_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_OR_ASSIGNMENT\n");strcpy($$,"|=");}
				   ;

conditional_expression:logical_OR_expression {printf("\tReduced : conditional_expression -> logical_OR_expression\n");strcpy($$,$1);}
					  |logical_OR_expression TERNARY expression COLON conditional_expression {printf("\tReduced : conditional_expression -> logical_OR_expression TERNARY expression COLON conditional_expression\n");}
					  ;

constant_expression:conditional_expression {printf("\tReduced : constant_expression -> conditional_expression\n");strcpy($$,$1);}
				   ;

logical_OR_expression:logical_AND_expression {printf("\tReduced : logical_OR_expression -> logical_AND_expression\n");strcpy($$,$1);}
					 |logical_OR_expression OPERATOR_OR logical_AND_expression
					 {
					     printf("\tReduced : logical_OR_expression -> logical_OR_expression OPERATOR_OR logical_AND_expression\n");
					     new_var();
					     fprintf(fptr,"%s = %s OR %s\n",varname,$1,$3);

					     strcpy(ic_code[idx].result,varname);
                         strcpy(ic_code[idx].op1,$1);
                         strcpy(ic_code[idx].opname,"OR");
                         strcpy(ic_code[idx].op2,$3);
                         idx++;

					     strcpy($$,varname);
                     }
					 ;

logical_AND_expression:inclusive_OR_expression {printf("\tReduced : logical_AND_expression -> inclusive_OR_expression\n");strcpy($$,$1);}
					  |logical_AND_expression OPERATOR_AND inclusive_OR_expression
					  {
					      printf("\tReduced : logical_AND_expression -> logical_AND_expression OPERATOR_AND inclusive_OR_expression\n");
					      new_var();
					      fprintf(fptr,"%s = %s AND %s\n",varname,$1,$3);

					      strcpy(ic_code[idx].result,varname);
                          strcpy(ic_code[idx].op1,$1);
                          strcpy(ic_code[idx].opname,"AND");
                          strcpy(ic_code[idx].op2,$3);
                          idx++;

					      strcpy($$,varname);
                      }
					  ;

inclusive_OR_expression:exclusive_OR_expression {printf("\tReduced : inclusive_OR_expression -> exclusive_OR_expression\n"); strcpy($$,$1);}
					   |inclusive_OR_expression OPERATOR_BITWISE_OR exclusive_OR_expression
					   {
					       printf("\tReduced : inclusive_OR_expression -> inclusive_OR_expression OPERATOR_BITWISE_OR exclusive_OR_expression\n");
					       new_var();
					       fprintf(fptr,"%s = %s B_OR %s\n",varname,$1,$3);
					       strcpy($$,varname);
                       }
					   ;

exclusive_OR_expression:AND_expression {printf("\tReduced : exclusive_OR_expression -> AND_expression\n"); strcpy($$,$1);}
					   |exclusive_OR_expression OPERATOR_BITWISE_XOR AND_expression
					   {
					       printf("\tReduced : exclusive_OR_expression -> exclusive_OR_expression OPERATOR_BITWISE_XOR AND_expression\n");
					       new_var();
					       fprintf(fptr,"%s = %s XOR %s\n",varname,$1,$3);

					       strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$1);
                           strcpy(ic_code[idx].opname,"XOR");
                           strcpy(ic_code[idx].op2,$3);
                           idx++;

					       strcpy($$,varname);
                       }
					   ;

AND_expression:equality_expression {printf("\tReduced : AND_expression -> equality_expression\n"); strcpy($$,$1);}
			  |AND_expression OPERATOR_BITWISE_AND equality_expression
			  {
			      printf("\tReduced : AND_expression -> AND_expression OPERATOR_BITWISE_AND equality_expression\n");
			      new_var();
                  fprintf(fptr,"%s = %s B_AND %s\n",varname,$1,$3);

                  strcpy(ic_code[idx].result,varname);
                  strcpy(ic_code[idx].op1,$1);
                  strcpy(ic_code[idx].opname,"B_AND");
                  strcpy(ic_code[idx].op2,$3);
                  idx++;

                  strcpy($$,varname);
              }

equality_expression:relational_expression {printf("\tReduced : equality_expression -> relational_expression\n");strcpy($$,$1);}
				   |equality_expression OPERATOR_EQUALITY_CHECKER relational_expression
				   {
				       printf("\tReduced : equality_expression -> equality_expression OPERATOR_EQUALITY_CHECKER relational_expression\n");
                       if(chk_type($1)==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,$1);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$1);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type($3)==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,$3);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$3);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,$3);
                           new_var();
                           fprintf(fptr,"%s = %s EQ %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"EQ");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s EQ %s\n",varname,$1,$3);
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,$1);
                       strcpy(ic_code[idx].opname,"EQ");
                       strcpy(ic_code[idx].op2,$3);
                       idx++;}

					     strcpy($$,varname);
                     }
				   |equality_expression OPERATOR_NOT_EQUAL relational_expression
				   {
				       printf("\tReduced : equality_expression -> equality_expression OPERATOR_NOT_EQUAL relational_expression\n");
				       if(chk_type($1)==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,$1);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$1);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type($3)==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,$3);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$3);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,$3);
                           new_var();
                           fprintf(fptr,"%s = %s NE %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"NE");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s NE %s\n",varname,$1,$3);
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,$1);
                       strcpy(ic_code[idx].opname,"NE");
                       strcpy(ic_code[idx].op2,$3);
                       idx++;}

					     strcpy($$,varname);
                     }
				   ;

relational_expression:shift_expression {printf("\tReduced : relational_expression -> shift_expression\n");strcpy($$,$1);}
					 |relational_expression OPERATOR_LESS_THAN shift_expression
					 {
					     printf("\tReduced : relational_expression -> relational_expression OPERATOR_LESS_THAN shift_expression\n");
					     if(chk_type($1)==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,$1);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$1);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type($3)==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,$3);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$3);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,$3);
                           new_var();
                           fprintf(fptr,"%s = %s LT %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"LT");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s LT %s\n",varname,$1,$3);
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,$1);
                       strcpy(ic_code[idx].opname,"LT");
                       strcpy(ic_code[idx].op2,$3);
                       idx++;}

					     strcpy($$,varname);
                     }
					 |relational_expression OPERATOR_GREATER_THAN shift_expression
					 {
					     printf("\tReduced : relational_expression -> relational_expression OPERATOR_GREATER_THAN shift_expression\n");
					     if(chk_type($1)==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,$1);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$1);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type($3)==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,$3);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$3);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,$3);
                           new_var();
                           fprintf(fptr,"%s = %s GT %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"GT");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s GT %s\n",varname,$1,$3);
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,$1);
                       strcpy(ic_code[idx].opname,"GT");
                       strcpy(ic_code[idx].op2,$3);
                       idx++;}

					     strcpy($$,varname);
                     }
					 |relational_expression OPERATOR_LESS_OR_EQUAL shift_expression
					 {
					     printf("\tReduced : relational_expression -> relational_expression OPERATOR_LESS_OR_EQUAL shift_expression\n");
					     if(chk_type($1)==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,$1);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$1);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type($3)==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,$3);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$3);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,$3);
                           new_var();
                           fprintf(fptr,"%s = %s LE %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"LE");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s LE %s\n",varname,$1,$3);
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,$1);
                       strcpy(ic_code[idx].opname,"LE");
                       strcpy(ic_code[idx].op2,$3);
                       idx++;}

					     strcpy($$,varname);
                     }
					 |relational_expression OPERATOR_GREATER_OR_EQUAL shift_expression
					 {
					     printf("\tReduced : relational_expression -> relational_expression OPERATOR_GREATER_OR_EQUAL shift_expression\n");
					     if(chk_type($1)==2)
                       {
                           new_var();
                           fprintf(fptr,"%s = %s\n",varname,$1);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$1);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempssstr,varname);

                           if(chk_type($3)==2)
                           {
                               new_var();
                           fprintf(fptr,"%s = %s\n",varname,$3);

                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,$3);
                           strcpy(ic_code[idx].opname,"EQUAL_TO");
                           strcpy(ic_code[idx].op2,"NA");
                           idx++;
                           strcpy(tempsss1tr,varname);
                           }
                           else strcpy(tempsss1tr,$3);
                           new_var();
                           fprintf(fptr,"%s = %s GE %s\n",varname,tempssstr,tempsss1tr);
                           strcpy(ic_code[idx].result,varname);
                           strcpy(ic_code[idx].op1,tempssstr);
                           strcpy(ic_code[idx].opname,"GE");
                           strcpy(ic_code[idx].op2,tempsss1tr);
                           idx++;
                       }
                       else {new_var();fprintf(fptr,"%s = %s GE %s\n",varname,$1,$3);
                       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,$1);
                       strcpy(ic_code[idx].opname,"GE");
                       strcpy(ic_code[idx].op2,$3);
                       idx++;}

					     strcpy($$,varname);
                     }
					 ;

shift_expression:additive_expression {printf("\tReduced : shift_expression -> additive_expression\n");strcpy($$,$1);}
			    |shift_expression OPERATOR_LEFT_SHIFT additive_expression
			    {
			        printf("\tReduced : shift_expression -> shift_expression OPERATOR_LEFT_SHIFT additive_expression\n");
			        new_var();
                    fprintf(fptr,"%s = %s LS %s\n",varname,$1,$3);

                    strcpy(ic_code[idx].result,varname);
                    strcpy(ic_code[idx].op1,$1);
                    strcpy(ic_code[idx].opname,"LSHIFT");
                    strcpy(ic_code[idx].op2,$3);
                    idx++;

					strcpy($$,varname);
                }
				|shift_expression OPERATOR_RIGHT_SHIFT additive_expression
				{
				    printf("\tReduced : shift_expression -> shift_expression OPERATOR_RIGHT_SHIFT additive_expression\n");
				    new_var();
                    fprintf(fptr,"%s = %s RS %s\n",varname,$1,$3);

                    strcpy(ic_code[idx].result,varname);
                    strcpy(ic_code[idx].op1,$1);
                    strcpy(ic_code[idx].opname,"RSHIFT");
                    strcpy(ic_code[idx].op2,$3);
                    idx++;

					strcpy($$,varname);
                }
				;

additive_expression:multiplicative_expression
                    {
                        printf("\tReduced : additive_expression -> multiplicative_expression\n");
                        strcpy($$,$1);
                    }
				   |additive_expression OPERATOR_PLUS multiplicative_expression
				   {
				       printf("\tReduced : additive_expression -> additive_expression OPERATOR_PLUS multiplicative_expression\n");
				       new_var();
				       fprintf(fptr,"%s = %s + %s\n",varname,$1,$3);

				       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,$1);
                       strcpy(ic_code[idx].opname,"ADD");
                       strcpy(ic_code[idx].op2,$3);
                       idx++;

				       strcpy($$,varname);
                    }
				   |additive_expression OPERATOR_MINUS multiplicative_expression
				   {
				       printf("\tReduced : additive_expression -> additive_expression OPERATOR_MINUS multiplicative_expression\n");
				       new_var();
				       fprintf(fptr,"%s = %s - %s\n",varname,$1,$3);

				       strcpy(ic_code[idx].result,varname);
                       strcpy(ic_code[idx].op1,$1);
                       strcpy(ic_code[idx].opname,"SUB");
                       strcpy(ic_code[idx].op2,$3);
                       idx++;

				       strcpy($$,varname);
                   }
				   ;

multiplicative_expression:cast_expression
                         {
                            printf("\tReduced : multiplicative_expression -> cast_expression\n");
                            strcpy($$,$1);
                         }
						 |multiplicative_expression OPERATOR_MULTIPLY cast_expression
						 {
						     printf("\tReduced : multiplicative_expression -> multiplicative_expression OPERATOR_MULTIPLY cast_expression\n");
						     new_var();
                             fprintf(fptr,"%s = %s * %s\n",varname,$1,$3);

                             strcpy(ic_code[idx].result,varname);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"MUL");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

                             strcpy($$,varname);
                         }
						 |multiplicative_expression OPERATOR_DIVIDE cast_expression
						 {
						     printf("\tReduced : multiplicative_expression -> multiplicative_expression OPERATOR_DIVIDE cast_expression\n");
						     new_var();
                             fprintf(fptr,"%s = %s / %s\n",varname,$1,$3);

                             strcpy(ic_code[idx].result,varname);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"DIV");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

                             strcpy($$,varname);
                         }
						 |multiplicative_expression OPERATOR_MODULUS cast_expression
						 {
						     printf("\tReduced : multiplicative_expression -> multiplicative_expression OPERATOR_MODULUS cast_expression\n");
						     new_var();
					         fprintf(fptr,"%s = %s % %s\n",varname,$1,$3);

					         strcpy(ic_code[idx].result,varname);
                             strcpy(ic_code[idx].op1,$1);
                             strcpy(ic_code[idx].opname,"MOD");
                             strcpy(ic_code[idx].op2,$3);
                             idx++;

					         strcpy($$,varname);
                         }
						 ;

cast_expression:unary_expression {printf("\tReduced : cast_expression -> unary_expression\n"); strcpy($$,$1);}
			   |PARANTHESIS_BEG type_name PARANTHESIS_END cast_expression
			   {
			       printf("\tReduced : cast_expression -> PARANTHESIS_BEG type_name PARANTHESIS_END cast_expression\n");
			       //strcpy($$,$2);
               }
			   ;

unary_expression:postfix_expression { printf("#### %s\n",$1);printf("\tReduced : unary_expression -> postfix_expression\n"); strcpy($$,$1);}
				|OPERATOR_INCREMENTOR unary_expression
				{
				    printf("\tReduced : unary_expression -> OPERATOR_INCREMENTOR unary_expression\n");
				    fprintf(fptr,"%s = %s + 1\n",$2,$2);

				    strcpy(ic_code[idx].result,$2);
                    strcpy(ic_code[idx].op1,$2);
                    strcpy(ic_code[idx].opname,"ADD");
                    strcpy(ic_code[idx].op2,"1");
                    idx++;

				    strcpy($$,$2);
                }
				|OPERATOR_DECREMENTOR unary_expression
				{
				    printf("\tReduced : unary_expression -> OPERATOR_DECREMENTOR unary_expression\n");
				    fprintf(fptr,"%s = %s - 1\n",$2,$2);

				    strcpy(ic_code[idx].result,$2);
                    strcpy(ic_code[idx].op1,$2);
                    strcpy(ic_code[idx].opname,"SUB");
                    strcpy(ic_code[idx].op2,"1");
                    idx++;

				    strcpy($$,$2);
                }
				|unary_operator cast_expression
				{
				    printf("\tReduced : unary_expression -> unary_operator cast_expression\n");
				    new_var();
				    fprintf(fptr,"%s = -%s\n",varname,$2);

				    strcpy(ic_code[idx].result,$2);
                    strcpy(ic_code[idx].op1,$2);
                    strcpy(ic_code[idx].opname,"NEG");
                    strcpy(ic_code[idx].op2,"NA");
                    idx++;

				    strcpy($$,varname);
                }
				|SIZEOF unary_expression {printf("\tReduced : unary_expression -> SIZEOF unary_expression\n");}
				|SIZEOF PARANTHESIS_BEG type_name PARANTHESIS_END {printf("\tReduced : unary_expression -> SIZEOF PARANTHESIS_BEG type_name PARANTHESIS_END\n");}
				;

unary_operator:OPERATOR_BITWISE_AND {printf("\tReduced : unary_operator -> OPERATR_BITWISE_AND\n"); strcpy($$,$1);}
			  |OPERATOR_MULTIPLY {printf("\tReduced : unary_operator -> OPERATOR_MULTIPLY\n"); strcpy($$,$1);}
			  |OPERATOR_PLUS {printf("\tReduced : unary_operator -> OPERATOR_PLUS\n"); strcpy($$,$1);}
			  |OPERATOR_MINUS {printf("\tReduced : unary_operator -> OPERATOR_MINUS\n"); strcpy($$,$1);}
			  |OPERATOR_TILDE {printf("\tReduced : unary_operator -> OPERATOR_TILDE\n"); strcpy($$,$1);}
			  |OPERATOR_NOT {printf("\tReduced : unary_operator -> OPERATOR_NOT\n"); strcpy($$,$1);}
			  ;

postfix_expression:primary_expression {printf("\tReduced : postfix_expression -> primary_expression\n");}
				  |postfix_expression SQUARE_BRACKET_BEG expression SQUARE_BRACKET_END
				  {
				      printf("\tReduced : postfix_expression -> postfix_expression SQUARE_BRACKET_BEG expression SQUARE_BRACKET_END\n");
				      //new_var();
				      strcpy(tempdim[d1++],$3);
				      found_arr_name--;
				      //printf(">>>>>>>found_arr_name %d\n",found_arr_name);
				      //printf("<<<<<<<<<<<<<<<< %s %s %s\n",$$,$1,$3);
				      //printf(">>>>>>%s\n",$1);
				      if_match_print($1);

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
                                fprintf(fptr,"%s = %s[%s]\n",varname,$1,cur_var);
                                char tempsstr[101];
                                strcpy(tempsstr,$1);
                                strcat(tempsstr,"[");
                                strcat(tempsstr,cur_var);
                                strcat(tempsstr,"]");
                                strcpy(ic_code[idx].result,varname);
                                strcpy(ic_code[idx].op1,tempsstr);
                                strcpy(ic_code[idx].opname,"EQUAL_TO");
                                strcpy(ic_code[idx].op2,"NA");
                                idx++;

                                strcpy($$,varname);
                            }
                            else
                            {
                                char tempor1[101];
                                //tempor1[0]='\0';
                                //printf("%s\n",cur_var);
                                strcpy(tempor1,$1);
                                strcat(tempor1,"[");
                                strcat(tempor1,cur_var);
                                strcat(tempor1,"]");
                                //strcpy(tempor1,strcat($1,strcat("[",strcat(cur_var,"]"))));
                                printf(">>><<<%s\n",tempor1);
                                strcpy($$,tempor1);
                            }
                            dimfound=0;
				      }
				      else strcpy($$,$1);
				      //dimfound=0;
                  }
				  |postfix_expression PARANTHESIS_BEG argument_expression_list PARANTHESIS_END {printf("\tReduced : postfix_expression -> postfix_expression PARANTHESIS_BEG argument_expression_list PARANTHESIS_END\n");}
				  |postfix_expression PARANTHESIS_BEG PARANTHESIS_END {printf("\tReduced : postfix_expression -> postfix_expression PARANTHESIS_BEG PARANTHESIS_END\n");}
				  |postfix_expression DOT IDENTIFIER {printf("\tReduced : postfix_expression -> postfix_expression DOT IDENTIFIER\n");}
				  |postfix_expression OPERATOR_LINK IDENTIFIER {printf("\tReduced : postfix_expression -> postfix_expression OPERATOR_LINK IDENTIFIER\n");}
				  |postfix_expression OPERATOR_INCREMENTOR
				  {
				      printf("\tReduced : postfix_expression -> postfix_expression OPERATOR_INCREMENTOR\n");
				      new_var();
				      fprintf(fptr,"%s = %s\n",varname,$1);

				      strcpy(ic_code[idx].result,varname);
                      strcpy(ic_code[idx].op1,$1);
                      strcpy(ic_code[idx].opname,"NA");
                      strcpy(ic_code[idx].op2,"NA");
                      idx++;

				      fprintf(fptr,"%s = %s + 1\n",$1,$1);

				      strcpy(ic_code[idx].result,$1);
                      strcpy(ic_code[idx].op1,$1);
                      strcpy(ic_code[idx].opname,"ADD");
                      strcpy(ic_code[idx].op2,"1");
                      idx++;

				      strcpy($$,varname);

                  }
				  |postfix_expression OPERATOR_DECREMENTOR
				  {
				      printf("\tReduced : postfix_expression -> postfix_expression OPERATOR_DECREMENTOR\n");
				      new_var();
				      fprintf(fptr,"%s = %s\n",varname,$1);

				      strcpy(ic_code[idx].result,varname);
                      strcpy(ic_code[idx].op1,$1);
                      strcpy(ic_code[idx].opname,"NA");
                      strcpy(ic_code[idx].op2,"NA");
                      idx++;

				      fprintf(fptr,"%s = %s - 1\n",$1,$1);

				      strcpy(ic_code[idx].result,$1);
                      strcpy(ic_code[idx].op1,$1);
                      strcpy(ic_code[idx].opname,"SUB");
                      strcpy(ic_code[idx].op2,"1");
                      idx++;

				      strcpy($$,varname);
                  }
				  ;

primary_expression:IDENTIFIER { printf("\tReduced : primary_expression -> IDENTIFIER\n");
                                    int temp_found_arr=is_it_array($1.name);
                                    if(temp_found_arr>0) found_arr_name=temp_found_arr;
                                    //printf("~~~~~~~~~ %d\n",found_arr_name);
                                    if(!present($1.name))
                                    {
                                        f=6;
                                        strcpy(temp,$1.name);
                                        yyerror();
                                    }
                                    strcpy($$,$1.name);
                              }
				  |constant {printf("\tReduced : primary_expression -> constant\n"); strcpy($$,$1);}
				  |STRING_CONSTANT { printf("\tReduced : primary_expression -> STRING_CONSTANT\n");
                                        if(flag)strcat(symtab[len].val," ");
                                        if(flag)strcat(symtab[len].val,$1.val);
                                        strcpy($$,$1.name);
                                   }
				  |PARANTHESIS_BEG expression PARANTHESIS_END {printf("\tReduced : primary_expression -> PARANTHESIS_BEG expression PARANTHESIS_END\n"); strcpy($$,$2);}
				  ;

argument_expression_list:assignment_expression {printf("\tReduced : argument_expression_list -> assignment_expression\n");}
						|argument_expression_list COMMA assignment_expression {printf("\tReduced : argument_expression_list -> argument_expression_list COMMA assignment_expression\n");}
						;

constant:NUMBER { printf("\tReduced : constant -> NUMBER\n");
                            if(flag)strcat(symtab[len].val," ");
                            if(flag)strcat(symtab[len].val,$1.val);
                            printf("%s\n",$1.val);
                            strcpy($$,$1.val);
                }
		|CHAR_CONSTANT { printf("\tReduced : constant -> CHAR_CONSTANT\n");
                            if(flag)strcat(symtab[len].val," ");
                            if(flag)strcat(symtab[len].val,$1.val);
                            strcpy($$,$1.val);
                       }
		|REAL_NUMBER { printf("\tReduced : constant -> REAL_NUMBER\n");
                            if(flag)strcat(symtab[len].val," ");
                            if(flag)strcat(symtab[len].val,$1.val);
                            strcpy($$,$1.val);
                     }
		|EXP_NUMBER { printf("\tReduced : constant -> EXP_NUMBER\n");
                            if(flag)strcat(symtab[len].val," ");
                            if(flag)strcat(symtab[len].val,$1.val);
                            strcpy($$,$1.val);
                    }
		;

%%

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
