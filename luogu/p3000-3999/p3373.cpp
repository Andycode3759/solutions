#include <cstdio>
using namespace std;
const int MAXN = 100005;

int n,q,m;
int arr[MAXN];

struct SegTreeNode
{
    long long sum;
    long long tagAdd,tagMult;
};
SegTreeNode st[MAXN*4];

void build(int idx,int l,int r)
{
    SegTreeNode &cur=st[idx];
    cur.tagAdd=0;
    cur.tagMult=1;
    if(l==r)
    {
        cur.sum=arr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build((idx<<1)|1,mid+1,r);
    cur.sum=(st[idx<<1].sum+st[(idx<<1)|1].sum)%m;
}
void passDown(int idx,int l,int r)
{
    SegTreeNode &cur=st[idx];
    SegTreeNode &ln=st[idx<<1],&rn=st[(idx<<1)|1];
    int mid=(l+r)>>1;
    ln.sum=(ln.sum*cur.tagMult+(mid-l+1)*cur.tagAdd)%m;
    rn.sum=(rn.sum*cur.tagMult+(r-mid)*cur.tagAdd)%m;
    ln.tagMult=(ln.tagMult*cur.tagMult)%m;
    rn.tagMult=(rn.tagMult*cur.tagMult)%m;
    ln.tagAdd=(ln.tagAdd*cur.tagMult+cur.tagAdd)%m;
    rn.tagAdd=(rn.tagAdd*cur.tagMult+cur.tagAdd)%m;
    cur.tagAdd=0;
    cur.tagMult=1;
}
void gatherUp(int idx)
{
    SegTreeNode &cur=st[idx];
    cur.sum=(st[idx<<1].sum+st[(idx<<1)|1].sum)%m;
}
void modifyAdd(int idx,int ql,int qr,int l,int r,int dlt)
{
    SegTreeNode &cur=st[idx];
    if(ql<=l&&r<=qr)
    {
        cur.sum=(cur.sum+(r-l+1)*dlt)%m;
        cur.tagAdd+=dlt;
        return;
    }
    passDown(idx,l,r);
    int mid=(l+r)>>1;
    if(ql<=mid) modifyAdd(idx<<1,ql,qr,l,mid,dlt);
    if(qr>mid) modifyAdd((idx<<1)|1,ql,qr,mid+1,r,dlt);
    gatherUp(idx);
}
void modifyMult(int idx,int ql,int qr,int l,int r,int dlt)
{
    SegTreeNode &cur=st[idx];
    if(ql<=l&&r<=qr)
    {
        cur.sum=(cur.sum*dlt)%m;
        cur.tagMult=(cur.tagMult*dlt)%m;
        cur.tagAdd=(cur.tagAdd*dlt)%m;
        return;
    }
    passDown(idx,l,r);
    int mid=(l+r)>>1;
    if(ql<=mid) modifyMult(idx<<1,ql,qr,l,mid,dlt);
    if(qr>mid) modifyMult((idx<<1)|1,ql,qr,mid+1,r,dlt);
    gatherUp(idx);
}
long long query(int idx,int ql,int qr,int l,int r)
{
    SegTreeNode &cur=st[idx];
    if(ql<=l&&r<=qr)
    {
        return cur.sum;
    }
    passDown(idx,l,r);
    int mid=(l+r)>>1;
    int res=0;
    if(ql<=mid) res=(res+query(idx<<1,ql,qr,l,mid))%m;
    if(qr>mid) res=(res+query((idx<<1)|1,ql,qr,mid+1,r))%m;
    return res;
}

int main()
{
    scanf("%d %d %d",&n,&q,&m);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);
    build(1,1,n);
    while(q--)
    {
        int op;
        int x,y,k;
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            scanf("%d %d %d",&x,&y,&k);
            modifyMult(1,x,y,1,n,k);
            break;
        case 2:
            scanf("%d %d %d",&x,&y,&k);
            modifyAdd(1,x,y,1,n,k);
            break;
        case 3:
            scanf("%d %d",&x,&y);
            printf("%lld\n",query(1,x,y,1,n));
            break;
        }
    }
    return 0;
}
