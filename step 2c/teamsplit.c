
// User: lovelotus(Prem Kamal)

//#include<bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define pii pair<int,int>
#define pip pair<int,pii>
#define F first
#define S second
*/
#define lli unsigned long long int
//using namespace std;
lli mod=1e6;

inline void fastread(int *a)
{
 register char c=0;
 while (c<33)
 {
     //c=getchar();
     c=getchar_unlocked();
 }
 *a=0;
 while (c>33)
 {
     *a=*a*10+c-'0';
     c=getchar_unlocked();
     //c=getchar();
 }
}

int pr[1000001];

int main()
{
    int t,n,i;
    int a,b,c,d;
    lli s1,s2;
    fastread(&t);
    while(t--)
    {
        fastread(&n);
        fastread(&a);
        fastread(&b);
        fastread(&c);
        fastread(&d);
        lli dif=0,s=d;
        pr[d]++;
        for(i=1;i<n;i++)
        {
            s=(a*s*s+b*s+c)%mod;
            /*if(s1>=mod) s1%=mod;
            s2=(b*s+c);
            if(s2>=mod) s2%=mod;
            s=s1+s2;
            if(s>=mod) s%=mod;
            //printf("s= %lld\n",s);
            */
            int x=(int)s;
            pr[x]++;
        }
        int f=1;
        for(i=0;i<1e6;i++)
        {
            if(pr[i]&1)
            {
                if(f) dif+=i;
                else dif-=i;
                f=1-f;
                pr[i]=0;
            }
        }
        //printf("%lld %lld\n",t1,t2);
        if(dif<0) dif*=-1;
        printf("%llu\n",dif);
    }
    return 0;
}
