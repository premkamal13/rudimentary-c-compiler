%{
	#include<stdio.h>
	char i_[4]="0";
int p=0,k=0,m=0;
char temp[5]="t";
int cou=0;
int j=0;int i,flag=0;
struct st
	{
		int type;
		char id[100];
		int dim;
		int b[10];
		
	}arr[500];
	char b2[100][100];
char w[100],res[100];

%}
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM NEW
%token EXTERN FLOAT FOR GOTO IF INT LONG REGISTER RETURN SHORT SIZEOF STATIC
%token STRUCT SWITCH TYPEDEF UNION SIGNED UNSIGNED VOID VOLATILE WHILE DOT
%token OPEN_SQ_BRACKET CLOSING_SQ_BRACKET OPEN_PARANTHISIS CLOSE_PARANTHISIS
%token OPEN_BRACKET CLOSE_BRACKET COMMA COLON EQUALTO SEMI_COLON HASH DOUBLE_QUOTES
%token NOT COMPLEMENT INCREMENT DECREMENT ADD SUB MULTIPLY AND_BIT DIV 
%token MOD R_SHIFT L_SHIFT LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQUAL
%token EQUALS NOT_EQUAL XOR OR_BIT AND OR TERNARY ADD_SHORT SUB_SHORT MUL_SHORT
%token DIV_SHORT MOD_SHORT AND_SHORT XOR_SHORT OR_SHORT LSHIFT_SHORT
%token RSHIFT_SHORT LINK
%token IDENTIFIER NUMBER REAL_NUMBER EXP_NUMBER CHAR_CONSTANT STRING_CONSTANT

%union{
	   
	   char a[1000];
	  }
%type <a>   declarator init_declarator init_declarator_list type_specifier declaration_specifiers declaration INT LONG FLOAT DOUBLE EQUALTO unary_operator expression assignment_operator direct_declarator constant primary_expression postfix_expression unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression AND_expression exclusive_OR_expression inclusive_OR_expression logical_AND_expression logical_OR_expression IDENTIFIER NUMBER CHAR_CONSTANT REAL_NUMBER EXP_NUMBER STRING_CONSTANT OPEN_SQ_BRACKET constant_expression assignment_expression CLOSING_SQ_BRACKET conditional_expression

%%

translation_unit:external_declaration 
				|translation_unit external_declaration 
				;

external_declaration:function_definition 
					|declaration 
					;

function_definition:declaration_specifiers declarator declaration_list compound_statement
				   |declarator declaration_list compound_statement 
				   |declaration_specifiers declarator compound_statement
				   |declarator compound_statement 
				   ;

declaration:declaration_specifiers init_declarator_list SEMI_COLON {

                                                                   if((strcmp($1,"int")==0)||(strcmp($1,"float")==0))arr[j].type=4;
																   else arr[j].type=8;
																  
																   //printf("%s ",$1);
																   //printf("%d\n",cou);
																   arr[j].dim=cou;
																   j++;
																   
																   cou=0;k=0;}
		   |declaration_specifiers SEMI_COLON
		   ;

declaration_list:declaration 
				|declaration_list declaration 
				;

declaration_specifiers:storage_class_specifier declaration_specifiers
					  |storage_class_specifier 
					  |type_specifier declaration_specifiers 
					  |type_specifier {strcpy($$,$1);}
					  |type_qualifier declaration_specifiers
					  |type_qualifier 
					  ;

storage_class_specifier:AUTO 
					   |REGISTER 
					   |STATIC 
					   |EXTERN 
					   |TYPEDEF
					   ;
                                    
type_specifier:VOID 
			  |CHAR 
			  |SHORT 
			  |INT {strcpy($$,$1);}
			  |LONG {strcpy($$,$1);}
			  |FLOAT {strcpy($$,$1);}
			  |DOUBLE {strcpy($$,$1);}
			  |SIGNED 
			  |UNSIGNED 
			  |struct_or_union_specifier 
			  |enum_specifier 
			  ;

type_qualifier:CONST
			  |VOLATILE
			  ;

struct_or_union_specifier:struct_or_union IDENTIFIER OPEN_BRACKET struct_declaration_list CLOSE_BRACKET
						 |struct_or_union OPEN_BRACKET struct_declaration_list CLOSE_BRACKET 
						 |struct_or_union IDENTIFIER 
						 ;

struct_or_union:STRUCT
			   |UNION 
			   ;
			   
struct_declaration_list:struct_declaration 
					   |struct_declaration_list struct_declaration 
					   ;

init_declarator_list:init_declarator 
					|init_declarator_list COMMA init_declarator
					;

init_declarator:declarator
			   |declarator EQUALTO initializer
			   ;
			   
struct_declaration:specifier_qualifier_list struct_declarator_list SEMI_COLON 
				  ;

