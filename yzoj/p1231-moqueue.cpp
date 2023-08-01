#include <cstdio>
using namespace std;
const int MAXN = 102;
const int MAXV = 1000006;

constexpr const int max(const int &a, const int &b)
{
    return a < b ? b : a;
}
constexpr const int min(const int &a, const int &b)
{
    return a > b ? b : a;
}

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
        for (int j = v; j >= weight[i] * cnt[i]; j--)
        {
            for (int k = min(cnt[i], j / weight[i]); k >= 0; k--)
            {
                ans[j] = max(ans[j], ans[j - k * weight[i]] + k * val[i]);
            }
        }
    }

    printf("%d\n", ans[v]);
    return 0;
}
