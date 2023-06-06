#include <cstdio>
using namespace std;
const int MAXN = 500005;

int tb[MAXN], nums[MAXN];
int n, m;

int lowbit(int x)
{
    return x & (-x);
}

void printNums()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%4d", tb[i]);
    }
    printf("\n");
}

void add(int pos, int dlt) // 将nums[pos]加上dlt
{
    while (pos <= n)
    {
        tb[pos] += dlt;
        pos += lowbit(pos);
    }
}

void addRange(int r, int dlt) // 将[1,r]加上dlt
{
    printf("addRange(%d, %d):\n", r, dlt);

    while (r > 0)
    {
        tb[r] += dlt * lowbit(r);
        r -= lowbit(r);
    }

    printNums();
}

int getSum(int pos) // 获取[1,pos]的和
{
    int res = 0;
    while (pos > 0)
    {
        res += tb[pos];
        pos -= lowbit(pos);
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", nums + i);
        add(i, nums[i]);
    }

    printNums();

    while (m--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            addRange(r, k);
            addRange(l - 1, -k);
        }
        else if (op == 2)
        {
            int l;
            scanf("%d", &l);
            printf("%d\n", getSum(l) - getSum(l - 1));
        }
    }
    return 0;
}
