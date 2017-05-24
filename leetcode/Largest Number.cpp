#include<bits/stdc++.h>
using namespace std;

//Largest Number  »ùÊıÅÅĞò
vector<int>::iterator find(vector<int>& mask,int val)
{
	int temp;
	vector<int>::iterator it=mask.begin();
	for(;it!=mask.end();++it)
	{
		temp=*it;
		while(temp>10)
		{
			temp/=10;
		}
		if(val>temp)
			return it;
	}
	return it;
}

string largestNumber(vector<int>& nums) {
    vector<int> mask;
    for(int i=0;i<nums.size();++i)
    {
    	if(nums[i]<10)
    	{
    		mask.insert(find(mask,nums[i]),nums[i]);
		}
		else{
			int temp=nums[i];
			while(temp>10)
			{
				temp/=10;
			}
			mask.insert(find(mask,temp),nums[i]);
		}
	}
	for(int i=0;i<mask.size();++i)
	{
		cout<<mask[i]<<" ";
	}
	cout<<endl;
	return "";
} 

int main()
{
	int test[5]={3, 40, 34, 9,5};
	vector<int> a(test,test+5);
	largestNumber(a);
	return 0;
}
