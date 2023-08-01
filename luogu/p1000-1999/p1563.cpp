// Unfinished
#include <cstdio>
using namespace std;
const int MAXN = 100005;

struct Person
{
    char name[13];
    int dir;
};
Person persons[MAXN];
int n, m;
int dir, len, cur = 1;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &persons[i].dir);
        scanf("%s", persons[i].name);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &dir, &len);
        dir = (dir ^ persons[cur].dir) * 2 - 1;
        cur += len * dir + n;
        if (cur > n)
            cur -= n;
        // printf("%d\n", cur);
    }
    printf("%s\n", persons[cur].name);
    return 0;
}
