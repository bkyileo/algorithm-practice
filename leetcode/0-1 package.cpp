// 0-1 package

#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> w,vector<int> v,int maxw)
{
	vector< vector<int> > dp (w.size()+1 , vector<int>(maxw+1,0) );

	
//	for(int i=1;i<w.size()+1;++i)
//	{
//		for (int j=1;j<maxw+1;++j)
//		{
//			if(w[i-1]<=j)
//				dp[i][j] = max(dp[i-1][j-w[i-1]]+v[i-1],dp[i-1][j]);
//				//dp[i-1][j-w[i-1]]+v[i-1] 表示 不包括这一件商品 并且包的重量 也是当前w减去这个商品重量的 
//				// 1) Maximum value obtained by n-1 items and W weight (excluding nth item).
//				// 2) Value of nth item plus maximum value obtained by n-1 items and 
//				//    W minus weight of the nth item (including nth item).
//			else
//				dp[i][j] = dp[i-1][j];
//				
//			for(int i=0;i<w.size()+1;++i)
//			{
//				for(int j=0;j<maxw+1;++j)
//					cout<<dp[i][j]<<" ";
//				cout<<endl;
//			}
//			cout<<endl;
//	
//		}
//	}
//	

	for(int i=0;i<v.size()+1;++i)
	{
		for(int j=1;j<maxw+1;++j)
		{
			if(w[i-1]<j)
			{
				dp[i][j]=max(dp[i-1][j-w[i-1]]+v[w[i-1]],dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}

	return 0;
}

int main()
{
	vector<int> w,v;
	v.push_back(6); v.push_back(10); v.push_back(12);v.push_back(10);
	w.push_back(1); w.push_back(2); w.push_back(3); w.push_back(1);
    int maxw = 5;
    solution(w,v,maxw);
    return 0;
} 
