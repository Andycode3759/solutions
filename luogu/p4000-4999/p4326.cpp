// AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    const double PI = acos(-1.0);
    int r;
    scanf("%d", &r);
    double realR = (double)r;
    printf("%lf\n%lf\n", realR * realR * PI, 2 * realR * realR);
    return 0;
}