#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int j = n; j > 0; j--)
    {
        for (int i = 0; i < n - j; i++) // n-j个空格
        {
            printf(" ");
        }
        for (int i = 0; i < 2 * j - 1; i++) // 2j-1个#
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
