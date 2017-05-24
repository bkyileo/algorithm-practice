//leetcode Evaluate Reverse Polish Notation
#include<bits/stdc++.h>
using namespace std;
//Çë¿¼ÂÇ¸ºÊý  
int evalRPN(vector<string>& tokens) {
    stack<int> s;
	for(auto i:tokens)
	{
		if(i.length()==1&&(i[0]=='+'||i[0]=='-'||i[0]=='*'||i[0]=='/')) 
		{
			int b=s.top();s.pop();
			int a=s.top();s.pop();
			//cout<<a<<" "<<b<<endl;	
			if(i[0]=='+')a=a+b;
			else if(i[0]=='-')a=a-b;
			else if(i[0]=='*')a=a*b;
			else if(i[0]=='/')a=a/b;
			s.push(a);
		}
		else
		{
			if(isdigit(i[0]))
			{
				int curr=0;
				for(auto j:i)
				{
					curr=10*curr+j-'0'; 
				}
				s.push(curr);
			}
			else
			{
				int sign;
				int curr=0;
				if(i[0]=='-')
					sign=-1;			
				for(int j=1;j<i.length();++j)
				{
					curr=10*curr+i[j]-'0'; 
				}
				s.push(sign*curr);
			}
			
		}
	}
	return s.top();
}

int main()
{
	vector<string> t;
	//["4", "13", "5", "/", "+"]
	t.push_back("4");
	t.push_back("-13");
	t.push_back("5");
	t.push_back("/");
	t.push_back("+");
	cout<<evalRPN(t)<<endl;
	return 0;
}
