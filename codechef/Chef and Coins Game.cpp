//Chef and Coins Game
#include<bits/stdc++.h>
using namespace std;
#define N 101
bool a[N];
int main()
{
	/*
	a[1]=true;a[2]=true;a[3]=true;
	a[4]=true;a[5]=true;a[6]=false;
	for(int i=7;i<101;++i)
	{
		bool flag=true;
		for(int j=2;j<sqrt(i);++j)
		{
			if(i%j==0)
				flag=false;
		}
		if(flag==true)a[i]=true;
		else
		{
			a[i]=a[i-6];
		}
	}
	for(int i=1;i<=100;++i)
	cout<<a[i]<<" ";
	*/
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n%6==0)
		cout<<"Misha"<<endl;
		else
		cout<<"Chef"<<endl;
	}
	return 0;
}
