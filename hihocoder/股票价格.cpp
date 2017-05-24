#include<bits/stdc++.h>
using namespace std;
//hihocoder ¹ÉÆ±¼Û¸ñ
struct stock
{
	int time;
	int price;
	stock(int a,int b):time(a),price(b){
	}		
};
struct cheap
{
	bool operator()(stock a,stock b)
	{
		return a.price>b.price;		
	}
};
struct dear
{
	bool operator()(stock a,stock b)
	{
		return a.price<b.price;		
	}
};
int main()
{
	priority_queue<stock,vector<stock>,cheap> cheaps;
	priority_queue<stock,vector<stock>,dear> dears;
	
	int m;
	cin>>m;
	char order;
	int t,p;
	
	int lastPrice,rmTime;
	rmTime=0;
	while(m--)
	{
		cin>>order;
		if(order=='R')
		{
			int temp;
			cin>>temp;
			rmTime=temp;
		}
		if(order=='P')
		{
			int a,b;
			cin>>a>>b;
			cheaps.push(stock(a,b));
			dears.push(stock(a,b));
			lastPrice=b;
		}
		if(order=='Q')
		{
			while(dears.top().time<=rmTime)
			{
				dears.pop();
			}
			while(cheaps.top().time<=rmTime)
			{
				cheaps.pop();
			}
			cout<<dears.top().price<<" "<<cheaps.top().price<<" "<<lastPrice<<endl;
		}
	}
	return 0;
}
