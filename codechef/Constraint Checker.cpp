//ms maybe AC
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	vector< vector<int> > digit;
	vector< vector<bool> > ops;
	set<char> st;
	for(int i=0;i<n;++i)
	{
		string curr;cin>>curr;
		int j=0;
		vector<int> d;
		vector<bool> o;		
		while(j<curr.length())
		{
			if(curr[j]=='<'&&curr[j+1]=='='){o.push_back(true);j++;j++;continue;}
			else if(curr[j]=='<'){o.push_back(false);j++;continue;}
			else if(curr[j]<='Z'&&curr[j]>='A'){d.push_back(1000005+curr[j]-'A');st.insert(curr[j]);++j;continue;}
			else 
			{
				int now=0;
				while(curr[j]<='9'&&curr[j]>=0&&j<curr.length())
				{
					now=now*10+(curr[j]-'0');
					j++;
				}
				d.push_back(now);
			}
		}
		digit.push_back(d);
		ops.push_back(o);
	}
	//for(set<char>::iterator i=st.begin();i!=st.end();++i)cout<<*i<<" ";cout<<endl;
	//for(int i=0;i<digit.size();++i){for(int j=0;j<digit[i].size();++j)cout<<digit[i][j]<<" ";cout<<endl;}
	//for(int i=0;i<ops.size();++i){for(int j=0;j<ops[i].size();++j)cout<<ops[i][j]<<" ";cout<<endl;}
	int t;cin>>t;
	for(int i=0;i<t;++i)
	{
		map<int,int> mp;
		bool flag=true;
		for(int j=0;j<st.size();++j)
		{
			char ch;int it;
			cin>>ch>>it;
			mp[ch-'A'+1000005]=it;
		}
		for(int j=0;j<digit.size();++j)
		{
			vector<int> now=digit[j];
			for(int k=0;k<now.size();++k)
			{
				if(now[k]>1000001)now[k]=mp[now[k]];
			}
			//for(int k=0;k<now.size();++k)cout<<now[k]<<" ";cout<<endl;
			for(int k=0;k<now.size()-1;++k)
			{
				if(now[k]>now[k+1]){flag=false;continue;}
				if(now[k]<now[k+1])continue;
				if(now[k]==now[k+1]&&!ops[j][k]){flag=false;continue;}
				if(now[k]==now[k+1]&&ops[j][k])continue;
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
/*
2
A<B<=E
30<=E<5
2
A 1
B 2
E 3
A 3
B 5
E 10
*/
