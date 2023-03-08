// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

struct Point
{
    double x, y;
};
Point points[MAXN];

struct Edge
{
    int from, to;
    double cost;
    Edge(int _f = 0, int _t = 0, double _c = 0)
    {
        from = _f;
        to = _t;
        cost = _c;
    }
};
struct EdgeCmp
{
    bool operator()(Edge a, Edge b)
    {
        return a.cost < b.cost;
    }
};
struct UnionFindSet
{
    int fatherOf[MAXN];
    int size;

    UnionFindSet(int _s)
    {
        size = _s;
        for (int i = 0; i <= size; i++)
        {
            fatherOf[i] = i;
        }
    }

    void merge(int father, int son)
    {
        fatherOf[getFather(son)] = father;
    }
    int getFather(int son)
    {
        if (fatherOf[son] == son)
            return son;
        return fatherOf[son] = getFather(fatherOf[son]);
    }
};

vector<Edge> edges;

bool alreadyConnected[MAXN][MAXN];

double distance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool isInSmt[MAXN];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    UnionFindSet ufs(n);
    Point p;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &p.x, &p.y);
        points[i] = p;
    }
    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        isInSmt[u] = isInSmt[v] = true;
        ufs.merge(u, v);
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (ufs.getFather(x) == ufs.getFather(y))
                continue;
            edges.push_back(Edge(x, y, distance(points[x], points[y])));
        }
    }
    sort(edges.begin(), edges.end(), EdgeCmp());
    double ans = 0;

    return 0;
}
