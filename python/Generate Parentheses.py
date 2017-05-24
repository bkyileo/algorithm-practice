__author__ = 'BK'
'''
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

Subscribe to see which companies asked this question
'''

class Solution(object):

    def helper(self,num,re,s,left,right):

        if right == num:
            re.append(s)
            return

        if left < num:self.helper(num,re,s+'(',left+1,right)
        if left > right:self.helper(num,re,s+')',left,right+1)

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        re=[]
        self.helper(n,re,'',0,0)
        return re

solu = Solution()
re=solu.generateParenthesis(2)
print re
