#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
constexpr int MAXN = 500005;
constexpr int INF = (1 << 30) - 1;

struct Qujian
{
    int l, r, len;
    bool operator<(const Qujian &b) const
    {
        return len < b.len;
    }
};
Qujian qj[MAXN];

int n, m;
vector<int> nums;
int tot;
inline int getIdx(int x)
{
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
}

struct SegTreeNode
{
    int val, mark;
};
SegTreeNode st[MAXN * 4];
void STBuild(int idx, int l, int r)
{
    SegTreeNode &cur = st[idx];
    cur.val = cur.mark = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    STBuild(idx << 1, l, mid);
    STBuild((idx << 1) | 1, mid + 1, r);
}
inline void STPassDown(int idx, int l, int r)
{
    SegTreeNode &cur = st[idx];
    SegTreeNode &lc = st[idx << 1], &rc = st[(idx << 1) | 1];
    lc.mark += cur.mark, rc.mark += cur.mark;
    lc.val += cur.mark, rc.val += cur.mark;
    cur.mark = 0;
}
void STAdd(int idx, int l, int r, int ql, int qr, int dlt)
{
    SegTreeNode &cur = st[idx];
    if (ql <= l && r <= qr)
    {
        cur.val += dlt;
        cur.mark += dlt;
        return;
    }
    STPassDown(idx, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        STAdd(idx << 1, l, mid, ql, qr, dlt);
    if (qr > mid)
        STAdd((idx << 1) | 1, mid + 1, r, ql, qr, dlt);
    cur.val = max(st[idx << 1].val, st[(idx << 1) | 1].val);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &qj[i].l, &qj[i].r);
        nums.push_back(qj[i].l);
        nums.push_back(qj[i].r);
        qj[i].len = qj[i].r - qj[i].l;
    }
    sort(qj + 1, qj + n + 1);
    sort(nums.begin(), nums.end());
    tot = unique(nums.begin(), nums.end()) - nums.begin();
    STBuild(1, 1, tot);
    for (int i = 1; i <= n; i++)
    {
        qj[i].l = getIdx(qj[i].l);
        qj[i].r = getIdx(qj[i].r);
    }

    int ans = INF;
    int tail = 1;
    for (int i = 1; i <= n; i++)
    {
        Qujian &cur = qj[i];
        STAdd(1, 1, tot, cur.l, cur.r, 1);
        while (st[1].val >= m)
        {
            ans = min(ans, cur.len - qj[tail].len);
            STAdd(1, 1, tot, qj[tail].l, qj[tail].r, -1);
            tail++;
        }
    }
    if (ans >= INF)
        ans = -1;
    printf("%d\n", ans);
    return 0;
}