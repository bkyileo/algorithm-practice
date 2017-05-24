//Courses in an university
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int num;cin>>num;
		vector<int> arr(num);
		for(int i=0;i<num;++i)cin>>arr[i];
		sort(arr.begin(),arr.end());
		cout<<num-arr[num-1]<<endl;
	}
	return 0;
}
