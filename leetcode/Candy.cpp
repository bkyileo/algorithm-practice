#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
	if (ratings.size()==0) return 0;
	vector<int> temp(ratings.size(),1);
	for(int i=1;i<ratings.size();++i)
	{
		if(ratings[i]>ratings[i-1])
		{
			temp[i]=temp[i-1]+1;
		}
	}

	for(int i=ratings.size()-1;i>0;--i)
	{
		if(ratings[i]<ratings[i-1] && temp[i-1]<temp[i]+1)
		{
			temp[i-1]=temp[i]+1;
		}
	}
	int res=0;
	for(int i=0;i<temp.size();++i)
	{
		res += temp[i];
	}

	 
	return res;
}

int main()
{
	int a[12] = {5, 6, 2, 2, 4, 8, 9, 5, 4, 0, 5, 1};
	vector<int> ratings(a,a+12);
	for(int i=0;i<ratings.size();++i)
	cout<<ratings[i]<<" ";
	cout<<endl;
	cout<<candy(ratings)<<endl;
}
