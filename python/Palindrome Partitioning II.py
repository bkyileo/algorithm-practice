__author__ = 'BK'
'''
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

Subscribe to see which companies asked this question
'''
def Palindrome(s):
    for i in xrange(0,len(s)/2):
        if s[i] != s[len(s)-i-1]:
            return False
    return True
class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        if Palindrome(s):
            return 0
        import sys
        res=sys.maxint
        for i in xrange(1,len(s)):
            #print s[0:i],s[i:]
            res = min(self.minCut(s[0:i])+self.minCut(s[i:])+1,res)
        return res

solu = Solution()
print solu.minCut("abcbcd")