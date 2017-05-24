//Chef And Binary Operation
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int c=0;
		int d=0;
		for(int i=0;i<a.length();++i)
		{
			c+='1'-a[i];
			d+='1'-b[i];
		}
		if( (c==0&&d>0) || (c==a.length()&&d<a.length()) )
		{
			cout<<"Unlucky Chef"<<endl;
		}	
		else
		{
			int ones=0;
			int zeros=0;
			for(int i=0;i<a.length();++i)
			{
				if(a[i]!=b[i])
				{
					if(a[i]=='0')zeros++;
					if(a[i]=='1')ones++;
				}
			}
			cout<<"Lucky Chef"<<endl;
			cout<<max(zeros,ones)<<endl;
		}
	}
	return 0;
}
