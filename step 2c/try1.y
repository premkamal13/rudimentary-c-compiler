%{
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
%}
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM THREE_DOT EXTERN FLOAT FOR GOTO IF INT LONG REGISTER RETURN SHORT lenOF STATIC
%token STRUCT SWITCH TYPEDEF UNION SIGNED UNSIGNED VOID VOLATILE WHILE DOT OPEN_SQ_BRACKET CLOSE_SQ_BRACKET OPEN_PARANTHESES CLOSE_PARANTHESES
%token OPEN_BRACES CLOSE_BRACES COMMA COLON EQUALS SEMI_COLON HASH SIZEOF DOUBLE_QUOTES NOT NEGATION INCREMENT DECREMENT PLUS MINUS MULTIPLY AND_BIT DIVIDE
%token MODULUS R_SHIFT L_SHIFT LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQUAL IS_EQUAL_TO NOT_EQUAL XOR OR_BIT AND OR TERNARY ADD_SHORT SUB_SHORT MUL_SHORT
%token DIV_SHORT MOD_SHORT AND_SHORT XOR_SHORT OR_SHORT LSHIFT_SHORT RSHIFT_SHORT LINK IDENTIFIER NUMBER REAL_NUMBER EXP_NUMBER CHAR_CONSTANT STRING_CONSTANT

%union{
	   int type;
	   struct abhishek entry;
	  }
%type <entry> IDENTIFIER NUMBER CHAR_CONSTANT REAL_NUMBER EXP_NUMBER STRING_CONSTANT

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

declaration:declaration_specifiers init_declarator_list SEMI_COLON {flag=0;printf("\tReduced : declaration -> declaration_specifiers init_declarator_list SEMI_COLON\n");s=cnt2*100+cnt1*10+cnt0;
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
																	yyerror();}
		   |declaration_specifiers SEMI_COLON {printf("\tReduced : declaration -> declaration_specifiers SEMI_COLON\n");}
		   ;

declaration_list:declaration {printf("\tReduced : declaration_list -> declaration\n");}
				|declaration_list declaration {printf("\tReduced : declaration_list -> declaration_list declaration\n");}
				;

declaration_specifiers:storage_class_specifier declaration_specifiers {printf("\tReduced : declaration_specifiers -> storage_class_specifier declaration_specifiers\n");}
					  |storage_class_specifier {printf("\tReduced : declaration_specifiers -> storage_class_specifier\n");}
					  |type_specifier declaration_specifiers {printf("\tReduced : declaration_specifiers -> type_specifier declaration_specifiers\n");}
					  |type_specifier {printf("\tReduced : declaration_specifiers -> type_specifier\n");}
					  |type_qualifier declaration_specifiers {printf("\tReduced : declaration_specifiers -> type_qualifier declaration_specifiers\n");}
					  |type_qualifier {printf("\tReduced : declaration_specifiers -> type_qualifier\n");}
					  ;

storage_class_specifier:AUTO {printf("\tReduced : storage_class_specifier -> AUTO\n");}
					   |REGISTER {printf("\tReduced : storage_class_specifier -> REGISTER\n");}
					   |STATIC {printf("\tReduced : storage_class_specifier -> STATIC\n");}
					   |EXTERN {printf("\tReduced : storage_class_specifier -> EXTERN\n");}
					   |TYPEDEF {printf("\tReduced : storage_class_specifier -> TYPEDEF\n");}
					   ;

type_specifier:VOID {printf("\tReduced : type_specifier -> VOID\n");}
			  |CHAR {printf("\tReduced : type_specifier -> CHAR\n");if(cnt0==0) cnt0+=2; else yyerror();}
			  |SHORT {printf("\tReduced : type_specifier -> SHORT\n");if(cnt1==0) cnt1++; else yyerror();}
			  |INT {printf("\tReduced : type_specifier -> INT\n");if(cnt0==0) cnt0++; else yyerror();}
			  |LONG {printf("\tReduced : type_specifier -> LONG\n");if(cnt1==0 || cnt1==-1) cnt1--; else yyerror();}
			  |FLOAT {printf("\tReduced : type_specifier -> FLOAT\n");if(cnt0==0) cnt0+=4; else yyerror();}
			  |DOUBLE {printf("\tReduced : type_specifier -> DOUBLE\n");if(cnt0==0) cnt0+=8; else yyerror();}
			  |SIGNED {printf("\tReduced : type_specifier -> SIGNED\n");if(cnt2==0) cnt2++; else yyerror();}
			  |UNSIGNED {printf("\tReduced : type_specifier -> UNSIGNED\n");if(cnt2==0) cnt2++; else yyerror();}
			  |struct_or_union_specifier {printf("\tReduced : type_specifier -> struct_or_union_specifier\n");}
			  |enum_specifier {printf("\tReduced : type_specifier -> enum_specifier\n");}
			  ;

