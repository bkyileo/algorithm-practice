#include<bits/stdc++.h>
using namespace std;
#define N 100005
//�� bug 
/*
	1 : ������ done
 	2 : ����anc����
	3 ��������� 
	4 �����㸸�ڵ� done
	5 �����������ڵ� done
*/ 
int father[N];
int rootmask[N];
vector<int> node[N];
map<string,int> mp;
vector<int> roots;
int id=0;
string names[N];

//�����˷ѿռ� 
int anc[N][30];
int dep[N];
 
void init()
{
	memset(rootmask,0,sizeof(rootmask));
	memset(dep,0,sizeof(dep));
	memset(anc,-1,sizeof(anc));
	for(int i=0;i<N;++i)
		father[i]=i;
}
void input()
{
	int n;
	cin>>n;
	names[0]="-1";
	while(n--)
	{
		string name1,name2;
		cin>>name1>>name2;
		if(mp[name1]==0)
		{
			mp[name1]=++id;
			names[id]=name1;
		}

		if(mp[name2]==0)
		{
			mp[name2]=++id;
			names[id]=name2;	
		}
		node[mp[name1]].push_back(mp[name2]);
		father[mp[name2]]=mp[name1];
		rootmask[mp[name2]]++;
	}
	//ò�Ʋ���Ҫ roots 
	for(int i=1;i<N;++i)
	{
		if(i<id && rootmask[i]==0)
		 	roots.push_back(i);
	} 
} 
void calAnc() //��ʼ��anc����
{
	for (int i = 1; i <= id; i++) 
			anc[i][0] = father[id]; //�߽����������
	
	for (int j = 1; (1 << j) < id; j++)
		for (int i = 0; i < id; i++)
			if (anc[i][j-1] != -1) //ע�ⳬ�����ڵ�����
				anc[i][j] = anc[anc[i][j-1]][j-1];
}

void calDep(int x, int y) //��ʼ��dep����
{
	dep[x] = y; //xΪ��ǰ�ڵ㣬yΪ���
	for (int i = 0; i < node[x].size(); i++)
		calDep(node[x][i], y+1);
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int query(int p, int q) //��ѯp��q�������������
{
	if (dep[p] < dep[q]) swap(p, q);//��pΪ��Ƚ����һ��

	int log = 1; //log(dep[p])����ȡ����Ϊ����������
	while ((1 << log) <= dep[p]) log++;
	log--;

	//��p������qͬһ��ĵط�
	for (int i = log; i >= 0; i--)
		if (dep[p] - (1 << i) >= dep[q])
			p = anc[p][i];

	if (p == q) return q; //����Ƿ��q�غ�

	//������������������ȵ�����
	for (int i = log; i >= 0; i--)
		if (anc[p][i] != -1 && anc[p][i] != anc[q][i])
			p = anc[p][i], q = anc[q][i];

	return father[p];//���׼�Ϊ�����������
}
int main()
{
	init();
	input();
	for(int i=0;i<roots.size();++i)
	{
		calDep(roots[i],0);
	}
	calAnc();
	int m;
	cin>>m;
	while(m--)
	{
		string name1,name2;
		cin>>name1>>name2;
		if(name1==name2)
			cout<<name1<<endl;
		else
			cout<<names[query(mp[name1],mp[name2])]<<endl;
	}
	return 0;
}
