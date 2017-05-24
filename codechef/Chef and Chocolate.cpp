//codechef Chef and Chocolate
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		long long x,y;
		cin>>x>>y;
		long long res=(x-1)+(y-1)*x;
		if(res%2)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
/*
. . . .
. . . .
. . . .
x=3 y=4
*/
