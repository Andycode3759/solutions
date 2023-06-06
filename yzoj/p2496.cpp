#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 3000006;
const int MAXN_LOG = 23;

int n;
int arrA[MAXN], arrB[MAXN];
int stA[MAXN_LOG][MAXN];
int sumB[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arrA + i);
        stA[0][i] = arrA[i];
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arrB + i);
        sumB[i] = arrB[i] + sumB[i - 1];
    }

    for (int lg = 1; lg < MAXN_LOG; lg++)
    {
        if ((1 << (lg - 1)) > n)
            break;
        for (int i = n; i >= 1; i--)
        {
            if (i - (1 << (lg - 1)) <= 0)
                break;
            stA[lg][i] = min(stA[lg - 1][i - (1 << (lg - 1))], stA[lg - 1][i]);
        }
    }

    return 0;
}
