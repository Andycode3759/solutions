// WA
#include <bits/stdc++.h>
using namespace std;

int a, b;
// equa => ax+b=0
bool aftereq = false;
char letter;

void parse(string s)
{
    bool sign = true;
    int i = 0;
    if (s[0] == '-')
    {
        sign = false;
        i = 1;
    }
    if (s[0] == '+')
        i = 1;
    int num;
    bool isletter = false;
    for (; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + s[i] - '0';
        }
        else // is letter
        {
            letter = s[i];
            isletter = true;
        }
    }
    if (!sign)
        num = -num;
    if (aftereq)
        num = -num;
    if (isletter)
        a += num;
    else
        b += num;
}

int main()
{
    string equa;
    cin >> equa;
    int s = 0;
    for (int i = 0; i < equa.size(); i++)
    {
        if (equa[i] == '+' || equa[i] == '-')
        {
            parse(equa.substr(s, i - s));
            s = i;
        }
        else if (equa[i] == '=')
        {
            parse(equa.substr(s, i - s));
            s = i + 1;
            aftereq = true;
        }
    }
    parse(equa.substr(s, equa.size() - s));

    printf("%c=%.3f\n", letter, -(b * 1.0) / a);
    return 0;
}
