//Median of adjacent maximum numbers
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int num;cin>>num;
		vector<int> arr(num*2);
		for(int i=0;i<num*2;++i)cin>>arr[i];
		sort(arr.begin(),arr.end());
		cout<<arr[num+num/2]<<endl;
		for(int i=0;i<num;++i)
		{
			cout<<arr[i]<<" "<<arr[num+i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