specifier_qualifier_list:type_specifier specifier_qualifier_list
						|type_specifier
						|type_qualifier specifier_qualifier_list 
						|type_qualifier 
						;

struct_declarator_list:struct_declarator 
					  |struct_declarator_list COMMA struct_declarator

struct_declarator:declarator 
				 |declarator COLON constant_expression 
				 |COLON constant_expression 
				 ;

enum_specifier:ENUM IDENTIFIER OPEN_BRACKET enumerator_list CLOSE_BRACKET 
			  |ENUM OPEN_BRACKET enumerator_list CLOSE_BRACKET
			  |ENUM IDENTIFIER 
			  ;

enumerator_list:enumerator 
			   |enumerator_list COMMA enumerator
			   ;

enumerator:IDENTIFIER 
		  |IDENTIFIER EQUALTO constant_expression 
		  ;

declarator:pointer direct_declarator 
		  |direct_declarator
		  ;

direct_declarator:IDENTIFIER  {//printf("%s ",$1);
                                   strcpy(arr[j].id,$1);}
				 |OPEN_PARANTHISIS declarator CLOSE_PARANTHISIS 
				 |direct_declarator OPEN_SQ_BRACKET constant_expression CLOSING_SQ_BRACKET {//printf("%s ",$3);
				                                                                                arr[j].b[k]=atoi($3);k++;cou++;}
				 |direct_declarator OPEN_SQ_BRACKET CLOSING_SQ_BRACKET 
				 |direct_declarator OPEN_PARANTHISIS parameter_type_list CLOSE_PARANTHISIS
				 |direct_declarator OPEN_PARANTHISIS identifier_list CLOSE_PARANTHISIS
				 |direct_declarator OPEN_PARANTHISIS CLOSE_PARANTHISIS 
				 ;

pointer:MULTIPLY type_qualifier_list 
	   |MULTIPLY 
	   |MULTIPLY type_qualifier_list pointer 
	   |MULTIPLY pointer 
	   ;

type_qualifier_list:type_qualifier
				   |type_qualifier_list type_qualifier 
				   ;

parameter_type_list:parameter_list 
				   |parameter_list COMMA NEW 
				   ;

parameter_list:parameter_declaration
			  |parameter_list COMMA parameter_declaration 
			  ;

parameter_declaration:declaration_specifiers declarator 
					 |declaration_specifiers abstract_declarator 
					 |declaration_specifiers 
					 ;

identifier_list:IDENTIFIER 
			   |identifier_list COMMA IDENTIFIER 
			   ;

initializer:assignment_expression 
		   |OPEN_BRACKET initializer_list CLOSE_BRACKET 
		   |OPEN_BRACKET initializer_list COMMA CLOSE_BRACKET 
		   ;

initializer_list:initializer 
				|initializer_list COMMA initializer 
				;

type_name:specifier_qualifier_list abstract_declarator 
		 |specifier_qualifier_list 
		 ;

abstract_declarator:pointer 
				   |pointer direct_abstract_declarator 
				   |direct_abstract_declarator 
				   ;

direct_abstract_declarator:OPEN_PARANTHISIS abstract_declarator CLOSE_PARANTHISIS 
						  |direct_abstract_declarator OPEN_SQ_BRACKET constant_expression CLOSING_SQ_BRACKET 
						  |OPEN_SQ_BRACKET constant_expression CLOSING_SQ_BRACKET 
						  |direct_abstract_declarator OPEN_SQ_BRACKET CLOSING_SQ_BRACKET 
						  |OPEN_SQ_BRACKET CLOSING_SQ_BRACKET 
						  |direct_abstract_declarator OPEN_PARANTHISIS parameter_type_list CLOSE_PARANTHISIS
						  |OPEN_PARANTHISIS parameter_type_list CLOSE_PARANTHISIS
						  |direct_abstract_declarator OPEN_PARANTHISIS CLOSE_PARANTHISIS 
						  |OPEN_PARANTHISIS CLOSE_PARANTHISIS
						  ;


statement:labeled_statement 
		 |expression_statement 
		 |compound_statement 
		 |selection_statement
		 |iteration_statement
		 |jump_statement
		 ;

labeled_statement:IDENTIFIER COLON statement 
				 |CASE constant_expression COLON statement
				 |DEFAULT COLON statement 
				 ;

expression_statement:expression SEMI_COLON 
					|SEMI_COLON 
					;

compound_statement:OPEN_BRACKET declaration_list statement_list CLOSE_BRACKET 
				  |OPEN_BRACKET declaration_list CLOSE_BRACKET
				  |OPEN_BRACKET statement_list CLOSE_BRACKET 
				  |OPEN_BRACKET CLOSE_BRACKET 
				  ;

statement_list:statement 
			  |statement_list statement
			  ;

