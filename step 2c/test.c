int i,varcnt=0;
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
        vartmp1=itoa(varcnt);
        int x=strlen(vartmp1);
        for(i=0;i<x;i++) varname[7+i]=vartmp1[i];
    }
