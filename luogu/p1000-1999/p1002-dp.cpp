/*
//----^^ACCEPTED^^----//
*/
#include <bits/stdc++.h>
using namespace std;

long long loca[25][25]; // loca[x][y] => paths count from (0,0) to (x,y)
int m, n;
int controlPoints[9][2];
const int ctrlPointDelta[9][2] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {0, 0}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void calculateCtrlPoints(int horseX, int horseY)
{
    for (int i = 0; i < 9; i++)
    {
        controlPoints[i][0] = horseX + ctrlPointDelta[i][0];
        controlPoints[i][1] = horseY + ctrlPointDelta[i][1];
    }
}

void initLoca()
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            loca[j][i] = -1; //-1 means unknown
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (controlPoints[i][0] >= 0 && controlPoints[i][1] >= 0)
            loca[controlPoints[i][0]][controlPoints[i][1]] = 0;
    }
    loca[0][0] = 1;
}

long long getLoca(int x, int y)
{
    if (x < 0 || y < 0 || x > n || y > m)
        return 0;
    if (loca[x][y] == -1)
    {
        loca[x][y] = getLoca(x - 1, y) + getLoca(x, y - 1);
    }
    // printf("loca[%d][%d]=%d\n", x, y, loca[x][y]);
    return loca[x][y];
}

int main()
{
    int hx, hy;
    scanf("%d%d%d%d", &n, &m, &hx, &hy);
    calculateCtrlPoints(hx, hy);
    initLoca();
    cout << getLoca(n, m) << endl;
    return 0;
}