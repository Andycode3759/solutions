// AC
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000006;

struct Fenwick
{
    Fenwick() {}
    Fenwick(int _s) { init(_s); }

    long long *data;
    int size;

    void init(int _size)
    {
        size = _size;
        data = new long long[size + 4];
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
    void free()
    {
        delete data;
    }
};

int n, q;
Fenwick fw;

int main()
{
    scanf("%d%d", &n, &q);
    fw.init(n);
    int input;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &input);
        fw.add(i, input);
    }
    while (q--)
    {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 1)
        {
            fw.add(a, b);
        }
        else if (op == 2)
        {
            printf("%lld\n", fw.getSum(b) - fw.getSum(a - 1));
        }
    }
    fw.free();
    return 0;
}