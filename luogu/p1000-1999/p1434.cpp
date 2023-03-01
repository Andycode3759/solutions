// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXL = 103;
const int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int areaMap[MAXL][MAXL];
int maxLength[MAXL][MAXL];
int r, c;

int getMaxLengthAt(int x, int y)
{
    int &ans = maxLength[x][y];
    if (ans >= 0)
        return ans;

    ans = 1;
    for (int d = 0; d < 4; d++)
    {
        int nx = x + DIR[d][0], ny = y + DIR[d][1];
        if (nx > 0 && ny > 0 && nx <= r && ny <= c && areaMap[nx][ny] < areaMap[x][y])
            ans = max(ans, getMaxLengthAt(nx, ny) + 1);
    }
    return ans;
}

int main()
{
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            scanf("%d", &areaMap[i][j]);
        }
    }
    memset(maxLength, -1, sizeof(maxLength));
    int ans = -1;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            ans = max(ans, getMaxLengthAt(i, j));
        }
    }
    printf("%d\n", ans);
    return 0;
}