type_qualifier:CONST {printf("\tReduced : type_qualifier -> CONST\n");}
			  |VOLATILE {printf("\tReduced : type_qualifier -> VOLATILE\n");}
			  ;

struct_or_union_specifier:struct_or_union IDENTIFIER OPEN_BRACES struct_declaration_list CLOSE_BRACES {printf("\tReduced : struct_or_union_specifier -> struct_or_union IDENTIFIER OPEN_BRACES struct_declaration_list CLOSE_BRACES\n");}
						 |struct_or_union OPEN_BRACES struct_declaration_list CLOSE_BRACES {printf("\tReduced : struct_or_union_specifier -> struct_or_union OPEN_BRACES struct_declaration_list CLOSE_BRACES\n");}
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
			   |declarator EQUALS initializer {printf("\tReduced : init_declarator -> declarator EQUALS initializer\n");}
			   ;

struct_declaration:specifier_qualifier_list struct_declarator_list SEMI_COLON {printf("\tReduced : struct_declaration -> specifier_qualifier_list struct_declarator_list SEMI_COLON\n");}
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

enum_specifier:ENUM IDENTIFIER OPEN_BRACES enumerator_list CLOSE_BRACES {printf("\tReduced : enum_specifier -> ENUM IDENTIFIER OPEN_BRACES enumerator_list CLOSE_BRACES\n");}
			  |ENUM OPEN_BRACES enumerator_list CLOSE_BRACES {printf("\tReduced : enum_specifier -> ENUM OPEN_BRACES enumerator_list CLOSE_BRACES\n");}
			  |ENUM IDENTIFIER {printf("\tReduced : enum_specifier -> ENUM IDENTIFIER\n");}
			  ;

enumerator_list:enumerator {printf("\tReduced : enumerator_list -> enumerator\n");}
			   |enumerator_list COMMA enumerator {printf("\tReduced : enumerator_list -> enumerator_list COMMA enumerator\n");}
			   ;

enumerator:IDENTIFIER {printf("\tReduced : enumerator -> IDENTIFIER\n");}
		  |IDENTIFIER EQUALS constant_expression {printf("\tReduced : enumerator -> IDENTIFIER EQUALS constant_expression\n");}
		  ;

declarator:pointer direct_declarator {printf("\tReduced : declarator -> pointer direct_declarator\n");}
		  |direct_declarator {printf("\tReduced : declarator -> direct_declarator\n");}
		  ;

direct_declarator:IDENTIFIER {flag=1;printf("\tReduced : direct_declarator -> IDENTIFIER\n");if(check_presence($1.symbol_specification))
																						{
																							len++;
																							strcpy(symbol_table[len].symbol_specification,$1.symbol_specification);
																							symbol_table[len].line_number=num;
																							symbol_table[len].data_type=-1;
																							symbol_table[len].sflag=0;
																							symbol_table[len].isarr=0;
																						}
																						else
																						{
																							printf("Already declared %s\n",$1.symbol_specification);
																							yyerror();
																						}
							 }
				 |OPEN_PARANTHESES declarator CLOSE_PARANTHESES {printf("\tReduced : direct_declarator -> OPEN_PARANTHESES declarator CLOSE_PARANTHESES\n");}
				 |direct_declarator OPEN_SQ_BRACKET constant_expression CLOSE_SQ_BRACKET {printf("\tReduced : direct_declarator -> direct_declarator OPEN_SQ_BRACKET constant_expression CLOSE_SQ_BRACKET\n");symbol_table[len].sflag=1;symbol_table[len].isarr=1;}
				 |direct_declarator OPEN_SQ_BRACKET CLOSE_SQ_BRACKET {printf("\tReduced : direct_declarator -> direct_declarator OPEN_SQ_BRACKET CLOSE_SQ_BRACKET\n");symbol_table[len].isarr=1;}
				 |direct_declarator OPEN_PARANTHESES parameter_type_list CLOSE_PARANTHESES {printf("\tReduced : direct_declarator -> direct_declarator OPEN_PARANTHESES parameter_type_list CLOSE_PARANTHESES\n");}
				 |direct_declarator OPEN_PARANTHESES identifier_list CLOSE_PARANTHESES {printf("\tReduced : direct_declarator -> direct_declarator OPEN_PARANTHESES identifier_list CLOSE_PARANTHESES\n");}
				 |direct_declarator OPEN_PARANTHESES CLOSE_PARANTHESES {printf("\tReduced : direct_declarator -> direct_declarator OPEN_PARANTHESES CLOSE_PARANTHESES\n");}
				 ;

