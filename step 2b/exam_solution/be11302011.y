%{
	#include<stdio.h>
	extern line_num;
	int cnt=0,scs=0,f=0,tq=0;
	int arr[]={0,1,4,16,64,1000,1004,4000,4004,4064,8000,8004,10000,11000,11004,14000,14004,18000,18004};
	void spec()
	{
        if(scs==1)
        {
            f=1;
            yyerror();
        }
        scs=1;
	}
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

declaration:declaration_specifiers init_declarator_list SEMICOLON {cnt=0; scs=0; tq=0; printf("\tReduced : declaration -> declaration_specifiers init_declarator_list SEMICOLON\n");}
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

type_specifier:VOID { func(0); printf("\tReduced : type_specifier -> VOID\n");}
			  |CHAR { func(1); printf("\tReduced : type_specifier -> CHAR\n");}
			  |INT { func(4); printf("\tReduced : type_specifier -> INT\n");}
			  |FLOAT { func(16); printf("\tReduced : type_specifier -> FLOAT\n");}
			  |DOUBLE { func(64); printf("\tReduced : type_specifier -> DOUBLE\n");}
			  |SHORT { func(1000); printf("\tReduced : type_specifier -> SHORT\n");}
			  |LONG { func(4000); printf("\tReduced : type_specifier -> LONG\n");}
			  |SIGNED { func(10000); printf("\tReduced : type_specifier -> SIGNED\n");}
			  |UNSIGNED { func(10000); printf("\tReduced : type_specifier -> UNSIGNED\n");}
			  |struct_or_union_specifier { func(0); printf("\tReduced : type_specifier -> struct_or_union_specifier\n");}
			  |enum_specifier { func(0); printf("\tReduced : type_specifier -> enum_specifier\n");}
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

struct_declaration:specifier_qualifier_list struct_declarator_list SEMICOLON {printf("\tReduced : struct_declaration -> specifier_qualifier_list struct_declarator_list SEMICOLON\n");}
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

direct_declarator:IDENTIFIER {printf("\tReduced : direct_declarator -> IDENTIFIER\n");}
				 |PARANTHESIS_BEG declarator PARANTHESIS_END {printf("\tReduced : direct_declarator -> PARANTHESIS_BEG declarator PARANTHESIS_END\n");}
				 |direct_declarator SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END {printf("\tReduced : direct_declarator -> direct_declarator SQUARE_BRACKET_BEG constant_expression SQUARE_BRACKET_END\n");}
				 |direct_declarator SQUARE_BRACKET_BEG SQUARE_BRACKET_END {printf("\tReduced : direct_declarator -> direct_declarator SQUARE_BRACKET_BEG SQUARE_BRACKET_END\n");}
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

expression_statement:expression SEMICOLON {printf("\tReduced : expression_statement -> expression SEMICOLON\n");}
					|SEMICOLON {printf("\tReduced : expression_statement -> SEMICOLON\n");}
					;

compound_statement:CURLY_BRACKET_BEG declaration_list statement_list CURLY_BRACKET_END {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG declaration_list statement_list CURLY_BRACKET_END\n");}
				  |CURLY_BRACKET_BEG declaration_list CURLY_BRACKET_END {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG declaration_list CURLY_BRACKET_END\n");}
				  |CURLY_BRACKET_BEG statement_list CURLY_BRACKET_END {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG statement_list CURLY_BRACKET_END\n");}
				  |CURLY_BRACKET_BEG CURLY_BRACKET_END {printf("\tReduced : compound_statement -> CURLY_BRACKET_BEG CURLY_BRACKET_END\n");}
				  ;

statement_list:statement {printf("\tReduced : statement_list -> statement\n");}
			  |statement_list statement {printf("\tReduced : statement_list -> statement_list statement\n");}
			  ;

selection_statement:IF PARANTHESIS_BEG expression PARANTHESIS_END statement {printf("\tReduced : selection_statement -> IF PARANTHESIS_BEG expression PARANTHESIS_END statement\n");}
				   |IF PARANTHESIS_BEG expression PARANTHESIS_END statement ELSE statement {printf("\tReduced : selection_statement -> IF PARANTHESIS_BEG expression PARANTHESIS_END statement ELSE statement\n");}
				   |SWITCH PARANTHESIS_BEG expression PARANTHESIS_END statement {printf("\tReduced : selection_statement -> SWITCH PARANTHESIS_BEG expression PARANTHESIS_END statement\n");}
				   ;

iteration_statement:WHILE PARANTHESIS_BEG expression PARANTHESIS_END statement {printf("\tReduced : iteration_statement -> WHILE PARANTHESIS_BEG expression PARANTHESIS_END statement\n");}
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

jump_statement:GOTO IDENTIFIER SEMICOLON {printf("\tReduced : jump_statement -> GOTO IDENTIFIER SEMICOLON\n");}
			  |CONTINUE SEMICOLON {printf("\tReduced : jump_statement -> CONTINUE SEMICOLON\n");}
			  |BREAK SEMICOLON {printf("\tReduced : jump_statement -> BREAK SEMICOLON\n");}
			  |RETURN expression SEMICOLON {printf("\tReduced : jump_statement -> RETURN expression SEMICOLON\n");}
			  |RETURN SEMICOLON {printf("\tReduced : jump_statement -> RETURN SEMICOLON\n");}
			  ;

expression:assignment_expression {printf("\tReduced : expression -> assignment_expression\n");}
		  |expression COMMA assignment_expression {printf("\tReduced : expression -> expression COMMA assignment_expression\n");}
		  ;

assignment_expression:conditional_expression {printf("\tReduced : assignment_expression -> conditional_expression\n");}
					 |unary_expression assignment_operator assignment_expression {printf("\tReduced : assignment_expression -> unary_expression assignment_operator assignment_expression\n");}
					 ;

assignment_operator:OPERATOR_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_ASSIGNMENT\n");}
				   |OPERATOR_MULTIPLIER {printf("\tReduced : assignment_operator -> OPERATOR_MULTIPLIER\n");}
				   |OPERATOR_DIVIDER {printf("\tReduced : assignment_operator -> OPERATOR_DIVIDER\n");}
				   |OPERATOR_MOD_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_MOD_ASSIGNMENT\n");}
				   |OPERATOR_ADDER {printf("\tReduced : assignment_operator -> OPERATOR_ADDER\n");}
				   |OPERATOR_SUBTRACTOR {printf("\tReduced : assignment_operator -> OPERATOR_SUBTRACTOR\n");}
				   |OPERATOR_LEFT_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_LEFT_ASSIGNMENT\n");}
				   |OPERATOR_RIGHT_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_RIGHT_ASSIGNMENT\n");}
				   |OPERATOR_AND_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_AND_ASSIGNMENT\n");}
				   |OPERATOR_BITWISE_XOR_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_BITWISE_XOR_ASSIGNMENT\n");}
				   |OPERATOR_OR_ASSIGNMENT {printf("\tReduced : assignment_operator -> OPERATOR_OR_ASSIGNMENT\n");}
				   ;

conditional_expression:logical_OR_expression {printf("\tReduced : conditional_expression -> logical_OR_expression\n");}
					  |logical_OR_expression TERNARY expression COLON conditional_expression {printf("\tReduced : conditional_expression -> logical_OR_expression TERNARY expression COLON conditional_expression\n");}
					  ;

constant_expression:conditional_expression {printf("\tReduced : constant_expression -> conditional_expression\n");}
				   ;

logical_OR_expression:logical_AND_expression {printf("\tReduced : logical_OR_expression -> logical_AND_expression\n");}
					 |logical_OR_expression OPERATOR_OR logical_AND_expression {printf("\tReduced : logical_OR_expression -> logical_OR_expression OPERATOR_OR logical_AND_expression\n");}
					 ;

logical_AND_expression:inclusive_OR_expression {printf("\tReduced : logical_AND_expression -> inclusive_OR_expression\n");}
					  |logical_AND_expression OPERATOR_AND inclusive_OR_expression {printf("\tReduced : logical_AND_expression -> logical_AND_expression OPERATOR_AND inclusive_OR_expression\n");}
					  ;

inclusive_OR_expression:exclusive_OR_expression {printf("\tReduced : inclusive_OR_expression -> exclusive_OR_expression\n");}
					   |inclusive_OR_expression OPERATOR_BITWISE_OR exclusive_OR_expression {printf("\tReduced : inclusive_OR_expression -> inclusive_OR_expression OPERATOR_BITWISE_OR exclusive_OR_expression\n");}
					   ;

exclusive_OR_expression:AND_expression {printf("\tReduced : exclusive_OR_expression -> AND_expression\n");}
					   |exclusive_OR_expression OPERATOR_BITWISE_XOR AND_expression {printf("\tReduced : exclusive_OR_expression -> exclusive_OR_expression OPERATOR_BITWISE_XOR AND_expression\n");}
					   ;

AND_expression:equality_expression {printf("\tReduced : AND_expression -> equality_expression\n");}
			  |AND_expression OPERATOR_BITWISE_AND equality_expression {printf("\tReduced : AND_expression -> AND_expression OPERATOR_BITWISE_AND equality_expression\n");}

equality_expression:relational_expression {printf("\tReduced : equality_expression -> relational_expression\n");}
				   |equality_expression OPERATOR_EQUALITY_CHECKER relational_expression {printf("\tReduced : equality_expression -> equality_expression OPERATOR_EQUALITY_CHECKER relational_expression\n");}
				   |equality_expression OPERATOR_NOT_EQUAL relational_expression {printf("\tReduced : equality_expression -> equality_expression OPERATOR_NOT_EQUAL relational_expression\n");}
				   ;

relational_expression:shift_expression {printf("\tReduced : relational_expression -> shift_expression\n");}
					 |relational_expression OPERATOR_LESS_THAN shift_expression {printf("\tReduced : relational_expression -> relational_expression OPERATOR_LESS_THAN shift_expression\n");}
					 |relational_expression OPERATOR_GREATER_THAN shift_expression {printf("\tReduced : relational_expression -> relational_expression OPERATOR_GREATER_THAN shift_expression\n");}
					 |relational_expression OPERATOR_LESS_OR_EQUAL shift_expression {printf("\tReduced : relational_expression -> relational_expression OPERATOR_LESS_OR_EQUAL shift_expression\n");}
					 |relational_expression OPERATOR_GREATER_OR_EQUAL shift_expression {printf("\tReduced : relational_expression -> relational_expression OPERATOR_GREATER_OR_EQUAL shift_expression\n");}
					 ;

shift_expression:additive_expression {printf("\tReduced : shift_expression -> additive_expression\n");}
			    |shift_expression OPERATOR_LEFT_SHIFT additive_expression {printf("\tReduced : shift_expression -> shift_expression OPERATOR_LEFT_SHIFT additive_expression\n");}
				|shift_expression OPERATOR_RIGHT_SHIFT additive_expression {printf("\tReduced : shift_expression -> shift_expression OPERATOR_RIGHT_SHIFT additive_expression\n");}
				;

additive_expression:multiplicative_expression {printf("\tReduced : additive_expression -> multiplicative_expression\n");}
				   |additive_expression OPERATOR_PLUS multiplicative_expression {printf("\tReduced : additive_expression -> additive_expression OPERATOR_PLUS multiplicative_expression\n");}
				   |additive_expression OPERATOR_MINUS multiplicative_expression {printf("\tReduced : additive_expression -> additive_expression OPERATOR_MINUS multiplicative_expression\n");}
				   ;

multiplicative_expression:cast_expression {printf("\tReduced : multiplicative_expression -> cast_expression\n");}
						 |multiplicative_expression OPERATOR_MULTIPLY cast_expression {printf("\tReduced : multiplicative_expression -> multiplicative_expression OPERATOR_MULTIPLY cast_expression\n");}
						 |multiplicative_expression OPERATOR_DIVIDE cast_expression {printf("\tReduced : multiplicative_expression -> multiplicative_expression OPERATOR_DIVIDE cast_expression\n");}
						 |multiplicative_expression OPERATOR_MODULUS cast_expression {printf("\tReduced : multiplicative_expression -> multiplicative_expression OPERATOR_MODULUS cast_expression\n");}
						 ;

cast_expression:unary_expression {printf("\tReduced : cast_expression -> unary_expression\n");}
			   |PARANTHESIS_BEG type_name PARANTHESIS_END cast_expression {printf("\tReduced : cast_expression -> PARANTHESIS_BEG type_name PARANTHESIS_END cast_expression\n");}
			   ;

unary_expression:postfix_expression {printf("\tReduced : unary_expression -> postfix_expression\n");}
				|OPERATOR_INCREMENTOR unary_expression {printf("\tReduced : unary_expression -> OPERATOR_INCREMENTOR unary_expression\n");}
				|OPERATOR_DECREMENTOR unary_expression {printf("\tReduced : unary_expression -> OPERATOR_DECREMENTOR unary_expression\n");}
				|unary_operator cast_expression {printf("\tReduced : unary_expression -> unary_operator cast_expression\n");}
				|SIZEOF unary_expression {printf("\tReduced : unary_expression -> SIZEOF unary_expression\n");}
				|SIZEOF PARANTHESIS_BEG type_name PARANTHESIS_END {printf("\tReduced : unary_expression -> SIZEOF PARANTHESIS_BEG type_name PARANTHESIS_END\n");}
				;

unary_operator:OPERATOR_BITWISE_AND {printf("\tReduced : unary_operator -> OPERATR_BITWISE_AND\n");}
			  |OPERATOR_MULTIPLY {printf("\tReduced : unary_operator -> OPERATOR_MULTIPLY\n");}
			  |OPERATOR_PLUS {printf("\tReduced : unary_operator -> OPERATOR_PLUS\n");}
			  |OPERATOR_MINUS {printf("\tReduced : unary_operator -> OPERATOR_MINUS\n");}
			  |OPERATOR_TILDE {printf("\tReduced : unary_operator -> OPERATOR_TILDE\n");}
			  |OPERATOR_NOT {printf("\tReduced : unary_operator -> OPERATOR_NOT\n");}
			  ;

postfix_expression:primary_expression {printf("\tReduced : postfix_expression -> primary_expression\n");}
				  |postfix_expression SQUARE_BRACKET_BEG expression SQUARE_BRACKET_END {printf("\tReduced : postfix_expression -> postfix_expression SQUARE_BRACKET_BEG expression SQUARE_BRACKET_END\n");}
				  |postfix_expression PARANTHESIS_BEG argument_expression_list PARANTHESIS_END {printf("\tReduced : postfix_expression -> postfix_expression PARANTHESIS_BEG argument_expression_list PARANTHESIS_END\n");}
				  |postfix_expression PARANTHESIS_BEG PARANTHESIS_END {printf("\tReduced : postfix_expression -> postfix_expression PARANTHESIS_BEG PARANTHESIS_END\n");}
				  |postfix_expression DOT IDENTIFIER {printf("\tReduced : postfix_expression -> postfix_expression DOT IDENTIFIER\n");}
				  |postfix_expression OPERATOR_LINK IDENTIFIER {printf("\tReduced : postfix_expression -> postfix_expression OPERATOR_LINK IDENTIFIER\n");}
				  |postfix_expression OPERATOR_INCREMENTOR {printf("\tReduced : postfix_expression -> postfix_expression OPERATOR_INCREMENTOR\n");}
				  |postfix_expression OPERATOR_DECREMENTOR {printf("\tReduced : postfix_expression -> postfix_expression OPERATOR_DECREMENTOR\n");}
				  ;

primary_expression:IDENTIFIER {printf("\tReduced : primary_expression -> IDENTIFIER\n");}
				  |constant {printf("\tReduced : primary_expression -> constant\n");}
				  |STRING_CONSTANT {printf("\tReduced : primary_expression -> STRING_constANT\n");}
				  |PARANTHESIS_BEG expression PARANTHESIS_END {printf("\tReduced : primary_expression -> PARANTHESIS_BEG expression PARANTHESIS_END\n");}
				  ;

argument_expression_list:assignment_expression {printf("\tReduced : argument_expression_list -> assignment_expression\n");}
						|argument_expression_list COMMA assignment_expression {printf("\tReduced : argument_expression_list -> argument_expression_list COMMA assignment_expression\n");}
						;

constant:NUMBER {printf("\tReduced : constant -> NUMBER\n");}
		|CHAR_CONSTANT {printf("\tReduced : constant -> CHAR_CONSTANT\n");}
		|REAL_NUMBER {printf("\tReduced : constant -> REAL_NUMBER\n");}
		|EXP_NUMBER {printf("\tReduced : constant -> EXP_NUMBER\n");}
		;

%%

#include "lex.yy.c"
int yyerror()
{
    printf("\nERROR:");
	printf("\t(LINE NO. %d) of the input file\nDescription:",line_num);
	if(f==1)
	{
        printf("More than one storage_class_specifier in one assignment\n");
	}
	else if(f==2)
	{
        printf("Invalid data type encountered\n");
	}
	else
	{
        printf("Invalid Syntax\n");
	}
	printf("\t(The further execution of program is being terminated!!!)\n");
	exit(0);
}

int main(int argc,char *argv[])
{
        if(argc<2)
        {
                printf("Correct format is <.exe><input file-name>\n");
                return -1;
        }
        yyin = fopen(argv[1],"r");
        yyparse();
        fclose(yyin);
        return 0;
}
