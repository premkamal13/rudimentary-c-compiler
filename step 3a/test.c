#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int i,varcnt=0;
char varname[1001],vartmp1[101];
void new_var()
{
        //namings like foo_00_1.
        varname[0]='f';
        varname[1]='o';
        varname[2]='o';
        varname[3]='_';
        varname[4]='0';
        varname[5]='0';
        varname[6]='_';
        sprintf(vartmp1,"%d",varcnt);
        int x=strlen(vartmp1);
        for(i=0;i<x;i++) varname[7+i]=vartmp1[i];
        varname[7+i]='\0';
        printf("%s\n",varname);
        varcnt++;
}


int main()
{
    int j;
    for(j=0;j<20;j++) new_var();
}
