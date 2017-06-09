#include<bits/stdc++.h> 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int l1,int r1,int l2,int r2)
{
	/*
		inorder   left root right
		postorder left right root
	*/
	if(r1<l1)return NULL;
	TreeNode* p = new TreeNode(postorder[r2]);
	int ct=-1;
	for(int i=l1;inorder[i]!=postorder[r2];++i)ct++;
	//left ct el
	p->left = helper(inorder,postorder,l1,l1+ct,l2,l2+ct);
	p->right = helper(inorder,postorder,l1+ct+2,r1,l2+ct+1,r2-1);
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
