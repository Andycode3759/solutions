// WA
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10020;
int music[100];
int f[MAXN];
long long func[MAXN];
int n, t, T;
int main()
{
    // last 678
    cin >> T;
    for (int l = 1; l <= T; l++)
    {
        memset(func, 0, sizeof(func));
        scanf("%d%d", &n, &t);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", music + i);
        }
        t--;
        func[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = t; j >= music[i]; j--)
            {
                if (func[j - music[i]])
                {
                    func[j] = func[j - music[i]] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = t; i >= 1; i--)
        {
            if (func[i])
            {
                ans = i + 678;
                printf("Case %d: %lld %d\n", l, func[i], ans);
                break;
            }
        }
    }
    return 0;
}