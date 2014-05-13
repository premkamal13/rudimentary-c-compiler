%{
FILE *fptr;
int er1=0,er2=0;
%}
single ("//")
doublest ("/*")
doubleend ("*/")
singledouble ("/*/")
%%
{single} {if(!er2) er1=1;}
\n {if((!er1) &&(!er2)) { fprintf(fptr,"\n"); } er1=0; }
{singledouble} {if(!er2) {er2=1;} else {er2=0;} }
{doubleend} {if(!er2) fprintf(fptr,"*/"); er2=0;}
{doublest} {if(!er1) er2=1;}
. { if((!er1)&&(!er2)) fprintf(fptr,"%s",yytext);}
%%
int yywrap()
{
return -1;
}
int main(int argc, char *argv[])
{
if(argc<3) 
{
printf("The input format is: <.exe> <inp> <out>");
return -1;
}
yyin=fopen(argv[1],"r");
fptr=fopen(argv[2],"w");
yylex();
fclose(yyin);
fclose(fptr);
return 0;
}