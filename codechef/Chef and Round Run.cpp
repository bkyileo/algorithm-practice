//code chef Chef and Round Run
#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
int t,n,j;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)cin>>arr[i];
		vector<bool> visit(n,false);
		unordered_set<int> st;
		if(n>10000)
		{
			for(int i=0;i<n;++i)
			{
				j=i;
				unordered_set<int> st2;
				while(!visit[j])
				{
					visit[j]=true;
					st2.insert(j);
					j=(j+arr[j]+1)%n;
				}
				if(st2.find(j)!=st2.end())
				{
					while(st.find(j)==st.end())
					{
						st.insert(j);
						j=(j+arr[j]+1)%n;
					}
				}
			}
		}
		else
		{
			for(int i=0;i<n;++i)
			{
				j=i;
				if(!visit[j])
				{
					vector<bool> visit2(n,false);
					while(!visit[j])
					{
						visit[j]=true;
						visit2[j]=true;
						j=(j+arr[j]+1)%n;
					}
					if(visit2[j])
					{
						while(st.find(j)==st.end())
						{
							st.insert(j);
							j=(j+arr[j]+1)%n;
						}
					}
				}
			}
		}
		cout<<st.size()<<endl;
	}
	return 0;
}
