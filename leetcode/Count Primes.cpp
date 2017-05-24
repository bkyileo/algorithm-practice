#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
	vector<bool> table(n+1,true);
	int count=0;
	int temp;
	int nums;
	for(int i=2;i<=n;++i)
	{
		if(table[i])
		{
			count++;
			temp=i;
			for(int j=2;j*temp<=n;++j)
			{
				table[temp*j]=false;
			}
		}
	} 
	return count;
} 

int main()
{
	cout<<countPrimes(120)<<endl;
	return 0;
}
