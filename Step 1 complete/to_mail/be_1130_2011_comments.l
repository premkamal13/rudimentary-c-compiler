%{
FILE *fptr;
int vary=0,varx=0;
%}
single ("//")
doublest ("/*")
doubleend ("*/")
%%
{single} {if(!varx) vary=1;}
\n {if((!vary) &&(!varx)) { fprintf(fptr,"\n"); } vary=0; }
{doubleend} {if(!varx) fprintf(fptr,"*/"); varx=0;}
{doublest} {if(!vary) varx=1;}
. { if((!vary)&&(!varx)) fprintf(fptr,"%s",yytext);}
%%
int yywrap()
{
return -1;
}
int main(int argc, char *argv[])
{
if(argc<3) 
{
printf("Error\n");
return -1;
}
yyin=fopen(argv[1],"r");
fptr=fopen(argv[2],"w");
yylex();
fclose(yyin);
fclose(fptr);
return 0;
}