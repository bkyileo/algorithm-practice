//code chef Chef and Big Soccer
/*
输入数据的第一行包含一个整数 T，代表测试数据的组数。接下来是 T 组数据。
每组数据的第一行包含三个整数 N、 M 和 s，代表狗的条数、传球的次数，以及初始时拿着
球的狗的编号。
第二行包含 M 个整数 A1, A2, . . . , AM，代表每次传球的传球力度。
输出格式
对于每组数据，输出一行，包含 N 个以空格隔开的整数，其中第 i 个数字应为最后第 i 条狗
拿到球的传球方案数对 109 + 7 取模得到的结果。
1 ≤ T ≤ 10
1 ≤ N, M ≤ 103
1 ≤ s ≤ N
1 ≤ Ai ≤ 10
*/
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
	int T,N,M,s,A;
	cin>>T;
	while(T--)
	{
		cin>>N>>M>>s;
		
		vector<int> dogsPre(N+1,0);
		vector<int> dogsCurr(N+1,0);
		
		vector<int> strength;
		while(M--) 
		{
			cin>>A;
			strength.push_back(A);
		}
		
		dogsPre[s]=1;
		for(int i=0;i<strength.size();++i)
		{
			for(int j=1;j<dogsCurr.size();++j)
			{
				if(j-strength[i]>0)
					dogsCurr[j] += dogsPre[j-strength[i]];
				if(j+strength[i]<=N)
					dogsCurr[j] += dogsPre[j+strength[i]];
				dogsCurr[j]=dogsCurr[j]%mod;
			}
			for(int i=0;i<dogsCurr.size();++i)
			{
				dogsPre[i]=dogsCurr[i];
				dogsCurr[i]=0;
			}
		}
		for(int i=1;i<dogsPre.size();++i)
		{
			cout<<dogsPre[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
