//UNFINISHED
#include <bits/stdc++.h>
using namespace std;

bool seq[100002];
int male[100002];   // seq[0]~seq[i]的1的个数
int female[100002]; // seq[0]~seq[i]的0的个数

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        seq[i] = s;
        if (i == 0)
        {
            if (s)
                male[0] = 1;
            else
                female[0] = 1;
        }
        else
        {
            female[i] = s ? female[i - 1] : female[i - 1] + 1;
            male[i] = s ? male[i - 1] + 1 : male[i - 1];
        }
    }

    return 0;
}
