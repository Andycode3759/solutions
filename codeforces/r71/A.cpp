// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 103;
char str[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", str);
        int len = strlen(str);
        if (len > 10)
        {
            char strAlt[9];
            strAlt[0] = str[0];
            int charWritten = sprintf(strAlt + 1, "%d", len - 2);
            sprintf(strAlt + 1 + charWritten, "%c", str[len - 1]);
            strAlt[2 + charWritten] = '\0';
            printf("%s\n", strAlt);
        }
        else
        {
            printf("%s\n", str);
        }
    }
    return 0;
}
