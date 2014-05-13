%{
int line=1;
%}
digit [0-9]
abet [a-zA-Z_]
adig [a-zA-Z0-9_]

number {digit}+

realnum {number}("."{number})?
expno {number}(.{number})?([Ee][+-]?{number}(.{number})?)?
charsconst "'"([^']|\\.)"'"

strsconst \"([^"]|\\.)*\"
var {abet}({adig})*

%%
auto {printf(" %d : AUTO\n",line);return AUTO;}
break {printf(" %d : BREAK\n",line);return BREAK;}
case {printf(" %d : CASE\n",line);return CASE;}
char {printf(" %d : CHAR\n",line);return CHAR;}
const {printf(" %d : CONST\n",line);return CONST;}

enum {printf(" %d : ENUM\n",line);return ENUM;}
extern {printf(" %d : EXTERN\n",line);return EXTERN;}
float {printf(" %d : FLOAT\n",line);return FLOAT;}
for {printf(" %d : FOR\n",line);return FOR;}

sizeof {printf(" %d : SIZEOF\n",line);return SIZEOF;}
static {printf(" %d : STATIC\n",line);return STATIC;}
struct {printf(" %d : STRUCT\n",line);return STRUCT;}
switch {printf(" %d : SWITCH\n",line);return SWITCH;}

goto {printf(" %d : GOTO\n",line);return GOTO;}
if {printf(" %d : IF\n",line);return IF;}
long {printf(" %d : LONG\n",line);return LONG;}
int {printf(" %d : INT\n",line);return INT;}
register {printf(" %d : REGISTER\n",line);return REGISTER;}
return {printf(" %d : RETURN\n",line);return RETURN;}
short {printf(" %d : SHORT\n",line);return SHORT;}

typedef {printf(" %d : TYPEDEF\n",line);return TYPEDEF;}
union {printf(" %d : UNION\n",line);return UNION;}
unsigned {printf(" %d : UNSIGNED\n",line);return UNSIGNED;}
void {printf(" %d : VOID\n",line);return VOID;}
volatile {printf(" %d : VOLATILE\n",line);return VOLATILE;}
while {printf(" %d : WHILE\n",line);return WHILE;}

default {printf(" %d : DEFAULT\n",line);return DEFAULT;}
continue {printf(" %d : CONTINUE\n",line);return CONTINUE;}
do {printf(" %d : DO\n",line);return DO;}
double {printf(" %d : DOUBLE\n",line);return DOUBLE;}
else {printf(" %d : ELSE\n",line);return ELSE;}

\n {line++;}


"*" {printf(" %d : OP_MULTIPLY\n",line); return OP_MULTIPLY;}
"/" {printf(" %d : OP_DIVIDE\n",line); return OP_DIVIDE;}
"=" {printf(" %d : OP_ASSIGNMENT\n",line); return OP_ASSIGNMENT;}
"\\" {printf(" %d : OP_SLASH\n",line); return OP_SLASH;}
"%" {printf(" %d : OP_MODULUS\n",line); return OP_MODULUS;}
"<" {printf(" %d : OP_LESS_THAN\n",line); return OP_LESS_THAN;}

"+" {printf(" %d : OP_PLUS\n",line); return OP_PLUS;}
"-" {printf(" %d : OP_MINUS\n",line); return OP_MINUS;}
"++" {printf(" %d : OP_INCREMENTOR\n",line); return OP_INCREMENTOR;}
"--" {printf(" %d : OP_DECREMENTOR\n",line); return OP_DECREMENTOR;}
"+=" {printf(" %d : OP_ADDER\n",line); return OP_ADDER;}
"-=" {printf(" %d : OP_SUBTRACTOR\n",line); return OP_SUBTRACTOR;}
"*=" {printf(" %d : OP_MULTIPLIER\n",line); return OP_MULTIPLIER;}
"/=" {printf(" %d : OP_DIVIDER\n",line); return OP_DIVIDER;}

