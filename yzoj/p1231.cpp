// AC
#include <cstdio>
using namespace std;
const int MAXN = 102;
const int MAXV = 1000006;

constexpr const int max(const int &a, const int &b)
{
    return a < b ? b : a;
}

struct Item
{
    int weight, val;
};
Item itNew[MAXV];
int itCnt = 0;

int v, n;
int weight[MAXN], val[MAXN], cnt[MAXN];
int ans[MAXV];

int main()
{
    scanf("%d%d", &v, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", weight + i, val + i, cnt + i);

    for (int i = 1; i <= n; i++)
    {
        int v = val[i], c = cnt[i], w = weight[i];
        Item t;
        for (int j = 0; c > (1 << j); j++)
        {
            c -= (1 << j);
            t.weight = w * (1 << j);
            t.val = v * (1 << j);
            itNew[++itCnt] = t;
        }
        if (c > 0)
        {
            t.weight = w * c;
            t.val = v * c;
            itNew[++itCnt] = t;
        }
    }

    for (int i = 1; i <= itCnt; i++)
    {
        Item &t = itNew[i];
        for (int j = v; j >= t.weight; j--)
        {
            ans[j] = max(ans[j], ans[j - t.weight] + t.val);
        }
    }

    printf("%d\n", ans[v]);
    return 0;
}
