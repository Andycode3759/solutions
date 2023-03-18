// AC
// Dijkstra模板
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10004;
const int INF = (1 << 31) - 1;

struct Vertex
{
    Vertex(int _d, int _i)
    {
        index = _i, dis = _d;
    }
    int index, dis;
};
struct VertexCmp
{
    bool operator()(Vertex a, Vertex b)
    {
        return a.dis > b.dis;
    }
};
struct Edge
{
    Edge(int _d, int _w, int _n)
    {
        dest = _d;
        weight = _w;
        next = _n;
    }
    int dest, weight;
    int next; // 下一条边在edges里的编号
};

priority_queue<Vertex, vector<Vertex>, VertexCmp> vertexies;
vector<Edge> edges;
int firstEdge[MAXN];
long long dis[MAXN];
bool book[MAXN];

void addEdge(int from, int to, int weight)
{
    edges.push_back(Edge(to, weight, firstEdge[from]));
    firstEdge[from] = edges.size() - 1;
}
int main()
{
    memset(firstEdge, -1, sizeof(firstEdge));

    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }

    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    vertexies.push(Vertex(0, s));

    while (!vertexies.empty())
    {
        int x = vertexies.top().index;
        vertexies.pop();
        if (book[x])
            continue;
        book[x] = true;
        for (int i = firstEdge[x]; i != -1; i = edges[i].next)
        {
            Edge &e = edges[i];
            if (dis[e.dest] > dis[x] + e.weight)
            {
                dis[e.dest] = dis[x] + e.weight;
                vertexies.push(Vertex(dis[e.dest], e.dest));
            }
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%lld ", dis[i]);
    printf("\n");
    return 0;
}
