#include<bits/stdc++.h>
using namespace std;

bool can(vector<int> paragraphs ,int w,int h,int curr,int P)
{
	// W / S characters in a line and  H / S lines in a page
	int p;
	int cols = (w/curr) ; // 一行几个字 
	int rows = (h/curr) ; // 一页多少行 
//	cout<<"一行几个字 "<<cols<<endl;
//	cout<<"一页多少行 "<<rows<<endl;
	int lines;
	int alllines=0;
	
	for(int i=0;i<paragraphs.size();++i)
	{
		lines = paragraphs[i]/cols;
		if(paragraphs[i]%cols>0) ++lines;
//		cout<<"这一段几行"<<lines<<endl;
		alllines += lines;
	}
//	cout<<"一共多少行 "<<alllines<<endl;
	p=alllines/rows;
	
	if(alllines%rows>0) ++p;
//	cout<<"一共多少页"<<p<<endl; 
	 
	if(p<=P)
		return true;
	else
		return false; 
} 

int main()
{
	int count;
	cin>>count;
	int characters;
	int left;
	int right;
	int mid;
	int res;
//	cout<<count<<endl;
	while(count--)
	{
		int  N,P,W,H;
		cin>>N>>P>>W>>H;
		vector<int> paragraphs;
		while(N--)
		{
			cin>>characters;
			paragraphs.push_back(characters);
		}
//		cout<<N<<P<<W<<H<<endl;
		left = 1;
		right = W>H?H:W;
//		cout<<left<<""<<right<<endl;
		while(left+1 != right)
		{
			mid=(left+right)/2;
//			cout<<"mid"<<mid<<endl;
			if (can(paragraphs,W,H,mid,P))
				left=mid;
			else
				right=mid;
		}
//		cout<<left<<"here"<<right<<endl;
		if ( can(paragraphs,W,H,right,P) )
			cout<<right<<endl;
		else
			cout<<left<<endl;
	}
	return 0;
}
