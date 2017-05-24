//Stable Members
#include<bits/stdc++.h>
using namespace std;
int father[100005];
vector<int> root[100005];
set<int> st;
int nums;
int main()
{
	memset(father,0,sizeof(father));
	cin>>nums;
	for(int i=1;i<=nums;++i)
	{
		st.insert(i);
		int k;cin>>k;
		for(int j=0;j<k;++j)
		{
			int curr;cin>>curr;
			root[i].push_back(curr);
		}
	}
	int res=0;
	while(!st.empty())
	{
		//vector<int> temp;
		for(set<int> ::iterator it=st.begin();it!=st.end();++it)
		{
			int curr=*it;
			if(root[curr].size()==1&&root[curr][0]==0){res++;father[curr]=curr;st.erase(curr);}
			if(root[curr].size()==1&&root[curr][0]!=0&&father[root[curr][0]]!=0){father[curr]=father[root[curr][0]];st.erase(curr);}
			if(root[curr].size()>1)
			{
				int lst=0;bool flag=false;int count=0;
				for(int i=0;i<root[curr].size();++i)
				{
					if(father[root[curr][i]]==0){flag=true;break;}
					else{if(father[root[curr][i]]!=lst)count++;lst=father[root[curr][i]];}
				}
				if(!flag){if(count>=2){res++;st.erase(curr);father[curr]=curr;}else{st.erase(curr);father[curr]=lst;}}
			}
		}
		//for(int i=0;i<temp.size();++i)st.erase(temp[i]);
	}
	//for(int i=1;i<=nums;++i)cout<<father[i]<<" ";cout<<endl;
	cout<<res<<endl;
	return 0;
}
