#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a+b>c && a+c>b && b+c>a) //Is a triangle
    {
        int a2=a*a,b2=b*b,c2=c*c;
        if(a2+b2==c2 || a2+c2==b2 || b2+c2==a2) //Is a right triangle
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    else
    {
        printf("not a triangle\n");
    }
    return 0;
}
