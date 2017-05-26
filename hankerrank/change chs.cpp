#include<bits/stdc++.h>
using namespace std;
void func(string s)
{
	//int i=0;
	int j=0;
	int k=s.length()-1;
	while(j<k)
	{
		if(s[j]<='z'&&s[j]>='a')
		{
			//i++;
			j++;
		}
		else if (s[j]<='Z'&&s[j]>='A')
		{
			swap(s[j],s[k--]);
		}
	}
	cout<<s<<endl;
}
bool com(char a,char b)
{
	bool upper1= (a<='z'&&a>='a')?false:true;
	bool upper2= (b<='z'&&b>='a')?false:true;
	if((upper1&&upper2)||(!upper1&&!upper2))return a<=b;
	if(upper1) return false;
	if(upper2) return true;
}
int main()
{
	string s="aAbBcCdDeE";
	//func(s);
	sort(s.begin(),s.end(),com);
	cout<<s<<endl;
	return 0;
}
