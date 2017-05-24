/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/ 
#include<bits/stdc++.h>
using namespace std;
struct TreeLinkNode {
 	int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void dfs(TreeLinkNode *left,TreeLinkNode *right)
{
	if(!left) return;
	left->next=right;
	right->next=NULL;
//	TreeLinkNode *df1 = left->left? left->left:left->right? :left->right? :right->left?right->left:right->right;
//	TreeLinkNode *df2 = left->left? left->left:left->right? :left->right? :right->left?right->left:right->right;
//	TreeLinkNode *df3 = left->left? left->left:left->right? :left->right? :right->left?right->left:right->right;
//	TreeLinkNode *df4 = left->left? left->left:left->right? :left->right? :right->left?right->left:right->right;
	dfs(left->left,left->right);
	dfs(left->right,right->left);
	dfs(right->left,right->right);
}
void connect(TreeLinkNode *root) {
    if(!root)return;
    root->next=NULL;
    if (!root->left && root->right) connect(root->right);
    if (root->left && !root->right) connect(root->left);
    dfs(root->left,root->right);
    }
/*
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/    
int main()
{ 
	TreeLinkNode *a=new TreeLinkNode(1);
	TreeLinkNode *b=new TreeLinkNode(2);
//	TreeLinkNode *c=new TreeLinkNode(3);
//	TreeLinkNode *d=new TreeLinkNode(4);
//	TreeLinkNode *e=new TreeLinkNode(5);
//	TreeLinkNode *f=new TreeLinkNode(7);
	
	a->left=b;
	//a->right=c;b->left=d;b->right=e;c->right=f;
	return 0;
}
