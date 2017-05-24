//codeforces Vacations
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int nums;cin>>nums;
	vector<int> act(nums);
	for(int i=0;i<nums;++i)cin>>act[i];
	
	int rest=0;
	bool ok=true;
	for(int i=0;i<nums;++i)
	{
		if(act[i]==0){
			ok=true;
			rest++;
		}
		else if(ok){ok=false;}
		else
		{
			if(act[i]==3&&act[i-1]!=3)
				act[i]=3-act[i-1];
			if(act[i]==1||act[i]==2)
			{
				if(act[i]!=act[i-1]);
				else
				{
					rest++;
					ok=true;
				}
			}
		}
	}
	cout<<rest<<endl;
	return 0;
}
//4
//2 1 2 1 0
