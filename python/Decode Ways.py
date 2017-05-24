# coding=utf-8
__author__ = 'BK'

'''
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
'''

'''
s[i]=s[i-1]+1+ if (s[i-1:i+1] in dict )
about '0'
'''
# DFS的方法引起栈爆
# 原始的方法考虑不足
class Solution:
    # @param {string} s
    # @return {integer}
    def dfs(self,s,res):
        if s == '':
            res.append(1)
            # res += 1
            return
        if '10' <= s[:2] <= '26':
            self.dfs(s[2:],res)
        if s[0]=='0':
            return
        self.dfs(s[1:],res)

    def numDecodings2(self, s):
        if len(s)==0 :
            return 0
        res=[]
        self.dfs(s,res)
        return len(res)
        #return res

    def numDecodings(self, s):

        if not s:
            return 0
        dp = [0] * (len(s)+1)
        dp[0] = 1

        for i in range(1,len(s)+1):
            if s[i-1] != '0':
                dp[i] += dp[i-1]
            if i > 1 and '10' <= s[i-2:i] <= '26':
                dp[i] += dp[i-2]
        return dp[-1]



if __name__=='__main__':

    solu = Solution()
    #print len('4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948')
    #print solu.numDecodings2('110')
    print solu.numDecodings('4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948')
