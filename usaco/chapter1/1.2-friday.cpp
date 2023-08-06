/*
ID: andycod1
TASK: friday
LANG: C++14
*/
#include <cstdio>
using namespace std;
const int DAYS[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int n;
int cnt[9];
int d=12;

void doYear(int y)
{
    bool leap;
    if(y%4!=0) leap=false;
    else
    {
        if(y%400==0) leap=true;
        else
        {
            if(y%100==0) leap=false;
            else leap=true;
        }
    }
    for(int i=1;i<=12;i++)
    {
        d=d%7;
        cnt[d+1]++;
        d+=DAYS[i];
        if(i==2&&leap) d++;
    }
}

int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        doYear(1899+i);
    }

    printf("%d %d ",cnt[6],cnt[7]);
    for(int i=1;i<=4;i++) printf("%d ",cnt[i]);
    printf("%d",cnt[5]);
    printf("\n");
    return 0;
}
