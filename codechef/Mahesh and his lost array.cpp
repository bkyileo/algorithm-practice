//Mahesh and his lost array
#include<bits/stdc++.h>
using namespace std;
multiset<int> nums;
vector<int> sumtemp;
multiset<int> sums;
int t,n,pown,curr;
int main()
{
	cin>>t;
	while(t--)
	{
		nums.clear();
		sums.clear();
		sumtemp.clear();
		cin>>n;
		pown=1;
		for(int i=0;i<n;++i)
		{
			pown=pown<<1;
		}
		for(int i=0;i<pown;++i)
		{
			cin>>curr;sums.insert(curr);
		}
		sums.erase(0);
		int index=0;
		for(int i=0;i<n;++i)
		{
			curr=*sums.begin();
			nums.insert(curr);
			int size=sumtemp.size();
			for(int j=0;j<size;++j)
			{
				sumtemp.push_back(curr+sumtemp[j]);	
			}
			sumtemp.push_back(curr);
			for(;index<sumtemp.size();++index)
			{
				sums.erase(sums.find(sumtemp[index]));
			}
			//cout<<"debug"<<endl;
			//for(multiset<int>::iterator it=nums.begin();it!=nums.end();++it)cout<<*it<<" ";cout<<endl;
		}
		for(multiset<int>::iterator it=nums.begin();it!=nums.end();++it)cout<<*it<<" ";cout<<endl;
	}
	return 0;
}
