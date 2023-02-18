// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXC = 1005;
const int MAXN = 103;
int maxValue[MAXN][MAXC]; // 将前i种物品放入容量为j的背包的最大价值

struct Item
{
    Item(int w = 0, int v = 0)
    {
        weight = w, value = v;
    }
    int weight, value;
} items[MAXN];

int main()
{
    int cap, n;
    scanf("%d%d", &cap, &n);
    for (int i = 1; i <= n; i++)
    {
        int w, v;
        scanf("%d%d", &w, &v);
        items[i] = Item(w, v);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            maxValue[i][j] = (i == 1 ? 0 : maxValue[i - 1][j]);
            if (j >= items[i].weight)
                maxValue[i][j] = max(maxValue[i][j], maxValue[i - 1][j - items[i].weight] + items[i].value);
        }
    }

    printf("%d\n", maxValue[n][cap]);

    return 0;
}
