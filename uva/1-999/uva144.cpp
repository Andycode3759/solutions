/*
 * ACCEPTED
 * Time:4 ms
    Memory:1440 kb
 * */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	int nowOutput;
	int store=0;
	int kase=1;
	int studentCount;
	queue<int> Q;
	int card[30]={0}; //card[i] => i号学生卡里的钱
	while(scanf("%d%d",&studentCount,&k)==2&&studentCount!=0&&k!=0)
	{
		//printf("Case %d: ",kase);
		while(!Q.empty()) Q.pop(); //clear
		for(int i=1;i<=studentCount;i++) //init Q and card
			{card[i]=0;Q.push(i);}
		nowOutput=1;
		store=0;
		for(;;)
		{
			if(nowOutput>k) nowOutput=1;
			store+=nowOutput;
			while(store>0&&!Q.empty())
			{
				int front = Q.front();
				Q.pop();
				//bool isFull = false;
				//collect
				card[front]+=store;
				store=0;
				if(card[front]>40)
				{
					store=card[front]-40;
					card[front]=40;
				}
				if(card[front]==40) //is full
				{
					cout << setw(3) << front;
					//printf("%d ",front);
				}
				else
				{
					Q.push(front);
				}
			}
			if(Q.empty()) break;
			nowOutput++;
		}
		printf("\n");
		kase++;
	}
}
/*
 * int k; // nowOutput max
 * int nowOutput;
 * int store;
 * 
 * for(;;nowOutput++)
 * {
 * if(nowOutput>k) nowOutput=1;
 * 
 * store+=nowOutput;
 * while(store>0&&!queue.empty())
 * {
 * student front=queue.pop();
 * bool isFull=front.collect(store);
 * if(isFull) printf(front);
 * else queue.push(front);
 * }
 * }
 * 
 * 
 * 
 * //场宽为3
 * */
