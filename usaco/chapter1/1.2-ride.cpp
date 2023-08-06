/*
ID: andycod1
TASK: ride
LANG: C++14
*/
#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 47;

char str1[10],str2[10];
int len1,len2;

int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);

    scanf("%s",str1); len1=strlen(str1);
    scanf("%s",str2); len2=strlen(str2);

    int q1=1,q2=1;
    for(int i=0;i<len1;i++)
    {
        q1=q1*(str1[i]-'A'+1)%MOD;
    }
    for(int i=0;i<len2;i++)
    {
        q2=q2*(str2[i]-'A'+1)%MOD;
    }

    printf(q1==q2?"GO\n":"STAY\n");
    return 0;
}
