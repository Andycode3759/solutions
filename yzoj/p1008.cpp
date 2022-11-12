/*
//----^^ACCEPTED^^----//
    Time:186 ms
    Memory:1732 kb
*/
#include <bits/stdc++.h>
using namespace std;

void increase(vector<int> &v, int pos) //处理进位
{
    if (v[pos] < 10)
        return;
    v[pos + 1] += v[pos] / 10;
    v[pos] = v[pos] % 10;
    increase(v, pos + 1);
}

void check(vector<int> &v) //调试用
{
    for (int i = v.size() + 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> a;
    vector<int> b;
    vector<int> result;
    int read = 0;
    bool negative = false;

    //input
    while ((read = getchar()) != '\n')
    {
        if (read == '-')
            negative = !negative;
        else
            a.push_back((int)(read - '0'));
    }
    while ((read = getchar()) != '\n' && read != EOF)
    {
        if (read == '-')
            negative = !negative;
        else
            b.push_back((int)(read - '0'));
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    //solve
    for (int i = 0; i < a.size() + b.size() - 1; i++) //初始化result 积不超过a+b位
    {
        result.push_back(0);
    }
    if ((a.size() == 1 && a[0] == 0) || (b.size() == 1 && b[0] == 0)) //秒出
    {
        cout << 0 << endl;
        return 0;
    }
    //check(a);
    //check(b);
    for (int powA = 0; powA < a.size(); powA++)
    {
        for (int powB = 0; powB < b.size(); powB++)
        {
            int little = a[powA] * b[powB];
            int targetPow = powA + powB;
            result[targetPow] += little;
        }
    }
    //check(result);
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] >= 10)
        {
            increase(result, i);
        }
    }

    //check(result);

    //output
    bool valid = false;
    if (negative)
        cout << '-';
    for (int i = result.size() + 1; i >= 0; i--)
    {
        if (result[i] != 0)
            valid = true;
        if (valid)
            cout << result[i];
    }
    cout << endl;
    return 0;
}
