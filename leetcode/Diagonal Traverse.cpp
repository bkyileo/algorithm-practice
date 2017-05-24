#include<bits/stdc++.h>
using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    vector<vector<int>> tp(matrix.size()+matrix[0].size()-1);
    for(int i=0;i<matrix[0].size();++i)
    for(int j=0;j<matrix.size();++j)
    {
    	tp[i+j].push_back(matrix[j][i]);
	}
	vector<int> res;
	bool f=true;
	for(auto i:tp)
	{
		if(f)
		{
			for(int j=0;j<i.size();++j)res.push_back(i[j]);
		}
		else
		{
			for(int j=i.size()-1;j>=0;--j)res.push_back(i[j]);
		}
		f=!f;
	}
	return res;
} 
int main()
{
	vector<int>a={1,2,3};
	vector<int>b={4,5,6};
	vector<int>c={7,8,9};
	vector<int>d={10,11,12};
	vector<vector<int>>arr;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	arr.push_back(d);
	vector<int> res=findDiagonalOrder(arr);
	for(auto i:res)cout<<i<<" ";cout<<endl;
}
