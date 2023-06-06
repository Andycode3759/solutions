#include <cstdio>
using namespace std;
const int MAXN = 500005;

int tb[MAXN], nums[MAXN];
int n, m;

int lowbit(int x)
{
    return x & (-x);
}

void add(int pos, int dlt)
{
    while (pos <= n)
    {
        tb[pos] += dlt;
        pos += lowbit(pos);
    }
}

int getSum(int pos)
{
    int res = 0;
    while (pos > 0)
    {
        res += tb[pos];
        pos -= lowbit(pos);
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", nums + i);
        add(i, nums[i]);
    }

    while (m--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, k;
            scanf("%d%d", &x, &k);
            add(x, k);
        }
        else if (op == 2)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", getSum(r) - getSum(l - 1));
        }
    }
    return 0;
}
