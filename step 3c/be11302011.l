%{
int line_num=1;
%}
digit [0-9]
alphabet [a-zA-Z_]
alphadig [a-zA-Z0-9_]
number {digit}+
realnum {number}("."{number})?
expno {number}(.{number})?([Ee][+-]?{number}(.{number})?)?
charconst "'"([^']|\\.)"'"
strconst \"([^"]|\\.)*\"
var {alphabet}({alphadig})*

%%
auto {printf("%d: AUTO\n",line_num);return AUTO;}
break {printf("%d: BREAK\n",line_num);return BREAK;}
case {printf("%d: CASE\n",line_num);return CASE;}
char {printf("%d: CHAR\n",line_num);return CHAR;}
const {printf("%d: CONST\n",line_num);return CONST;}
continue {printf("%d: CONTINUE\n",line_num);return CONTINUE;}
default {printf("%d: DEFAULT\n",line_num);return DEFAULT;}
do {printf("%d: DO\n",line_num);return DO;}
double {printf("%d: DOUBLE\n",line_num);return DOUBLE;}
else {printf("%d: ELSE\n",line_num);return ELSE;}
enum {printf("%d: ENUM\n",line_num);return ENUM;}
extern {printf("%d: EXTERN\n",line_num);return EXTERN;}
float {printf("%d: FLOAT\n",line_num);return FLOAT;}
for {printf("%d: FOR\n",line_num);return FOR;}
goto {printf("%d: GOTO\n",line_num);return GOTO;}
if {printf("%d: IF\n",line_num);return IF;}
long {printf("%d: LONG\n",line_num);return LONG;}
int {printf("%d: INT\n",line_num);return INT;}
register {printf("%d: REGISTER\n",line_num);return REGISTER;}
return {printf("%d: RETURN\n",line_num);return RETURN;}
short {printf("%d: SHORT\n",line_num);return SHORT;}
sizeof {printf("%d: SIZEOF\n",line_num);return SIZEOF;}
signed {printf("%d: SIZEOF\n",line_num);return SIGNED;}
static {printf("%d: STATIC\n",line_num);return STATIC;}
struct {printf("%d: STRUCT\n",line_num);return STRUCT;}
switch {printf("%d: SWITCH\n",line_num);return SWITCH;}
typedef {printf("%d: TYPEDEF\n",line_num);return TYPEDEF;}
union {printf("%d: UNION\n",line_num);return UNION;}
unsigned {printf("%d: UNSIGNED\n",line_num);return UNSIGNED;}
void {printf("%d: VOID\n",line_num);return VOID;}
volatile {printf("%d: VOLATILE\n",line_num);return VOLATILE;}
while {printf("%d: WHILE\n",line_num);return WHILE;}
\n {line_num++;}

