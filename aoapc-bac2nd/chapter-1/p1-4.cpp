#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    float arc = n/180.0*M_PI;
    printf("sin(n)=%.3f\ncos(n)=%.3f\n",sin(arc),cos(arc));
    return 0;
}
