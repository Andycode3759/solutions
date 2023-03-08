// AC
#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 105;

void repChar(char ch, int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("%c", ch);
    }
}

bool isnum(char c)
{
    return c >= '0' && c <= '9';
}

int main()
{
    int method, repeat, reversed;
    char str[MAXLEN];
    scanf("%d%d%d", &method, &repeat, &reversed);
    reversed = reversed == 2 ? -1 : 1;
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '-')
        {
            char l = str[i - 1], r = str[i + 1];
            if ((!(isalpha(l) && isalpha(r)) && !(isnum(l) && isnum(r))) || r <= l)
            {
                printf("-");
                continue;
            }
            char from, to;
            from = reversed > 0 ? str[i - 1] : str[i + 1];
            to = reversed > 0 ? str[i + 1] : str[i - 1];
            for (char c = from + reversed; (reversed > 0 && c < to) || (reversed < 0 && c > to); c += reversed)
            {
                switch (method)
                {
                case 1:
                    repChar(c, repeat);
                    break;

                case 2:
                    repChar(toupper(c), repeat);
                    break;

                case 3:
                    repChar('*', repeat);
                    break;
                }
            }
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}