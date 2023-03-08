// AC
#include <bits/stdc++.h>
#define DEBUG_ON false
#define deb(x)    \
    if (DEBUG_ON) \
    {             \
        x;        \
    }
using namespace std;

// #define int long lon
long long dp[21][21];
bool book[21][21] = {0}; // book[x][y] => (x,y) passed
int n, m;                // destination
int controlPoints[9][2];
const int ctrlPointDelta[9][2] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {0, 0}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
int answer = 0;
const int dir[2][2] = {{1, 0}, {0, 1}};

void calculateCtrlPoints(int horseX, int horseY)
{
    for (int i = 0; i < 9; i++)
    {
        controlPoints[i][0] = horseX + ctrlPointDelta[i][0];
        controlPoints[i][1] = horseY + ctrlPointDelta[i][1];
    }
}

bool isGoodPoint(int x, int y)
{
    if (book[x][y])
        return false;
    if (x < 0 || y < 0 || x > n || y > m)
        return false;
    for (int i = 0; i < 9; i++)
    {
        if (controlPoints[i][0] == x && controlPoints[i][1] == y)
            return false;
    }
    return true;
}

long long dfs(int x, int y)
{
    deb(printf("x=%d y=%d\n", x, y));
    if (dp[x][y] != 0)
        return dp[x][y];
    if (x == n && y == m)
        return dp[x][y] = 1;
    long long ret = 0;
    for (int i = 0; i < 2; i++)
    {
        int nx, ny;
        deb(printf("dir=%d\n", i));
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if (isGoodPoint(nx, ny))
        {
            book[nx][ny] = true;
            ret += dfs(nx, ny);
            book[nx][ny] = false;
        }
        else
        {
            deb(printf("Not good\n"));
        }
    }
    return dp[x][y] = ret;
}

int main()
{
    int hx, hy;
    scanf("%d%d%d%d", &n, &m, &hx, &hy);
    calculateCtrlPoints(hx, hy);
    deb(for (int i = 0; i < 9; i++) { printf("%d %d\n", controlPoints[i][0], controlPoints[i][1]); });
    cout << dfs(0, 0) << endl;

    // DFS
}

/*

dfs(x,y)
{
    if(x==n,y==m)
    {
        answer++;
        return;
    }
    for(dir to be right or down)
    {
        x=go dir x;
        y=go dir y;
        if(isGoodPoint(x,y))
        {
            book[x][y]=true;
            dfs(x,y);
            book[x][y]=false;
        }
    }
    return;
}

*/