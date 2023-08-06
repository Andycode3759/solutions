/*
ID: andycod1
TASK: beads
LANG: C++14
*/
#include <cstdio>
using namespace std;
const int MAXN = 707;

constexpr int max(int a,int b)
{
    return a<b?b:a;
}

int n;
char str[MAXN];

int getAns(int pos)
{
    char lst='w';
    int res=0;
    for(int i=pos;i>=1;i--)
    {
        if(res>=n/2) break;
        if(lst=='w'||str[i]=='w'||str[i]==lst)
        {
            res++;
            if(str[i]!='w') lst=str[i];
        }
        else break;
    }
    lst='w';
    for(int i=pos+1;i<=n;i++)
    {
        if(res>=n/2) break;
        if(lst=='w'||str[i]=='w'||str[i]==lst)
        {
            res++;
            if(str[i]!='w') lst=str[i];
        }
        else break;
    }
    return res;
}

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);

    scanf("%d %s",&n,str+1);
    for(int i=1;i<=n;i++)
    {
        str[i+n]=str[i];
    }
    n*=2;

    int ans=0;
    for(int i=1;i<n;i++)
    {
        int t=getAns(i);
        // printf("%d: %d\n",i,t);
        ans=max(ans,t);
    }

    printf("%d\n",ans);
    return 0;
}
