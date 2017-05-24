#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	if (n==0)
    	return;
    	sort(nums1.begin(),nums1.end());
    	sort(nums2.begin(),nums2.end());
        vector<int>::iterator i = nums1.begin();
        vector<int>::iterator j = nums2.begin();
        
//		for (int k=0;k<nums1.size();k++)
//		cout<<nums1[k]<<" ";
//		cout<<endl;
        
		while (*i!=*--nums1.end() && *j!=*nums2.end())
        {		
        	if(*j<*i)
        	{
				nums1.insert(i,*j);
				j++;
			}
			i++;
			
//			for (int k=0;k<nums1.size();k++)
//			cout<<nums1[k]<<" ";
//			cout<<endl;
		}
		
//		for (int k=0;k<nums1.size();k++)
//		cout<<nums1[k]<<" ";
//		cout<<endl;
		
		while(*j!=*nums2.end())
		{
			nums1.insert(nums1.end(),*j);
			j++;
		}
		return; 
    }
};

int main()
{
	vector<int> a;
	vector<int> b;
	
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	//b.push_back(11);
	//b.push_back(12);
	
	Solution solu;

	solu.merge(a,a.size(),b,b.size());
	for (int k=0;k<a.size();k++)
	cout<<a[k]<<" ";
	

	
}