"+" {printf("%d: OPERATOR_PLUS\n",line_num); return OPERATOR_PLUS;}
"-" {printf("%d: OPERATOR_MINUS\n",line_num); return OPERATOR_MINUS;}
"++" {printf("%d: OPERATOR_INCREMENTOR\n",line_num); return OPERATOR_INCREMENTOR;}
"--" {printf("%d: OPERATOR_DECREMENTOR\n",line_num); return OPERATOR_DECREMENTOR;}
"+=" {printf("%d: OPERATOR_ADDER\n",line_num); return OPERATOR_ADDER;}
"-=" {printf("%d: OPERATOR_SUBTRACTOR\n",line_num); return OPERATOR_SUBTRACTOR;}
"*=" {printf("%d: OPERATOR_MULTIPLIER\n",line_num); return OPERATOR_MULTIPLIER;}
"/=" {printf("%d: OPERATOR_DIVIDER\n",line_num); return OPERATOR_DIVIDER;}
"*" {printf("%d: OPERATOR_MULTIPLY\n",line_num); return OPERATOR_MULTIPLY;}
"/" {printf("%d: OPERATOR_DIVIDE\n",line_num); return OPERATOR_DIVIDE;}
"=" {printf("%d: OPERATOR_ASSIGNMENT\n",line_num); return OPERATOR_ASSIGNMENT;}
"\\" {printf("%d: OPERATOR_SLASH\n",line_num); return OPERATOR_SLASH;}
"%" {printf("%d: OPERATOR_MODULUS\n",line_num); return OPERATOR_MODULUS;}
"<" {printf("%d: OPERATOR_LESS_THAN\n",line_num); return OPERATOR_LESS_THAN;}
">" {printf("%d: OPERATOR_GREATER_THAN\n",line_num); return OPERATOR_GREATER_THAN;}
"!" {printf("%d: OPERATOR_NOT\n",line_num); return OPERATOR_NOT;}
"&" {printf("%d: OPERATOR_BITWISE_AND\n",line_num); return OPERATOR_BITWISE_AND;}
"|" {printf("%d: OPERATOR_BITWISE_OR\n",line_num); return OPERATOR_BITWISE_OR;}
"&&" {printf("%d: OPERATOR_AND\n",line_num); return OPERATOR_AND;}
"||" {printf("%d: OPERATOR_OR\n",line_num); return OPERATOR_OR;}
"^" {printf("%d: OPERATOR_BITWISE_XOR\n",line_num); return OPERATOR_BITWISE_XOR;}
"~" {printf("%d: OPERATOR_TILDE\n",line_num); return OPERATOR_TILDE;}
"==" {printf("%d: OPERATOR_EQUALITY_CHECKER\n",line_num); return OPERATOR_EQUALITY_CHECKER;}
"&=" {printf("%d: OPERATOR_AND_ASSIGNMENT\n",line_num); return OPERATOR_AND_ASSIGNMENT;}
"|=" {printf("%d: OPERATOR_OR_ASSIGNMENT\n",line_num); return OPERATOR_OR_ASSIGNMENT;}
"<=" {printf("%d: OPERATOR_LESS_OR_EQUAL\n",line_num); return OPERATOR_LESS_OR_EQUAL;}
">=" {printf("%d: OPERATOR_GREATER_OR_EQUAL\n",line_num); return OPERATOR_GREATER_OR_EQUAL;}
"!=" {printf("%d: OPERATOR_NOT_EQUAL\n",line_num); return OPERATOR_NOT_EQUAL;}
"->" {printf("%d: OPERATOR_LINK\n",line_num); return OPERATOR_LINK;}
"^=" {printf("%d: OPERATOR_BITWISE_XOR_ASSIGNMENT\n",line_num); return OPERATOR_BITWISE_XOR_ASSIGNMENT;}
">>" {printf("%d: OPERATOR_RIGHT_SHIFT\n",line_num); return OPERATOR_RIGHT_SHIFT;}
"<<" {printf("%d: OPERATOR_LEFT_SHIFT\n",line_num); return OPERATOR_LEFT_SHIFT;}
"%=" {printf("%d: OPERATOR_MOD_ASSIGNMENT\n",line_num); return OPERATOR_MOD_ASSIGNMENT;}
"<<=" {printf("%d: OPERATOR_LEFT_ASSIGNMENT\n",line_num); return OPERATOR_LEFT_ASSIGNMENT;}
"..." {printf("%d: THREE_DOTS\n",line_num); return THREE_DOTS;}
"?" {printf("%d: TERNARY\n",line_num); return TERNARY;}
"." {printf("%d: DOT\n",line_num); return DOT;}
"[" {printf("%d: SQUARE_BRACKET_BEG\n",line_num); return SQUARE_BRACKET_BEG;}
"]" {printf("%d: SQUARE_BRACKET_END\n",line_num); return SQUARE_BRACKET_END;}
"{" {printf("%d: CURLY_BRACKET_BEG\n",line_num); return CURLY_BRACKET_BEG;}
"}" {printf("%d: CURLY_BRACKET_END\n",line_num); return CURLY_BRACKET_END;}
"(" {printf("%d: PARANTHESIS_BEG\n",line_num); return PARANTHESIS_BEG;}
")" {printf("%d: PARANTHESIS_END\n",line_num); return PARANTHESIS_END;}
"," {printf("%d: COMMA\n",line_num); return COMMA;}
":" {printf("%d: COLON\n",line_num); return COLON;}
";" {printf("%d: SEMICOLON\n",line_num); return SEMICOLON;}
"#" {printf("%d: SHARP\n",line_num); return SHARP;}
\" {printf("%d: DOUBLE_QUOTES\n",line_num); return DOUBLE_QUOTES;}

{number} {printf("%d: NUMBER %s\n",line_num,yytext); strcpy(yylval.values.val,yytext); return NUMBER;}
{realnum} {printf("%d: REAL_NUMBER %s\n",line_num,yytext); strcpy(yylval.values.val,yytext); return REAL_NUMBER;}
{expno} {printf("%d: EXP_NUMBER %s\n",line_num,yytext); strcpy(yylval.values.val,yytext); return EXP_NUMBER;}
{charconst} {printf("%d: CHAR_CONSTANT %s\n",line_num,yytext); strcpy(yylval.values.val,yytext); return CHAR_CONSTANT;}
{strconst} {printf("%d: STRING_CONSTANT %s\n",line_num,yytext); strcpy(yylval.values.val,yytext); return STRING_CONSTANT;}

{var} {printf("%d: IDENTIFIER: %s\n",line_num,yytext);strcpy(yylval.values.name,yytext); return IDENTIFIER;}
" " {}

%%
int yywrap()
{
return -1;
}
