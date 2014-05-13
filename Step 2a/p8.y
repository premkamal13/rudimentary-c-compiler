%{
%}
%token PLUS MULT NUMBER NEW_LINE
%nonassoc PLUS
%%
line:line expr NEW_LINE {printf("Output result=%d\n",$2);}
    |
    ;
expr:expr PLUS expr {$$=$1+$3;}
    |expr MULT expr {$$=$1*$3;}
    |NUMBER {$$=$1;}
    ;
%%
#include "lex.yy.c"
int yyerror()
{printf("Error\n");}
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Enter filename to be Compiled\n");
		return -1;
	}
	yyin = fopen(argv[1], "r");
	yyparse();
	return 0;
}
