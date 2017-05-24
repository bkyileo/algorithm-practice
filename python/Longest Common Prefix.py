__author__ = 'BK'
'''
Write a function to find the longest common prefix string amongst an array of strings.

Subscribe to see which companies asked this question
'''

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs)==0:
            return

        common=strs[0]
        for i in strs:
            if len(i)<len(common):
                common=i

        for i in strs:
            for j in xrange(len(common)):
                if common[j] != i[j]:
                    common = common[0:j]
                    break
        return common

solu = Solution()
a=['abcd','abc','abcab','abcde']
print solu.longestCommonPrefix(a)