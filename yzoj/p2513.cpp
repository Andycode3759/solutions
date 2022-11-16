/*
//----^^ACCEPTED^^----//
    Time:32 ms
    Memory:1464 kb
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int li[105];
    int x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &li[i]);
    }
    scanf("%d", &x);
    bool inserted = false;
    for (int i = 0; i < n; i++) //秒出
    {
        if (i == x - 1)
        {
            printf("%d ", li[n - 1]);
            inserted = true;
            continue;
        }
        if (inserted)
        {
            printf("%d ", li[i - 1]);
        }
        else
        {
            printf("%d ", li[i]);
        }
    }
    printf("\n");
    return 0;
}
