#include<bits/stdc++.h>
using namespace std;
//10ÒÔÄÚµÄ½×³Ë 
int ns(int n)
{
	if(n==0)return 1;
	return n*ns(n-1);
}

int cantor(vector<int> a)
{
	int res=0;
	vector<int> temp(a.size(),0);
	for(int i=0;i<a.size();i++)
	{
		for(int j=i+1;j<a.size();++j)
		{
			if(a[j]<a[i])temp[i]++;
		}
	}
	for(int i=0;i<a.size();++i)
	{
		//cout<<temp[i]<<" "<<9-i<<endl;
		res+=temp[i]*ns(a.size()-1-i);
	}
	return res;
}
vector<int> recantor(int a,int nums)
{
	vector<bool> visit(nums,false);
	vector<int> res;
	for(int i=0;i<nums;++i)
	{
		int temp=ns(nums-1-i);
		int b=a/temp;
		int c=a-b*temp;
		int index=b;
		for(int j=0;j<index;++j)
		{
			if(visit[j])index++;
		}
		while(visit[index])index++;
		res.push_back(index);
		visit[index]=true;
		a=c;
	}
	return res;
}
main()
{
	//cout<<ns(5)<<endl;
	cout<<cantor(vector<int>{8,7,6,5,4,3,2,1,0})<<endl;

	
	vector<int> res2=recantor(98884,9);	
	for(auto i:res2)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
} 
