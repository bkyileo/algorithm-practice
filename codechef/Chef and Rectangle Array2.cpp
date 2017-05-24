//codechef Chef and Rectangle Array
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> sumtable(vector<vector<int>> matrix) {
    int row = matrix.size();
    int col = row>0 ? matrix[0].size() : 0;
    vector<vector<int>> sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
    for(int i=1; i<=row; i++) {
        for(int j=1; j<=col; j++) {
            sums[i][j] = matrix[i-1][j-1] + 
                sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
        }
    }
    return sums;
}

int sumRegion(vector<vector<int>> sums,int row1, int col1, int row2, int col2) {
    return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
}

vector<int> maxSlidingWindow(vector<int> nums, int k) {
    vector<int> result;
    deque<int> q;
    for(int i=0; i<nums.size(); i++){
        if(!q.empty() && q.front()==i-k)  q.pop_front();
        while(!q.empty() && nums[q.back()] < nums[i])  q.pop_back();
        q.push_back(i);
        if(i>=k-1)  result.push_back(nums[q.front()]);
    }
    return result;
}
int slove (vector<vector<int>> table,vector<vector<int>> maze,int a,int b)
{
	int res=INT_MAX;
	int n=table.size();
	int m=table[0].size();
	vector<int> totals((m-b)*(n-a));
	vector<int> maxs((m-b)*(n-a));
	int index=0;
	for(int j=0;j<m-b;++j)
	{
		for(int i=0;i<n-a;++i)
		{
			totals[index++]=sumRegion(table,i,j,i+a-1,j+b-1);
		}
	}
	index=0;
	vector<vector<int>> t(maze.size());
	for(int i=0;i<maze.size();++i)
	{
		t[i]=maxSlidingWindow(maze[i],b);
	}
	for(int i=0;i<t[0].size();++i)
	{
		vector<int> temp(t.size());
		for(int j=0;j<t.size();++j)
		{
			temp[j]=t[j][i];
		}
		vector<int>curr=maxSlidingWindow(temp,a);
		for(int j=0;j<curr.size();++j)
		{
			maxs[index++]=curr[j];
		}
	} 
	assert(maxs.size()==totals.size());  
	for(int i=0;i<maxs.size();++i)
		res=min(res,a*b*maxs[i]-totals[i]);
	return res;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector< vector<int> > maze(n,vector<int>(m));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>maze[i][j];
		}
	}
	vector<vector<int>> table=sumtable(maze);
	int q;
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		cout<<slove(table,maze,a,b)<<endl;
	}
	
	return 0;
}
