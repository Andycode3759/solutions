// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int n, m;
long long arr[MAXN];

struct SegTreeNode
{
    int left, right;
    SegTreeNode *lc, *rc;
    long long sum;
    long long cache;

    int getMid()
    {
        return (left + right) / 2;
    }
    int getLength()
    {
        return right - left + 1;
    }
};
struct SegTree
{
    int size;
    SegTreeNode *root;
    vector<SegTreeNode> nodePool;

    SegTree(int _s)
    {
        size = _s;
    }

    SegTreeNode *newNode()
    {
        SegTreeNode *n = new SegTreeNode();
        n->lc = NULL;
        n->rc = NULL;
        nodePool.push_back(*n);
        return n;
    }
    void build(int l, int r, SegTreeNode &n)
    {
        n.left = l;
        n.right = r;
        n.cache = 0;
        if (l == r)
        {
            n.sum = arr[l];
            return;
        }
        n.lc = newNode();
        n.rc = newNode();
        int mid = (l + r) / 2;
        build(l, mid, *n.lc);
        build(mid + 1, r, *n.rc);
        n.sum = n.lc->sum + n.rc->sum;
    }
    void add(int l, int r, long long k, SegTreeNode &n)
    {
        if (n.left == l && n.right == r)
        {
            n.sum += k * (r - l + 1);
            n.cache += k;
            return;
        }
        int mid = n.getMid();
        if (n.cache > 0)
        {
            n.lc->sum += n.cache * (mid - n.left + 1);
            n.rc->sum += n.cache * (n.right - mid);
            n.lc->cache += n.cache;
            n.rc->cache += n.cache;
            n.cache = 0;
        }
        if (l <= mid)
        {
            add(l, mid, k, *n.lc);
        }
        if (r > mid)
        {
            add(mid + 1, r, k, *n.rc);
        }
        n.sum = n.lc->sum + n.rc->sum;
    }
    long long query(int l, int r, SegTreeNode &n)
    {
        if (n.left == l && n.right == r)
        {
            return n.sum;
        }
        int mid = n.getMid();
        if (n.cache > 0)
        {
            n.lc->sum += n.cache * (mid - n.left + 1);
            n.rc->sum += n.cache * (n.right - mid);
            n.lc->cache += n.cache;
            n.rc->cache += n.cache;
            n.cache = 0;
        }
        long long res = 0;
        if (l <= mid)
        {
            res += query(l, mid, *n.lc);
        }
        if (r > mid)
        {
            res += query(mid + 1, r, *n.rc);
        }
        return res;
    }
    void deleteNode(SegTreeNode *n)
    {
        if (n->lc != NULL)
            deleteNode(n->lc);
        if (n->rc != NULL)
            deleteNode(n->rc);
        delete n;
    }
    void free()
    {
        deleteNode(root);
        vector<SegTreeNode>().swap(nodePool);
    }
};

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
    }
    SegTree st(n);
    st.root = st.newNode();
    st.build(1, n, *st.root);
    int op, x, y;
    long long k;
    while (m--)
    {
        scanf("%d%d%d", &op, &x, &y);
        switch (op)
        {
        case 1:
            scanf("%lld", &k);
            st.add(x, y, k, *st.root);
            break;
        case 2:
            printf("%lld\n", st.query(x, y, *st.root));
            break;
        }
    }
    return 0;
}
