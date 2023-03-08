// AC
#include <bits/stdc++.h>
using namespace std;

typedef list<int>::iterator li;

list<int> s;
bool removed[100002];
li pos[100002];

int main()
{
    int n, m;
    scanf("%d", &n);
    s.push_back(1);
    pos[1] = s.begin();
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        scanf("%d%d", &k, &p);
        li x = pos[k];
        if (p)
            x++;
        pos[i] = s.insert(x, i);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int input;
        scanf("%d", &input);
        removed[input] = true;
    }
    for (li i = s.begin(); i != s.end(); i++)
    {
        if (!removed[*i])
            printf("%d ", *i);
    }
    printf("\n");
    return 0;
}
