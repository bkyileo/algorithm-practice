// code chef Chef and special numbers
#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
	���������ֵķ���
	ÿ����һλ������������Ӱ�쿼�Ǹ�λ����һλ�Ե�ǰ�������ʵ�Ӱ��
	dp��ϵ
	0 no �ϸ�����
	1 ok �ϸ���ȷ 
	2 ok ԭ��û���� ����û����
	3 ok ԭ��û���� ����û���� 
	4 ok ԭ��û���� ����û����
	5 ok ԭ��û���� ����û����
	6 ok ԭ��û���� ����û����
	7 ok ԭ��û���� ����û���� 
	8 ok ԭ��û���� ����û����
	9 ok ԭ��û���� ����û����
	dp������� 
	[18][10][10][1]
	LR �ǵڼ������� 
	index(r)-index(l)
*/ 

void slove()
{ 
	int t;cin>>t;
	ll l,r,k,count,curr;
	bool visit[10]; 
	while(t--)
	{
		cin>>l>>r>>k;
		ll res=0;
		for(ll i=l;i<=r;++i)
		{
			memset(visit,false,sizeof(visit));
			count=0;
			curr=i;
			while(curr)
			{
				int a=curr%10;
				if(a!=0&&i%a==0&&!visit[a])
				{
					count++;
					visit[a]=true;			
				}
				curr=curr/10;
			}
			if(count>=k)
				res++;
		}
		cout<<res<<endl;
	} 
	return ;
}
int main()
{
	slove();
	return 0;
} 
