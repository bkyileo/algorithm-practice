//codeforces Launch of Collider
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;cin>>n;
	vector<int> c(n);
	vector<char> d(n);
	for(int i=0;i<n;++i)cin>>d[i];
	for(int i=0;i<n;++i)cin>>c[i];
	int count=INT_MAX;
	bool flag=false;
	for(int i=0;i<n-1;++i)
		if(d[i]=='R'&&d[i+1]=='L')
		{
			count=min(count,(c[i+1]-c[i])/2);
			flag=true;
		}
	if(flag)cout<<count<<endl;
	else cout<<-1<<endl;
	return 0;
} 
