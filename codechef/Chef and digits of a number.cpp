#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
	string s;
	vector<int> arr(2,0);
	cin>>s;
	for(auto i:s)
	{
		if(i=='1')arr[1]++;
		if(i=='0')arr[0]++;
	}
	if(arr[0]==1||arr[1]==1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	}
	return 0;
}
