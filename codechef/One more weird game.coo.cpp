//code chef One more weird game
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int x,y;cin>>x>>y;
		cout<<(x-1)*(y-1)*2+x-1+y-1<<endl;	
	}
} 
/*
0 1 1
1 2 2
1 2 2

2 0 2
0 4 0
2 0 2
*/
