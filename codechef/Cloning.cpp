#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,q;cin>>n>>q;
		for(int i=0;i<n;++i)cin>>arr[i];
		for(int i=0;i<q;++i)
		{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			a--;b--;c--;d--;
			vector<int> tp1(b-a+1);
			vector<int> tp2(d-c+1);
			for(int j=a;j<=b;++j)tp1[j-a]=arr[j];
			for(int j=c;j<=d;++j)tp2[j-c]=arr[j];
			sort(tp1.begin(),tp1.end());
			sort(tp2.begin(),tp2.end());
			int ct=0;
			for(int j=0;j<tp1.size();++j)
			{
				if(tp1[j]!=tp2[j])ct++;
				if(ct>1)break;
			}
			if(ct>1)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}		
	}
} 
