#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000006;

char str[MAXN],pat[MAXN];
int brd[MAXN];
int len1,len2;

int main()
{
    scanf("%s %s",str+1,pat+1);
    len1=strlen(str+1),len2=strlen(pat+1);
    int j=0;
    for(int i=2;i<=len2;i++)
    {
        while(j!=0 && pat[i]!=pat[j+1]) j=brd[j];
        if(pat[j+1]==pat[i]) j++;
        brd[i]=j;
    }
    j=0;
    for(int i=1;i<=len1;i++)
    {
        while(j!=0 && pat[j+1]!=str[i]) j=brd[j];
        if(pat[j+1]==str[i]) j++;
        if(j==len2) printf("%d\n",i-len2+1),j=brd[j];
    }

    for(int i=1;i<=len2;i++) printf("%d ",brd[i]);
    printf("\n");
    return 0;
}
