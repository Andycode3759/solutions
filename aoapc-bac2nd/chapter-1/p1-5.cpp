#include<bits/stdc++.h>
using namespace std;

int main()
{
    int amount;
    scanf("%d",&amount);
    int price=amount*95;
    if(price>=300)
    {
        printf("%.2f\n",price*0.85);
    }
    else
    {
        printf("%.2f\n",(float)price);
    }
    return 0;
}
