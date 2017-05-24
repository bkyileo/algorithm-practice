//codechef Chef and Rectangle Array
#include<bits/stdc++.h>
using namespace std;
//substak 1 暴力解 
int slove1(vector< vector<int> > maze,int a,int b)
{
	int res=INT_MAX;
	int n=maze.size();
	int m=maze[0].size();
	for(int i=0;i<=n-a;++i)
	for(int j=0;j<=m-b;++j)
	{
		
		int total=0;
		int maxnum=0;
		for(int x=0;x<a;++x)
		for(int y=0;y<b;++y)
		{
			maxnum=max(maxnum,maze[i+x][j+y]);
			total+=maze[i+x][j+y];
			//cout<<"maxnum,total : "<<maxnum<<" "<<total<<endl;
		}
		res=min(res,a*b*(maxnum)-total);
	} 
	return res;
}
//substak 2 将矩阵转化成rmq问题  TLE
struct node
{
	int l;
	int r;
	int sums;
	int maxs;
};
void build(vector<node>& tree,vector<int> arr,int id,int l,int r)
{
	tree[id].l=l;tree[id].r=r;
	if(l==r)
	{
		tree[id].maxs=arr[l];
		tree[id].sums=arr[l];
		return ;
	}
	else
	{
		int mid=(l+r)/2;
		build(tree,arr,2*id,l,mid);
		build(tree,arr,2*id+1,mid+1,r);
		tree[id].maxs=max(tree[id*2].maxs,tree[id*2+1].maxs);
		tree[id].sums=tree[id*2].sums+tree[id*2+1].sums;
	}
}
vector<vector<node>> init(vector< vector<int> > maze)
{
	int n=maze.size();
	int m=maze[0].size();
	//int rmq[n][10];
	vector<vector<node>> query;
	//涉及到求和问题，所以不能用ts方法，需要线段树的方法 
	for(int i=0;i<n;++i)
	{
		vector<node> ithTree(4*m);
		build(ithTree,maze[i],1,0,m-1);
		for(auto i:ithTree)
		{
			cout<<i.sums<<" ";
		}
		cout<<endl;
		for(auto i:ithTree)
		{
			cout<<i.maxs<<" ";
		}
		cout<<endl;
		cout<<endl;
		query.push_back(ithTree);
	}
	return query;
} 
int querym(vector<node> seg ,int id, int L, int R) {
    if (seg[id].r < L || seg[id].l > R) return 0;
    if (seg[id].l >= L && seg[id].r <= R) {
        return seg[id].maxs;
    }
    return max(querym(seg,id * 2, L, R), querym(seg,id * 2 + 1, L, R));
}
int querys(vector<node> seg ,int id, int L, int R) {
    if (seg[id].r < L || seg[id].l > R) return 0;
    if (seg[id].l >= L && seg[id].r <= R) {
        return seg[id].sums;
    }
    return (querys(seg,id * 2, L, R)+querys(seg,id * 2 + 1, L, R));
}
int slove2(vector<vector<node>> table,vector< vector<int> > maze,int a,int b)
{
	int res=INT_MAX;
	int n=maze.size();
	int m=maze[0].size();
	for(int i=0;i<=n-a;++i)
	for(int j=0;j<=m-b;++j)
	{
		
		int total=0;
		int maxnum=0;
		for(int x=0;x<a;++x)
		{
			maxnum=max(maxnum,querym(table[i+x],1,j,j+b-1));
			total+=querys(table[i+x],1,j,j+b-1);
			cout<<"maxnum,total : "<<maxnum<<" "<<total<<endl;
		}
		res=min(res,a*b*(maxnum)-total);
	} 
	return res;
	return 0;
}
//to rmq 还是TLE 
//子区域的最大值可以转化成rmq问题
//子区域的和 可以直接在赋值的时候加起来
vector< vector< vector<int> > > init2(vector< vector<int> > maze)
{
	vector< vector< vector<int> > >table;
	int n=maze.size();
	int m=maze[0].size();
	for(int x=0;x<n;++x)
	{
		vector< vector<int> >rmq(m,vector<int>(10,0));
		vector<int> curr=maze[x];
		for(int j=0;j<m;++j)
		{
			rmq[j][0]=curr[j];
		}
		for(int i=1;(1<<i)<m;++i)
		{
			for(int j=0;j+(1<<i)<=m;++j)
			{
				if(rmq[j][i-1]>rmq[j+(1<<(i-1))][i-1])
					rmq[j][i]=rmq[j][i-1];
				else
					rmq[j][i]=rmq[j+(1<<(i-1))][i-1];
			}
		}
		/*
		for(auto i:rmq)
		{
			for(auto j:i)
			{
				cout<<j<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		*/
		table.push_back(rmq);
	}
	return table;
}
int get(vector< vector<int> >f,int b,int e){
	int j=(int)log2(e - b+1);//区域长度的j,使得(2^j)大于等于请求区间的一半即可
    return f[b][j] > f[e-(1<<j)+1][j] ? f[b][j] : f[e-(1<<j)+1][j];//f[e-(1<<j)+1][j] 表示以e为中点长为2^j的区间 
}

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

