#include <queue>
#include <cstdio>
using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>> Q;

int main()
{
    scanf("%d",&n);
    long long ans=0;
    for(int i=1;i<=n;i++) 
    {
        int p;
        scanf("%d",&p);
        if(!Q.empty() && Q.top()<p) ans+=p-Q.top(), Q.pop(), Q.push(p);
        Q.push(p);
    }

    printf("%lld\n",ans);
    return 0;
}
