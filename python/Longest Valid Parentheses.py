__author__ = 'BK'
'''
Given a string containing just the characters '(' and ')',
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()",
which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()",
which has length = 4.

Subscribe to see which companies asked this question
'''

class Solution(object):

    def helper(self,s,current,maxlen):

        if len(s)<2:
            return maxlen
        elif s[0:2] =='()':
            current += 2
            maxlen = max(maxlen,current)
            return self.helper(s[2:],current,maxlen)
        else:
            return self.helper(s[1:],0,maxlen)

    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        dp = [0]*(len(s)+1)
        stack = []

        for i in xrange(len(s)):
            if s[i] =='(':
                stack.append(i)
            elif stack:
                left=stack.pop()
                dp[i+1]=dp[left]+i-left+1

        return max(dp)



solu =Solution()
s=')()())'
print solu.longestValidParentheses(s)