selection_statement:IF OPEN_PARANTHISIS expression CLOSE_PARANTHISIS statement 
				   |IF OPEN_PARANTHISIS expression CLOSE_PARANTHISIS statement ELSE statement 
				   |SWITCH OPEN_PARANTHISIS expression CLOSE_PARANTHISIS statement 
				   ;

iteration_statement:WHILE OPEN_PARANTHISIS expression CLOSE_PARANTHISIS statement 
				   |DO statement WHILE OPEN_PARANTHISIS expression CLOSE_PARANTHISIS SEMI_COLON 
				   |FOR OPEN_PARANTHISIS expression SEMI_COLON expression SEMI_COLON expression CLOSE_PARANTHISIS statement 
				   |FOR OPEN_PARANTHISIS expression SEMI_COLON expression SEMI_COLON CLOSE_PARANTHISIS statement 
				   |FOR OPEN_PARANTHISIS expression SEMI_COLON SEMI_COLON expression CLOSE_PARANTHISIS statement 
				   |FOR OPEN_PARANTHISIS expression SEMI_COLON SEMI_COLON CLOSE_PARANTHISIS statement
				   |FOR OPEN_PARANTHISIS SEMI_COLON expression SEMI_COLON expression CLOSE_PARANTHISIS statement 
				   |FOR OPEN_PARANTHISIS SEMI_COLON expression SEMI_COLON CLOSE_PARANTHISIS statement 
				   |FOR OPEN_PARANTHISIS SEMI_COLON SEMI_COLON expression CLOSE_PARANTHISIS statement 
				   |FOR OPEN_PARANTHISIS SEMI_COLON SEMI_COLON CLOSE_PARANTHISIS statement
				   ;
				   
jump_statement:GOTO IDENTIFIER SEMI_COLON 
			  |CONTINUE SEMI_COLON 
			  |BREAK SEMI_COLON 
			  |RETURN expression SEMI_COLON 
			  |RETURN SEMI_COLON 
			  ;

expression:assignment_expression {}
		  |expression COMMA assignment_expression 
		  ;

assignment_expression:conditional_expression {}
					 | unary_expression assignment_operator assignment_expression {
					 
					 
					 
					 if(strcmp($2,"=")==0)
					 {printf("%s=",$$);f1();}
					 
					 else if(strcmp($2,"+=")==0)
					 {printf("%s=%s+",$$,$$);f1();}
					 
					 else if(strcmp($2,"-=")==0)
					 {printf("%s=%s-",$$,$$);f1();}
					 
					 else if(strcmp($2,"*=")==0)
					 {printf("%s=%s*",$$,$$);f1();}
					 
					 else if(strcmp($2,"/=")==0)
					 {printf("%s=%s/",$$,$$);f1();}
					 
					 
					 
					 }
					 ;

assignment_operator:EQUALTO{strcpy($$,$1);}
				   |MUL_SHORT {strcpy($$,$1);}
				   |DIV_SHORT {strcpy($$,$1);}
				   |MOD_SHORT {strcpy($$,$1);}
				   |ADD_SHORT {strcpy($$,$1);}
				   |SUB_SHORT {strcpy($$,$1);}
				   |LSHIFT_SHORT 
				   |RSHIFT_SHORT 
				   |AND_SHORT 
				   |XOR_SHORT 
				   |OR_SHORT 
				   ;

conditional_expression:logical_OR_expression {strcpy($$,$1);}
					  |logical_OR_expression TERNARY expression COLON conditional_expression 
					  ;
					  
constant_expression:conditional_expression {strcpy($$,$1);}
				   ;
				   
logical_OR_expression:logical_AND_expression{strcpy($$,$1);}
					 |logical_OR_expression OR logical_AND_expression
					 ;

logical_AND_expression:inclusive_OR_expression {strcpy($$,$1);}
					  |logical_AND_expression AND inclusive_OR_expression
					  ;
					  
inclusive_OR_expression:exclusive_OR_expression{strcpy($$,$1);}
					   |inclusive_OR_expression OR_BIT exclusive_OR_expression
					   ;

exclusive_OR_expression:AND_expression {strcpy($$,$1);}
					   |exclusive_OR_expression XOR AND_expression 
					   ;
					  
AND_expression:equality_expression {strcpy($$,$1);}
			  |AND_expression AND_BIT equality_expression 

equality_expression:relational_expression {strcpy($$,$1);}
				   |equality_expression EQUALS relational_expression 
				   |equality_expression NOT_EQUAL relational_expression
				   ;

relational_expression:shift_expression{strcpy($$,$1);}
					 |relational_expression LESS_THAN shift_expression
					 |relational_expression GREATER_THAN shift_expression
					 |relational_expression LESS_EQUAL shift_expression 
					 |relational_expression GREATER_EQUAL shift_expression 
					 ;

