#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void find(vector<int> vec,int val)
{
	//一定可以找得到 
	int index=0;
	while(index!=vec.size() && vec[index]!=val)++index;
	return index;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<TreeNode*> s;
        if (preorder.size()==0) return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);
		TreeNode* curr = root;
        
        for(int i=1;i<preorder.size();++i)
        {
        	if(find(inorder,preorder[i])<find(inorder,s.top()->val))
        	{
        		TreeNode* temp = new TreeNode(preorder[i]);
        		s.push(temp);
        		curr->left=temp;
        		curr=s.top();
			}
			else
			{
				TreeNode* temp = new TreeNode(preorder[i]);
				while(find(inorder,preorder[i])>find(inorder,s.top()->val) && !s.empty())
					{
						curr=s.top();
						s.pop();
					}
				curr->right=temp;
				s.push(temp);
				curr=s.top();
			} 
		}
		return root;
    }
};
