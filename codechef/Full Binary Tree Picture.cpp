//ms Full Binary Tree Picture 
#include<bits/stdc++.h>
using namespace std;
/*
           #
          / \
         /   \
        /     \
       /       \
      /         \
     #           #
    / \         / \
   /   \       /   \
  #     #     #     #
 / \   / \   / \   / \
#   # #   # #   # #   # 
*/
int n,m;
vector< pair<long long,long long> > vt;
bool com(pair<int,int> a,pair<int,int> b)
{
	return a.first!=b.first ? a.first>b.first : a.second>b.second;
}
void init()
{
	
	if(n==1){vt.push_back(make_pair(0,0));return ;}
	else
	{
		vt.push_back(make_pair(0,0));vt.push_back(make_pair(2,2));vt.push_back(make_pair(2,-2));
		int curr=3;
		for(int i=3;i<=n;++i)
		{
			int count=vt.size();
			for(int j=0;j<count;++j)
			{
				vt[j].first+=curr;
				vt[j].second+=curr;
			}
			for(int j=0;j<count;++j)
			{
				vt.push_back(make_pair(vt[j].first,-vt[j].second));
			}
			vt.push_back(make_pair(0,0));
			curr*=2;
		}	
	}
	//cout<<vt.size()<<endl;
	//sort(vt.begin(),vt.end(),com);
	//for(int i=0;i<vt.size();++i)cout<<vt[i].first<<"~"<<vt[i].second<<" ";cout<<endl;
}
int main()
{
	cin>>n>>m;
	init();
	while(m--)
	{
		int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		int res=0;
		for(int i=0;i<vt.size();++i)
		{
			if(vt[i].first>=x1 && vt[i].first<=x2 && vt[i].second>=y1 && vt[i].second<=y2)res++;
		}
		cout<<res<<endl;
	}
	return 0;
}
