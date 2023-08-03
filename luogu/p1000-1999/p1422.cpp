#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int t1,t2,t3;
    t1=min(150,n);
    n-=t1;
    t2=min(250,n);
    n-=t2;
    t3=n;
    double fee=t1*0.4463+t2*0.4663+t3*0.5663;
    printf("%.1lf\n",fee);
    return 0;
}