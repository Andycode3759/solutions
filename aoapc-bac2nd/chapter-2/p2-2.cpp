#include <bits/stdc++.h>
using namespace std;

int main()
{
    int kase = 1;
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3)
    {
        bool bad = true;
        for (int i = 10; i <= 100; i++)
        {
            if (i % 3 == a && i % 5 == b && i % 7 == c)
            {
                printf("Case %d: %d\n", kase, i);
                bad = false;
                break;
            }
        }
        if (bad)
            printf("Case %d: No answer\n", kase);
        kase++;
    }
    return 0;
}
