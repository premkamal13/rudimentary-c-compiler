%{
int line_num=1;
%}
digit [0-9]
alphabet [a-zA-Z_]
alphadig [a-zA-Z0-9_]
nonchar [^{alphadig}]
number {digit}+
realnum {number}(.{number})?
expno {number}(.{number})?([Ee][+-]?{number}(.{number})?)?
charconst "'"([^"]|\\.)"'"
strconst \"([^"]|\\.)*\"
var {alphabet}({alphadig})*

%%
("auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"while") {printf("%d: KEYWORD_%s\n",line_num,yytext);}
("do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if") {printf("%d: KEYWORD_%s\n",line_num,yytext); }
("int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static") {printf("%d: KEYWORD_%s\n",line_num,yytext);}
("struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile") {printf("%d: KEYWORD_%s\n",line_num,yytext);}

\n {line_num++;}

"+" {printf("%d: OPERATOR_PLUS\n",line_num);}
"-" {printf("%d: OPERATOR_MINUS\n",line_num);}
"++" {printf("%d: OPERATOR_INCREMENTOR\n",line_num);}
"--" {printf("%d: OPERATOR_DECREMENTOR\n",line_num);}
"+=" {printf("%d: OPERATOR_ADDER\n",line_num);}
"-=" {printf("%d: OPERATOR_SUBTRACTOR\n",line_num);}
"*=" {printf("%d: OPERATOR_MULTIPLIER\n",line_num);}
"/=" {printf("%d: OPERATOR_DIVIDER\n",line_num);}
"*" {printf("%d: OPERATOR_MULTIPLY\n",line_num);}
"/" {printf("%d: OPERATOR_DIVIDE\n",line_num);}
"=" {printf("%d: OPERATOR_ASSIGNMENT\n",line_num);}
"\\" {printf("%d: OPERATOR_SLASH\n",line_num);}
"%" {printf("%d: OPERATOR_MODULUS\n",line_num);}
"<" {printf("%d: OPERATOR_<\n",line_num);}
">" {printf("%d: OPERATOR_>\n",line_num);}
"!" {printf("%d: OPERATOR_NOT\n",line_num);}
"&" {printf("%d: OPERATOR_BITWISE_AND\n",line_num);}
"|" {printf("%d: OPERATOR_BITWISE_OR\n",line_num);}
"&&" {printf("%d: OPERATOR_AND\n",line_num);}
"||" {printf("%d: OPERATOR_OR\n",line_num);}
"^" {printf("%d: OPERATOR_BITWISE_XOR\n",line_num);}
"~" {printf("%d: OPERATOR_TILDE\n",line_num);}
"==" {printf("%d: OPERATOR_EQUALITY_CHECKER\n",line_num);}
"&=" {printf("%d: OPERATOR_AND_ASSIGNMENT\n",line_num); }
"|=" {printf("%d: OPERATOR_OR_ASSIGNMENT\n",line_num); }
"<=" {printf("%d: OPERATOR_LESS_OR_EQUAL\n",line_num); }
">=" {printf("%d: OPERATOR_GREATER_OR_EQUAL\n",line_num); }
"!=" {printf("%d: OPERATOR_NOT_EQUAL\n",line_num); }
"->" {printf("%d: OPERATOR_LINK\n",line_num); }
"^=" {printf("%d: OPERATOR_XOR_ASSIGNMENT\n",line_num); }
">>" {printf("%d: OPERATOR_RIGHT_SHIFT\n",line_num); }
"<<" {printf("%d: OPERATOR_LEFT_SHIFT\n",line_num); }
"<<=" {printf("%d: OPERATOR_LEFT_ASSIGNMENT\n",line_num); }
">>=" {printf("%d: OPERATOR_RIGHT_ASSIGNMENT\n",line_num); }

"." {printf("%d: DOT\n",line_num);}
"[" {printf("%d: SQUARE_BRACKET_BEG\n",line_num);}
"]" {printf("%d: SQUARE_BRACKET_END\n",line_num);}
"{" {printf("%d: CURLY_BRACKET_BEG\n",line_num);}
"}" {printf("%d: CURLY_BRACKET_END\n",line_num);}
"(" {printf("%d: PARENTHESIS_BEG\n",line_num);}
")" {printf("%d: PARENTHESIS_END\n",line_num);}
"," {printf("%d: COMMA\n",line_num);}
":" {printf("%d: COLON\n",line_num);}
";" {printf("%d: SEMICOLON\n",line_num);}
"#" {printf("%d: SHARP\n",line_num);}

{number} {printf("%d: NUMBER %s\n",line_num,yytext);}
{realnum} {printf("%d: REAL_NUMBER %s\n",line_num,yytext);}
{expno} {printf("%d: EXP_NUMBER %s\n",line_num,yytext);}
{charconst} {printf("%d: CHAR_CONSTANT %s\n",line_num,yytext);}
{strconst} {printf("%d: STRING_CONSTANT %s\n",line_num,yytext);}

{var} {printf("%d: IDENTIFIER %s\n",line_num,yytext);}
" " {}
. {printf("%d: UNIDENTIFIED_TOKEN %s\n",line_num,yytext);}

%%
int yywrap()
{
return -1;
}
int main(int argc,char *argv[])
{
if(argc<2)
{
printf("The input format is: .exe inp\n");
return -1;
}
yyin = fopen(argv[1],"r");
yylex();
fclose(yyin);
return 0;
}
