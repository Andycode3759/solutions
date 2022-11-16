/*
//----^^ACCEPTED^^----//
    Time:34 ms
    Memory:1448 kb
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, w, k;
    scanf("%d%d%d", &m, &w, &k);
    int nowM = 1, nowW = 1;
    for (int song = 0; song < k; song++)
    {
        if (nowM > m)
            nowM = 1;
        if (nowW > w)
            nowW = 1;
        printf("%d %d\n", nowM, nowW);
        nowM++;
        nowW++;
    }
    return 0;
}
