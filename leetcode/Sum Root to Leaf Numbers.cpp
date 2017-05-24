#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void dfs(TreeNode* root,int curr,vector<int> &temp)
{
	if(root->left || root->right)
	{
		if(root->left)
			dfs(root->left,curr*10+root->val,temp);
		if(root->right)
			dfs(root->right,curr*10+root->val,temp);
	}
	else
		temp.push_back(curr*10+root->val);
}

int sumNumbers(TreeNode* root) {
    int res=0;
	vector<int> temp;
    dfs(root,0,temp);
    for(int i=0;i<temp.size();++i)
        res += temp[i];
    return res;
}

int main()
{
	TreeNode* a =new TreeNode(9);
	cout<<sumNumbers(a);
}

