
#include<bits/stdc++.h>
using namespace std;
set<long long> s;
vector<long long> temp;
long long all,ct;
long long l,r,k;
void solve(int left,int right,int remain)
{
	//cout<<left<<" "<<right<<" "<<remain<<endl; 
	if(remain==0)return ;
	all=0;ct=0;k=0;
	for(int i=left;i<right;++i)all+=temp[i];
	for(int i=left;i<right&&ct<all/2;++i){
		ct+=temp[i],k=i;
	}
	s.insert(k+1);
	remain--;
	l=(k-left)*remain/(right-left);
	if((k-left)*remain%(right-left)!=0)l++;
	r=remain-l;
	solve(left,k,l);
	solve(k+1,right,r);
}
void ck(int p,int n)
{
	if(s.find(0)!=s.end())s.erase(s.find(0));
	if(s.find(n)!=s.end())s.erase(s.find(n));
	if(s.size()!=p)
	{	
		int i=1;
		while(s.size()<p)s.insert(i++);
		while(s.size()>p)s.erase(s.begin());
	}
}
int main()
{
	long long n,p;cin>>n>>p;
	vector< vector<long long> >arr(n,vector<long long>(n));
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>arr[i][j];
	temp=vector<long long>(n,0);
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)
	temp[i]+=arr[i][j];
	s.clear();
	solve(0,n,p-1);
	ck(p-1,n);
	for(auto i:s)cout<<i<<" ";cout<<endl;
	temp.clear();
	temp=vector<long long>(n,0);
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)
	temp[j]+=arr[i][j];
	s.clear();
	solve(0,n,p-1);
	ck(p-1,n);
	for(auto i:s)cout<<i<<" ";cout<<endl;
	return 0;
} 
