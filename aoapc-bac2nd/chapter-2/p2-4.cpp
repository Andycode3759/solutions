#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    int kase = 1;
    while (scanf("%lld%lld", &n, &m) == 2)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        double result = 0;
        for (; n <= m; n++)
        {
            result += 1.0 / (n*n);
        }
        printf("Case %d: %.5f\n", kase, result);
        kase++;
    }
    return 0;
}
