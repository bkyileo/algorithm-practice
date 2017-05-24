#include<bits/stdc++.h>
using namespace std;
int main()
{
	return 0;
}

vector<int> target;
bool dfs(BinTree* root,int i)
{
    if(!root)return false;
    if(i==target.size()&&!root->l&&!root->r)return true;
    if(root->v==target[i])
    {
       if(dfs(root->l,i+1))return true;
       if(dfs(root->r,i+1))return true;
       return false;
    }
    else
    {
      return false;
    }
}
bool IsBranch(BinTree* root, int nodeList[],int nodeListSize)
{
	target.clear(); 
    for(int i=0;i<nodeListSize;++i)target.push_back(nodeList[i]);
	return dfs(root,0);
} 
