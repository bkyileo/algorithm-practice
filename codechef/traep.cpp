//hihocoder Æ½ºâÊ÷¡¤Treap
//lower_bound test
#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::set<int>::iterator itlow;
	set<int> st;
	int n;cin>>n;
	char ch;
	int curr;
	while(n--)
	{
		cin>>ch>>curr;
		if(ch=='I')
			st.insert(curr);
		if(ch=='Q')
		{
			itlow=st.lower_bound(curr);
			if(*itlow==curr)
				cout<<curr<<endl;
			else
			{
				itlow--;
				cout<<*itlow<<endl;
			}
		}
	}
	return 0;
}
