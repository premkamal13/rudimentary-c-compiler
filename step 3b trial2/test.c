#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char tempstr[1001];

char tempdim[101][101],cur_var[101];
int d1,arr_sz,varcnt=0,arr_sz;
char symtab_dim[101],vartmp1[1001];
char varname[51];
void new_var()
{
    int i;
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
    //printf("%s\n",varname);
    varcnt++;
}

int nonnum[101];
char symtabdim_list[101][101];
int calc_value(int dtt)
{
    if(dtt==1 || dtt==1000) return 1;
    else if(dtt==4) return 4;
    else if(dtt==16) return 4;
    else if(dtt==64) return 8;
    else if(dtt==4000) return 8;
    else if(dtt==8000) return 16;
    return 16;
}


void gen_imm_code()
{
    int d2=0,d3=0;
    char imm_var1[101],imm_var2[101];
    new_var();
    printf("%s = 0\n",varname);
    strcpy(imm_var1,varname);
    while(d3<d1)
    {
        printf("in loopwa\n");
        new_var();
        printf("%s = %s\n",varname,tempdim[d3]);
        strcpy(imm_var2,varname);
        if(d2+1<d1)
        {
            int d4=d2+1;
            while(d4<d1)
            {
                printf("%s = %s * %s\n",varname,varname,symtabdim_list[d4]);
                d4++;
            }
        }
        printf("%s = %s + %s\n",imm_var1,imm_var1,imm_var2);
        d3++;
        d2++;
    }
    printf("le beta, bahare nai aaya\n");
    printf("%s = %s * %d\n",imm_var1,imm_var1,calc_value(4));
    strcpy(cur_var,imm_var1);
}

void check_valid_dim()
{
    int i,j;
    if(arr_sz!=d1) {printf("yyerror(1)\n"); return -1;}
    else
    {
        int tk=0,k1=0;
        for(i=0;i<d1;i++)
        {
            nonnum[i]=0;
            int x=strlen(tempdim[i]);
            for(j=0;j<x;j++)
            {
                if(tempdim[i][j]<'0' || tempdim[i][j]>'9') nonnum[i]=1;
            }
            k1=0;
            while(symtab_dim[tk]!=' ') {tempstr[k1++]= symtab_dim[tk]; tk++;}
            tempstr[k1]='\0';
            tk++;
            strcpy(symtabdim_list[i],tempstr);
            if(nonnum[i]==0)
            {
                int dim1= atoi(tempstr);
                int dim2= atoi(tempdim[i]);
                if(dim1<dim2) {printf("%d %d yyerror(%d)\n",dim1,dim2,i); return -1;}
            }
        }
        gen_imm_code();
    }
}

int main()
{
    int i;
    scanf("%d %d\n",&arr_sz,&d1);
    gets(symtab_dim);
    for(i=0;i<d1;i++) scanf("%s",tempdim[i]);
    new_var();
    strcpy(cur_var,varname);
    check_valid_dim();
    return 0;
}
