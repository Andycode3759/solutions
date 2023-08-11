#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 100005;

struct Edge
{
    Edge(int _d, int _v) : dest(_d), val(_v) {}
    int dest, val;
};
vector<Edge> child[MAXN];

int n;
int path[MAXN];

void dfs(int fa, int cur)
{
    for (int i = 0, len = child[cur].size(); i < len; i++)
    {
        Edge &e = child[cur][i];
        if (e.dest == fa)
            continue;
        path[e.dest] = path[cur] ^ e.val;
        dfs(cur, e.dest);
    }
}

int trie[2][MAXN * 31], cnt;
void insert(int x)
{
    int p = 0;
    for (int i = 0; i < 31; i++)
    {
        int c = (x & 1);
        x = (x >> 1);
        if (trie[c][p] == 0)
            trie[c][p] = ++cnt;
        p = trie[c][p];
    }
}
int find(int x)
{
    int res = 0;
    int p = 0;
    for (int i = 0; i < 31; i++)
    {
        int c = (x & 1);
        x = (x >> 1);
        if (trie[c ^ 1][p] != 0)
        {
            res += (1 << i);
            p = trie[c ^ 1][p];
        }
        else
            p = trie[c][p];
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        child[u].push_back(Edge(v, w));
        child[v].push_back(Edge(u, w));
    }
    dfs(0, 1);
    for (int i = 1; i <= n; i++)
    {
        insert(path[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, find(path[i]));
    }
    printf("%d\n", ans);
    return 0;
}