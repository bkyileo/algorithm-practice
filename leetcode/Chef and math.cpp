// code chef may challenge 
/*
�����Ҫ�����������������һ������ Q ��ѯ�ʣ�ÿ��ѯ�ʻ���� X �� K��Ҫ������ж�
���ַ��������� K �������������ӳ� X����ע�⣬�ӷ��е�˳���ǲ���Ҫ�ģ��� f(i)+ f(j)+ f(k)
�� f(j) + f(i) + f(k) �ᱻ����ͬһ���������ң���Ҳ���Զ��ʹ��ͬһ������
���ڴ𰸿��ܴܺ�������𰸶� 109 + 7 (1000000007) ȡģ�õ��Ľ����
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
// fibonacci 44

vector<int> fibonacci;
void prepare(vector<int>& t)
{	
	
	fibonacci.push_back(1);
	fibonacci.push_back(2);
	while(fibonacci[fibonacci.size()-1]<1000000007)
	{
		fibonacci.push_back(fibonacci[fibonacci.size()-1]+fibonacci[fibonacci.size()-2]);
	}
	return ;
}

int dfs(int x,int k,int nth)
{
	if(k==0)
	{
		if(x==0)
			return 1;
		else
			return 0; 
	}
	//��һ�仰 50�֣��� 
 	if ((long long)fibonacci[nth] * k < x) {
        return 0;
    }
	else if(x==0 || nth==0)
		return 0;
	else
	{
		int res=dfs(x,k,nth-1);
		if (x >= fibonacci[nth-1])
            res += dfs(x-fibonacci[nth-1],k-1,nth);
        return res%mod;
	}
	
}  

void dfs2(int x,int k,int last,long long &count)
{
	if(x==0 && k==0 ) 
	{
		count++;
		return ;
	}
	if(k>0)
	{
		
		for(int i=fibonacci.size()-1;i>=0;--i)
		{
			if(fibonacci[i]>last || x-fibonacci[i]<0 || (long long) k*fibonacci[i]<x)
				continue;
			dfs2(x-fibonacci[i],k-1,fibonacci[i],count);
		}
	}
	return ;
}

int main()
{
	prepare(fibonacci);

	int Q;
	int X,K;
	long long count;
	cin>>Q;
	while(Q--)
	{
		count=0;
		cin>>X>>K;
		dfs2(X,K,fibonacci[43],count);
		cout<<count%mod<<endl;
	}
	return 0;
} 
