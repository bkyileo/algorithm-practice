#include<bits/stdc++.h>
using namespace std;
int findRadius(vector<int>& houses, vector<int>& heaters) {
	sort(heaters.begin(),heaters.begin()+heaters.size());
	int pos;
	int left,right,dis;
	int res=0;
	for(auto i:houses)
	{
		pos=lower_bound(heaters.begin(),heaters.begin()+heaters.size(),i)-heaters.begin();
		//cout<<"pos : "<<pos<<endl;
		left=pos-1>=0?pos-1:0;
		right=pos==heaters.size()?pos-1:pos;
		dis=min(abs(heaters[left]-i),abs(heaters[right]-i));
		res=max(res,dis);
	} 
	return res;
}
int main()
{
	vector<int> h{1,2,3,4};
	vector<int> t{4};
	cout<<findRadius(h,t)<<endl;
	return 0;
} 
