//code chef Enormous Input Test 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int res=0;
	int curr;
	while(n--)
	{
		scanf("%d",&curr);
		if(curr%k==0)res++;
	}
	printf("%d",res);
	return 0;
} 