pointer:MULTIPLY type_qualifier_list {printf("\tReduced : pointer -> MULTIPLY type_qualifier_list\n");}
	   |MULTIPLY {printf("\tReduced : pointer -> MULTIPLY\n");}
	   |MULTIPLY type_qualifier_list pointer {printf("\tReduced : pointer -> MULTIPLY type_qualifier_list pointer\n");}
	   |MULTIPLY pointer {printf("\tReduced : pointer -> MULTIPLY pointer\n");}
	   ;

type_qualifier_list:type_qualifier {printf("\tReduced : type_qualifier_list -> type_qualifier\n");}
				   |type_qualifier_list type_qualifier {printf("\tReduced : type_qualifier_list -> type_qualifier_list type_qualifier\n");}
				   ;

parameter_type_list:parameter_list {printf("\tReduced : parameter_type_list -> parameter_list\n");}
				   |parameter_list COMMA THREE_DOT {printf("\tReduced : parameter_type_list -> parameter_list COMMA THREE_DOT\n");}
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
		   |OPEN_BRACES initializer_list CLOSE_BRACES {printf("\tReduced : initializer -> OPEN_BRACES initializer_list CLOSE_BRACES\n");}
		   |OPEN_BRACES initializer_list COMMA CLOSE_BRACES {printf("\tReduced : initializer -> OPEN_BRACES initializer_list COMMA CLOSE_BRACES\n");}
		   ;

initializer_list:initializer {printf("\tReduced : initializer_list -> initializer\n");}
				|initializer_list COMMA initializer {printf("\tReduced : initializer_list -> initializer_list COMMA initializer\n");}
				;

type_symbol_specification:specifier_qualifier_list abstract_declarator {printf("\tReduced : type_symbol_specification -> specifier_qualifier_list abstract_declarator\n");}
		 |specifier_qualifier_list {printf("\tReduced : type_symbol_specification -> specifier_qualifier_list\n");}
		 ;

abstract_declarator:pointer {printf("\tReduced : abstract_declarator ->  pointer\n");}
				   |pointer direct_abstract_declarator {printf("\tReduced : abstract_declarator ->  pointer direct_abstract_declarator\n");}
				   |direct_abstract_declarator {printf("\tReduced : abstract_declarator -> direct_abstract_declarator\n");}
				   ;

