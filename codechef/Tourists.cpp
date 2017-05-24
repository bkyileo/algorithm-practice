#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, flag, top, sum, du[N], ans[N];
multiset<int> mp[N];
vector<int> path;
void dfs(int x)
{
    ans[++top] = x;
    for(auto i:mp[x])
    {
        mp[x].erase(mp[x].find(i));
        mp[i].erase(mp[i].find(x));
        dfs(i);
        break;
    }    
}
void fleury(int x)
{
    top = 1;
    ans[top] = x;
    while(top > 0)
    {
        int k = 0;
		if(mp[ans[top]].size()>=1)k=1;
        if(k == 0)
        {
            path.push_back(ans[top]);
            top--;
        }
        else if(k == 1)
        {
            top--;
            dfs(ans[top+1]);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(du, 0, sizeof(du));
    vector<pair<int,int>> res;
    int a,b;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        mp[x].insert(y);
        mp[y].insert(x);
        du[x]++;
        du[y]++;
        res.push_back(make_pair(x,y));
    }
    flag = 1;
    for(int i = 1; i <= n; i++)
    {
        if(du[i]%2==1||du[i]==0)
        {
			flag=0;
			break;
        }
    }
    if(flag==1)
	{
		fleury(1);
		multiset<pair<int,int>> st; 
		for(int i=path.size()-1;i>0;--i)
		{
			st.insert(make_pair(path[i],path[i-1]));
		}
		if(st.size()!=res.size()){
			cout<<"NO"<<endl;return 0; 
		} 
		cout<<"YES"<<endl;
		for(auto i:res)
		{
			if(st.find(i)!=st.end())
			{
				cout<<i.first<<" "<<i.second<<endl;
				st.erase(st.find(i));				
			}
			else
			{
				cout<<i.second<<" "<<i.first<<endl;
				st.erase(st.find(make_pair(i.second,i.first)));	
			}	
		}
	}
    else{
        cout<<"NO"<<endl;
	}
    return 0;
} 
