// AC
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int kases;
    scanf("%d", &kases);
    getchar(); // 吞掉\n
    for (int i = 0; i < kases; i++)
    {
        string str = "";
        int combo = 0;
        int score = 0;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'O')
            {
                combo++;
                score += combo;
            }
            else if (str[i] == 'X')
            {
                combo = 0;
            }
            else
            {

                break;
            }
            // printf("Combo = %d\n",combo); //debug
        }
        printf("%d\n", score);
    }
    return 0;
}