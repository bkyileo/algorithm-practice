#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k;
	cin>>n>>k;
	//when it lower than 3 
	if(n==1)
	{
		long long a;
		int res=0;
		cin>>a;
		if(a<=k)res++;
		cout<<res<<endl;
		return 0;
	}
	if(n==2)
	{
		long long a,b;
		int res=0;
		cin>>a>>b;
		if(a<=k)res++;
		if(b<=k)res++;
		if(log(a)+log(b)<=log(k))res++;
		cout<<res<<endl;
		return 0;
	}
	vector<float>arr(n);
	float target=log10(k);
	for(int i=0;i<n;++i)
	{
		long long curr;
		cin>>curr;
		arr[i]=log10(curr);
	}
	sort(arr.begin(),arr.end());
	vector<float> tp1(pow(2,n/3),0.0);
	vector<float> tp2(pow(2,n/3),0.0);
	vector<float> tp3(pow(2,n-2*n/3),0.0);
	for(int i=0;i<pow(2,n/3);++i)
	{
		for(int j=0;j<n/3;++j) 
			if(i&(1<<j))tp1[i]+=arr[j];
	} 
	for(int i=0;i<pow(2,n/3);++i)
	{
		for(int j=0;j<n/3;++j) 
			if(i&(1<<j))tp2[i]+=arr[n/3+j];
	}
	for(int i=0;i<pow(2,n-2*n/3);++i)
	{
		for(int j=0;j<n-2*n/3;++j) 
			if(i&(1<<j))tp3[i]+=arr[2*n/3+j];
	}
	//for(auto i:tp1)cout<<i<<" ";cout<<endl;
	//for(auto i:tp2)cout<<i<<" ";cout<<endl;
	//for(auto i:tp3)cout<<i<<" ";cout<<endl;
	long long res=-1;
	sort(tp3.begin(),tp3.end());
	//cout<<"target : "<<target<<endl;
	for(int i=0;i<tp1.size();++i)
	{
		for(int j=0;j<tp2.size();++j)
		{
			res+=upper_bound(tp3.begin(),tp3.end(),target-tp1[i]-tp2[j])-tp3.begin();
		}
	}
	cout<<res<<endl;
	
	
} 
