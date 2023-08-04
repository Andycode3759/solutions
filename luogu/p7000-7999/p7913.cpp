#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 100005;

struct Node
{
    int l,r;
    const bool operator<(const Node &b) const
    {
        return l==b.l? r<b.r: l<b.l;
    }
};
struct Plane
{
    Plane(int _l,int _p):lvTime(_l),pos(_p){}
    int lvTime,pos;
    const bool operator<(const Plane &b) const
    {
        return lvTime==b.lvTime? pos>b.pos: lvTime>b.lvTime;
    }
};

int n,m1,m2;
Node nation[MAXN],glob[MAXN];
int bel1[MAXN],bel2[MAXN];

priority_queue<int,vector<int>,greater<int>> wq;
priority_queue<Plane> iq;

int main()
{
    scanf("%d %d %d",&n,&m1,&m2);
    for(int i=1;i<=m1;i++)
    {
        scanf("%d %d",&nation[i].l,&nation[i].r);
    }
    for(int i=1;i<=m2;i++)
    {
        scanf("%d %d",&glob[i].l,&glob[i].r);
    }

    sort(nation+1,nation+1+m1);
    sort(glob+1,glob+1+m2);

    for(int i=1;i<=n;i++) wq.push(i);
    for(int i=1;i<=m1;i++)
    {
        Node &cur=nation[i];
        while(!iq.empty() && cur.l>=iq.top().lvTime)
        {
            wq.push(iq.top().pos);
            iq.pop();
        }
        if(wq.empty()) continue;
        int dest=wq.top(); wq.pop();
        bel1[dest]++;
        iq.push(Plane(cur.r,dest));
    }
    
    priority_queue<int,vector<int>,greater<int>>().swap(wq);
    priority_queue<Plane>().swap(iq);

    for(int i=1;i<=n;i++) wq.push(i);
    for(int i=1;i<=m2;i++)
    {
        Node &cur=glob[i];
        while(!iq.empty() && cur.l>=iq.top().lvTime)
        {
            wq.push(iq.top().pos);
            iq.pop();
        }
        if(wq.empty()) continue;
        int dest=wq.top(); wq.pop();
        bel2[dest]++;
        iq.push(Plane(cur.r,dest));
    }

    for(int i=1;i<=n;i++) bel1[i]+=bel1[i-1],bel2[i]+=bel2[i-1];

    int ans=0;
    for(int a1=0;a1<=n;a1++)
    {
        int a2=n-a1;
        ans=max(ans,bel1[a1]+bel2[a2]);
    }
    printf("%d\n",ans);
    return 0;
}
