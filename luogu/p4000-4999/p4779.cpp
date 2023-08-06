//dijkstra
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 100005;
const int MAXM = 200005;
const int INF = (1<<30)-1;

struct Edge
{
    Edge(int _d=0,int _n=0,int _v=0):dest(_d),next(_n),val(_v){}
    int dest,next,val;
};
Edge edges[MAXM];
int head[MAXN],tot=0;
void addEdge(int src,int dest,int val)
{
    edges[++tot]=Edge(dest,head[src],val);
    head[src]=tot;
}

int n,m,s;

struct Node
{
    Node(int _d,int _u):dis(_d),u(_u){}
    int dis,u;
    const bool operator<(const Node &b) const
    {
        return dis>b.dis;
    }
};
priority_queue<Node> Q;
bool vis[MAXN];
int dis[MAXN];

int main()
{
    scanf("%d %d %d",&n,&m,&s);
    for(int i=1;i<=m;i++)
    {
        int a,b,v;
        scanf("%d %d %d",&a,&b,&v);
        addEdge(a,b,v);
    }

    for(int i=1;i<=n;i++) dis[i]=INF;
    dis[s]=0;
    Q.push(Node(0,s));
    while(!Q.empty())
    {
        int u=Q.top().u; Q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i!=0;i=edges[i].next)
        {
            Edge &e=edges[i];
            if(dis[u]+e.val < dis[e.dest])
            {
                dis[e.dest]=dis[u]+e.val;
                Q.push(Node(dis[e.dest],e.dest));
            }
        }
    }

    for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    printf("\n");
    return 0;
}
