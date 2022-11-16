/*
//----!!BAD SOLUTION!!----//
    Reason:
        答案错误
    Input:
        6 6 3 3
    Output:
        1
    Supposed to be:
        6
*/
#include <bits/stdc++.h>
using namespace std;
int controlPoints[9][2];
int ctrlPointDelta[9][2] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {0, 0}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, -1}};
int destX, destY, horseX, horseY;
int answer = 0;
struct Node
{
    int x;
    int y;
    int step;
};
vector<Node> book;

bool isValidPos(int x, int y)
{
    if (x < 0 || y < 0 || x > destX || y > destY) //meaningful
    {
        return false;
    }
    for (int i = 0; i < 9; i++) //not control point
    {
        if (controlPoints[i][0] == x && controlPoints[i][1] == y)
        {
            return false;
        }
    }
    for (int i = 0; i < book.size(); i++) //not exist
    {
        if (book[i].x == x && book[i].y == y)
        {
            return false;
        }
    }
    return true;
}

void bfs(int head, int step)
{
    if (head == book.size()) //queue is empty
    {
        return;
    }
    if (book[head].x == destX && book[head].y == destY)
    {
        answer++;
        bfs(head + 1, step + 1);
        return;
    }
    Node down, right;
    down = book[head];
    right = book[head];
    down.x++;
    right.y++;
    down.step++;
    right.step++;
    if (isValidPos(right.x, right.y))
    {
        book.push_back(right);
    }
    if (isValidPos(down.x, down.y))
    {
        book.push_back(down);
    }
    bfs(head + 1, step + 1);
    return;
}

int main()
{
    cin >> destX >> destY >> horseX >> horseY;
    for (int i = 0; i < 9; i++)
    {
        controlPoints[i][0] = horseX + ctrlPointDelta[i][0];
        controlPoints[i][1] = horseY + ctrlPointDelta[i][1];
    }
    Node n;
    n.x = 0;
    n.y = 0;
    n.step = 0;
    book.push_back(n);
    bfs(0, 0);
    cout << answer << endl;
    return 0;
}