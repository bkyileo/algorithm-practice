//Chef and Segments
#include<bits/stdc++.h>
using namespace std;
int a[1001];
int b[1001];
bool visit[1001];
int dp[1001];
//AC subtask2 O(N^4) 再优化一点点就好了 
void slove(vector<int> nums)
{
	int n=nums.size();
	int res=0;
	bool visit[1001];
	for(int a=0;a<n;++a)
	{
		for(int b=a;b<n;++b)
		{
			memset(visit,false,sizeof(visit));
			for(int i=a;i<=b;++i)
				visit[nums[i]]=true;
			for(int c=b+1;c<n;++c)
			{
				for(int d=c;d<n;++d)
				{
					if(visit[nums[d]])
					{
						break;
					}
					res++;
				}
			}
		}	
	}
	cout<<res<<endl;
}

/*
	又做出了一部优化 O(N^3) 
	哈哈哈 劳资优化成功啦 
*/
void slove2(int *nums,int n)
{
	long long res=0;
	int count=0;
	for(int a=0;a<n;++a)
	{
		memset(visit,false,sizeof(visit));
		for(int b=a;b<n;++b)
		{
			visit[nums[b]]=true;
			for(int c=b+1;c<n;++c)
			{
				if(!visit[nums[c]])
				{
					count++;
				}
				else
				{
					res+=dp[count];
					count=0;
				}
			}
			if(count!=0)
			{
				res+=dp[count];
				count=0;	
			}
		}	
	}
	printf("%d\n",res);
}
int main()
{
	int t;
	scanf("%d",&t);
	int num;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=1000;++i)
		dp[i]=i+i*(i-1)/2;
	while(t--)
	{
		scanf("%d",&num); 
		for(int i=0;i<num;++i)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(a,a+num);
		int size=unique(a,a+num)-a;
		for(int i=0;i<num;i++)
			b[i]=lower_bound(a,a+size,b[i])-a + 1;
		slove2(b,num);
	}
	return 0;
} 
