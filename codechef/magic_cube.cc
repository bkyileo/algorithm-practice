#include<bits/stdc++.h>
#define CUBE vector< vector < vector<int> > >
using namespace std;
//backtracking
struct location
{
	int x;
	int y;
	int z;
	location(int a,int b,int c):x(a),y(b),z(c){}
};
int M,N,P,L,all_size;
CUBE org_cube;
vector< CUBE > add_cubes;
vector<location> res;
CUBE input(int size)
{
	CUBE cube(size,vector<vector<int>>(size,vector<int>(size)));
	for(int i=0;i<size;++i)
	{
		for(int j=0;j<size;++j)
		{
			for(int k=0;k<size;++k)
			{
				cin>>cube[i][j][k];
			}
		}
	}
	return cube;
}
bool ok(int left)
{
	int cnt=0;
	for(int i=0;i<N;++i)
	for(int j=0;j<N;++j)
	for(int k=0;k<N;++k)
	if(org_cube[i][j][k]%P)cnt++;
	
	if(cnt>left)return false;
	else return true;

}
void debug()
{
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			for(int k=0;k<N;++k)
				cout<<org_cube[i][j][k]<<" ";
			cout<<endl;
		}		
		cout<<endl;
	}
}
bool solve(int index)
{
	if(index==M)return true;
	else
	{
		CUBE curr=add_cubes[index];
		L=curr.size();
		int sz=N-L+1;
		for(int i=0;i<sz;++i)
		for(int j=0;j<sz;++j)
		for(int k=0;k<sz;++k)
		{
			//cout<<"location : "<<i<<" "<<j<<" "<<k<<endl;
			location tp=location(i,j,k);
			res.push_back(tp);
			all_size=all_size-L*L*L;
			for(int o=0;o<L;++o)
			for(int p=0;p<L;++p)
			for(int q=0;q<L;++q)
			org_cube[i+o][j+p][k+q]+=curr[o][p][q];
			//cout<<"L : "<<L<<endl;
			//debug();
			if(ok(all_size))
			{
				if(solve(index+1))return true;
			}
			for(int o=0;o<L;++o)
			for(int p=0;p<L;++p)
			for(int q=0;q<L;++q)
			org_cube[i+o][j+p][k+q]-=curr[o][p][q];
			all_size=all_size+L*L*L;
			res.pop_back();		
		}
		return false;
	}
}
int main()
{
	cin>>N>>M>>P;
	org_cube=input(N);
	add_cubes=vector<CUBE>(M);
	all_size=0;
	for(int i=0;i<M;++i)
	{
		cin>>L;
		CUBE tp_cube=input(L);
		add_cubes[i]=tp_cube;
		all_size+=L*L*L;
	}
	if(solve(0))
	{
		for(int i=0;i<M;++i)
			cout<<res[i].x<<" "<<res[i].y<<" "<<res[i].z<<endl;
	}
 	return 0;
}
