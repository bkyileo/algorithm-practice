#include<bits/stdc++.h>
using namespace std;
//给出2个循环数组，分别代表当前的花费和拥有，请问能不能找出一个节点index
//让他一直循环下去
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	//如果当前挂了的话，之前的所有的gas station也不行
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
