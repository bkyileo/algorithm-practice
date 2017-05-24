//code chef Chef and Big Soccer
/*
�������ݵĵ�һ�а���һ������ T������������ݵ��������������� T �����ݡ�
ÿ�����ݵĵ�һ�а����������� N�� M �� s������������������Ĵ������Լ���ʼʱ����
��Ĺ��ı�š�
�ڶ��а��� M ������ A1, A2, . . . , AM������ÿ�δ���Ĵ������ȡ�
�����ʽ
����ÿ�����ݣ����һ�У����� N ���Կո���������������е� i ������ӦΪ���� i ����
�õ���Ĵ��򷽰����� 109 + 7 ȡģ�õ��Ľ����
1 �� T �� 10
1 �� N, M �� 103
1 �� s �� N
1 �� Ai �� 10
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
