%{
#include <string.h>
int num=1;
%}
alpha [A-Za-z_]
digit [0-9]
number {digit}+
any [^a-zA-Z_0-9]
escapeseq [abfnrtv\'"0]|(nnn)|(xhh)|(uhhhh)
%option noyywrap

%%

auto {printf("%d ",num);printf("AUTO\n");return AUTO;}
break {printf("%d ",num);printf("BREAK\n");return BREAK;}
case {printf("%d ",num);printf("CASE\n");return CASE;}
char {printf("%d ",num);printf("CHAR\n");return CHAR;}
const {printf("%d ",num);printf("CONST\n");return CONST;}
continue {printf("%d ",num);printf("CONTINUE\n");return CONTINUE;}
default {printf("%d ",num);printf("DEFAULT\n");return DEFAULT;}
do {printf("%d ",num);printf("DO\n");return DO;}
double {printf("%d ",num);printf("DOUBLE\n");return DOUBLE;}
else {printf("%d ",num);printf("ELSE\n");return ELSE;}
enum {printf("%d ",num);printf("ENUM\n");return ENUM;}
extern {printf("%d ",num);printf("EXTERN\n");return EXTERN;}
float {printf("%d ",num);printf("FLOAT\n");return FLOAT;}
for {printf("%d ",num);printf("FOR\n");return FOR;}
goto {printf("%d ",num);printf("GOTO\n");return GOTO;}
if {printf("%d ",num);printf("IF\n");return IF;}
int {printf("%d ",num);printf("INT\n");return INT;}
long {printf("%d ",num);printf("LONG\n");return LONG;}
register {printf("%d ",num);printf("REGISTER\n");return REGISTER;}
return {printf("%d ",num);printf("RETURN\n");return RETURN;}
short {printf("%d ",num);printf("SHORT\n");return SHORT;}
sizeof {printf("%d ",num);printf("SIZEOF\n");return SIZEOF;}
static {printf("%d ",num);printf("STATIC\n");return STATIC;}
struct {printf("%d ",num);printf("STRUCT\n");return STRUCT;}
switch {printf("%d ",num);printf("SWITCH\n");return SWITCH;}
typedef {printf("%d ",num);printf("TYPEDEF\n");return TYPEDEF;}
union {printf("%d ",num);printf("UNION\n");return UNION;}
signed {printf("%d ",num);printf("SIGNED\n");return SIGNED;}
unsigned {printf("%d ",num);printf("UNSIGNED\n");return UNSIGNED;}
void {printf("%d ",num);printf("VOID\n");return VOID;}
volatile {printf("%d ",num);printf("VOLATILE\n");return VOLATILE;}
while {printf("%d ",num);printf("WHILE\n");return WHILE;}


\[ {printf("%d ",num);printf("OPEN_SQ_BRACKET\n");return OPEN_SQ_BRACKET;}
\] {printf("%d ",num);printf("CLOSING_SQ_BRACKET\n");return CLOSE_SQ_BRACKET;}
\( {printf("%d ",num);printf("OPEN_PARANTHESES\n");return OPEN_PARANTHESES;}
\) {printf("%d ",num);printf("CLOSE_PARANTHESES\n");return CLOSE_PARANTHESES;}
\{ {printf("%d ",num);printf("OPEN_BRACES\n");return OPEN_BRACES;}
\} {printf("%d ",num);printf("CLOSE_BRACES\n");return CLOSE_BRACES;}
\, {printf("%d ",num);printf("COMMA\n");return COMMA;}
\: {printf("%d ",num);printf("COLON\n");return COLON;}
\= {printf("%d ",num);printf("EQUALS\n");return EQUALS;}
\; {printf("%d ",num);printf("SEMI_COLON\n");return SEMI_COLON;}
\# {printf("%d ",num);printf("HASH\n");return HASH;}
\" {printf("%d ",num);printf("DOUBLE_QUOTES\n");return DOUBLE_QUOTES;}
\. {printf("%d ",num);printf("DOT\n");return DOT;}

\! {printf("%d ",num);printf("NOT\n");return NOT;}
\~ {printf("%d ",num);printf("NEGATION\n");return NEGATION;}
\+ {printf("%d ",num);printf("PLUS\n");return PLUS;}
\- {printf("%d ",num);printf("MINUS\n");return MINUS;}
\+\+ {printf("%d ",num);printf("INCREMENT\n");return INCREMENT;}
\-\- {printf("%d ",num);printf("DECREMENT\n");return DECREMENT;}
\* {printf("%d ",num);printf("MULTIPLY\n");return MULTIPLY;}
\& {printf("%d ",num);printf("AND_BIT\n");return AND_BIT;}
\/ {printf("%d ",num);printf("DIVIDE\n");return DIVIDE;}
\% {printf("%d ",num);printf("MODULUS\n");return MODULUS;}
\>\> {printf("%d ",num);printf("R_SHIFT\n");return R_SHIFT;}
\<\< {printf("%d ",num);printf("L_SHIFT\n");return L_SHIFT;}
\< {printf("%d ",num);printf("LESS_THAN\n");return LESS_THAN;}
\<\= {printf("%d ",num);printf("LESS_EQUAL\n");return LESS_EQUAL;}
\> {printf("%d ",num);printf("GREATER_THAN\n");return GREATER_THAN;}
\>\= {printf("%d ",num);printf("GREATER_EQUAL\n");return GREATER_EQUAL;}
\=\= {printf("%d ",num);printf("IS_EQUAL_TO\n");return IS_EQUAL_TO;}
\!\= {printf("%d ",num);printf("NOT_EQUAL\n");return NOT_EQUAL;}
\^ {printf("%d ",num);printf("XOR\n");return XOR;}
\| {printf("%d ",num);printf("OR_BIT\n");return OR_BIT;}
\&\& {printf("%d ",num);printf("AND\n");return AND;}
\|\| {printf("%d ",num);printf("OR\n");return OR;}
\? {printf("%d ",num);printf("TERNARY\n");return TERNARY;}
\+\= {printf("%d ",num);printf("ADD_SHORT\n");return ADD_SHORT;}
\-\= {printf("%d ",num);printf("SUB_SHORT\n");return SUB_SHORT;}
\*\= {printf("%d ",num);printf("MUL_SHORT\n");return MUL_SHORT;}
\/\= {printf("%d ",num);printf("DIV_SHORT\n");return DIV_SHORT;}
\%\= {printf("%d ",num);printf("MOD_SHORT\n");return MOD_SHORT;}
\&\= {printf("%d ",num);printf("AND_SHORT\n");return AND_SHORT;}
\^\= {printf("%d ",num);printf("XOR_SHORT\n");return XOR_SHORT;}
\|\= {printf("%d ",num);printf("OR_SHORT\n");return OR_SHORT;}
\<\<\= {printf("%d ",num);printf("LSHIFT_SHORT\n");return LSHIFT_SHORT;}
\>\>\= {printf("%d ",num);printf("RSHIFT_SHORT\n");return RSHIFT_SHORT;}
\-\> {printf("%d ",num);printf("LINK\n");return LINK;}
\.\.\. {printf("%d ",num);printf("THREE_DOT\n");return THREE_DOT;}

{alpha}({alpha}|{digit})* {printf("%d: IDENTIFIER: %s\n",num,yytext);strcpy(yylval.entry.symbol_specification,yytext);return IDENTIFIER;}

{number} {printf("%d: NUMBER: ",num);ECHO;printf("\n");strcpy(yylval.entry.value,yytext);return NUMBER;}
{number}(\.{number})? {printf("%d: REAL_NUMBER: ",num);ECHO;strcpy(yylval.entry.value,yytext);printf("\n");return REAL_NUMBER;}
{number}(\.{number})?[Ee][+-]?{number}(\.{number})? {printf("%d: EXP_NUMBER: ",num);ECHO;strcpy(yylval.entry.value,yytext);printf("\n");return EXP_NUMBER;}
\'([^']|(\\{escapeseq}))\' {printf("%d: CHAR_CONSTANT: ",num);ECHO;printf("\n");strcpy(yylval.entry.value,yytext);return CHAR_CONSTANT;}
\"([^"]|(\\\"))*\" {printf("%d: STRING_CONSTANT: ",num);ECHO;printf("\n");strcpy(yylval.entry.value,yytext);return STRING_CONSTANT;}

\t {}
" " {}
. {printf("%d: ERROR\n",num);}
\n {num++;}

%%
