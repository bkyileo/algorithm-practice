//code chef CHEFELEC: Chefland and Electricity
#include<bits/stdc++.h>
using namespace std;
void slove(string s,vector<int> arr)
{
	// greedy TLE
	long long res=0;
	set<int> indexs;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='1')	
			indexs.insert(i);
	}
	int dis=INT_MAX;
	int tempIndex=-1;
	while(indexs.size()<arr.size())
	{
		for(auto i:indexs)
		{
			if(i-1>-1&&indexs.find(i-1)==indexs.end())
				if(abs(arr[i-1]-arr[i])<dis)
					{
						tempIndex=i-1;
						dis=abs(arr[i-1]-arr[i]);
					}
			if(i+1<arr.size()&&indexs.find(i+1)==indexs.end())
				if(abs(arr[i+1]-arr[i])<dis)
					{
						tempIndex=i+1;
						dis=abs(arr[i+1]-arr[i]);
					}
		}
		res+=dis;
		indexs.insert(tempIndex);
		dis=INT_MAX;
		tempIndex=-1;
	}
	cout<<res<<endl;
	return ;
	 
}

void slove2(string s,vector<int> arr)
{
	//more greedy
	long long res=0;
	vector<int> temp;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='1')
			temp.push_back(i);
	}
	res+=arr[temp[0]]-arr[0];
	res+=arr[arr.size()-1]-arr[temp[temp.size()-1]];
	for(int i=0;i<temp.size()-1;++i)
	{
		int left=temp[i];
		int right=temp[i+1];
		int count=INT_MIN;
		for(int j=left;j<right;++j)
		{
			count=max(count,(arr[j+1]-arr[j]));
		}
		res = res + (arr[right]-arr[left])-count; 
	}
	cout<<res<<endl;
	return ;
	
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int nums;
		string village;
		cin>>nums;
		cin>>village;
		vector<int> arr(nums);
		for(int i=0;i<nums;++i)
			cin>>arr[i];
		slove2(village,arr);
	}
	return 0;
} 
