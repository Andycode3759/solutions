#include <bits/stdc++.h>
using namespace std;

int main()
{
    int kase = 1;
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3)
    {
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }
        double raw = (double)a / (double)b;
        printf("Case %d: %d.", kase, (int)raw);
        raw -= (int)raw;
        for (int i = 0; i < c; i++)
        {
            raw *= 10.0;
            printf("%d", i == c - 1 ? (int)(raw + 0.5) : (int)raw); //最后一位特判 四舍五入
            raw -= (int)raw;
        }
        printf("\n");
    }
    return 0;
}
