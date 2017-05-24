//code chef Andrash and Stipendium
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		vector<int> arr(n);
		for(int i=0;i<n;++i)
			scanf("%d",&arr[i]);
		bool flag=true;
		bool a=false;
		float gpa=0;
		for(int i=0;i<n;++i)
		{
			if(arr[i]==2)
				flag=false;
			if(arr[i]==5)
				a=true;
			gpa+=arr[i];	
		}
		if(gpa/n<4.0)flag=false;
		if(flag&&a)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
