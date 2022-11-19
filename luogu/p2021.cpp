#include <bits/stdc++.h>
using namespace std;

list<int> rp; // rp[i] => 牌堆从上到下第i张牌是原序列的第rp[i]张牌
int mapping[1000003];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        rp.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int top = rp.front();
        rp.pop_front();
        rp.push_back(top);
        mapping[rp.front()] = i;
        rp.pop_front();
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", mapping[i]);
    }
    printf("\n");
    return 0;
}
