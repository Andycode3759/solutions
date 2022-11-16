/*
//----^^ACCEPTED^^----//
    Time:35 ms
    Memory:1448 kb
*/
#include <bits/stdc++.h>
using namespace std;

int floors[202] = {0};
int n;

struct Node
{
    int nowFloor, step;
};

bool isGoodFloor(int f)
{
    if (f <= 0 || f > n)
        return false;
    return true;
}
bool contains(vector<Node> &v, int n)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].nowFloor == n)
            return true;
    }
    return false;
}

int main()
{
    int start, target;
    vector<Node> Q;
    int head = 0;

    // input
    scanf("%d%d%d", &n, &start, &target);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &floors[i]);
    }
    /*
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", floors[i]);
        }
        printf("\n");
    */
    // solve
    Node f;
    f.nowFloor = start;
    f.step = 0;
    Q.push_back(f);
    bool solvable = false;
    while (head < Q.size())
    {
        Node up, down;
        Node &current = Q[head];
        if (current.nowFloor == target)
        {
            printf("%d\n", current.step);
            solvable = true;
            break;
        }
        up.nowFloor = current.nowFloor + floors[current.nowFloor];
        down.nowFloor = current.nowFloor - floors[current.nowFloor];
        up.step = current.step + 1;
        down.step = current.step + 1;
        if (isGoodFloor(up.nowFloor) && !contains(Q, up.nowFloor))
        {
            Q.push_back(up);
        }
        if (isGoodFloor(down.nowFloor) && !contains(Q, down.nowFloor))
        {
            Q.push_back(down);
        }
        head++;
    }

    // output
    if (!solvable)
        printf("-1\n");
    return 0;
}
