#include<bits/stdc++.h>
using namespace std;

float combine(int a,int b)
{
	//组合数 a>b 
	float res=1.0;
	for(int i=a;i>a-b;--i)
		res*=i;
	for(int i=b;i>1;--i)
		res/=i;
	return res;
} 

int main()
{
	while(1)
	{ 
	int x,y;
	cin>>x>>y;
	//x为胜利 y为失败 

	float res=0;
	for(int i=0;i<y;++i)
	{
		//cout<<x<<" "<<pow(0.5,i+x)<<" "<<combine(i+x-1,i)<<endl;
		res += x*combine(i+x-1,i)*pow(0.5,i+x);
	}
	
	for(int i=0;i<x;++i)
	{
		//cout<<i<<" "<<pow(0.5,i+y)<<" "<<combine(i+y-1,i)<<endl;
		res += i*combine(i+y-1,i)*pow(0.5,i+y);
	}
	
	cout<<res<<endl;
	} 
}
