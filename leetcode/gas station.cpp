#include<bits/stdc++.h>
using namespace std;
//����2��ѭ�����飬�ֱ����ǰ�Ļ��Ѻ�ӵ�У������ܲ����ҳ�һ���ڵ�index
//����һֱѭ����ȥ
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	//�����ǰ���˵Ļ���֮ǰ�����е�gas stationҲ����
	int res=0;
	int rest=0;
	int n=gas.size();
	int f=0;
	for(int i=0;i<n;++i)
	{
		f+=gas[i]-cost[i];
		if(rest+gas[i]-cost[i]<0)
		{
			res=i+1;
			rest=0;
		}
		else
		{
			rest+=gas[i]-cost[i];
		}
	}
	if(f<0)return -1;
	return res;
} 
int main()
{
	vector<int> gas={2,3,1};
	vector<int> cost={3,1,2};
	cout<<canCompleteCircuit(gas,cost)<<endl;
	return 0;
} 
