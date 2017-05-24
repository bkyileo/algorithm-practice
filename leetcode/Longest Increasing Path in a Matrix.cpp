// leetcode
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	int y;
	int val;
	node(int a,int b,int c):x(a),y(b),val(c){
	}
}; 
struct com
{
	bool operator()(node a,node b)
	{
		return a.val>b.val;
	}
};
int longestIncreasingPath(vector<vector<int>>& matrix) {
	const int m= matrix.size();
	if(m==0) return 0;
	const int n= matrix[0].size();
	
	vector< vector<int> > mp(m,vector<int>(n,1));
	priority_queue<node,vector<node>,com> q;
	for(int i=0;i<m;++i)
	for(int j=0;j<n;++j){
		q.push(node(i,j,matrix[i][j]));
	}
	int res=0;
	while(!q.empty())
	{
		node curr=q.top();
		q.pop();
		int currx=curr.x;
		int curry=curr.y;
		
		if(currx-1>=0 && matrix[currx][curry]>matrix[currx-1][curry])
			mp[currx][curry]=max(mp[currx][curry],mp[currx-1][curry]+1);
		if(curry-1>=0 && matrix[currx][curry]>matrix[currx][curry-1])
			mp[currx][curry]=max(mp[currx][curry],mp[currx][curry-1]+1);
		if(currx+1<m && matrix[currx][curry]>matrix[currx+1][curry])
			mp[currx][curry]=max(mp[currx][curry],mp[currx+1][curry]+1);
		if(curry+1<n && matrix[currx][curry]>matrix[currx][curry+1])
			mp[currx][curry]=max(mp[currx][curry],mp[currx][curry+1]+1);
			
		res=res>mp[currx][curry]?res:mp[currx][curry];
	}
//	for(auto i:mp)
//	{
//		for(auto j:i)
//			cout<<j<<" ";
//		cout<<endl;
//	}

	return res;
} 

int main()
{
	vector<vector<int>> test{{3,4,5},{3,2,6},{2,2,1}};
	cout<<longestIncreasingPath(test)<<endl;
	return 0;
}
