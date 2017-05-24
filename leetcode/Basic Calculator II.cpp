//Implement 
//a basic calculator to evaluate a simple expression string.

//The expression string contains only non-negative integers, +, -, *, / 
//operators and empty spaces . The integer division should truncate toward zero. 

#include<bits/stdc++.h>
using namespace std;

int calculate(string s) {
	int res=0;
	int last=0;
	int temp=0;
	int sign=1;
	s='+'+s;
	for(int i=0;i<s.length();)
	{

		if(s[i]=='+')
		{
			sign=1;
			while(!isdigit(s[i]))
			{
				i++;
			}
			while(isdigit(s[i]))
			{
				temp=temp*10+s[i]-'0';
				i++;
			}
			last=temp;
			res+=temp;
			temp=0;
		}
		else if(s[i]=='-')
		{
			sign=-1;
			while(!isdigit(s[i]))
			{
				i++;
			}
			while(isdigit(s[i]))
			{
				temp=temp*10+s[i]-'0';
				i++;
			}
			last=temp;
			res-=temp;
			temp=0;
		}
		else if(s[i]=='*')
		{
			res -= sign*last;
			while(!isdigit(s[i]))
			{
				i++;
			}
			while(isdigit(s[i]))
			{
				temp=temp*10+s[i]-'0';
				i++;
			}
			last=last*temp;
			res += sign*last;
			temp=0;
		}
		else if(s[i]=='/')
		{
			res -= sign*last;
			while(!isdigit(s[i]))
			{
				i++;
			}
			while(isdigit(s[i]))
			{
				temp=temp*10+s[i]-'0';
				i++;
			}
			last=last/temp;
			res += sign*last;
			temp=0;
		}
		else
			++i;
	}
	
	return res;
} 
int main()
{
	cout<<calculate(" 3+5 / 2 ")<<endl;
	return 0;
}
