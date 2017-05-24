// Kruscal ��С�������㷨 
// ��С������������ ��set���� ��Ϊ�п������е궼���˵���û�����ӳɱ� 
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
struct edge{
	int from;
	int to;
	int cost;
	edge(int a,int b,int c):from(a),to(b),cost(c){
	} 
};
struct com
{
	bool operator()(edge a,edge b)
	{
		return a.cost>b.cost;
	}
};
int father [maxn];
int rnk[maxn];
int find(int x)
{
	if(father[x]==x)return father[x];
	else
	{
		father[x]=find(father[x]);
		return father[x];
	}
}
void setUnion(int x,int y)
{
	int a=find(x);
	int b=find(y);
	if(a==b) return ;
	
	if (rnk[a] > rnk[b]) father[b] = a;
	else 
	{
		father[a]  = b;
		rnk[b] += rnk[a] == rnk[b];
	}
	/*����д�� ���Ҫ������Ͻڵ��� 
	{
		father[x]=b;
		return ;
	}
	*/
}
int main()
{	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		father[i]=i;
		rnk[i]=0;
	}
	priority_queue<edge,vector<edge>,com> qu;
	for(int i=0;i<m;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		qu.push(edge(a,b,c));
	}
	int res=0;
	while(!qu.empty())
	{
		edge curr=qu.top();
		qu.pop();
		int a,b;
		a=curr.from;
		b=curr.to;
		if(find(a)!=find(b))
		{
			res+=curr.cost;
			setUnion(a,b);
		}
	}
	cout<<res<<endl;
	return 0;
}
