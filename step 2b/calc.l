%{
int lineno=1;
%}

digit	[0-9]
number	{digit}*

%option noyywrap

%%

\n	{ printf("%d: NEW_LINE\n", lineno); lineno++; return NEW_LINE; }

{number} { printf("%d: NUMBER: %s\n", lineno,  yytext); strcpy(yylval.name, yytext); return NUMBER; }

"+"	{ printf("%d: PLUS\n", lineno); return PLUS; }
"*"	{ printf("%d: MULT\n", lineno); return MULT; }

.	{ printf("%d: %c: unrecognized\n", lineno, yytext[0]); }

%%
