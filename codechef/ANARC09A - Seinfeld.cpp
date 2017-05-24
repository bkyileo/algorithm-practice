//spoj ANARC09A - Seinfeld
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int index=1;
	string s;
	while(cin>>s)
	{
		int temp=0;
		int nums=0;
		if(s[0]=='-')break;
		for(auto i:s)
		{
			if(i=='{')temp++;
			if(i=='}')
			{
				if(temp>0)temp--;
				else
				{
					nums++;
					temp++;
				}
			}
		}
		if(temp>0)
			nums+=temp/2;
		cout<<index<<". "<<nums<<endl;
		index++;
	}
	return 0;
}
//1. 2
