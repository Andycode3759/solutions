// AC
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000006;

struct Fenwick
{
    Fenwick() {}
    Fenwick(int _s) { init(_s); }

    long long data[MAXN];
    int size;

    void init(int _size)
    {
        size = _size;
        memset(data, 0, sizeof(data));
    }
    void add(int pos, long long dlt)
    {
        while (pos <= size)
        {
            data[pos] += dlt;
            pos += (pos & (-pos));
        }
    }
    long long getSum(int pos)
    {
        long long res = 0;
        while (pos > 0)
        {
            res += data[pos];
            pos -= (pos & (-pos));
        }
        return res;
    }
};

int n, q;
long long arr[MAXN];
Fenwick fwDlt, fwDltIdx;

int main()
{
    scanf("%d%d", &n, &q);
    fwDlt.init(n), fwDltIdx.init(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
        fwDlt.add(i, arr[i] - arr[i - 1]);
        fwDltIdx.add(i, (i - 1) * (arr[i] - arr[i - 1]));
    }
    while (q--)
    {
        int op, l, r;
        long long x;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%lld", &l, &r, &x);
            fwDlt.add(l, x), fwDlt.add(r + 1, -x);
            fwDltIdx.add(l, x * (l - 1)), fwDltIdx.add(r + 1, (-x) * r);
        }
        else if (op == 2)
        {
            // for (int i = 1; i <= n; i++)
            // {
            //     printf("%lld ", fwDlt.getSum(i));
            // }
            // printf("\n");

            scanf("%d%d", &l, &r);
            long long sumR = r * fwDlt.getSum(r) - fwDltIdx.getSum(r);
            long long sumL = (l - 1) * fwDlt.getSum(l - 1) - fwDltIdx.getSum(l - 1);
            printf("%lld\n", sumR - sumL);
        }
    }
    return 0;
}