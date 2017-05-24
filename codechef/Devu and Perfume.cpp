//code chef Devu and Perfume
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int left,right,up,down;
		int n,m;cin>>n>>m;
		left=m;right=0;up=0;down=n;
		bool flag=false;
		for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			char ch;cin>>ch;
			if(ch=='*')
			{
				flag=true;
				if(i>up)up=i;
				if(i<down)down=i;
				if(j>right)right=j;
				if(j<left)left=j;
			}
		}
		if(flag==false) 
		{
			cout<<0<<endl;
		}
		else
		{
		//cout<<"ио об вС ср"<<up<<" "<<down<<" "<<left<<" "<<right<<endl;
			int updown=up-down;
			int leftright=right-left;
			int res=max(updown,leftright);
			res=(res+1)/2+1; 
			cout<<res<<endl;
		}
	}
} 
