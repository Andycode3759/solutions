#include <bits/stdc++.h>
#define EMPTY_STACK -2147483648
using namespace std;

char exprs[55];
int memStack[55];
int stackTop = 0;
const char NumChar[] = "0123456789";

void push(int n)
{
    memStack[stackTop] = n;
    stackTop++;
}
int pop()
{
    if (stackTop == 0)
        return EMPTY_STACK;
    stackTop--;
    return memStack[stackTop];
}
int *getTop()
{
    if (stackTop == 0)
        return NULL;
    return &memStack[stackTop - 1];
}
bool isNum(char c)
{
    for (int i = 0; i < 10; i++)
    {
        if (NumChar[i] == c)
            return true;
    }
    return false;
}

int main()
{
    scanf("%s", exprs);
    int len = strlen(exprs);
    bool ended = false;
    int numCache = 0;
    for (int i = 0; i < len; i++)
    {
        char ec = exprs[i];

        switch (ec)
        {
        case '.': // num end
            push(numCache);
            numCache = 0;
            break;
        case '@': // end
            ended = true;
            break;
        default: // num or operation
            if (isNum(ec))
            {
                numCache *= 10;
                numCache += ec - '0';
            }
            else // then it must be an operation
            {
                int o = pop();
                switch (ec)
                {
                case '+':
                    *(getTop()) += o;
                    break;
                case '-':
                    *(getTop()) -= o;
                    break;
                case '*':
                    *(getTop()) *= o;
                    break;
                case '/':
                    *(getTop()) /= o;
                    break;
                }
            }
            break;
        }
        if (ended)
            break;
    }
    printf("%d\n", memStack[0]);
    return 0;
}
