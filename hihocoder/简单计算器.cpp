//hihocoder 简单计算器
#include<bits/stdc++.h>
using namespace std;
//直接给出优先级比较好 
vector<string> polish(string s)
{
	vector<string> res;
	stack<string> helper;
	int curr=0;
	bool flag=false;
	for(int i=0;i<s.length();++i)
	{
		//cout<<s[i]<<endl;
		if(isdigit(s[i]))
		{
			curr=10*curr+s[i]-'0';
			flag=true;
		}
		else
		{
			if(flag)
				res.push_back(to_string(curr));	
			curr=0;
			flag=false;
			
			if(s[i]=='+')
			{
				while(!helper.empty()&&helper.top()!="(")
				{
					res.push_back(helper.top());
					helper.pop();
				}
				helper.push("+");
			}
			if(s[i]=='-')
			{
				while(!helper.empty()&&helper.top()!="(")
				{
					res.push_back(helper.top());
					helper.pop();
				}
				helper.push("-");
			}
			if(s[i]=='*')
			{
				if(!helper.empty() && (helper.top()=="+"||helper.top()=="-"))
				{
					helper.push("*");
				}
				else
				{
					while(!helper.empty() && (helper.top()=="*"||helper.top()=="/"))
					{
						res.push_back(helper.top());
						helper.pop();
					}
					helper.push("*");
				}
			}
			if(s[i]=='/')
			{
				if(!helper.empty() && (helper.top()=="+"||helper.top()=="-"))
				{
					helper.push("/");
				}
				else
				{
					while(!helper.empty() && (helper.top()=="*"||helper.top()=="/"))
					{
						res.push_back(helper.top());
						helper.pop();
					}
					helper.push("/");
				}
			}
			if(s[i]=='(')
			{
				helper.push("(");
			}
			if(s[i]==')')
			{
				while(helper.top()!="(")
				{
					res.push_back(helper.top());
					helper.pop();
				}
				helper.pop();
			}
		}
	}
	if(flag) 
		res.push_back(to_string(curr));
	while(!helper.empty())
	{
		res.push_back(helper.top());
		helper.pop();
	}
	//for(auto i:res)
	//cout<<i<<" ";cout<<endl;
	return res;
}

int evalRPN(vector<string> tokens) {
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
	string s;
	cin>>s;
	//polish("1+((2+3)*4)-5");
	cout<<evalRPN(polish(s))<<endl;
	return 0;
}
