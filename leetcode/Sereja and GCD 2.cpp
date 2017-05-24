//code chef
/*
Sereja 想要你求出有多少长度为 N 的序列 A： A1, A2, . . . , AN (1 ≤ Ai ≤ M)，满足对于任意
一对下标 i 和 j (1 ≤ i < j ≤ N)，使得 gcd(Ai, Aj) = 1。
由于答案可能很大，请输出答案对 109 + 7 (1000000007) 取模得到的结果。
数据范围和子任务
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ M ≤ 100
子任务 1（ 10 分， 时间限制 5 秒）：
1 ≤ N, M ≤ 10
子任务 2（ 25 分， 时间限制 15 秒）：
1 ≤ N ≤ 100
子任务 3（ 65 分， 时间限制 15 秒）：
*/

/*
思路 1 :  想不起如何回溯 

在[2,N]中找 N 个互素的数字 算全排
在[2,N]中找N-1个互素的数字 算加上1的全排
在[2,N]中找N-2个互素的数字 算加上1的全排
。。。。。。。。。 
在[2,N]中找1个互素的数字 算加上1的全排列

res += 1; 
思路 2 ：
借鉴8皇后思想 
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