int slove3(vector<vector<vector<int>>> table,vector<vector<int>> summaze,int a,int b)
{
	int res=INT_MAX;
	int n=summaze.size();
	int m=summaze[0].size();
	for(int i=0;i<n-a;++i)
	for(int j=0;j<m-b;++j)
	{
		int maxnum=0;
		for(int x=0;x<a;++x)
		{
			maxnum=max(maxnum,get(table[i+x],j,j+b-1));
		}
		int total=sumRegion(summaze,i,j,i+a-1,j+b-1);
		//cout<<"maxnum,total : "<<maxnum<<" "<<total<<endl;
		res=min(res,a*b*(maxnum)-total);
	} 
	return res;
}
// 使用subwindow的方法每一次直接在全图做查询 
vector<int> maxSlidingWindow(vector<int> nums, int k) {
    vector<int> result;
    deque<int> q;
    for(int i=0; i<nums.size(); i++){
        /*** remove the top element **/
        if(!q.empty() && q.front()==i-k)  q.pop_front();
        /*** keep the element in the queue is monotically-decreasing ***/
        while(!q.empty() && nums[q.back()] < nums[i])  q.pop_back();
        q.push_back(i);
        if(i>=k-1)  result.push_back(nums[q.front()]);
    }
    return result;
}
int slove4 (vector<vector<int>> table,vector<vector<int>> maze,int a,int b)
{
	//step1 查询全图的 total
	//step2 查询全图的 maxSlidingWindow
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
			int total=sumRegion(table,i,j,i+a-1,j+b-1);
			//totals.push_back(total);
			totals[index++]=total;
		}
	}
	index=0;
	vector<vector<int>> t(maze.size());
	for(int i=0;i<maze.size();++i)
	{
		vector<int> curr=maxSlidingWindow(maze[i],b);
		t[i]=curr;
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
			//maxs.push_back(curr[j]);
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
	//scanf("%d%d",&n,&m);
	vector< vector<int> > maze(n,vector<int>(m));
	for(int i=0;i<n;++i)
	{
		//vector<int> temp;
		for(int j=0;j<m;++j)
		{
			//int t;
			//scanf("%d",maze[i][j]);
			cin>>maze[i][j];
			//temp.push_back(t);
		}
		//maze.push_back(temp);
	}
	//vector<vector<vector<int>>>table1=init2(maze);
	vector<vector<int>> table=sumtable(maze);
	/*
	cout<<"sums:"<<endl;
	for(auto i:table2)
	{
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	*/
	int q;
	cin>>q;
	//scanf("%d",&q);
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		//scanf("%d%d",&a,&b);
		//cout<<slove1(maze,a,b)<<endl;
		//printf("%d\n",slove1(maze,a,b));
		//cout<<slove2(table,maze,a,b)<<endl;
		//cout<<slove3(table1,table2,a,b)<<endl;
		cout<<slove4(table,maze,a,b)<<endl;
	}
	
	return 0;
}
