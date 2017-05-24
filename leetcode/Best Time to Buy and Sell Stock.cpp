#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    vector<int> diff;
    for(int i=0;i<prices.size()-1;++i)
    {
    	diff.push_back(prices[i+1]-prices[i]);
	}
	for(int i=0;i<diff.size();++i)
	//cout<<diff[i]<<" ";
	cout<<endl;
	int res=diff[0];
	int local=diff[0];
	for(int i=1;i<diff.size();++i)
	{
		local=max(diff[i],local+diff[i]);
		res=max(res,local);
	}
	return res;
}

int main()
{
	vector<int> a;
	a.push_back(3);
	a.push_back(1);
	a.push_back(2);
	a.push_back(5);
	a.push_back(4);
	//a.push_back(6);
	cout<<maxProfit(a);
	return 0;
}
