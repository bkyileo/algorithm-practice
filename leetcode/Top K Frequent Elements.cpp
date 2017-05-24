#include<bits/stdc++.h>
using namespace std;

struct node
{
	int v;
	int f;
	node(int a,int b):v(a),f(b)
	{
	}
};
struct com
{
	bool operator() (node a,node b)
	{
		return a.f<b.f;
	}
};
vector<int> topKFrequent(vector<int>& nums, int k) {
	vector<int> res;
	if(nums.size()==0 || k==0) return res;
	map<int,int> m;
	for(auto i:nums)
	{
		m[i]++;
	}
	priority_queue<node,vector<node>,com>q;
	for(map<int,int>::iterator i=m.begin();i!=m.end();++i)
	{
		q.push(node(i->first,i->second));
	} 
	for(int i=0;i<k;++i)
	{
		res.push_back(q.top().v);
		q.pop(); 
	}
//	for(auto i:res)
//	{
//		cout<<i<<" ";
//	}
//	cout<<endl;
	return res;   
} 
int main()
{
	vector<int> t{1,1,1,2,2,2,3,2,4,5,7,9,9,9,9,9,9,9};
	topKFrequent(t,2);
	return 0;
}
