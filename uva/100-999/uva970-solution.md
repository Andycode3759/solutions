## 题意翻译

> 如不需要阅读可跳转到[正文](#题解正文)。

人们用粒子加速器进行实验来研究高能粒子相碰撞产生的现象。当高能粒子相碰时，它们会消失并生成新的粒子，有时还会有光发出。

我们着重研究三种夸克 $X,Y,Z$ 碰撞时的现象。不同的夸克具有不同的质量，$X$ 最轻，$Z$ 最重，$Y$ 位于另二者之间。

举例来说，当一个 $X$ 夸克与另一个 $X$ 夸克相撞时，两者都会湮灭，同时产生一个新的 $Y$ 夸克。我们可以用如下表达式表达这个反应：

$X+X \Rightarrow Y$

所有可能的夸克反应结果如下表：

| +   | $X$ | $Y$ | $Z$ |
| --- | --- | --- | --- |
| $X$ | $Y$ | $X$ | $Z$ |
| $Y$ | $X$ | $Y$ | $Y$ |
| $Z$ | $Z$ | $Y$ | $X$ |

例如，$X+Z \Rightarrow Z, Z+Z \Rightarrow X$。给定一个夸克序列，我们可以计算出可能的相互作用的结果，前提假设**只有相邻的两个夸克才能互相反应**。每次两个夸克相反应，序列中反应物所在的位置会被产物所替换。自然地，任何一个序列经过若干次反应后都会只剩下一个夸克粒子作为最终产物。同时，相同的序列若以不同的顺序反应，得到的最终产物粒子也可能会不同。

例如，初始序列为 $ZYX$，那么会有两种可能的反应方式：

1. $ZYX \Longrightarrow YX(Z+Y \Rightarrow Y) \Longrightarrow X(Y+X \Rightarrow X)$
2. $ZYX \Longrightarrow ZX(Y+X \Rightarrow X) \Longrightarrow Z(Z+X \Rightarrow Z)$

其中方式二得到的夸克 $Z$ 的质量最大。

编写一个程序，给定若干个夸克序列，求各个序列反应后可能得到的**质量最大的最终粒子**。

### 输入

第 1 行为一个整数 $N$，表示序列个数；之后的 $N$ 行每行为一个夸克序列，保证仅由 $'X','Y','Z'$ 三种字符组成，且长度不超过 $100$。

### 输出

输出 $N$ 行，表示第 $N$ 个序列完全反应后可能得到的质量最大的最终粒子。

## 题解正文

看到题目大多数人的第一反应可能是区间动态规划，用类似于[合并石子](https://www.luogu.com.cn/problem/P1775)的方法，定义 $heaviest(l,r)$ 为序列中从位置 $l$ 到位置 $r$ 所能合成的最重粒子，再进行区间切分。但问题随之而来：如何写出转移方程？注意到**两个最重的粒子合成出的粒子不一定更重**，即以下解法是 **_错误_** 的：

```c++
char interact(char a, char b); // 返回两个粒子反应后的生成物，具体实现略

for (int k = left; k < right; k++)
        heaviest[left][right] = max(heaviest[left][right], interact(heaviest[left][k], heaviest[k + 1, right]));
```

问题的根源在于：粒子的质量在反应过程中不具有传递性。两个粒子合成的产物可能比两者更重，也可能更轻。因此我们要换一个角度考虑问题。不妨尝试这样定义状态：$possible(l,r,x)$ 表示序列中 $[l,r]$ 的区间**是否可能合成出粒子** $x$ 。如此一来问题就简单了不少：状态转移方程即题目中给出的反应表！

具体来说，如果我们要求出 $possible(l,r,x)$ 的值，可以先进行区间切分，再根据产物$x$的情况去表中查找所有可能的反应物组合。如果左右两个子区间合成出对应的反应物是可能的，那么总的区间自然可以合成出要求的产物 $x$。

如何求出答案呢？元素总共只有 $3$ 种，因此从重到轻一一枚举完全是可行的。

具体代码实现：

```c++
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

// 储存元素序列
char seq[MAXN];
// possible[i][j][x]表示：从i到j的区间能否形成元素x（x的值0为X,1为Y,2为Z），储存值为-1表示未知，0表示否，1表示是
int possible[MAXN][MAXN][3];

// 记忆化搜索+递归，求出possible[left][right][element]的值并返回
bool isPossibleToForm(int left, int right, char element)
{
    // 记忆化搜索模板
    if (possible[left][right][element - 'X'] >= 0)
        return possible[left][right][element - 'X'];
    int &ans = possible[left][right][element - 'X']; // 利用引用简化代码

    if (left == right) // 区间指向单个位置，那么唯一能“合成”的元素自然就是序列中此位置的元素本身
        return ans = (seq[left] == element);

    // 区间切分
    for (int k = left; k < right; k++)
    {
        switch (element)
        // 根据反应物的所有可能搭配查表，记得反应物表是左右对称的，因此左右区间的对应的反应物交换位置后依然可行
        {
        case 'X':
            if (isPossibleToForm(left, k, 'X') && isPossibleToForm(k + 1, right, 'Y') ||
                isPossibleToForm(left, k, 'Y') && isPossibleToForm(k + 1, right, 'X') ||
                isPossibleToForm(left, k, 'Z') && isPossibleToForm(k + 1, right, 'Z'))
                return ans = true;
            break;
        case 'Y':
            if (isPossibleToForm(left, k, 'X') && isPossibleToForm(k + 1, right, 'X') ||
                isPossibleToForm(left, k, 'Y') && isPossibleToForm(k + 1, right, 'Y') ||
                isPossibleToForm(left, k, 'Y') && isPossibleToForm(k + 1, right, 'Z') ||
                isPossibleToForm(left, k, 'Z') && isPossibleToForm(k + 1, right, 'Y'))
                return ans = true;
            break;
        case 'Z':
            if (isPossibleToForm(left, k, 'X') && isPossibleToForm(k + 1, right, 'Z') ||
                isPossibleToForm(left, k, 'Z') && isPossibleToForm(k + 1, right, 'X'))
                return ans = true;
            break;
        }
    }
    // 所有可能的区间切分都不可行（在查表过程中没有返回），返回false
    return ans = false;
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        // 注意多组数据需重置数组
        memset(possible, -1, sizeof(possible));
        scanf("%s", seq + 1);
        int len = strlen(seq + 1); // 序列的长度是未知的，需要自己获取

        // 从重到轻依次枚举产物
        if (isPossibleToForm(1, len, 'Z'))
        {
            printf("Z\n");
        }
        else if (isPossibleToForm(1, len, 'Y'))
        {
            printf("Y\n");
        }
        else // Z和Y都不行那自然只剩X了，可以直接输出
        {
            printf("X\n");
        }
    }
    return 0;
}
```
