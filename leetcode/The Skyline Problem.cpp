#include<bits/stdc++.h>
//buildings l r h
using namespace std;
bool com(vector<int> a,vector<int> b)
{
	if(a[0]!=b[0])return a[0]<b[0];
	else
	{
		if(a[1]==b[1])return a[2]>b[2];
		if(a[1]>b[1]&&a[2]==1&&b[2]==1)return true;
		if(a[1]>b[1]&&a[2]==1&&b[2]==-1)return true;
		if(a[1]>b[1]&&a[2]==-1&&b[2]==1)return false;
		if(a[1]>b[1]&&a[2]==-1&&b[2]==-1)return false;
		
		if(a[1]<b[1]&&a[2]==1&&b[2]==1)return false;
		if(a[1]<b[1]&&a[2]==1&&b[2]==-1)return false;
		if(a[1]<b[1]&&a[2]==-1&&b[2]==1)return true;
		if(a[1]<b[1]&&a[2]==-1&&b[2]==-1)return true;
		/*
		if(a[1]!=b[1])return a[1]>b[1];
		else
		{
			return a[2]>b[2];
		}
		*/
	}
	//return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
}
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> tp;
    int l,r,h;
	for(int i=0;i<buildings.size();++i)
	{
		//x,y,h
		//x,h,bool
		vector<int> curr0(3);
		curr0[0]=buildings[i][0];
		curr0[1]=buildings[i][2];
		curr0[2]=1;
		tp.push_back(curr0);
		vector<int> curr1(3);
		curr1[0]=buildings[i][1];
		curr1[1]=buildings[i][2];
		curr1[2]=-1;
		tp.push_back(curr1);
	}
	sort(tp.begin(),tp.end(),com);
	multiset<int> s;
	s.insert(0);
	vector<pair<int, int>> res;
	for(auto i:tp)
	{
		
		if(i[2]==1)
		{
			s.insert(i[1]);
			if(i[1]==*s.rbegin()&&s.count(i[1])==1)
			res.push_back(make_pair(i[0],i[1]));
		}
		if(i[2]==-1)
		{
			if(*s.rbegin()==i[1]&&s.count(i[1])==1)
			{
				//cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
				s.erase(s.find(i[1]));	
				res.push_back(make_pair(i[0],*s.rbegin()));
			}
			else
			{
				s.erase(s.find(i[1]));
			}
		}
	}
	//for(auto i:res)cout<<i.first<<" "<<i.second<<endl;
	return res;
}
int main()
{
	vector<vector<int>> buildings;
	int a1[3]={1,2,1};
	int b1[3]={1,2,2};
	int c1[3]={1,2,3};
	//int d1[3]={15,20,10};
	//int e1[3]={19,24,8};
	
	vector<int> a(a1,a1+3);
	vector<int> b(b1,b1+3);
	vector<int> c(c1,c1+3);
	//vector<int> d(d1,d1+3);
	//vector<int> e(e1,e1+3);
	
	buildings.push_back(a);
	buildings.push_back(b);
	buildings.push_back(c);
	//buildings.push_back(d);
	//buildings.push_back(e);
	//[[0,2,3],[2,5,3]]
	getSkyline(buildings);
	return 0;
}
