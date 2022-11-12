#include <bits/stdc++.h>
using namespace std;

int main()
{
    int year;
    scanf("%d", &year);
    //不要嵌套 不要嵌套 不要嵌套
    if (year % 400 == 0) //四百年一定闰
    {
        printf("yes\n");
        return 0;
    }

    if (year % 100 == 0) //不是四百年 百年不闰
    {
        printf("no\n");
        return 0;
    }

    if (year % 4 == 0) //不是百年 四年一闰
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}
