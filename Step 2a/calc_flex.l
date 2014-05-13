%{
int lineno=1;
%}
digit	[0-9]
number	{digit}*

%%
\n	{ return NEW_LINE; lineno++; }
{number} { yylval=atoi(yytext); return NUMBER;}
"+"	{ return PLUS; }
"*"	{ return MULT; }
.	{ printf("%d: %c: unrecognised\n", lineno, yytext[0]);}
%%
int yywrap()
{
return -1;
}
