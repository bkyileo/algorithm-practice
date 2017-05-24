#include<bits/stdc++.h>
using namespace std;

 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(vector<int> &temp,TreeNode* root,int k)
{
    if(temp.size()==k)return;
    if(!root) return;
    dfs(temp,root->left,k);
    temp.push_back(root->val);
    dfs(temp,root->right,k);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> temp;
    dfs(temp,root,k); 
    return temp[k-1];
}

int main()
{
	TreeNode* root=new TreeNode(1);
	cout<<kthSmallest(root,1)<<endl;
} 
