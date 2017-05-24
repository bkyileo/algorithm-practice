// code chef Shortest Path in Binary Trees
#include<bits/stdc++.h>
using namespace std;
/*
1 ¡Ü N ¡Ü 10^5
1 ¡Ü i, j ¡Ü 10^9
*/
void whatis(vector<int> p)
{
	for(auto i:p)
	{
		cout<<i<<" ";
	}
	cout<<endl;
} 
int solve(int a,int b)
{
	vector<int> path;
	//a<b
	if(a>b) swap(a,b);
	while(a)
	{
		path.push_back(a);
		if(a%2)
			a-- ;
		a /=2 ;
	}
	//whatis(path);
	int i=0;
	int res=0;
	while(b != path[i])
	{
		if(b>path[i])
		{
			if(b%2)
				b--;
			b/=2;
			res++;
		}
		if(b<path[i])
		{
			i++;
			res++;
		}
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		cout<<solve(a,b)<<endl;
	}
}

