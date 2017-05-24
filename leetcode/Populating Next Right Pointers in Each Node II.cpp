#include<bits/stdc++.h>
using namespace std;
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root) {
        TreeLinkNode *pre  = new TreeLinkNode(0);
		TreeLinkNode *curr = new TreeLinkNode(0);
        //bfs ±éÀú
		while(root)
		{	
			
			if(root->left)
			{
				pre->next=root->left;
				pre=pre->next;
			}
			
			if(root->right)
			{
				pre->next=root->right;
				pre=pre->next;
			}
			
			root=root->next;
			
			if(!root)
			{
				
				root = curr->next;
				curr->next=NULL;
				pre  = curr;
				curr = pre;
			}
			
		 } 
        
    }

int main()
{
	TreeLinkNode *a = new TreeLinkNode(1);
	TreeLinkNode *b = new TreeLinkNode(2);
	TreeLinkNode *c = new TreeLinkNode(3);
	TreeLinkNode *d = new TreeLinkNode(4);
	TreeLinkNode *e = new TreeLinkNode(5);
	a->left=b;a->right=c;b->left=d;b->right=e;
	connect(a);
}
