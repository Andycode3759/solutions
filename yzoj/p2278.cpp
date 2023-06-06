// AC
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000006;

struct Fenwick
{
    Fenwick() {}
    Fenwick(int _s)
    {
        init(_s);
    }

    long long data[MAXN];
    int size;

    void init(int _size)
    {
        size = _size;
        memset(data, 0, sizeof(long long) * (size + 4));
    }
    void add(int pos, int dlt)
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
int arr[MAXN];
Fenwick fwDlt;

int main()
{
    scanf("%d%d", &n, &q);
    fwDlt.init(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        fwDlt.add(i, arr[i] - arr[i - 1]);
    }
    while (q--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            fwDlt.add(l, x), fwDlt.add(r + 1, -x);
        }
        else if (op == 2)
        {
            int p;
            scanf("%d", &p);
            printf("%lld\n", fwDlt.getSum(p));
        }
    }
    return 0;
}