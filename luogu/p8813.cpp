/*
//----^^ACCEPTED^^----//
*/
#include<bits/stdc++.h>
using namespace std;

const int Limit = 1000000000;

int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    if(a>Limit)
    {
        printf("-1\n");
        return 0;
    }
    if(a==1)
    {
        printf("1\n");
        return 0;
    }
    long long ans=1;
    for(long long i=0;i<b;i++)
    {
        ans*=a;
        if(ans>Limit)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
