#include<bits/stdc++.h>
using namespace std;
bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        vector<int> sums(n+1);
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            sums[i+1] = nums[i] + sums[i];
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j+i < n; j++) {
                int sum1 = sums[j+i+1] - sums[j] - dp[j][j+i-1];
                int sum2 = sums[j+i+1] - sums[j] - dp[j+1][j+i];
                dp[j][j+i] = max(sum1, sum2);
            }
        }
        return dp[0][n-1] >= sums[n] / 2 + sums[n] % 2;      
}
int main()
{
	return 0;
} 
