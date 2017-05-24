#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(stack<TreeNode*> & pipe,TreeNode* root)
{
	if(root->left && root->right)
	{
		pipe.push(root->right);
		root->right=root->left;
		root->left=NULL;
		helper(pipe,root->right);
	}
	
	if(!root->left && root->right)
		helper(pipe,root->right);
	
	if(root->left && !root->right)
	{
		root->right=root->left;
		root->left=NULL;
		helper(pipe,root->right);
	}
	
	if(!root->left && !root->right)
	{
		if(pipe.empty())
			return ;
		else
		{
			root->right=pipe.top();
			pipe.pop();
			helper(pipe,root->right);
		}
	}
}


void flatten(TreeNode* root) {
        stack<TreeNode*> pipe;
        if(!root) return;
        helper(pipe,root);
        
    }
    
void run(TreeNode* root)
{
	if(!root)return;
	cout<<root->val<<" ";
	run(root->right);
}

void run2(TreeNode* root)
{
	if(!root)return;
	run(root->left);
	cout<<root->val<<" ";
	run(root->right);
}

int main()
{
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(5);
	TreeNode* d = new TreeNode(3);
	TreeNode* e = new TreeNode(4);
	TreeNode* f = new TreeNode(6);
	a->left=b;a->right=c;b->left=d;b->right=e;c->right=f;
	flatten(a);
	run(a);
	cout<<endl;
	run2(a);
}
