//code chef
#include<bits/stdc++.h>
using namespace std;

int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int nums;
		string isIndia;
		cin>>nums>>isIndia;
		int div=(isIndia=="INDIAN")?200:400;
		int score=0;
		string price;
		while(nums--)
		{
			cin>>price;
			if(price=="CONTEST_WON")
			{
				int rank;
				cin>>rank;
				rank=300+20-rank>300?300+20-rank:300;
				score+=rank;
			}
			if(price=="TOP_CONTRIBUTOR")
			{
				score += 300;
			}
			if(price=="BUG_FOUND")
			{
				int bug;
				cin>>bug;
				score += bug;
			}
			if(price=="CONTEST_HOSTED")
			{
				score += 50;
			}
		}
		cout<<(score/div)<<endl;
	}
	return 0;
	
}
