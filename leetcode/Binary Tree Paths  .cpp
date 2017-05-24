#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(vector<string> &res,TreeNode* root,string s)
{
	if(!root->left&&!root->right)
	{
		s=s+s+to_string(root->val)
		res.push_back(s);
		return ;
	}
	
	s = s+to_string(root->val)+"->";
	if(root->left)
		dfs(res,root->left,s);
	if(root->right) 
		dfs(res,root->right,s);
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> temp;
	if(!root) return temp;
	dfs(temp,root,"");
	return temp;    
} 
