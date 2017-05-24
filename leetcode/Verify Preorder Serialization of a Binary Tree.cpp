#include<bits/stdc++.h>
using namespace std;
bool isValidSerialization(string preorder) {
	vector<string> temp;
	string curr="";
	for(int i=0;i<preorder.length();++i)
	{
		if(preorder[i]==',')
		{
			temp.push_back(curr);
			curr="";
		}
		else
		{
			curr+=preorder[i];
		}		
	}
	temp.push_back(curr);
	//for(auto i:temp)cout<<i<<" ";cout<<endl;
	if(temp.size()==1&&temp[0]=="#")return true;
	else if(temp[0]=="#")return false;
	stack<int> sk;
	sk.push(0);
	for(int i=0;i<temp.size();++i)
	{
		if(sk.empty())return false;
		if(temp[i]!="#")
		{
			sk.top()+=1;
			sk.push(0);
		}
		else
		{
			if(sk.top()<2)
			{
				sk.top()+=1;
			}	
		}
		while(!sk.empty()&&sk.top()==2)
		{
			sk.pop();
		}
	}
	if(!sk.empty())return false;
	else return true;    
}
int main()
{
	cout<<isValidSerialization("9,#,#")<<endl;
	return 0;
} 
