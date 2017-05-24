#include<bits/stdc++.h>
using namespace std;

vector<int> countBits(int num) {
	vector<int> res;
	if(num==0) return res;
	res.push_back(0);
	for(int i=1;i<=num;++i)
	{
		if(i%2)
		{
			res.push_back(res[res.size()-1]+1);
		}
		else
		{
			int count=0;
			int temp=i;
			while(temp%2==0)
			{
				count++;
				temp/=2;
			}
			res.push_back(res[res.size()-1]+1-count);
		}
	}  
	return res;   
}
int main()
{
	vector<int> res=countBits(16);
	for(auto i:res)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}
