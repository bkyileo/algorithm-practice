// spoj Tri graphs
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int index=1;
	while(1)
	{
		int t;cin>>t;
		if(t==0)break;
		else
		{
			//没有考虑负数 
			int la,lb,lc,ca,cb,cc;
			cin>>la>>lb>>lc;
			la=lb+1;lc=min(lb+lc,lb);
			for(int i=2;i<t;++i)
			{
				cin>>ca>>cb>>cc;
				ca=min(ca+la,ca+lb);
				cb=min( min(ca+cb,la+cb),min(lb+cb,lc+cb) );
				cc=min( min(lc+cc,lb+cc),cb+cc);
				la=ca;lb=cb,lc=cc;
				//cout<<"--"<<la<<" "<<lb<<" "<<lc<<"--"<<endl; 
			}
			cout<<index<<". "<<lb<<endl;
			index++;
		}
	}
	return 0;
}
