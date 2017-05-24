//code chef
#include<bits/stdc++.h>
using namespace std;
void whatisQ(queue<bool> q,bool flag)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"flag "<<flag<<endl;
}
void solve(int b,string s)
{
	//mask b;
	queue<bool> q;
	int ans=0;
	bool flag=true;
	int i=0;
	while(i<s.length())
	{
	    //whatisQ(q,flag);
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
            ++i;
			continue;
		}
		if(!q.empty() && q.front()&&flag)
		{
			ans+=1;
			q.pop();
			flag=!flag;
			//cout<<"todo"<<endl;
			continue;
		}
        if(!q.empty() && q.front()&&!flag)
		{
			q.pop();
			continue;
		}
		if(!q.empty() && !q.front()&&flag)
		{
			q.pop();
			continue;
		}
		if(!q.empty() && !q.front()&&!flag)
		{
			ans+=1;
			q.pop();
			//cout<<"todo"<<endl;
			flag=!flag;
			continue;
		}

	}
    while(!q.empty())
    {
        //whatisQ(q,flag);
        if(q.front()&&flag)
        {
            ans+=1;
            q.pop();
            //cout<<"todo"<<endl;
            flag=!flag;
            continue;
        }
        if(q.front()&&!flag)
        {
            q.pop();
            continue;
        }
        if(!q.front()&&flag)
        {
            q.pop();
            continue;
        }
        if(!q.front()&&!flag)
        {
            ans+=1;
            q.pop();
            //cout<<"todo"<<endl;
            flag=!flag;
            continue;
        }
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
