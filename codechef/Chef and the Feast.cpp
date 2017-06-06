#include<bits/stdc++.h>
using namespace std;
bool com (int i,int j) { return (i>j); }
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		vector<int> arr;
		int ct=0;
		long long sum=0;
		for(int i=0;i<n;++i)
		{
			int curr;cin>>curr;
			if(curr>=0)
			{
				ct++;
				sum+=curr;
			}
			else
			{
				arr.push_back(curr);
			}
		}
		sort(arr.begin(),arr.end(),com);
		long long res = sum * ct;
		for(int i=0;i<arr.size();++i)
		{
			if( res+arr[i] <= (sum+arr[i]) * (ct+1))
			{
				sum = sum+arr[i];
				ct++ ;
				res = sum*ct ;
			}
			else
			{
				for(int j=i;j<arr.size();++j)
					res+=arr[j];	
				break;
			}
		}
		cout<< res <<endl;
	}
	return 0;
} 
/*
1
3
-8 4 -4 
*/
