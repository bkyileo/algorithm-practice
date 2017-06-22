#include<bits/stdc++.h>
using namespace std;
void slove()
{
	int n,k;
	cin>>n>>k;
	vector<long long> arr(n);
	for(int i=0;i<n;++i)cin>>arr[i];
	sort(arr.begin(),arr.end());
	if(2*k>n)k=n-k;
	int tp=(n-2*k)/2;
	vector<long long> num1;
	vector<long long> num2;
	int ct=0;
	for(int i=0;i<n;++i)
	{
		if(i<tp||i>=2*k+tp)
		{
			num1.push_back(arr[i]);
		}
		else
		{
			if(i%2==0)
			{
				num1.push_back(arr[i]);
			}
			else
			{
				num2.push_back(arr[i]);	
			}
		}
	}
	//cout<<num1.size()<<" "<<num2.size()<<endl; 
	long long res=0;
	for(int i=0;i<num1.size();++i)
	{
		for(int j=0;j<num2.size();++j)
		{
			res+=abs(num1[i]-num2[j]);
		}
	}
	cout<<res<<endl;
}
int main()
{
	slove();
	return 0;
} 
