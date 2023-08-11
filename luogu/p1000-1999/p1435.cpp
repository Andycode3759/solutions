#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
const int MAXN = 1005;

int len;
char str[MAXN];
stack<char> S;

int solve(int p, int t)
{
    while (!S.empty())
        S.pop();
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        if (t == 0 && i == p)
            continue;
        if (i < p)
            S.push(str[i]);
        if (i > p || (t == 1 && i == p))
        {
            if (!S.empty() && S.top() != str[i])
                res += 2;
            if (S.empty())
                res++;
            else
                S.pop();
        }
    }
    while (!S.empty())
        res++, S.pop();
    // printf("p=%d t=%d res=%d\n",p,t,res);
    return res;
}

int main()
{
    scanf("%s", str);
    len = strlen(str);
    int ans = 9999;
    for (int i = 0; i < len; i++)
        ans = min(ans, solve(i, 0));
    for (int i = 0; i < len; i++)
        ans = min(ans, solve(i, 1));
    printf("%d\n", ans);
    return 0;
}