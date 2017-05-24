//Given a sorted integer array without duplicates, return the summary of its ranges.

//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
#include<bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
	vector<string> res;
	if(nums.size()==0) return res;
	
	int start = nums[0];
	int last = nums[0];
	int end = nums[0];
	string s;
	
	for(int i=1;i<nums.size();++i)
	{
		if(nums[i]-last==1)
		{
			end = nums[i];
			last = end;
		}
		else
		{
			if(end!=start)
			{
				s=s+to_string(start)+"->"+to_string(end);
				res.push_back(s);
				s="";			
			}
			else
			{
				res.push_back(to_string(start));
			}	

			start = nums[i];
			last = nums[i];
			end = nums[i];
			
			}
		}
	
	if(end!=start)
	{
		s=s+to_string(start)+"->"+to_string(end);
		res.push_back(s);			
	}
	else
	{
		res.push_back(to_string(start));
	}		
	return res;
}

int main()
{
	int a[6]={0,1,2,4,5,7};
	vector<int> b(a,a+6);
	vector<string> res=summaryRanges(b);
	for(auto i:res)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	
	cout<<res.size()<<endl;
	return 0;
}
