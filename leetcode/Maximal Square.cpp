#include<bits/stdc++.h>
using namespace std;

    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int m=0;
        for(int i=0;i<matrix.size();++i)
        {
            dp[i][0]=matrix[i][0]=='1'?1:0;
            m=max(m,dp[i][0]);
        }
        for(int i=0;i<matrix[0].size();++i)
        {
            dp[0][i]=matrix[0][i]=='1'?1:0;
            m=max(m,dp[0][i]);
        }
        int temp;
        
        for(int i=1;i<matrix.size();++i)
        {
            for(int j=1;j<matrix[0].size();++j)
            {
                if(matrix[i][j]=='1')
                {
                    temp=min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j]=min(temp,dp[i-1][j-1])+1;
                    m=max(m,dp[i][j]);
                }
            }
        }
//        for(int i=0;i<dp.size();++i)
//        {
//        	for(int j=0;j<dp[0].size();++j)
//        	{
//        		cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
        return m*m;
    }

int main()
{
	vector<vector<char>> matrix;
	vector<char> a;
	a.push_back('1');
	a.push_back('0');
	matrix.push_back(a);
	cout<<maximalSquare(matrix);
	return 0;
 } 
