# coding=utf-8
__author__ = 'BK'
'''
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
Subscribe to see which companies asked this question
思路 : 第一步 找公共最长子序列
       第二步 对最长子序列进行操作
'''
class Solution(object):
    def helper(self,word1,word2):
        dp = [[0 for i in xrange(len(word1))]for j in xrange(len(word2))]
        maxstep=0
        for i in xrange(len(word1)):
            for j in xrange(len(word2)):
                if word2[j]==word1[i]:
                    dp[j][i]=dp[j-1][i-1]+1
                    maxstep=max(maxstep,dp[j][i])
                else:
                    # dp[j][i]=max(dp[j][i-1],dp[j-1][i])
                    dp[j][i]=0
        return   maxstep

    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        res=self.helper(word1, word2)

        return max(len(word1),len(word2))-res

solu = Solution()
print solu.helper('shaohui','ahui')