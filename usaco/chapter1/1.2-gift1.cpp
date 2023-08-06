/*
ID: andycod1
TASK: gift1
LANG: C++14
*/
#include <cstdio>
#include <string>
#include <map>
using namespace std;

map<string,int> account;
string pers[12];
int n;

char input[20];

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",input);
        pers[i]=string(input);
        account[pers[i]]=0;
    }
    while(scanf("%s",input)>0)
    {
        int m,p;
        scanf("%d %d",&m,&p);
        if(p==0) continue;
        int g=m/p;
        string giver(input);
        account[giver]+=m%p-m;
        for(int i=1;i<=p;i++)
        {
            scanf("%s",input);
            string rec(input);
            account[rec]+=g;
        }
    }

    for(int i=1;i<=n;i++)
    {
        printf("%s %d\n",pers[i].c_str(),account[pers[i]]);
    }
    return 0;
}
