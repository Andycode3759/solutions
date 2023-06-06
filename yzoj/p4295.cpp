// AC
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 10004;

struct Node
{
    int lc = -1, rc = -1;
};
Node ctree[MAXN];

stack<int> st;
vector<int> seq;
queue<int> Q;
int arr[MAXN];
int n;

int main()
{
    arr[0] = -999;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }

    st.push(0);
    for (int i = 1; i <= n; i++)
    {
        int j = -1, f;
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            j = st.top();
            st.pop();
        }
        f = st.top();

        ctree[f].rc = i;
        if (j != -1 && j != f)
        {
            ctree[i].lc = j;
        }
        st.push(i);
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     printf("ctree[%d]: lc=%d rc=%d\n", i, ctree[i].lc, ctree[i].rc);
    // }

    Q.push(0);
    while (!Q.empty())
    {
        int f = Q.front();
        seq.push_back(f);
        Q.pop();
        if (ctree[f].lc != -1)
            Q.push(ctree[f].lc);
        if (ctree[f].rc != -1)
            Q.push(ctree[f].rc);
    }
    for (int i = 1; i < seq.size(); i++)
    {
        printf("%d ", arr[seq[i]]);
    }
    printf("\n");
    return 0;
}
