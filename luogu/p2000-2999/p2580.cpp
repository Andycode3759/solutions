#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 500005;

int trie[28][MAXN], cnt;
int exist[MAXN];

void insert(char *str, int len)
{
    int p = 0;
    for (int i = 0; i < len; i++)
    {
        int c = str[i] - 'a';
        if (trie[c][p] == 0)
            trie[c][p] = ++cnt;
        p = trie[c][p];
    }
    exist[p] = 1;
}
int find(char *str, int len)
{
    int p = 0;
    for (int i = 0; i < len; i++)
    {
        int c = str[i] - 'a';
        if (trie[c][p] == 0)
            return 0;
        p = trie[c][p];
    }
    return exist[p]++;
}

char input[55];
int n, m;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", input);
        insert(input, strlen(input));
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", input);
        int res = find(input, strlen(input));
        if (res == 0)
            printf("WRONG\n");
        else if (res == 1)
            printf("OK\n");
        else if (res >= 2)
            printf("REPEAT\n");
    }
    return 0;
}