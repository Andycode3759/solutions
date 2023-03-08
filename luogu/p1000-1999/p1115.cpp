// AC
#include <bits/stdc++.h>
using namespace std;

int nums[200002];
int mem[200002]; // mem[i] => 以i位置结尾的子段中和最大的子段之和

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    mem[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (mem[i - 1] < 0)
        {
            mem[i] = nums[i];
        }
        else // mem[i - 1] >= 0
        {
            mem[i] = mem[i - 1] + nums[i];
        }
    }
    int max = mem[0];
    for (int i = 1; i < n; i++)
    {
        if (mem[i] > max)
            max = mem[i];
    }
    printf("%d\n", max);
    return 0;
}
