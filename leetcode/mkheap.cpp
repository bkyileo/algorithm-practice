#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//������ν�һ����С��
void mkheap(TreeNode* root)
{
	if(!root->left && !root->right) return;
	if(root->left && root->val>root->left->val)
	{
		int temp=root->val;
		root->val=root->left->val;
		root->left->val=temp;
	}
	if(root->right && root->val>root->right->val)
	{
		int temp=root->val;
		root->val=root->right->val;
		root->right->val=temp;
	}
	if(root->left)mkheap(root->left);
	if(root->right)mkheap(root->right);
	
}

int main()
{
	vector<int> heap;
	
} 
