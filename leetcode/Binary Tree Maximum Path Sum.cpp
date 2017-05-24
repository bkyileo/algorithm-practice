/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/ 
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxchild(TreeNode * root,int premax,int local)
{
	if (!root) return premax;
	local=local+root->val;
	premax=max(local,premax);
	return max(maxchild(root->left,premax,local),maxchild(root->right,premax,local));
}

int helper(TreeNode* root)
{
	    int left = maxchild(root->left,root->val,root->val);
        int right = maxchild(root->right,root->val,root->val);
    	int res = max(max(left,right),left+right-root->val);
		return res;
}
void  helper2(TreeNode* root,vector<int> &temp)
{
	if (!root) return ;
	temp.push_back(helper(root));
	helper2(root->left,temp);
	helper2(root->right,temp);
}
int maxPathSum(TreeNode* root) {
	vector<int> temp;
	helper2(root,temp);
	int res=INT_MIN;
	for(int i=0;i<temp.size();++i)
	{
		cout<<temp[i]<<" ";
		res=max(temp[i],res);
	}
	cout<<endl;
	return res;
}
int main() 
{
	TreeNode *a = new TreeNode(-1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	TreeNode *d = new TreeNode(-4);
	TreeNode *e = new TreeNode(-5);
	TreeNode *f = new TreeNode(6);
	TreeNode *g = new TreeNode(7);
	
	a->left=b;a->right=c;b->left=d;b->right=e;c->left=f;c->right=g;
	cout<<maxchild(a,0,0)<<endl;
	cout<<maxPathSum(a)<<endl;
}
