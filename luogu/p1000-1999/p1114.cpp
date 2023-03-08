// AC
#include <bits/stdc++.h>
using namespace std;

// bool seq[100002];
int prefSum[100002];
map<int, int> hashleft;  //某元素最早出现的位置
map<int, int> hashright; //某元素最后出现的位置
set<int> exists;         //出现过的元素

int conv(int n)
{
    return n == 1 ? 1 : -1; // 1=male,-1=female
}

void showPrefSum(int n) // debug
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", prefSum[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    int answer = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        if (i == 0) // first person
        {
            prefSum[0] = conv(s);
        }
        else
        {
            prefSum[i] = prefSum[i - 1] + conv(s);
        }
        exists.insert(prefSum[i]);
        if (prefSum[i] == 0)
            answer = i + 1;
    }

    //showPrefSum(n);

    for (int i = 0; i < n; i++)
    {
        int s = prefSum[i];
        if (!hashleft.count(s)) // not found
        {
            hashleft[s] = i;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int s = prefSum[i];
        if (!hashright.count(s)) // not found
        {
            hashright[s] = i;
        }
    }

    for (set<int>::iterator i = exists.begin(); i != exists.end(); i++)
    {
        int result = hashright[*i] - hashleft[*i];
        if (result > answer)
            answer = result;
    }

    printf("%d\n", answer);

    return 0;
}
