// AC
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100005;
const int MAXB = 20;

struct SegTreeNode
{
    int l, r;
    int val[MAXB];
    int mark;
};
SegTreeNode st[MAXN << 2];

int arr[MAXN];

void updateNode(SegTreeNode &node, int x)
{
    for (int i = 0; i < MAXB; i++)
    {
        if ((x >> i) & 1 > 0)
        {
            node.val[i] = node.r - node.l + 1 - node.val[i];
        }
    }
}
void gatherUp(int idx)
{
    SegTreeNode &node = st[idx];
    SegTreeNode &lc = st[idx << 1], &rc = st[(idx << 1) | 1];
    for (int i = 0; i < MAXB; i++)
    {
        node.val[i] = lc.val[i] + rc.val[i];
    }
}
void passDown(int idx)
{
    SegTreeNode &node = st[idx];
    SegTreeNode &lc = st[idx << 1], &rc = st[(idx << 1) | 1];
    lc.mark ^= node.mark, rc.mark ^= node.mark;
    updateNode(lc, node.mark);
    updateNode(rc, node.mark);
    node.mark = 0;
}
void build(int l, int r, int idx)
{
    SegTreeNode &node = st[idx];
    node.l = l, node.r = r;
    memset(node.val, 0, sizeof(node.val));
    node.mark = 0;
    if (l == r)
    {
        for (int i = 0; i < MAXB; i++)
        {
            if (((arr[l] >> i) & 1) > 0)
            {
                node.val[i] = 1;
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, (idx << 1) | 1);
    gatherUp(idx);
}
void update(int l, int r, int x, int idx)
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
        updateNode(node, x);
        node.mark ^= x;
        return;
    }
    if (node.mark > 0)
        passDown(idx);
    int nmid = (node.l + node.r) >> 1;
    if (l <= nmid)
        update(l, r, x, idx << 1);
    if (r > nmid)
        update(l, r, x, (idx << 1) | 1);
    gatherUp(idx);
}
long long query(int l, int r, int idx)
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
        long long res = 0;
        for (int i = 0; i < MAXB; i++)
        {
            res += (1LL * node.val[i]) << i;
        }
        return res;
    }
    if (node.mark > 0)
        passDown(idx);
    int nmid = (node.l + node.r) >> 1;
    long long res = 0;
    if (l <= nmid)
        res += query(l, r, idx << 1);
    if (r > nmid)
        res += query(l, r, (idx << 1) | 1);
    return res;
}

int n, m;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }

    build(1, n, 1);

    scanf("%d", &m);
    int op, l, r, x;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(l, r, 1));
        }
        else if (op == 2)
        {
            scanf("%d%d%d", &l, &r, &x);
            update(l, r, x, 1);
        }
    }
    return 0;
}
