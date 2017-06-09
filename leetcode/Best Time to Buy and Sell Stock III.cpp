#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
	int buy1 = -1e9;
	int sell1 = 0;
	int buy2 = -1e9;
	int sell2 = 0;
	for(auto i:prices)
	{
		sell2 = max(sell2,i+buy2);
		buy2 = max(buy2,sell1-i);
		sell1 = max(sell1,i+buy1);
		buy1 = max(buy1,-i);
	}
	return sell2;
}
int main()
{
	vector<int> arr{1,2,3,4,5,6};
	cout<<maxProfit(arr)<<endl;
	return 0;
}
