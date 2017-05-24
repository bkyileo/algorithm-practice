#include<bits/stdc++.h>
using namespace std;
void whatisrmq();
void input();
void dfs(int curr,int dep);
void rmqBuild();
int rmqQuery();
void whatis();
void whatisrmq();
/*
	������
	val first depth ��ֵ
	��RMQ�Ľӿ� 
*/
#define N 8
vector<int> edge[N];

void input()
{
	int m;cin>>m;
	while(m--)
	{
		int father,son;
		cin>>father>>son;
		edge[father].push_back(son);
	}
}
//val ���ʵĴ���depth ����ʱ����ȣ�first ��һ�η���ʱ��˳�� 
int val[15];
int depth[15];
int first[8];
int id=0;
void dfs(int curr,int dep)
{
	val[id]=curr; depth[id]=dep; first[curr]=id; id++; 
	for(int i=0;i<edge[curr].size();++i)
	{
		dfs(edge[curr][i],dep+1);
		//�ݹ�������֮�������� 
		val[id]=curr; depth[id]=dep; id++;
	} 
}

// ����˼�� LCA(x, y) = val[RMQ(depth, first[x], first[y])]
// RMQ(depth, first[x], first[y]) ָ����id  
int rmq[15][5];
void rmqBuild()
{
	memset(rmq,100,sizeof(rmq));
	 
	for(int i=0;i<15;++i)
	{
		//rmq[i][0]=depth[i];
		rmq[i][0]=i;
	}
	
	for(int i=1;(1<<i)<15;++i)
	{
		for(int j=0;j+(1<<i)<=15;++j)
		{
			if(depth[rmq[j][i-1]]<depth[rmq[j+(1<<(i-1))][i-1]])
				rmq[j][i]=rmq[j][i-1];
			else
				rmq[j][i]=rmq[j+(1<<(i-1))][i-1];
		}
	}
	//whatisrmq();
}
int rmqQuery()
{
	int m;
	cin>>m;
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		l=first[l];
		r=first[r];
		if(l>r) swap(l,r);
		cout<<"l,r: "<<l<<" "<<r<<endl; 
		int m = (int)log2(r-l+1);
		int index=depth[rmq[l][m]]<depth[rmq[r-(1<<m)+1][m]]?rmq[l][m]:rmq[r-(1<<m)+1][m];
		cout<<val[index]<<endl;
	}
}

// ���²鿴����ʹ�� 
void whatis()
{
	for(int i=0;i<15;++i)
	{
		cout<<val[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<15;++i)
	{
		cout<<depth[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<8;++i)
	{
		cout<<first[i]<<" ";
	}
	cout<<endl;
}

void whatisrmq()
{
	for(int i=0;i<15;++i)
	{
		for(int j=0;j<5;++j)
		{
			cout<<rmq[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	input();
	//Ҫ��������ʼdfs 
	dfs(0,0);
	whatis();
	rmqBuild();
	rmqQuery();
	return 0;
}
