//Given a binary search tree (BST), find the lowest common ancestor (LCA) 
//of two given nodes in the BST.
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int l=p->val;
    int r=q->val;
    if(r<l)
    {
    	int temp=l;
    	l=r;r=temp;
	}
	if(root->val>=l && root->val<=r)
		return root;
	if(root->val>r)
		return lowestCommonAncestor(root->left,p,q);
	if(root->val<l)
		return lowestCommonAncestor(root->right,p,q);
}
int main()
{
	return 0;
}

