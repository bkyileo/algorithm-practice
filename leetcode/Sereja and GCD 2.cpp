//code chef
/*
Sereja ��Ҫ������ж��ٳ���Ϊ N ������ A�� A1, A2, . . . , AN (1 �� Ai �� M)�������������
һ���±� i �� j (1 �� i < j �� N)��ʹ�� gcd(Ai, Aj) = 1��
���ڴ𰸿��ܴܺ�������𰸶� 109 + 7 (1000000007) ȡģ�õ��Ľ����
���ݷ�Χ��������
1 �� T �� 10
1 �� N �� 105
1 �� M �� 100
������ 1�� 10 �֣� ʱ������ 5 �룩��
1 �� N, M �� 10
������ 2�� 25 �֣� ʱ������ 15 �룩��
1 �� N �� 100
������ 3�� 65 �֣� ʱ������ 15 �룩��
*/

/*
˼· 1 :  �벻����λ��� 

��[2,N]���� N �����ص����� ��ȫ��
��[2,N]����N-1�����ص����� �����1��ȫ��
��[2,N]����N-2�����ص����� �����1��ȫ��
������������������ 
��[2,N]����1�����ص����� �����1��ȫ����

res += 1; 
˼· 2 ��
���8�ʺ�˼�� 
*/ 

#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
bool primes[101];
void prepare()
{
	memset(primes,true,sizeof(primes));
	for(int i=2;i<101;i++)
	{
		if(primes[i])
		{
			int j=2;
			while(j*i<101)
			{
				primes[j*i]=false;
				j++;
			}
		}
	}
}

void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
bool gcd1(int a,int b)
{
	//a>b
	if(a<b) swap(a,b);
	int div;
	int temp;
	while(b)
	{
		temp=b;
		div=a/b;
		b=a-b*div;
		a=temp;
	}
	if(a==1) return true;
	return false;
}

bool place(vector<int> temp)
{
	if(temp.size()==0) return true;
	int last=temp[temp.size()-1];
	
	for(int i=0;i<temp.size()-1;++i)
	{
		if(!gcd1(last,temp[i]))
			return false; 
	}
	return true;
}
void dfs(int &count,int curr,int n,int m,vector<int> temp)
{
	if(curr>n)
	{	
		count++ ;
		if (count>mod)
			count=count%mod;
		return ;
	}
	for(int i=1;i<=m;++i)
	{
		temp.push_back(i);
		if(place(temp))
			dfs(count,curr+1,n,m,temp);
		temp.pop_back();
	}
}
int main()
{
	prepare();
	int t;
	cin>>t;
	int n,m;
	int count;
	while(t--)
	{
		cin>>n>>m;
		count=0;
		vector<int> temp;
		dfs(count,1,n,m,temp);
		cout<<count<<endl;
	} 
	return 0;
}


