// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXR = 1002;
int triangle[MAXR][MAXR];
int maxSum[MAXR][MAXR];
int r;

int getMaxSum(int x, int y)
{
    if (maxSum[x][y] >= 0)
        return maxSum[x][y];

    if (x == r)
        return maxSum[x][y] = triangle[x][y];

    return maxSum[x][y] = max(getMaxSum(x + 1, y), getMaxSum(x + 1, y + 1)) + triangle[x][y];
}

int main()
{
    scanf("%d", &r);
    for (int x = 1; x <= r; x++)
    {
        for (int y = 1; y <= x; y++)
        {
            scanf("%d", &triangle[x][y]);
        }
    }
    memset(maxSum, -1, sizeof(maxSum));
    printf("%d\n", getMaxSum(1, 1));
    return 0;
}
