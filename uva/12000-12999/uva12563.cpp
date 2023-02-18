// WA
#include <bits/stdc++.h>
using namespace std;
const int MAXT = 10086;
const int MAXN = 52;
const int JGJQ = 678;
int maxCount[MAXN][MAXT]; // 将前i种物品放入容量为j的背包的最大价值
int songs[MAXN];

int main()
{

    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++)
    {
        memset(maxCount, 0, sizeof(maxCount));
        memset(songs, 0, sizeof(songs));

        int n, t;
        scanf("%d%d", &n, &t);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", songs + i);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= t - 1; j++)
            {
                maxCount[i][j] = (i == 1 ? 0 : maxCount[i - 1][j]);
                if (j >= songs[i])
                    maxCount[i][j] = max(maxCount[i][j], maxCount[i - 1][j - songs[i]] + 1);
            }
        }

        int ansCount = -1;
        int ansLength = t - 1;
        for (int i = 1; i <= t - 1; i++)
        {
            if (maxCount[n][i] > ansCount)
            {
                ansCount = maxCount[n][i];
                ansLength = i;
            }
        }

        printf("Case %d: %d %d\n", kase, ansCount + 1, ansLength + JGJQ);
    }

    return 0;
}
