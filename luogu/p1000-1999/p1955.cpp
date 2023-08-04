#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int>::iterator iter;
const int MAXN = 200005;

struct Edge
{
    int a,b;
};

vector<Edge> eq,neq;
vector<int> arr;
int bcj[MAXN];
int n;

inline int bcjGetFa(int x)
{
    if(bcj[x]==x) return x;
    else return bcj[x]=bcjGetFa(bcj[x]);
}
inline void bcjMerge(int a,int b)
{
    bcj[bcjGetFa(a)]=bcjGetFa(b);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        eq.clear(),neq.clear(),arr.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            Edge e;
            int t;
            scanf("%d %d %d",&e.a,&e.b,&t);
            if(t==1) eq.push_back(e);
            else neq.push_back(e);
            arr.push_back(e.a),arr.push_back(e.b);
        }
        sort(arr.begin(),arr.end());
        iter newEnd = unique(arr.begin(),arr.end());
        int tot=newEnd-arr.begin();
        for(int i=0,len=eq.size();i<len;i++)
        {
            eq[i].a=lower_bound(arr.begin(),newEnd,eq[i].a)-arr.begin();
            eq[i].b=lower_bound(arr.begin(),newEnd,eq[i].b)-arr.begin();
        }
        for(int i=0,len=neq.size();i<len;i++)
        {
            neq[i].a=lower_bound(arr.begin(),newEnd,neq[i].a)-arr.begin();
            neq[i].b=lower_bound(arr.begin(),newEnd,neq[i].b)-arr.begin();
        }
        for(int i=0;i<=tot;i++) bcj[i]=i;
        for(int i=0,len=eq.size();i<len;i++)
        {
            bcjMerge(eq[i].a,eq[i].b);
        }
        bool flag=false;
        for(int i=0,len=neq.size();i<len;i++)
        {
            if(bcjGetFa(neq[i].a)==bcjGetFa(neq[i].b))
            {
                flag=true;
                break;
            }
        }
        printf(flag?"NO\n":"YES\n");
    }    
    return 0;
}
