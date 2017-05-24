#include<bits/stdc++.h>
using namespace std;
bool help(vector<int> used,int n)
{
	//for(auto i:used)cout<<i<<" ";cout<<endl;
	//cout<<"n : "<<n<<endl;
	for(int i=0;i<used.size();i++)
	{
		if(used[i]==0&&i+1>=n)return true;
	}
	for(int i=0;i<used.size();i++)
	{
		if(used[i]==0)
		{ 
			used[i]=1;
			if(!help(used,n-i-1))return true;
			used[i]=0;
		} 
	}
	return false;
} 
bool canIWin(int maxChoosableInteger, int desiredTotal) {
	if(maxChoosableInteger>=desiredTotal)return true;
	if((maxChoosableInteger+1)*maxChoosableInteger/2<desiredTotal)return false;
	vector<int> use=vector<int>(maxChoosableInteger,0);
	return help(use,desiredTotal);
}
int main()
{
	cout<<canIWin(10,11)<<endl;
	return 0;
}
