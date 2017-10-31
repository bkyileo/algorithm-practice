#include<bits/stdc++.h>
using namespace std;
/*
in :
2 3 3 2
1 2 3 4 5 6
1 3 2 2 3 1

out : 
14 10
32 28
*/
int rowA,colA,rowB,colB;
bool matrixMultify(vector<int>& a,vector<int>& b,vector<int>& res)
{
	if(colA!=rowB)return false;
	else
	{
		for(int i=0;i<rowA*colB;++i)
		{
			int currRow = i/colB;
			int currCol = i%colB;
			for(int j=0;j<colA;++j)
			{
				res[i] += a[currRow*colA+j] * b[colB*j+currCol]; 
			}
		}
	}
	return true;
}
int main()
{
	cin>>rowA>>colA>>rowB>>colB;
	vector<int> a(rowA*colA);
	vector<int> b(rowB*colB);
	
	for(int i=0;i<rowA;++i)
	for(int j=0;j<colA;++j)
	cin>>a[i*colA+j];
	
	for(int i=0;i<rowA;++i)
	for(int j=0;j<colA;++j)
	cin>>b[i*colA+j];
	
	vector<int> res(rowA*colB);
	matrixMultify(a,b,res);
	
	for(int i=0;i<rowA;++i)
	{
		for(int j=0;j<colB;++j)
			cout<<res[i*colB+j]<<" ";
		cout<<endl;
	}
	
	return 0;
} 
