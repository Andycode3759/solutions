/*
//----!!BAD SOLUTION!!----//
    Reason:
        WA 5 cases, TLE 12 cases
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    long long n,e,d;
    long long p,q;
    bool success;
    scanf("%d",&k);
    for(int kase=0;kase<k;kase++)
    {
        scanf("%lld%lld%lld",&n,&d,&e);
        long long halfn = n/2;
        success=false;
        for(p=1;p<=halfn;p++)
        {
            q=n/p;
            if(p*q==n && (p-1)*(q-1)+1==e*d)
            {
                printf("%lld %lld\n",p,q);
                success=true;
                break;
            }
        }
        if(!success)
        {
            printf("NO\n");
        }
    }
    return 0;
}
