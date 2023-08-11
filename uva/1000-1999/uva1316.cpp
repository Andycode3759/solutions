#include <cstdio>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
constexpr int MAXN = 10004;

__gnu_pbds::priority_queue<int> itemOnDay[MAXN], Q;
int n, maxd;

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i = 1; i <= maxd; i++)
            itemOnDay[i].clear();
        Q.clear();
        maxd = 0;

        for (int i = 1; i <= n; i++)
        {
            int p, d;
            scanf("%d %d", &p, &d);
            itemOnDay[d].push(p);
            maxd = max(maxd, d);
        }
        int ans = 0;
        for (int i = maxd; i >= 1; i--)
        {
            Q.join(itemOnDay[i]);
            if (!Q.empty())
            {
                ans += Q.top();
                Q.pop();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}