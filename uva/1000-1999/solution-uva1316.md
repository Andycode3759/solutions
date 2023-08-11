> 注：洛谷上本题已经关闭题解通道，故只能发在个人博客里。没打算申请加入主题解区。

对于一个在第 $d$ 天过期的商品，其可以卖出的时间为第 $1$ 天到第 $d$ 天。显然，从第 $1$ 天开始，越往后能卖的商品越少。那么反过来，从最后一天开始往前推，能卖的商品会越来越多。形式化地，记第 $i$ 天能卖出的商品数量为 $f(i)$，$1 \leq i \leq max\{d_i\}$，那么 $f$ 一定是一个单调不递增的函数。

既然这样，我们用一个大根堆 $Q$ 放置目前可以卖出的商品，再从最后一天开始从后往前枚举，记当前考虑的为第 $a$ 天，$a \larr from\ max\{d_i\}\ to\ 1$，每次将第 $a$ 天过期的所有商品价格加入到 $Q$ 中，再取堆顶作为这一天卖出的商品。这样做一定可以得到最大的利润。堆的维护理论上用暴力（循环 + `std::priority_queue.push_back()`）也能过，但这里演示一下平板电视可并堆（`__gnu_pbds::priority_queue`）的 $O(n \cdot logn)$ 写法：

```c++
// 个人不喜欢用万能头，minimal include主义者
#include <cstdio>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
constexpr int MAXN = 10004;

__gnu_pbds::priority_queue<int> itemOnDay[MAXN], Q;
int n, maxd;

int main()
{
    // 顺便解释一下，scanf的返回值是读到的变量个数
    // 能读到n说明还有输入
    while (scanf("%d", &n) == 1)
    {
        // 数据不清空，爆零两行泪
        for (int i = 1; i <= maxd; i++)
            itemOnDay[i].clear();
        Q.clear();
        maxd = 0;

        for (int i = 1; i <= n; i++)
        {
            int p, d;
            scanf("%d %d", &p, &d);
            itemOnDay[d].push(p);
            maxd = max(maxd, d);
        }
        int ans = 0;
        for (int i = maxd; i >= 1; i--)
        {
            // join操作可以把右边的堆并入左边（右边的似乎会被清空？），
            // 且仅需O(logn)的时间复杂度
            Q.join(itemOnDay[i]);
            if (!Q.empty())
            {
                ans += Q.top();
                Q.pop();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
```

### 参考文献

> - Fighting_Peter.C++ \_\_gnu_pbds（hash，可并堆，平衡树）[EB/OL].(2021-08-23)[2023-08-09].<https://blog.csdn.net/Fighting_Peter/article/details/119870941>
