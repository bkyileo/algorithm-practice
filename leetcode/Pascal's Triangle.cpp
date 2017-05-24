/*
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > generate(int numRows) {
	vector< vector<int> > res;
	if(numRows==0) return res;
	int curr=1;
	while(curr<=numRows)
	{
		vector<int> temp;
		for(int i=0;i<curr;++i)
		{
			if (i==0 || i==curr-1)
				temp.push_back(1);
			else
				temp.push_back(res[curr-2][i-1]+res[curr-2][i]);
		}
		res.push_back(temp);
		curr++;
	}
	return res;
}
void tral(vector< vector<int> > res)
{
	for(int i=0;i<res.size();++i)
	{
		for(int j=0;j<res[i].size();++j)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
 } 
int main()
{
	vector< vector<int> > res=generate(10);
	tral(res);
}
