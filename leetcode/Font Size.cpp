#include<bits/stdc++.h>
using namespace std;

bool can(vector<int> paragraphs ,int w,int h,int curr,int P)
{
	// W / S characters in a line and  H / S lines in a page
	int p;
	int cols = (w/curr) ; // һ�м����� 
	int rows = (h/curr) ; // һҳ������ 
//	cout<<"һ�м����� "<<cols<<endl;
//	cout<<"һҳ������ "<<rows<<endl;
	int lines;
	int alllines=0;
	
	for(int i=0;i<paragraphs.size();++i)
	{
		lines = paragraphs[i]/cols;
		if(paragraphs[i]%cols>0) ++lines;
//		cout<<"��һ�μ���"<<lines<<endl;
		alllines += lines;
	}
//	cout<<"һ�������� "<<alllines<<endl;
	p=alllines/rows;
	
	if(alllines%rows>0) ++p;
//	cout<<"һ������ҳ"<<p<<endl; 
	 
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
