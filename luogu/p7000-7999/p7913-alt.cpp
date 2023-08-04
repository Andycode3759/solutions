#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct Node
{
    int l,r;
    const bool operator<(const Node &b) const
    {
        return l==b.l? r<b.r: l<b.l;
    }
};

int n,m1,m2;
Node nation[MAXN],glob[MAXN];
int bel1[MAXN],bel2[MAXN];
int lst[MAXN];
int c1,c2;

int main()
{
    scanf("%d %d %d",&n,&m1,&m2);
    for(int i=1;i<=m1;i++)
    {
        scanf("%d %d",&nation[i].l,&nation[i].r);
    }
    sort(nation+1,nation+1+m1);
    for(int i=1;i<=m1;i++)
    {
        Node &cur=nation[i];
        for(int j=1;j<MAXN;j++)
        {
            if(cur.l>=lst[j])
            {
                bel1[j]++;
                lst[j]=cur.r;
                c1=max(c1,j);
                break;
            }
        }
    }
    for(int i=1;i<=n;i++) bel1[i]+=bel1[i-1];

    for(int i=1;i<MAXN;i++) lst[i]=0;

    for(int i=1;i<=m2;i++)
    {
        scanf("%d %d",&glob[i].l,&glob[i].r);
    }
    sort(glob+1,glob+1+m2);
    for(int i=1;i<=m2;i++)
    {
        Node &cur=glob[i];
        for(int j=1;j<MAXN;j++)
        {
            if(cur.l>=lst[j])
            {
                bel2[j]++;
                lst[j]=cur.r;
                c2=max(c2,j);
                break;
            }
        }
    }
    for(int i=1;i<=n;i++) bel2[i]+=bel2[i-1];

    //printf("%d %d\n",c1,c2);

    int ans=0;
    for(int a1=0;a1<=n;a1++)
    {
        int a2=n-a1;
        ans=max(ans,bel1[a1]+bel2[a2]);
    }
    printf("%d\n",ans);
    return 0;
}