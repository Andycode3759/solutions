#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 100005;

struct Action
{
    Action(int _t, int _l, int _r, int _v, int _p)
    {
        type = _t;
        l = _l;
        r = _r;
        val = _v;
        pos = _p;
    }
    int type; // 0修改，1查询
    int l, r;
    int val;
    int pos;
};

vector<Action> acts;
int n, m;
long long ans[MAXN];
long long t[MAXN];

void solve(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;

    solve(l, mid);
    solve(mid + 1, r);

    memset(t, 0, sizeof(t));
    for (int i = l; i <= mid; i++)
    {
        Action &a = acts[i];
        if (a.type == 0)
        {
            t[a.l] += a.val, t[a.r + 1] -= a.val;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        t[i] += t[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        t[i] += t[i - 1];
    }
    for (int i = mid + 1; i <= r; i++)
    {
        Action &a = acts[i];
        if (a.type == 1)
        {
            ans[a.pos] += t[a.r] - t[a.l - 1];
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        acts.push_back(Action(0, i, i, t, i));
    }
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            acts.push_back(Action(0, l, r, k, i));
        }
        else if (op == 2)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            acts.push_back(Action(1, l, r, 0, i));
        }
    }

    solve(0, acts.size() - 1);

    for (int i = n; i < acts.size(); i++)
    {
        Action &a = acts[i];
        if (a.type == 1)
        {
            printf("%lld\n", ans[a.pos]);
        }
    }
    return 0;
}