#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	string a,b;
	int t1,t2;
	bool c1,c2;
	while(t--)
	{
		cin>>a>>b;
		t1=0;t2=0;can=true;
		for(int i=0;i<a.length();++i)
		{
			if(t1>2||t2>2){can=false;break;}
			else
			{			
				if(a[i]=='1'&&b[i]=='1'){if(t1==1||t2==1){can=false;break;}t1=0;t2=0;}
				if(a[i]=='2'&&b[i]=='2'){t1++;t2++;}
				if(a[i]!=b[i])
				{
					if(t2==1&&t1==1){can=false;break;}
					if(t2==2&&t1==2){can=false;break;}

					if(t2==2&&t1==1){t2=0;t1=2;}
					if(t2==2&&t1==0){t2=0;t1=1;}

					if(t2==1&&t1==){can=false;break;}
					if(t2==1&&t1==1){can=false;break;}
					
					if(t2==1&&t1==1){can=false;break;}
					if(t2==1&&t1==1){can=false;break;}
				}
			}
			
		}
		if(!can){cout<<0<<endl;continue;}
	}
	return 0;
}
