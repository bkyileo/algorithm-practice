//code chef
#include<bits/stdc++.h>
using namespace std;
void solve(int b,string s)
{
	//mask b;
	queue<bool> q;
	int ans=0;
	bool flag=true;
	for(int i=0;i<s.length();++i)
	{
		if(q.size()<b)
		{
			if(s[i]=='R' && flag)
				q.push(true);
			if(s[i]=='R' && !flag)
				q.push(false);
			if(s[i]=='G' && flag)
				q.push(false);
			if(s[i]=='G' && !flag)
				q.push(true);
			continue;
		}
		if(!q.empty() && q.front()==flag)
		{
			ans+=1;
			q.pop();
			flag=!flag;
			continue;
		}
		if(!q.empty() && q.front()!=flag)
		{
			q.pop();
			continue;
		}
	}
	while(q.empty()!=0 && q.front()==flag)
	{
		ans+=1;
		q.pop();
		flag=!flag;
	}
	while(q.empty()!=0 && q.front()!=flag)
	{
		q.pop();
	}
	cout<<ans<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		string s;
		cin>>s;
		solve(b,s);
	}
	return 0;
 }
 /*
 RGGRGRG
 100 flag=1 ans=0
  00 flag=0 ans=1
 */
