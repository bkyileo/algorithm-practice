#include<bits/stdc++.h>
using namespace std;


int calculate(string s) {
    int res=0;
    int sign=1;
    int temp=0;
	stack<int> signs,nums;
	for(auto i:s)
	{
		if(isdigit(i))
		{
			temp = temp*10 + i-'0';
		}
		else
		{
			res += sign*temp;
			temp=0;

			if(i=='(')
			{
				nums.push(res);
				signs.push(sign);
				res=0;
				sign=1;
			}
			if(i==')')
			{
				res = nums.top()+res*signs.top();
				nums.pop();
				signs.pop();
				sign=1;
			}
			if(i=='+')
			{
				sign=1;
			}
			if(i=='-')
			{
				sign=-1;
			}
		}
	}
	res += temp*sign;
	return res;
} 

int main()
{
	cout<<calculate("1-(5)")<<endl;
	return 0;
}