">" {printf(" %d : OP_GREATER_THAN\n",line); return OP_GREATER_THAN;}
"!" {printf(" %d : OP_NOT\n",line); return OP_NOT;}
"&" {printf(" %d : OP_BITWISE_AND\n",line); return OP_BITWISE_AND;}
"|" {printf(" %d : OP_BITWISE_OR\n",line); return OP_BITWISE_OR;}
"&&" {printf(" %d : OP_AND\n",line); return OP_AND;}

">=" {printf(" %d : OP_GREATER_OR_EQUAL\n",line); return OP_GREATER_OR_EQUAL;}
"!=" {printf(" %d : OP_NOT_EQUAL\n",line); return OP_NOT_EQUAL;}
"->" {printf(" %d : OP_LINK\n",line); return OP_LINK;}
"^=" {printf(" %d : OP_BITWISE_XOR_ASSIGNMENT\n",line); return OP_BITWISE_XOR_ASSIGNMENT;}

"||" {printf(" %d : OP_OR\n",line); return OP_OR;}
"^" {printf(" %d : OP_BITWISE_XOR\n",line); return OP_BITWISE_XOR;}
"~" {printf(" %d : OP_TILDE\n",line); return OP_TILDE;}
"==" {printf(" %d : OP_EQUALITY_CHECKER\n",line); return OP_EQUALITY_CHECKER;}
"&=" {printf(" %d : OP_AND_ASSIGNMENT\n",line); return OP_AND_ASSIGNMENT;}
"|=" {printf(" %d : OP_OR_ASSIGNMENT\n",line); return OP_OR_ASSIGNMENT;}
"<=" {printf(" %d : OP_LESS_OR_EQUAL\n",line); return OP_LESS_OR_EQUAL;}

">>" {printf(" %d : OP_RIGHT_SHIFT\n",line); return OP_RIGHT_SHIFT;}
"<<" {printf(" %d : OP_LEFT_SHIFT\n",line); return OP_LEFT_SHIFT;}
"%=" {printf(" %d : OP_MOD_ASSIGNMENT\n",line); return OP_MOD_ASSIGNMENT;}
"<<=" {printf(" %d : OP_LEFT_ASSIGNMENT\n",line); return OP_LEFT_ASSIGNMENT;}

"[" {printf(" %d : SQUARE_BRACKET_BEG\n",line); return SQUARE_BRACKET_BEG;}
"]" {printf(" %d : SQUARE_BRACKET_END\n",line); return SQUARE_BRACKET_END;}
"{" {printf(" %d : CURLY_BRACKET_BEG\n",line); return CURLY_BRACKET_BEG;}
"}" {printf(" %d : CURLY_BRACKET_END\n",line); return CURLY_BRACKET_END;}
"(" {printf(" %d : PARANTHESIS_BEG\n",line); return PARANTHESIS_BEG;}
")" {printf(" %d : PARANTHESIS_END\n",line); return PARANTHESIS_END;}

"..." {printf(" %d : THREE_DOTS\n",line); return THREE_DOTS;}
"?" {printf(" %d : TERNARY\n",line); return TERNARY;}
"." {printf(" %d : DOT\n",line); return DOT;}

"," {printf(" %d : COMMA\n",line); return COMMA;}
":" {printf(" %d : COLON\n",line); return COLON;}
";" {printf(" %d : SEMICOLON\n",line); return SEMICOLON;}
"#" {printf(" %d : SHARP\n",line); return SHARP;}
\" {printf(" %d : DOUBLE_QUOTES\n",line); return DOUBLE_QUOTES;}

{number} {printf(" %d : NUMBER %s\n",line,yytext); return NUMBER;}
{realnum} {printf(" %d : REAL_NUMBER %s\n",line,yytext); return REAL_NUMBER;}
{expno} {printf(" %d : EXP_NUMBER %s\n",line,yytext); return EXP_NUMBER;}
{charsconst} {printf(" %d : CHAR_CONSTANT %s\n",line,yytext); return CHAR_CONSTANT;}
{strsconst} {printf(" %d : STRING_CONSTANT %s\n",line,yytext); return STRING_CONSTANT;}

{var} {printf(" %d : IDENTIFIER: %s\n",line,yytext); return IDENTIFIER;}
" " {}

%%
int yywrap(){return -1;}
