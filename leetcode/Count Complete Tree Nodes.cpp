#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode* root)
{
	//get levels 
	int res=0;
	while(root)
	{
		root=root->left;
		res++;
	}
	return res;
}

void findPath(TreeNode* root,vector<bool> &path)
{
	if(!root) return ;
	if(dfs(root->left)==dfs(root->right))
	{
		path.push_back(true);
		findPath(root->right,path);
	}
	if(dfs(root->left)!=dfs(root->right))
	{
		path.push_back(false);
		findPath(root->left,path);
	}
}

int countNodes(TreeNode* root) {
	if(!root) return 0;
	vector<bool> path;
	findPath(root,path);
	int base=dfs(root);
	int res=1<<(base-1);
	int add=1<<(base-1);
//	for(auto i:path)
//	{
//		cout<<i<<endl;
//	}
//	
	for(auto i:path)
	{
		if(i)
		{
			add = add>>1;
			res += add;
		}
		else
		{
			add=add>>1; 
		} 
	}
	return res;
}

int main()
{
	TreeNode *a=new TreeNode(0);
	TreeNode *b=new TreeNode(0);
	TreeNode *c=new TreeNode(0);
	TreeNode *d=new TreeNode(0);
	//TreeNode *e=new TreeNode(0);
	
	a->left=b;a->right=c;
	b->left=d;
	//b->right=e;
	
	cout<<countNodes(a)<<endl;
	return 0;
	
}
