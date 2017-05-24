#include<bits/stdc++.h>
using namespace std;

bool check(int m,int n)
{
	while(1)
	{
		m=m>>1;
		n=n>>1;
		if(n&&!m) return false;
		if(!n&&!m) return true;
	}
}
int find(int m,int n)
{
	int res=0;
	int count=0;
	while(n)
	{
		count++;
		if((n&1)!=(m&1))
		{
			//cout<<(n&1)<<" "<<(m&1)<<endl;
			res=count;
		}
		n=n>>1;
		m=m>>1;
	}	
	return res;
}
int rangeBitwiseAnd(int m, int n) {
    if(!check(m,n)) return 0;
	int count=find(m,n);
	cout<<count;
	n=n>>count;
	n=n<<count;
	return n;
	
}

int main()
{
	cout<<rangeBitwiseAnd(3,3);
	return 0;
}
