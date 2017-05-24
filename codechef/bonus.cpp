#include<bits/stdc++.h>
using namespace std;
const float moneyLimit = 200.0; 
vector<float> bonus;

bool solve(float money,int num)
{
	/*
		random function : rand()
		corner cases:
			1 beyond/below moneyLimit 
				solve(201.0,10);
				solve(-2.0,10);
			2 beyond/below numLimit
				solve(1.0,0);
			3 decimal digits limit
				solve(1.111,0);
		test cases:
			1 solve(200.0,10);
			2 solve(0.11,3);
			3 solve(0.10,10);	
	*/
	if( money>moneyLimit || money<0.0)return false;
	int mask = money*100;
	if( num<=0 || mask<num)return false;
	if( abs(float(mask)-money*100) > 1e-6)return false;
	bonus=vector<float>(num,0.0);
	int distri;
	int cnt; 
	mask -= num;
	while(mask >= num)
	{
		distri = mask/num;
		cnt = 0;
		for(int i = 0;i < num;++i)
		{
			if(rand()%2)
			{
				bonus[i] += float(distri);
				cnt++;
			}
		}
		mask -= cnt*distri;
	}
	bonus[rand()%(num-1)] += mask;
	for(int i = 0;i < num; ++i)
	{
		bonus[i] += 1.0;
		bonus[i] /= 100.0;
	}
	return true;
}
void debug()
{
	float all=0.0;
	for(auto i:bonus)
	{
		cout<<i<<" ";
		all+=i;
	}
	cout<<endl;
	cout<<all<<endl;
}
int main()
{
	// test cases
	if(solve(200.0,10)) debug();
	if(solve(0.11,3)) debug();
	if(solve(0.10,10)) debug();
	// corner cases
	if(solve(200.1,10)) debug();
	if(solve(-200.0,10)) debug();
	if(solve(200.0,0)) debug();
	if(solve(0.10,11)) debug();
	if(solve(0.111,11)) debug();
	
	return 0;
}
 
