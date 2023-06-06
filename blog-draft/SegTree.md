# 线段树的一万种套路

本篇文章主要把有关线段树实现的坑和一些应用做一个大致介绍。笔者从初学线段树到终于写对模板题花了将近三个月的时间，期间走了不少弯路，故将其中的心得体会整理成本文，一是为了自己日后方便复习，二能够为后人留下一定参考。

**本文不对线段树的概念进行讲解**（但或许可以加深你对线段树的认识，或者对一些似懂非懂的概念作出更好的解释），如果你还不知道线段树是什么，可以去查阅 [OI Wiki](https://oi-wiki.org/ds/seg/)。

## 模板实现

例题：区间修改（增加），区间求和 [P3372](https://www.luogu.com.cn/problem/P3372)

维护区间和的线段树是最经典的线段树实现之一，但大多数初次实现的代码经常会犯不少错误。

### 大致框架

对于任何一个数据结构，我们应当首先明确其可以实现的功能和各个状态的意义。线段树主要由 5 个需要实现的功能组成：

- 建树：初始化线段树，使其各节点的值对应原始数据的初始状态；
- 修改：将给定的区间拆分成若干个线段树上节点对应的子区间，再分别执行修改操作；
- 查询：将给定的区间拆分成若干个线段树上节点对应的子区间，将所有子区间的结果求和；
- 上传信息：通过两个子节点的结果更新父节点的结果；
- 下传信息：遇到有懒惰标记的节点时将标记下放给子节点并更新结果。

### 定义

由于笔者熟悉的线段树实现可能和读者的不太一样，故在此给出一些文中通用的变量和结构体定义：

```c++
struct SegTreeNode  // 线段树节点
{
    int l, r;   // 节点对应区间的左、右端点
    long long sum;  // 区间和
    long long mark; // 懒惰标记
};
SegTreeNode st[MAXN << 2];  // 线段树本体，MAXN视数据范围有具体值
int arr[MAXN];  // 原始数据
```

另外，~~由于笔者深受面向对象思想毒害，~~ 程序实现中可能会出现大量的引用变量用以简化代码。如果读者觉得不适应，可以将引用变量名直接替换为其初始化时的赋值。为节省篇幅，部分与上下文无关的代码片段可能会被省略号（...）替代。

### 经典错误 1：错误地跳过下传信息

```c++
void add(int idx, int l, int r, int x)
{
    SegTreeNode &node = st[idx];
    SegTreeNode &lc = st[idx << 1], &rc = st[(idx << 1) | 1];
    // 顺便提示一下，idx<<1 等价于 idx*2，(idx<<1)|1 等价于 idx*2+1，
    // 但是位运算会比十进制数运算快很多。
    ...
    if (node.mark > 0)
    {
        SegTreeNode &node = st[idx];
        lc.mark += node.mark, rc.mark += node.mark;
        lc.sum += node.mark * (lc.r - lc.l + 1);
        rc.sum += node.mark * (rc.r - rc.l + 1);
        node.mark = 0;
    }
    ...
}
```

不要想当然地认为懒惰标记都是正数。若题目没有注明 $x>0$，那么**增加量也可能是负数**。因此正确的写法应该把`if`判断去掉，或者把`node.mark > 0`的条件修改为`node.mark != 0`。

### 经典错误 2：下传信息/更新节点时覆盖原有标记

```c++
void add(int idx, int l, int r, int x)
{
    SegTreeNode &node = st[idx];
    SegTreeNode &lc = st[idx << 1], &rc = st[(idx << 1) | 1];
    if (l <= node.l && r >= node.r)
    {
        node.sum += x * node.getLength();
        node.mark = x;
        return;
    }
    if (node.mark != 0)
    {
        SegTreeNode &node = st[idx];
        lc.mark = node.mark, rc.mark = node.mark;
        lc.sum += node.mark * (lc.r - lc.l + 1);
        rc.sum += node.mark * (rc.r - rc.l + 1);
        node.mark = 0;
    }
    ...
}
```

这段代码有两处错误：当找到目标节点时覆盖原有标记，以及下传信息后覆盖了子节点的标记。懒惰标记意味着存在没有执行的“更新结果”的任务，如果你给一个节点更新懒惰标记（或者说给予新的“更新结果”的任务），那么先前“更新结果”的任务不可能被取消（否则最终结果就不对了！），正确做法应该是“旧帐新帐一起算”。但是在不同的线段树应用中，懒惰标记是合并还是覆盖要视具体的需求而定，不要盲目地认为全部的懒惰标记都应该合并（见**简单应用**，例题 1）。

### 经典错误 3：递归时传递错误的子区间

```c++
void build(int idx, int l, int r)
{
    SegTreeNode &node = st[idx];
    ...
    build(idx << 1, l, mid);
    build((idx << 1) | 1, mid + 1, r);
    node.sum = st[idx << 1].sum + st[(idx << 1) | 1].sum;
}

void add(int idx, int l, int r, int x)
{
    SegTreeNode &node = st[idx];
    ...
    int nmid = (node.l + node.r) >> 1;
    // 当l+r>=0时，(l+r)>>1 等价于 (l+r)/2。
    if (l <= nmid)
        add(idx << 1, l, nmid, x);
    if (r > nmid)
        add((idx << 1) | 1, nmid + 1, r, x);
    node.sum = st[idx << 1].sum + st[(idx << 1) | 1].sum;
}

long long getSum(int idx, int l, int r)
{
    SegTreeNode &node = st[idx];
    ...
    int nmid = (node.l + node.r) >> 1;
    long long res = 0;
    if (l <= nmid)
        res += getSum(idx << 1, l, nmid);
    if (r > nmid)
        res += getSum((idx << 1) | 1, nmid + 1, r);
    return res;
}
```

`build`函数实现的建树没有问题，但`add`和`getSum`在递归时传递的区间就不对了。`add`和`getSum`函数中区间参数的含义为“最终需要查询的区间”，因此**在递归过程中不能改变**，否则会得到错误的结果。例如，假设线段树根节点对应的区间是 $[1,100]$，调用 `getSum(1, 1, 1)` 查询 $[1,1]$ 的区间和（即位置 $1$ 的值）；如果使用上面的实现，递归后将会调用 `getSum(2, 1, 50)`，原始区间被拉长了，获得的结果也就会是错误的。只需记住：当且仅当在建树时，区间在递归时才需要折半，其余情况都是传原区间。

### 经典错误 4：忘记上传/下传信息

```c++
void add(int idx, int l, int r, int x)
{
    SegTreeNode &node = st[idx];
    if (node.l >= l && node.r <= r)
    {
        node.sum += (node.r - node.l + 1) * x;
        node.mark += x;
        return;
    }
    int nmid = (node.l + node.r) >> 1;
    if (l <= nmid)
        add(idx << 1, l, r, x);
    if (r > nmid)
        add((idx << 1) | 1, l, r, x);
    return;
}
```

由于上传/下传信息一般比较简单，故很多情况下会在 `add` 或 `getSum` 函数中直接写相关代码，而不会包装成一个函数。这也导致上传/下传信息经常会被忘记。**切记在建树和更新时要上传信息、更新和查询时要下传信息。** 推荐将上传/下传信息写成一个函数，在 `add` 和 `getSum` 中调用，作为模板的一部分，这样就不容易忘记。

## 简单应用

线段树往往用于解决与区间有关的修改、查询问题，最常见也最简单的应用就是将模板中的求和（加法）换成别的一种运算。但有时，能用线段树解决的问题也不一定与数学运算相关。

### 例题 1：数颜色（[Count Color, POJ2777](http://poj.org/problem?id=2777)）

> **题目大意**：一条长木板被分为等长的 $L$ 段，从左到右标号为 $1,2,3,...,L$。现在有两种操作：
>
> 1. `C A B C`：将木板的第 $A$ 到 $B$ 段全部涂成颜色 $C$；
> 2. `P A B`：输出木板的第 $A$ 到 $B$ 段共有多少种不同的颜色。
>
> 输入 $L,T,O$，分别为木板长度、颜色种数和操作总数，以及 $O$ 个操作（每个一行）。对每一个操作 `P` 输出对应的结果，一个结果占一行。（输入输出样例见原题）
> 数据范围：$1 \leq L \leq 10^5,~1 \leq T \leq 30,~1 \leq O \leq 10^5,~1 \leq C \leq T$。**$A$ 可能大于 $B$。**
> 规定一种颜色被另一种颜色覆盖后，只能看到最上面的颜色。木板默认为颜色 $1$。

本题乍一看好像和线段树没什么关系，这不就纯纯模拟题吗？事实上，这是一道典型的区间修改/查询问题，而线段树就是解决此类问题的最好工具。线段树的节点储存的信息是这一段区间中所包含的颜色（注意不能简单地储存颜色数量，否则无法在上传信息时合并），该怎么储存呢？仔细分析可以发现，颜色种数 $T$ 并不是很大，可以用二进制数的方法储存。即用一个 32 位的`int`整数，从低到高的第 $i$ 位为 $1$ 表示存在颜色 $i$。如此，颜色的合并也可以很方便地用位运算实现。最终输出答案时只需要数一数结果的二进制数里有多少个 $1$ 就可以了。

另外需要注意一点，懒惰标记应该覆盖而不是合并，因为涂色操作是直接覆盖一整个区间的，这一点与区间和模板需要区分开。再次强调：**懒惰标记是合并还是覆盖要视具体情况而定。**

由于篇幅有限，这里只给出线段树的五大功能部分的实现：

```c++
struct SegTreeNode
{
    int l, r;
    int col;    // 二进制数形式储存的颜色
    int mark;
};
SegTreeNode st[MAXN << 2];

void passDown(int idx)
{
	SegTreeNode &node = st[idx];
	SegTreeNode &lc = st[idx << 1], &rc = st[(idx << 1) | 1];
	lc.mark = node.mark, rc.mark = node.mark;   // 注意此处的懒惰标记是直接覆盖，无需合并
	lc.col = node.mark, rc.col = node.mark; // 由于涂色是直接覆盖，原有的颜色都会丢失，故直接赋值即可
	node.mark = 0;
}
void gatherUp(int idx)
{
	SegTreeNode &node = st[idx];
	node.col = st[idx << 1].col | st[(idx << 1) | 1].col;
}
void build(int idx, int l, int r)
{
    SegTreeNode &node = st[idx];
    node.l = l, node.r = r;
    node.col = 1;
    node.mark = 0;
    if (l == r)
    {
    	return;
	}
	int mid = (l + r) >> 1;
	build(idx << 1, l, mid);
	build((idx << 1) | 1, mid + 1, r);
	gatherUp(idx);  // 这一行可以省略，毕竟全部为颜色1，上传后结果不会发生改变
}
void update(int idx, int l, int r, int c)   // 此处的c传的是二进制数形式的颜色，即c要转化为1<<(c-1)
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
    	node.col = c;
    	node.mark = c;
    	return;
	}
	if (node.mark != 0)
	    passDown(idx);

	int nmid = (node.l + node.r) >> 1;
	if (l <= nmid)
	    update(idx << 1, l, r, c);
	if (r > nmid)
	    update((idx << 1) | 1, l, r, c);
	gatherUp(idx);
	return;
}
int query(int idx, int l, int r)
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
    	return node.col;
	}
	if (node.mark != 0)
	    passDown(idx);

	int res = 0;
	int nmid = (node.l + node.r) >> 1;
	if (l <= nmid)
	    res = res | query(idx << 1, l, r);
	if (r > nmid)
	    res = res | query((idx << 1) | 1, l, r);   // 查询结果需要合并
	return res;
}
```

### 例题 2：区间修改（异或），区间求和（XOR on Segment, [CF242E](https://codeforces.com/contest/242/problem/E)|[洛谷](https://www.luogu.com.cn/problem/CF242E)）

_温馨提醒：由于 CodeForces API 变动，洛谷上暂时不能提交 CodeForces 的远程测评（Remote OJ），需要提交可以去官网原题。_

> **题目大意**：给定 $n$ 个数的序列 $a$，处理 $m$ 次操作，操作分两种：
>
> 1. `1 l r`：求 $a_l$ 到 $a_r$ 区间的所有数的和；
> 2. `2 l r x`：把 $a_l$ 到 $a_r$ 区间内的每个数都与 $x$ 异或，将结果覆盖原来的数。
>
> 输入 $n,m$，一行 $n$ 个数组成的序列 $a$，以及 $m$ 个操作（每个一行）；对于每一种操作 1 输出其对应结果，一个结果占一行。输入输出样例见原题。
> 数据范围：$1 \leq n \leq 10^5,\ 1 \leq m \leq 5 \times 10^4,\ 0 \leq a_i \leq 10^6,\ 1 \leq x \leq 10^6$。

## 线段树变种
