#include<bits/stdc++.h>
using namespace std;
int maxRotateFunction(vector<int>& A) {
	int n=A.size();
	int sum=0;
	for(int i=0;i<n;++i)
	{
		sum+=A[i];	
	}
	int res=0;
	for(int i=0;i<n;++i)res+=i*A[i];
	int curr=res;
	for(int i=0;i<n;++i)
	{
		curr=(curr+sum-n*A[n-1-i]);
		res=max(res,curr);
	}
	return res;
} 
int main()
{
	vector<int> arr={4,3,2,6};
	cout<<maxRotateFunction(arr)<<endl;
	
}
