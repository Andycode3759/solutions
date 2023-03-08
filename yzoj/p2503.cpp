// TLE
#include <bits/stdc++.h>
using namespace std;
const int inf = 616616616;
int nowMin = inf;
bool book[102][102] = {0}; // book[x][y]表示x,y已走过
const int posiMoves[12][2] = {
    {-2, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-2, 2}, {-1, -2}, {1, -2}, {2, -2}, {2, -1}, {2, 1}, {2, 2}, {1, 2}};

struct Node
{
    int x, y, step;
};
bool isGood(Node n)
{
    if (n.x <= 0 || n.y <= 0 || n.x > 100 || n.y > 100 || book[n.x][n.y])
        return false;
    else
        return true;
}
void solve(Node a) // dfs
{
    if (a.x == 1 && a.y == 1)
    {
        nowMin = min(a.step, nowMin);
        return;
    }
    for (int i = 0; i < 12; i++)
    {
        Node n;
        n.x = a.x + posiMoves[i][0];
        n.y = a.y + posiMoves[i][1];
        n.step = a.step + 1;
        if (isGood(n))
        {
            book[a.x][a.y] = true;
            solve(n);
            book[a.x][a.y] = false;
        }
    }
}
int main()
{
    Node a, b;
    a.step = 0;
    b.step = 0;
    scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
    solve(a);
    printf("%d\n", nowMin);
    book[102][102] = {0};
    nowMin = inf;
    solve(b);
    printf("%d\n", nowMin);
}
