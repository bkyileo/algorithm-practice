// 算法分析 8皇后问题
#include<bits/stdc++.h>
using namespace std;
bool place(vector<int> arr,int curr)
{
	for(int i=0;i<curr;++i)
	{
		if(arr[i]==arr[curr]||abs(arr[curr]-arr[i])==curr-i)
		return false;
	}
	return true;
}
void queues(int num,int curr,vector<int> arr,int &res)
{
	if(curr>=num)
	{
		res++;
		return ;
	}
	else
	{
		for(int i=0;i<num;++i)
		{
			arr[curr]=i; 
			if(place(arr,curr))
			{
				queues(num,curr+1,arr,res);
			}
			arr[curr]=0;
		}
	}
		
} 
int main()
{
	int res=0;
	queues(8,0,vector<int>(8,0),res);
	cout<<res<<endl;
	return 0;	
} 
