//hihocoder 扩展二进制数
#include<bits/stdc++.h>
//80
using namespace std;
vector<int> arr; 
void dfs(int index,int curr,int &res,vector<int> h)
{
	if(curr==0)
	{
		//for(auto i:h)cout<<i<<" ";cout<<endl;
		res++;
		return ;
	}
	if(index<0)
	{
		return ;
	}
	if(curr<0)
	{
		return ;
	}
	if((long long)curr>(long long)4*arr[index])
	{
		return ;
	}
	else
	{
		for(int i=0;i<3;++i)
		{
			//h.push_back(i);
			dfs(index-1,curr-i*arr[index],res,h);
			//h.pop_back();
		}
	}
}
int main()
{
	int i=0;
	while( (1<<i)<=1000000000 )
	{
		arr.push_back(1<<i);
		++i;
	}
	arr.push_back(1<<i);
	//while(1)
	//{ 
	int n;
	cin>>n;
	int temp=1;
	int index=0;
	while(temp<n)
	{
		temp*=2;
		index++;
	}
	int res=0;
	vector<int> h;
	dfs(index,n,res,h);
	cout<<res<<endl;
	//}
	return 0;
	//999999999
	//1000000000
} 
