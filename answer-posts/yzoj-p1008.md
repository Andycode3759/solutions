~~提交了10次才通过，我太菜了~~

用a,b,result三个vector<int>保存数字，设`a[i]`,`b[i]`表示数字的第i位，即10的i次幂的系数。基本思路很简单，模拟竖式乘法，遍历a和b的每一位i和j，把答案的第i+j位加上`a[i]*b[i]`：
```c++
result[i+j]+=a[i]*b[j];
```
数学原理如下：
$$
(a_{i} \times  10^{i}) \times (b_{j} \times 10^{j}) = a_{i} \times b_{j} \times 10^{i+j}
$$
之后再把每一位上的系数化成小于10，即通常的十进制计数法，数学原理同上。

有一些细节需要注意，比如初始化result时，考虑到乘积的位数不会超过a和b的位数之和；以及不需要每算一次都处理一次进位，全部算完后从0次开始扫一遍，有大于10的系数就处理一次进位；输出要逆序，按照从左往右次方越来越低的顺序（这还涉及到判断当前位是不是有效数字，即从第一个非0位开始输出。如果答案就是0，说明乘数中有一个为0，输入完后可以直接判断~~，有0就秒出~~）。

最后还有正负号的问题，用bool变量存储正负，判断每行的第一个字符是不是负号，是的话就把bool变量反转一下（`n=!n`）。如果是负数输出时别忘了打印一个负号。

笔者之前有尝试过使用short（2字节，16位整数）甚至char（1字节，8位整数）储存所有数据，但后来发现它们的范围都不够大，可能会溢出，故还是无奈选用int。内存大小还是贪不得呀～

最后是AC了的代码：

```c++
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
```