direct_abstract_declarator:OPEN_PARANTHESES abstract_declarator CLOSE_PARANTHESES {printf("\tReduced : direct_abstract_declarator -> OPEN_PARANTHESES abstract_declarator CLOSE_PARANTHESES\n");}
						  |direct_abstract_declarator OPEN_SQ_BRACKET constant_expression CLOSE_SQ_BRACKET {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator OPEN_SQ_BRACKET constant_expression CLOSE_SQ_BRACKET\n");}
						  |OPEN_SQ_BRACKET constant_expression CLOSE_SQ_BRACKET {printf("\tReduced : direct_abstract_declarator -> OPEN_SQ_BRACKET constant_expression CLOSE_SQ_BRACKET\n");}
						  |direct_abstract_declarator OPEN_SQ_BRACKET CLOSE_SQ_BRACKET {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator OPEN_SQ_BRACKET CLOSE_SQ_BRACKET\n");}
						  |OPEN_SQ_BRACKET CLOSE_SQ_BRACKET {printf("\tReduced : direct_abstract_declarator -> OPEN_SQ_BRACKET CLOSE_SQ_BRACKET\n");}
						  |direct_abstract_declarator OPEN_PARANTHESES parameter_type_list CLOSE_PARANTHESES {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator OPEN_PARANTHESES parameter_type_list CLOSE_PARANTHESES\n");}
						  |OPEN_PARANTHESES parameter_type_list CLOSE_PARANTHESES {printf("\tReduced : direct_abstract_declarator -> OPEN_PARANTHESES parameter_type_list CLOSE_PARANTHESES\n");}
						  |direct_abstract_declarator OPEN_PARANTHESES CLOSE_PARANTHESES {printf("\tReduced : direct_abstract_declarator -> direct_abstract_declarator OPEN_PARANTHESES CLOSE_PARANTHESES\n");}
						  |OPEN_PARANTHESES CLOSE_PARANTHESES {printf("\tReduced : direct_abstract_declarator -> OPEN_PARANTHESES CLOSE_PARANTHESES\n");}
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

expression_statement:expression SEMI_COLON {printf("\tReduced : expression_statement -> expression SEMI_COLON\n");}
					|SEMI_COLON {printf("\tReduced : expression_statement -> SEMI_COLON\n");}
					;

compound_statement:OPEN_BRACES declaration_list statement_list CLOSE_BRACES {printf("\tReduced : compound_statement -> OPEN_BRACES declaration_list statement_list CLOSE_BRACES\n");}
				  |OPEN_BRACES declaration_list CLOSE_BRACES {printf("\tReduced : compound_statement -> OPEN_BRACES declaration_list CLOSE_BRACES\n");}
				  |OPEN_BRACES statement_list CLOSE_BRACES {printf("\tReduced : compound_statement -> OPEN_BRACES statement_list CLOSE_BRACES\n");}
				  |OPEN_BRACES CLOSE_BRACES {printf("\tReduced : compound_statement -> OPEN_BRACES CLOSE_BRACES\n");}
				  ;

statement_list:statement {printf("\tReduced : statement_list -> statement\n");}
			  |statement_list statement {printf("\tReduced : statement_list -> statement_list statement\n");}
			  ;

selection_statement:IF OPEN_PARANTHESES expression CLOSE_PARANTHESES statement {printf("\tReduced : selection_statement -> IF OPEN_PARANTHESES expression CLOSE_PARANTHESES statement\n");}
				   |IF OPEN_PARANTHESES expression CLOSE_PARANTHESES statement ELSE statement {printf("\tReduced : selection_statement -> IF OPEN_PARANTHESES expression CLOSE_PARANTHESES statement ELSE statement\n");}
				   |SWITCH OPEN_PARANTHESES expression CLOSE_PARANTHESES statement {printf("\tReduced : selection_statement -> SWITCH OPEN_PARANTHESES expression CLOSE_PARANTHESES statement\n");}
				   ;

iteration_statement:WHILE OPEN_PARANTHESES expression CLOSE_PARANTHESES statement {printf("\tReduced : iteration_statement -> WHILE OPEN_PARANTHESES expression CLOSE_PARANTHESES statement\n");}
				   |DO statement WHILE OPEN_PARANTHESES expression CLOSE_PARANTHESES SEMI_COLON {printf("\tReduced : iteration_statement -> DO statement WHILE OPEN_PARANTHESES expression CLOSE_PARANTHESES SEMI_COLON\n");}
				   |FOR OPEN_PARANTHESES expression SEMI_COLON expression SEMI_COLON expression CLOSE_PARANTHESES statement {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES expression SEMI_COLON expression SEMI_COLON expression CLOSE_PARANTHESES statement\n");}
				   |FOR OPEN_PARANTHESES expression SEMI_COLON expression SEMI_COLON CLOSE_PARANTHESES statement {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES expression SEMI_COLON expression SEMI_COLON CLOSE_PARANTHESES statement\n");}
				   |FOR OPEN_PARANTHESES expression SEMI_COLON SEMI_COLON expression CLOSE_PARANTHESES statement {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES expression SEMI_COLON SEMI_COLON expression CLOSE_PARANTHESES statement\n");}
				   |FOR OPEN_PARANTHESES expression SEMI_COLON SEMI_COLON CLOSE_PARANTHESES statement {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES expression SEMI_COLON SEMI_COLON CLOSE_PARANTHESES statement\n");}
				   |FOR OPEN_PARANTHESES SEMI_COLON expression SEMI_COLON expression CLOSE_PARANTHESES statement {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES SEMI_COLON expression SEMI_COLON expression CLOSE_PARANTHESES statement\n");}
				   |FOR OPEN_PARANTHESES SEMI_COLON expression SEMI_COLON CLOSE_PARANTHESES statement {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES SEMI_COLON expression SEMI_COLON CLOSE_PARANTHESES statement\n");}
				   |FOR OPEN_PARANTHESES SEMI_COLON SEMI_COLON expression CLOSE_PARANTHESES statement {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES SEMI_COLON SEMI_COLON expression CLOSE_PARANTHESES statement\n");}
				   |FOR OPEN_PARANTHESES SEMI_COLON SEMI_COLON CLOSE_PARANTHESES statement {printf("\tReduced : iteration_statement -> FOR OPEN_PARANTHESES SEMI_COLON SEMI_COLON CLOSE_PARANTHESES statement\n");}
				   ;

jump_statement:GOTO IDENTIFIER SEMI_COLON {printf("\tReduced : jump_statement -> GOTO IDENTIFIER SEMI_COLON\n");}
			  |CONTINUE SEMI_COLON {printf("\tReduced : jump_statement -> CONTINUE SEMI_COLON\n");}
			  |BREAK SEMI_COLON {printf("\tReduced : jump_statement -> BREAK SEMI_COLON\n");}
			  |RETURN expression SEMI_COLON {printf("\tReduced : jump_statement -> RETURN expression SEMI_COLON\n");}
			  |RETURN SEMI_COLON {printf("\tReduced : jump_statement -> RETURN SEMI_COLON\n");}
			  ;

expression:assignment_expression {printf("\tReduced : expression -> assignment_expression\n");}
		  |expression COMMA assignment_expression {printf("\tReduced : expression -> expression COMMA assignment_expression\n");}
		  ;

assignment_expression:conditional_expression {printf("\tReduced : assignment_expression -> conditional_expression\n");}
					 |unary_expression assignment_operator assignment_expression {printf("\tReduced : assignment_expression -> unary_expression assignment_operator assignment_expression\n");}
					 ;

assignment_operator:EQUALS {printf("\tReduced : assignment_operator -> EQUALS\n");}
				   |MUL_SHORT {printf("\tReduced : assignment_operator -> MUL_SHORT\n");}
				   |DIV_SHORT {printf("\tReduced : assignment_operator -> DIV_SHORT\n");}
				   |MOD_SHORT {printf("\tReduced : assignment_operator -> MOD_SHORT\n");}
				   |ADD_SHORT {printf("\tReduced : assignment_operator -> ADD_SHORT\n");}
				   |SUB_SHORT {printf("\tReduced : assignment_operator -> SUB_SHORT\n");}
				   |LSHIFT_SHORT {printf("\tReduced : assignment_operator -> LSHIFT_SHORT\n");}
				   |RSHIFT_SHORT {printf("\tReduced : assignment_operator -> RSHIFT_SHORT\n");}
				   |AND_SHORT {printf("\tReduced : assignment_operator -> AND_SHORT\n");}
				   |XOR_SHORT {printf("\tReduced : assignment_operator -> XOR_SHORT\n");}
				   |OR_SHORT {printf("\tReduced : assignment_operator -> OR_SHORT\n");}
				   ;

conditional_expression:logical_OR_expression {printf("\tReduced : conditional_expression -> logical_OR_expression\n");}
					  |logical_OR_expression TERNARY expression COLON conditional_expression {printf("\tReduced : conditional_expression -> logical_OR_expression TERNARY expression COLON conditional_expression\n");}
					  ;

constant_expression:conditional_expression {printf("\tReduced : constant_expression -> conditional_expression\n");}
				   ;

logical_OR_expression:logical_AND_expression {printf("\tReduced : logical_OR_expression -> logical_AND_expression\n");}
					 |logical_OR_expression OR logical_AND_expression {printf("\tReduced : logical_OR_expression -> logical_OR_expression OR logical_AND_expression\n");}
					 ;

logical_AND_expression:inclusive_OR_expression {printf("\tReduced : logical_AND_expression -> inclusive_OR_expression\n");}
					  |logical_AND_expression AND inclusive_OR_expression {printf("\tReduced : logical_AND_expression -> logical_AND_expression AND inclusive_OR_expression\n");}
					  ;

inclusive_OR_expression:exclusive_OR_expression {printf("\tReduced : inclusive_OR_expression -> exclusive_OR_expression\n");}
					   |inclusive_OR_expression OR_BIT exclusive_OR_expression {printf("\tReduced : inclusive_OR_expression -> inclusive_OR_expression OR_BIT exclusive_OR_expression\n");}
					   ;

exclusive_OR_expression:AND_expression {printf("\tReduced : exclusive_OR_expression -> AND_expression\n");}
					   |exclusive_OR_expression XOR AND_expression {printf("\tReduced : exclusive_OR_expression -> exclusive_OR_expression XOR AND_expression\n");}
					   ;

AND_expression:equality_expression {printf("\tReduced : AND_expression -> equality_expression\n");}
			  |AND_expression AND_BIT equality_expression {printf("\tReduced : AND_expression -> AND_expression AND_BIT equality_expression\n");}

equality_expression:relational_expression {printf("\tReduced : equality_expression -> relational_expression\n");}
				   |equality_expression IS_EQUAL_TO relational_expression {printf("\tReduced : equality_expression -> equality_expression IS_EQUAL_TO relational_expression\n");}
				   |equality_expression NOT_EQUAL relational_expression {printf("\tReduced : equality_expression -> equality_expression NOT_EQUAL relational_expression\n");}
				   ;

relational_expression:shift_expression {printf("\tReduced : relational_expression -> shift_expression\n");}
					 |relational_expression LESS_THAN shift_expression {printf("\tReduced : relational_expression -> relational_expression LESS_THAN shift_expression\n");}
					 |relational_expression GREATER_THAN shift_expression {printf("\tReduced : relational_expression -> relational_expression GREATER_THAN shift_expression\n");}
					 |relational_expression LESS_EQUAL shift_expression {printf("\tReduced : relational_expression -> relational_expression LESS_EQUAL shift_expression\n");}
					 |relational_expression GREATER_EQUAL shift_expression {printf("\tReduced : relational_expression -> relational_expression GREATER_EQUAL shift_expression\n");}
					 ;

shift_expression:additive_expression {printf("\tReduced : shift_expression -> additive_expression\n");}
			    |shift_expression L_SHIFT additive_expression {printf("\tReduced : shift_expression -> shift_expression L_SHIFT additive_expression\n");}
				|shift_expression R_SHIFT additive_expression {printf("\tReduced : shift_expression -> shift_expression R_SHIFT additive_expression\n");}
				;

additive_expression:multiplicative_expression {printf("\tReduced : additive_expression -> multiplicative_expression\n");}
				   |additive_expression PLUS multiplicative_expression {printf("\tReduced : additive_expression -> additive_expression PLUS multiplicative_expression\n");}
				   |additive_expression MINUS multiplicative_expression {printf("\tReduced : additive_expression -> additive_expression MINUS multiplicative_expression\n");}
				   ;

multiplicative_expression:cast_expression {printf("\tReduced : multiplicative_expression -> cast_expression\n");}
						 |multiplicative_expression MULTIPLY cast_expression {printf("\tReduced : multiplicative_expression -> multiplicative_expression MULTIPLY cast_expression\n");}
						 |multiplicative_expression DIVIDE cast_expression {printf("\tReduced : multiplicative_expression -> multiplicative_expression DIVIDE cast_expression\n");}
						 |multiplicative_expression MODULUS cast_expression {printf("\tReduced : multiplicative_expression -> multiplicative_expression MODULUS cast_expression\n");}
						 ;

cast_expression:unary_expression {printf("\tReduced : cast_expression -> unary_expression\n");}
			   |OPEN_PARANTHESES type_symbol_specification CLOSE_PARANTHESES cast_expression {printf("\tReduced : cast_expression -> OPEN_PARANTHESES type_symbol_specification CLOSE_PARANTHESES cast_expression\n");}
			   ;

unary_expression:postfix_expression {printf("\tReduced : unary_expression -> postfix_expression\n");}
				|INCREMENT unary_expression {printf("\tReduced : unary_expression -> INCREMENT unary_expression\n");}
				|DECREMENT unary_expression {printf("\tReduced : unary_expression -> DECREMENT unary_expression\n");}
				|unary_operator cast_expression {printf("\tReduced : unary_expression -> unary_operator cast_expression\n");}
				|lenOF unary_expression {printf("\tReduced : unary_expression -> lenOF unary_expression\n");}
				|lenOF OPEN_PARANTHESES type_symbol_specification CLOSE_PARANTHESES {printf("\tReduced : unary_expression -> lenOF OPEN_PARANTHESES type_symbol_specification CLOSE_PARANTHESES\n");}
				;

unary_operator:AND_BIT {printf("\tReduced : unary_operator -> AND_BIT\n");}
			  |MULTIPLY {printf("\tReduced : unary_operator -> MULTIPLY\n");}
			  |PLUS {printf("\tReduced : unary_operator -> PLUS\n");}
			  |MINUS {printf("\tReduced : unary_operator -> MINUS\n");}
			  |NEGATION {printf("\tReduced : unary_operator -> NEGATION\n");}
			  |NOT {printf("\tReduced : unary_operator -> NOT\n");}
			  ;

postfix_expression:primary_expression {printf("\tReduced : postfix_expression -> primary_expression\n");}
				  |postfix_expression OPEN_SQ_BRACKET expression CLOSE_SQ_BRACKET {printf("\tReduced : postfix_expression -> postfix_expression OPEN_SQ_BRACKET expression CLOSE_SQ_BRACKET\n");}
				  |postfix_expression OPEN_PARANTHESES argument_expression_list CLOSE_PARANTHESES {printf("\tReduced : postfix_expression -> postfix_expression OPEN_PARANTHESES argument_expression_list CLOSE_PARANTHESES\n");}
				  |postfix_expression OPEN_PARANTHESES CLOSE_PARANTHESES {printf("\tReduced : postfix_expression -> postfix_expression OPEN_PARANTHESES CLOSE_PARANTHESES\n");}
				  |postfix_expression DOT IDENTIFIER {printf("\tReduced : postfix_expression -> postfix_expression DOT IDENTIFIER\n");}
				  |postfix_expression LINK IDENTIFIER {printf("\tReduced : postfix_expression -> postfix_expression LINK IDENTIFIER\n");}
				  |postfix_expression INCREMENT {printf("\tReduced : postfix_expression -> postfix_expression INCREMENT\n");}
				  |postfix_expression DECREMENT {printf("\tReduced : postfix_expression -> postfix_expression DECREMENT\n");}
				  ;

primary_expression:IDENTIFIER {printf("\tReduced : primary_expression -> IDENTIFIER\n");for(j=1;j<=len;j++)
																						{if(!check_presence($1.symbol_specification))
																							break;
																						else
																						{
																							printf("Yet not declared %s\n",$1.symbol_specification);
																							yyerror();
																						}}}
				  |constant {printf("\tReduced : primary_expression -> constant\n");}
				  |STRING_CONSTANT {printf("\tReduced : primary_expression -> STRING_CONSTANT\n");if(flag==1)
																strcpy(symbol_table[len].value,strcat(strcat(symbol_table[len].value," "),$1.value));}
				  |OPEN_PARANTHESES expression CLOSE_PARANTHESES {printf("\tReduced : primary_expression -> OPEN_PARANTHESES expression CLOSE_PARANTHESES\n");}
				  ;

argument_expression_list:assignment_expression {printf("\tReduced : argument_expression_list -> assignment_expression\n");}
						|argument_expression_list COMMA assignment_expression {printf("\tReduced : argument_expression_list -> argument_expression_list COMMA assignment_expression\n");}
						;

constant:NUMBER {printf("\tReduced : constant -> NUMBER\n");if(flag==1)
																strcpy(symbol_table[len].value,strcat(strcat(symbol_table[len].value," "),$1.value));}
		|CHAR_CONSTANT {printf("\tReduced : constant -> CHAR_CONSTANT\n");if(flag==1)
																strcpy(symbol_table[len].value,strcat(strcat(symbol_table[len].value," "),$1.value));}
		|REAL_NUMBER {printf("\tReduced : constant -> REAL_NUMBER\n");if(flag==1)
																strcpy(symbol_table[len].value,strcat(strcat(symbol_table[len].value," "),$1.value));}
		|EXP_NUMBER {printf("\tReduced : constant -> EXP_NUMBER\n");if(flag==1)
																strcpy(symbol_table[len].value,strcat(strcat(symbol_table[len].value," "),$1.value));}
		;

%%

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
