#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10000007;

inline long long eulerPhi(long long x)
{
    long long ans = x;
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            ans = ans / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        ans = ans / x * (x - 1);
    return ans;
}

int n;
bool notPrime[MAXN];

int main()
{
    scanf("%d", &n);
    long long ans = 0;

    notPrime[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (notPrime[i])
            continue;
        for (int j = 2; j * i <= n; j++)
            notPrime[j * i] = true;

        for (int j = 1; j <= n / i; j++)
        {
            for (int k = 1; k <= n / i; k++)
            {
                if (__gcd(j, k) == 1)
                    ans++;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}