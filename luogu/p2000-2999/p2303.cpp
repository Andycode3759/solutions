#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
vector<long long> p;

long long eulerPhi(long long x)
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

int main()
{
    scanf("%lld", &n);
    long long ans = 0;

    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            p.push_back(i);
            if (i != n / i)
                p.push_back(n / i);
        }
    }
    for (int i = 0, len = p.size(); i < len; i++)
    {
        long long d = p[i];
        ans += d * eulerPhi(n / d);
    }

    printf("%lld\n", ans);
    return 0;
}