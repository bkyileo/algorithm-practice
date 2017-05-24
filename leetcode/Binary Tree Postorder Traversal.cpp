/*
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct node{
	TreeNode* tree;
	bool left;
	bool right;
	node(TreeNode* a) : tree(a), left(false),right(false) {}
};
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root)	return res;
    stack<node> temp;
	temp.push(node(root));
	while( !temp.empty() )
	{
		node a = temp.top();
		
		if( (a.left && a.right) || ( a.left&& !a.tree->right) || ( a.right&& !a.tree->left) || ( !a.tree->left && !a.tree->right) )
		{
			res.push_back(a.tree->val);
			temp.pop();
			continue;
		}
		
		if( !a.left && a.tree->left)
		{
			temp.top().left=true;
			temp.push(node(a.tree->left));
			continue;
		}
		
		if( !a.right && a.tree->right)
		{
			temp.top().right=true;
			temp.push(node(a.tree->right));
			continue;
		}

	} 
	return res;
}
int main()
{
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	TreeNode *d = new TreeNode(4);
	TreeNode *e = new TreeNode(5);
	a->left=b;a->right=c;b->right=d;c->left=e;
	
	vector<int> res=postorderTraversal(a);
	for(int i=0;i<res.size();++i)
		cout<<res[i]<<" ";
	cout<<endl;
	
	return 0;
}
