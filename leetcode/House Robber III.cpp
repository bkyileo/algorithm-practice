#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#define maxn 100005
int chose[maxn];
int notchose[maxn];

void dfs(TreeNode* curr,int id)
{
	if(!curr) 
	{
		chose[id]=0;
		notchose[id]=0;
		return ;
	}	
	if(chose[2*id]!=-1 && chose[2*id+1]!=-1)
	{
		chose[id]=curr->val+notchose[2*id]+notchose[2*id+1];
		
		int case1,case2,case3,case4;
		case1=chose[2*id]+chose[2*id+1];
		case2=chose[2*id]+notchose[2*id+1];
		case3=chose[2*id+1]+notchose[2*id];
		case4=notchose[2*id]+notchose[2*id+1];
		
		notchose[id]=max(max(case1,case2),max(case3,case4));
		return ;
	}
	dfs(curr->left,2*id);
	dfs(curr->right,2*id+1);
}

int rob(TreeNode* root) {
	memset(chose,-1,sizeof(chose));
	memset(notchose,-1,sizeof(notchose));       
	dfs(root,1);
	return max(chose[1],notchose[1]);
}
