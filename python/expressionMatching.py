__author__ = 'BK'
'''
Implement regular expression matching
with support for '.' and '*'.
'''


class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        # if s=='':
        #     return True
        # if p=='':
        #     return False

        spos=0
        ppos=0
        while spos<len(s) and ppos<len(p):
            if s[spos] == p[ppos] or p[ppos]=='.':
                spos +=1
                ppos +=1
                continue
            if p[ppos] == '*':
                return self.isMatch(s[spos+1:], p)
            return self.isMatch(s, p[ppos+1:])

        if (spos == len(s)):
            return True
        return False

solu=Solution()

# s='aab'
# p='c*a*b'

s="aaa"
p="aa"

# s="ab"
# p=".*"
print solu.isMatch(s,p)