shift_expression:additive_expression{strcpy($$,$1);}
			    |shift_expression L_SHIFT additive_expression 
				|shift_expression R_SHIFT additive_expression 
				;
				
additive_expression:multiplicative_expression {strcpy($$,$1);}
				   |additive_expression ADD multiplicative_expression{f();printf("%s+%s\n",$1,$3);strcpy($$,temp);}
				   |additive_expression SUB multiplicative_expression{f();printf("%s-%s\n",$1,$3);strcpy($$,temp);}
				   ;
				   
multiplicative_expression:cast_expression{strcpy($$,$1);}
						 |multiplicative_expression MULTIPLY cast_expression{f();printf("%s*%s\n",$1,$3);strcpy($$,temp);}
						 |multiplicative_expression DIV cast_expression{f();printf("%s/%s\n",$1,$3);strcpy($$,temp);}
						 |multiplicative_expression MOD cast_expression
						 ;
						 
cast_expression:unary_expression {strcpy($$,$1);}
			   |OPEN_PARANTHISIS type_name CLOSE_PARANTHISIS cast_expression
			   ;
			   
unary_expression:postfix_expression {strcpy($$,$1);}
				|INCREMENT unary_expression{printf("%s=%s+1\n",$2,$2);f();printf("%s\n",$2);strcpy($$,temp);}
				|DECREMENT unary_expression{printf("%s=%s-1\n",$2,$2);f();printf("%s\n",$2);strcpy($$,temp);}
				|unary_operator cast_expression {f();printf("-%s\n",$2);strcpy($$,temp);}
				|SIZEOF unary_expression 
				|SIZEOF OPEN_PARANTHISIS type_name CLOSE_PARANTHISIS
				;
				
unary_operator:AND_BIT 
			  |MULTIPLY 
			  |ADD 
			  |SUB 
			  |COMPLEMENT
			  |NOT
			  ;

postfix_expression:primary_expression {strcpy($$,$1);}
				  |postfix_expression OPEN_SQ_BRACKET expression CLOSING_SQ_BRACKET{
				  
																			for(i=0;i<j;i++)
																			{
																			 if(strcmp(arr[i].id,$1)==0)
																				break;
																				}
																		
																			strcpy(b2[m],$3);m++;
																			
																			if(m==arr[i].dim) {cal();flag=1;strcat($1,"[");strcat($1,w);strcat($1,"]");strcpy(res,$1);f();printf("%s\n",$1);strcpy($$,res);}
				                                                             
																			 
																			 
																			 
																			 }
				  |postfix_expression OPEN_PARANTHISIS argument_expression_list CLOSE_PARANTHISIS
				  |postfix_expression OPEN_PARANTHISIS CLOSE_PARANTHISIS 
				  |postfix_expression DOT IDENTIFIER 
				  |postfix_expression LINK IDENTIFIER 
				  |postfix_expression INCREMENT{f();printf("%s\n",$1);printf("%s=%s+1\n",$1,$1);strcpy($$,$1);}
				  |postfix_expression DECREMENT {f();printf("%s\n",$1);printf("%s=%s-1\n",$1,$1);}
				  ;

primary_expression:IDENTIFIER {strcpy($$,$1);}
				  |constant {strcpy($$,$1);}
				  |STRING_CONSTANT 
				  |OPEN_PARANTHISIS expression CLOSE_PARANTHISIS {strcpy($$,$2);}
				  ;
				  
argument_expression_list:assignment_expression 
						|argument_expression_list COMMA assignment_expression 
						;
						
constant:NUMBER{strcpy($$,$1);}
		|CHAR_CONSTANT 
		|REAL_NUMBER 
		|EXP_NUMBER
		;
	
%%

#include "lex.yy.c"



cal()
{
f();printf("0\n");strcpy(w,temp);
for(k=0;k<m;k++)
{
f();printf("%s\n",b2[k]);
for(j=k+1;j<m;j++)
printf("%s=%s*%d\n",temp,temp,arr[i].b[j]);

printf("%s=%s+%s\n",w,w,temp);
}
printf("%s=%s*%d\n",w,w,arr[i].type);
m=0;



}

f1()
{
printf("%s\n",temp);
}


f()
{
strcpy(temp,"t");
 sprintf(i_, "%d", p);
 strcat(temp,i_);
  p++;
  printf("%s=",temp);
  }


int yyerror()
{
	printf("ERROR\n");
}

int main(int argc,char *argv[])
{
        if(argc<2)
        {
                printf("Error \n");
                return -1;
        }
        yyin = fopen(argv[1],"r");
        yyparse();
	/*	for(i=0;i<j;i++)
		{
		printf("%d %s %d ",arr[i].type,arr[i].id,arr[i].dim);
		for(cou=0;cou<arr[i].dim;cou++)
		printf("%d ",arr[i].b[cou]);
		printf("\n");
		}*/
        fclose(yyin);
        return 0;
}
