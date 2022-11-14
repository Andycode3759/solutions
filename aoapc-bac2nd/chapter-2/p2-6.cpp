//UNFINISHED
#include <bits/stdc++.h>
using namespace std;

bool book[10] = {0}; // book[i]==true表示i已经用过
int abc[3] = {0};

bool isGood(int &def, int &ghi) //顺便把def和ghi求出来
{
    int realAbc = abc[0] * 100 + abc[1] * 10 + abc[2];
    def = realAbc * 2;
    ghi = realAbc * 3;
    if (def >= 1000 || ghi >= 1000)
        return false;
    int d = def / 100, e = def / 10 % 10, f = def % 10;
    int g = ghi / 100, h = ghi / 10 % 10, i = ghi % 10;
    /*
    //debug
        for (int i = 0; i <= 9; i++)
        {
            printf("%d", book[i]);
        }
        printf("\n");
    //debug
    */

    bool anotherBook[10];
    for (int i = 0; i <= 9; i++)
    {
        anotherBook[i] = book[i];
    }
    anotherBook[d] = true;
    anotherBook[e] = true;
    anotherBook[f] = true;
    anotherBook[g] = true;
    anotherBook[h] = true;
    anotherBook[i] = true;
    for (int i = 0; i <= 9; i++)
    {
        if (!anotherBook[i])
            return false;
    }
    return true;
}

void dfs(int step)
{
    if (step >= 3)
    {
        int def, ghi;
        if (isGood(def, ghi))
        {
            printf("%d %d %d\n",
                   abc[0] * 100 + abc[1] * 10 + abc[2],
                   def, ghi);
        }
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (!book[i])
        {
            abc[step] = i;
            book[i] = true;
            dfs(step + 1);
            book[i] = false;
        }
    }
}

int main()
{
    dfs(0);
    printf("\n");
    return 0;
}
