// Unfinished
#include <bits/stdc++.h>
using namespace std;

struct Gap
{
    long long a, b;
    long long dis;
};

int cmp(Gap a, Gap b)
{
    return b.dis - a.dis; // 从大到小排序
}

vector<Gap> allGap;
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    int beg;
    scanf("%d", &beg);
    for (int i = 1; i < n; i++)
    {
        Gap &current = allGap[i - 1];
        current.a = beg;
        scanf("%d", &beg);
        current.b = beg;
        current.dis = current.b - current.a;
    }
    sort(allGap.begin(), allGap.end(), cmp);
    long long result = 0;
    for (int i = 0; i < m - 1; i++)
    {
        result += allGap[i].dis; // 最大的m-1段间隔
    }
    return 0;
}
