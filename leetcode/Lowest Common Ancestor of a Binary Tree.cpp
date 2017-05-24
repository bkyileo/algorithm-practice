//Lowest Common Ancestor of a Binary Tree 

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

bool dfs(TreeNode* root, TreeNode* p)
{
	if(!root) return false;
	if(root==p) return true;
	if(dfs(root->left,p)||dfs(root->right,p)) return true;
	return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==p||root==q) return root;
    bool flag=dfs(root->left,p);
    if(flag^dfs(root->left,q)) return root;
    if(flag) return lowestCommonAncestor(root->left,p,q);
    return lowestCommonAncestor(root->right,p,q);
}

int main()
{
	return 0;
}
