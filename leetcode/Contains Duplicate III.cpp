#include<bits/stdc++.h>
using namespace std;

struct node
{
	long long val;
	int index;
	node *left;
	node *right;
	node(long long x,int y):val(x),index(y),left(NULL),right(NULL){
	}
};

bool dfs(node *root,node *curr,int t,int k)
{
	
	if(abs(curr->val-root->val)<=t && curr->index-root->index<=k)
		return true;
	if(!root->left && !root->right)
		return false;
		
	float diff=curr->val-root->val;
	if(root->left && diff<=t)
		if(dfs(root->left,curr,t,k))
			return true;
	if(root->right && -diff<=t)
		if(dfs(root->right,curr,t,k))
			return true;
	return false;
}


void insert(node *root,node *curr,int t,int k)
{
	if(curr->val>root->val)
	{
		if(!root->right)
		{
			root->right=curr;
			return ;
		}
		else
		{
			insert(root->right,curr,t,k);		
		}
	}
	else
	{
		if(!root->left)
		{	
			root->left=curr;
			return ;			
		}
		else
		{
			insert(root->left,curr,t,k);			
		}
	} 
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	
	if(nums.size()==0) return false;
	node * root=new node(nums[0],0);
    for(int i=1;i<nums.size();i++)
    {
    	node * curr=new node(nums[i],i);
    	if(dfs(root,curr,t,k))
    		return true;
    	insert(root,curr,t,k);

	}
	return false;
}

int main()
{
	int a[2]={-1,2147483647};
	vector<int> b(a,a+2);
	//cout<<INT_MAX<<endl;
	cout<<containsNearbyAlmostDuplicate(b,1,2147483647);
	return 0;
}
