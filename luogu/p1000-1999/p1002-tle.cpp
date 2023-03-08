// TLE
#include <bits/stdc++.h>
using namespace std;
int n, m;          // 终点坐标
int ctrlPts[9][2]; // 马及其控制点坐标
int answer = 0;
bool book[21][21] = {0};      // book[x][y] => 当前路径中已经走过了(x,y)
const int CtrlPtDlt[9][2] = { // 控制点相对位置
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {0, 0},
    {-1, 2},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1}};
const int Dir[2][2] = {{0, 1}, {1, 0}}; // 向下走和向右走

void calculateCtrlPts(int horseX, int horseY)
{
    for (int i = 0; i < 9; i++)
    {
        ctrlPts[i][0] = horseX + CtrlPtDlt[i][0];
        ctrlPts[i][1] = horseY + CtrlPtDlt[i][1];
    }
}
bool isGoodPoint(int x, int y) // 利用return的短路特性，避免if-else嵌套，更加简洁
{
    if (book[x][y])
        return false;
    if (x < 0 || y < 0 || x > n || y > m)
        return false;
    for (int i = 0; i < 9; i++)
    {
        if (ctrlPts[i][0] == x && ctrlPts[i][1] == y)
            return false;
    }
    return true;
}
void dfs(int x, int y)
{
    if (x == n && y == m)
    {
        answer++;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int nx, ny;
        nx = x + Dir[i][0];
        ny = y + Dir[i][1];
        if (isGoodPoint(nx, ny))
        {
            book[nx][ny] = true; // 在当前的路径中标记“脚印”
            dfs(nx, ny);
            book[nx][ny] = false; // 收回“脚印”的标记
        }
    }
    return;
}

int main()
{
    int horseX, horseY;
    scanf("%d%d%d%d", &n, &m, &horseX, &horseY);
    calculateCtrlPts(horseX, horseY); // 计算马的控制点
    dfs(0, 0);
    printf("%d\n", answer);
    return 0;
}