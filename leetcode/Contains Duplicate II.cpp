#include<bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int,float> m;
    for(int i=0;i<nums.size();++i)
    {
        if(m[nums[i]]==0)
        {
            m[nums[i]]=i+0.5;
        }
        else
        {
            if(i-m[nums[i]]+0.5<=k)
                return true;
        }
    }
    return false;
}

int main()
{
	int a[3]={1,2,1};
	vector<int> t(a,a+3);
	cout<<containsNearbyDuplicate(t,1)<<endl;
}
