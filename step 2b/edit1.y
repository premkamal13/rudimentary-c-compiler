%{
%}

%token NEW_LINE NUMBER PLUS MULT
%union {
        int value;
        char name[100];
}
%type 5 NUMBER
%%
line:	line expr NEW_LINE { printf("*** Sum = %d\n", $2); }
	|
	;

expr	: expr PLUS expr { $$ = $1 + $3; }
	| expr MULT expr { $$ = $1 * $3; }
	| NUMBER { $$ = atoi($1); }
	;

%%
#include "lex.yy.c"

int yyerror()
{
	printf("Error\n");
}

int main(int argc, char *argv[])
{
    printf("%d\n",sizeof(yylval));
	if (argc != 2)
	{
		printf("Enter filename to be Compiled\n");
		return -1;
	}

	yyin = fopen(argv[1], "r");

	yyparse();

	return 0;
}
