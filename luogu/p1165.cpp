/*
//----^^ACCEPTED^^----//
*/
#include <bits/stdc++.h>
using namespace std;

// stack<int> boxes;
int boxes[200002];
int top = 0;
int nowMax = -1;

int getMax()
{
    if (top == 0)
        return 0;
    int max = boxes[0];
    for (int i = 1; i < top; i++)
    {
        if (boxes[i] > max)
            max = boxes[i];
    }
    return max;
}
void push(int n)
{
    if (n > nowMax)
        nowMax = n;
    boxes[top] = n;
    top++;
}
void pop()
{
    if (top == 0)
        return;
    top--;
    if (boxes[top] == nowMax)
        nowMax = getMax();
    boxes[top] = 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int ope;
        scanf("%d", &ope);
        switch (ope)
        {
        case 0: // in
            int w;
            scanf("%d", &w);
            push(w);
            break;

        case 1: // out
            pop();
            break;

        case 2: // query
            printf("%d\n", nowMax);
            break;
        }
    }
    return 0;
}
