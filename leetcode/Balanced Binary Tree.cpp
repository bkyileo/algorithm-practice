#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
        
        if (!root) return 0;
    	queue<TreeNode*> level;
    	int res=0;
    	level.push(root);
    	while(!level.empty())
    	{
    		int size=level.size();
    		for(int i=0;i<size;++i)
    		{
    			if (level.front()->left)
    				level.push(level.front()->left);
    			if (level.front()->right)
    				level.push(level.front()->right);
    			cout<<level.front()->val<<" ";	
    			level.pop();
    		}
    		cout<<endl;
    		++res;
    	}
    	return res;
		}
//[3,9,20,null,null,15,7]
int main()
{
	TreeNode* a=new TreeNode(3); 
	TreeNode* b=new TreeNode(9); 
	TreeNode* c=new TreeNode(20); 
	TreeNode* d=new TreeNode(15); 
	TreeNode* e=new TreeNode(7); 
	a->left=b;
	a->right=c;
	c->left=d;
	c->right=e;
	
	cout<<maxDepth(a)<<endl;
}
