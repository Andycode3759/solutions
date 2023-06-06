// By @LgxTpre
#include <cstdio>
using namespace std;
const int MAXN = 100005;

struct SegTreeNode
{
    int l, r;
    long long sum = 0;
    long long mark;

    int getLength()
    {
        return r - l + 1;
    }
    int getMid()
    {
        return (r + l) >> 1;
    }
};

SegTreeNode st[MAXN << 2];
int arr[MAXN];
int n, m;

void build(int idx, int l, int r)
{
    SegTreeNode &node = st[idx];
    node.l = l, node.r = r;
    if (l == r)
    {
        node.sum = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    node.sum = st[idx * 2].sum + st[idx * 2 + 1].sum;
}

void passDown(int idx)
{
    SegTreeNode &node = st[idx];
    SegTreeNode &lc = st[idx * 2], &rc = st[idx * 2 + 1];
    lc.mark += node.mark, rc.mark += node.mark;
    lc.sum += node.mark * lc.getLength(),
        rc.sum += node.mark * rc.getLength();
    node.mark = 0;
}

void add(int idx, int l, int r, int x)
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
        node.sum += x * node.getLength();
        node.mark += x;
        return;
    }
    passDown(idx);
    int nmid = node.getMid();
    if (l <= nmid)
        add(idx * 2, l, r, x);
    if (r > nmid)
        add(idx * 2 + 1, l, r, x);
    node.sum = st[idx * 2].sum + st[idx * 2 + 1].sum;
}

long long getSum(int idx, int l, int r)
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
        // printf("st[%d,%d]: %lld\n", node.l, node.r, node.sum);
        return node.sum;
    }
    passDown(idx);
    int nmid = node.getMid();
    long long res = 0;
    if (l <= nmid)
        res += getSum(idx * 2, l, r);
    if (r > nmid)
        res += getSum(idx * 2 + 1, l, r);

    // printf("st[%d,%d]: %lld\n", node.l, node.r, node.sum);
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    build(1, 1, n);
    int op, x, y, k;
    while (m--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%d", &x, &y, &k);
            add(1, x, y, k);
        }
        else if (op == 2)
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", getSum(1, x, y));
        }
    }
    return 0;
}