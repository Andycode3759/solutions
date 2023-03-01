// AC
#include <bits/stdc++.h>
using namespace std;
const int MOD = 80112002;
const int MAXN = 5005;

vector<int> foodOf[MAXN];
int chainCount[MAXN];
bool hasEater[MAXN];
bool hasFood[MAXN];

int getChainCount(int root)
{
    int &ans = chainCount[root];
    if (ans > 0)
        return ans;

    if (!hasFood[root])
    {
        return ans = 1;
    }

    ans = 0;
    vector<int> &foodList = foodOf[root];
    for (int i = 0; i < foodList.size(); i++)
    {
        ans = (ans + getChainCount(foodList[i])) % MOD;
    }
    return ans;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int eater, food;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &food, &eater);
        foodOf[eater].push_back(food);
        hasEater[food] = true;
        hasFood[eater] = true;
    }
    memset(chainCount, -1, sizeof(chainCount));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!hasEater[i])
            ans = (ans + getChainCount(i)) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}
