#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
TreeNode* dfs(vector<int>& nums,int left,int right)
{
    if (left>right) return NULL;
    int mid=(left+right)/2;
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=dfs(nums,left,mid-1);
    root->right=dfs(nums,mid+1,right);
    return root;
    
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums,0,nums.size()-1);
}
void preorder(TreeNode* root)
{
	if(!root) return;
	preorder(root->left);
	cout<<root->val<<" ";
	preorder(root->right);
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);
	
	preorder(sortedArrayToBST(nums));
	cout<<endl;
}
