#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;string name;
		cin>>n>>name;
		vector<int> arr(n);
		for(int i=0;i<n;++i)cin>>arr[i];
		if(n==1&&arr[0]%2==0&&name=="Dee")cout<<"Dee"<<endl;
		else cout<<"Dum"<<endl;
	}
	return 0;
}
/*
2 win
1 2 win
1 2 2 win
2 2 2 win
1 1 1 win
2 2 2 2 win
3 3 3 win
1 2 1 win
*/
