#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void qsort(vector<int> &nums,int l,int r)
{
	if(l>=r) return;

	int right =r;
	
	int temp=nums[l];
	int i=l;
	int j=l;
	while(j<=right)
	{
		if(nums[j]<temp)
		{
			swap(nums[i],nums[j]);
			i++;
			j++;
		}
		else if(nums[j]>temp)
		{
			swap(nums[right],nums[j]);
			right--;
		}
		else
		{
			j++;
		}
	}
	qsort(nums,l,i);
	qsort(nums,j,r);
}

int main()
{
	int a[6]={2,1,4,3,5,4};
	vector<int> t(a,a+6);
	qsort(t,0,5);
	for(auto i:t)
	{
		cout<<i<<" ";
	} 
	cout<<endl;
}
