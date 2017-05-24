#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int res1;
    int res2;
    int count1=0;
    int count2=0;
    
    for(auto i:nums)
    {
    	if(count1!=0&&i==res1) {count1++;continue;}
    	if(count2!=0&&i==res2) {count2++;continue;}
    	if(count1==0) {count1=1;res1=i;continue;}
    	if(count2==0) {count2=1;res2=i;continue;}
    	count1--;count2--;
	}
	int z1=0;int z2=0;
	for(auto i:nums)
	{
		if(i==res1 && count1>0) z1++;
		if(i==res2 && count2>0) z2++;
	}
	vector<int> res;
	if(z1>nums.size()/3) res.push_back(res1);
	if(z2>nums.size()/3) res.push_back(res2);
	
//	for(auto i:res)
//	{
//		cout<<i<<" ";
//	}
//	cout<<endl;
//	cout<<res.size()<<endl;
	
	return res;
} 

int main()
{
	vector<int> a;
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);

	majorityElement(a);
	return 0;
}
