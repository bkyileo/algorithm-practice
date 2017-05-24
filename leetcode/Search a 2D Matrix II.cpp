//Search a 2D Matrix II

#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& line, int target,int left,int right)
{
	if(line[left]>target || line[right]<target) return false;
	int mid ;
	while(left!=right-1)
	{
		mid = (left+right)>>1;
		if(line[mid]>target)
		{
			right=mid;
		}
		else
		{
			left=mid;
		}
	}
	cout<<line[left]<<"~"<<line[right]<<endl;
	if(line[left]==target||line[right]==target)
		return true;
	return false; 
} 

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int i=matrix.size();
	int j=matrix[0].size();
	if(i==0||j==0) return false;
	for(auto i:matrix)
	{
		for(auto k:i)
		{
			cout<<k<<" ";
		}
		cout<<endl;
		
		if(search(i,target,0,j-1))
			return true;
	}
	return false;	
} 
 
int main()
{
	vector< vector<int> > temp;
	int a[3]={1,3,5};
	int b[3]={6,7,12};
	int c[3]={11,14,14};
	
	vector<int> a1(a,a+3);
	vector<int> b1(b,b+3);
	vector<int> c1(c,c+3);
	
	temp.push_back(a1);
	temp.push_back(b1);
	temp.push_back(c1);
	
	
	cout<<searchMatrix(temp,14)<<endl;
	return 0;
}
