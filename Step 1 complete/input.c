#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int hash[11];

int main()
{
    int a;
    double b;
    a=a+b;
    a+=b;
    int n,k,i,err,x;
    char y='a',inta, int_;
    char str[]="sasasa sasa";
    double x1 = 12.3, y=12.34e+56.78;
    char s='/'; char s1="asasa\n"sasa;
    int $a*bc*d;
    int a=" kamal ";
    int sasa1313=1232;
    sasa1313-=10;
    auto name, autoa;
    scanf("%d%d",&n,&k);
    int cnt=0;
    while(n--)
    {
        scanf("%d",&x);
        int err=0;
        for(i=0;i<10;i++) hash[i]=0;
        while(x)
        {
            int y=x%10;
            hash[y]=1;
            x/=10;
        }
        for(i=0;i<=k;i++) if(!hash[i]) err=1;
        if(!err) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
