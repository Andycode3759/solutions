#include <cstdio>
#include <utility>
using namespace std;
const int MAXN = 100005;

struct Node
{
    int id;
    int ls,rs;
    int val;
    int dist;
    const bool operator<(const Node &b) const
    {
        return val==b.val?id<b.id:val<b.val;
    }
};
Node pool[MAXN];

int bel[MAXN];
bool del[MAXN];

int find(int x)
{
    return bel[x]==x? x: bel[x]=find(bel[x]);
}

int merge(int x, int y)
{
    if(x==0 || y==0) return x|y;
    if(pool[y]<pool[x]) swap(x,y);
    Node &nx=pool[x],&ny=pool[y];
    nx.rs=merge(nx.rs,y);
    if(pool[nx.rs].dist>pool[nx.ls].dist) swap(nx.ls,nx.rs);
    nx.dist=pool[nx.rs].dist+1;
    return x;
}

int n,m;

int main()
{
    pool[0].dist=-1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        pool[i].val=t;
        pool[i].id=i;
        bel[i]=i;
    }
    while(m--)
    {
        int op;
        int x,y;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d %d",&x,&y);
            if(del[x]||del[y]) continue;
            x=find(x), y=find(y);
            if(x!=y) bel[x]=bel[y]=merge(x,y);
        }
        else if(op==2)
        {
            scanf("%d",&x);
            if(del[x])
            {
                printf("-1\n");
                continue;
            }
            x=find(x);
            printf("%d\n",pool[x].val);
            del[x]=true;
            bel[pool[x].ls]=bel[pool[x].rs]=bel[x]=merge(pool[x].ls,pool[x].rs);
            pool[x].ls=pool[x].rs=0;
            pool[x].dist=0;
        }
    }
    return 0;
}
