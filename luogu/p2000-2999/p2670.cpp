/*
//----^^ACCEPTED^^----//
*/
#include <bits/stdc++.h>
using namespace std;

char gameMap[102][102];
int n, m;
const int surround[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool isGoodPos(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    else
        return true;
}
bool isBomb(int x, int y)
{
    return isGoodPos(x, y) && gameMap[x][y] == '*';
}

int main()
{
    // input
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            gameMap[i][j] = str[j];
        }
    }

    // solve
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (gameMap[x][y] == '*')
                continue;
            int count = 0;
            for (int i = 0; i < 8; i++)
            {
                if (isBomb(x + surround[i][0], y + surround[i][1]))
                    count++;
            }
            gameMap[x][y] = count + '0';
        }
    }

    // output
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            printf("%c", gameMap[x][y]);
        }
        printf("\n");
    }

    return 0;
}
