// AC
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 100006;

int n;

int x[MAXN], y[MAXN];
long long sumx[MAXN], sumy[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", x + i, y + i);
    }
    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        sumx[i] = sumx[i - 1] + x[i];
        sumy[i] = sumy[i - 1] + y[i];
    }

    int cx, cy, dx, dy;
    long long dis = 0;

    cx = x[n / 2];
    dx = upper_bound(x + 1, x + 1 + n, cx) - x - 2;
    dis += cx * (2 * dx - n) + sumx[n] - 2 * sumx[dx];

    cy = y[n / 2];
    dy = upper_bound(y + 1, y + 1 + n, cy) - y - 2;
    dis += cy * (2 * dy - n) + sumy[n] - 2 * sumy[dy];

    printf("%lld\n", dis);
    return 0;
}
