#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10000007;
int phonenum[MAXN];
int mapping[128];

int main()
{

    mapping[(int)'A']=2;
    mapping[(int)'B']=2;
    mapping[(int)'C']=2;
    mapping[(int)'D']=3;
    mapping[(int)'E']=3;
    mapping[(int)'F']=3;
    mapping[(int)'G']=4;
    mapping[(int)'H']=4;
    mapping[(int)'I']=4;
    mapping[(int)'J']=5;
    mapping[(int)'K']=5;
    mapping[(int)'L']=5;
    mapping[(int)'M']=6;
    mapping[(int)'N']=6;
    mapping[(int)'O']=6;
    mapping[(int)'P']=7;
    mapping[(int)'R']=7;
    mapping[(int)'S']=7;
    mapping[(int)'T']=8;
    mapping[(int)'U']=8;
    mapping[(int)'V']=8;
    mapping[(int)'W']=9;
    mapping[(int)'X']=9;
    mapping[(int)'Y']=9;

    int n;
    scanf("%d",&n);
    ios::sync_with_stdio(false);
    for(int i=0;i<n;i++)
    {
        string rawpn;
        int realpn=0;
        cin>>rawpn;
        for(int d=0;d<rawpn.size();d++)
        {
            if(rawpn[d]=='-') continue;
            if(rawpn[d]>='0'&&rawpn[d]<='9')
            {
                realpn*=10;
                realpn+=rawpn[d]-'0';
            }
            else //letters
            {
                realpn*=10;
                realpn+=mapping[(int)rawpn[d]];
            }
        }
        phonenum[realpn]++;
    }
    bool flag=true;
    for(int i=0;i<MAXN;i++)
    {
        if(phonenum[i]>1)
        {
            flag=false;
            printf("%03d-%04d %d\n",i/10000,i%10000,phonenum[i]);
        }
    }
    if(flag)
    {
        printf("No duplicates.\n");
    }
    return 0;
}
