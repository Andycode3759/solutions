/*
 * ACCEPTED
 * Time:29 ms
    Memory:1456 kb
 * */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	list<int> L;
	int n,m;
	int input;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&input);
		L.push_back(input);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&input);
		list<int>::iterator target=L.begin();
		while(target!=L.end()&&*target<=input) target++;
		L.insert(target,input);
	}
	for_each(L.begin(), L.end(), [](const int n) { printf("%d ",n); });

	printf("\n");
	return 0;
}
