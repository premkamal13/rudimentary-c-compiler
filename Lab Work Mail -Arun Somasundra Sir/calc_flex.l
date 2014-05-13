%{

	int lineno=1;

%}


digit	[0-9]

number	{digit}*


%%


\n		{ printf("%d: NEW_LINE\n", lineno); lineno++; }


{number} 		{ printf("%d: NUMBER: %s\n", lineno,  yytext); }


"+"		{ printf("%d: PLUS\n", lineno); }

"*"		{ printf("%d: MULT\n", lineno); }


.		{ printf("%d: %c: unrecognized\n", lineno, yytext[0]); } 


%%

int yywrap()
{
	return -1;
}
int main(int argc, char *argv[])

{
	
if (argc != 2)
	
{
		
printf("Enter filename to be Compiled\n");
		
return -1;
	
}

	
yyin = fopen(argv[1], "r");

	
yylex();

	
return 0;

}
