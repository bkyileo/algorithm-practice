__author__ = 'BK'
'''
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
'''
class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        if len(s1)+len(s2)!=len(s3):return False

        if s3=='':
            return True
        if s1=='':
            if s2==s3:
                return True
            else:
                return False
        if s2=='' :
            if s1==s3:
                return True
            else:
                return False

        if s3[0]!=s1[0] and s3[0]!=s2[0]:
            return False
        if s3[0]==s1[0] and s3[0]!=s2[0]:
            return self.isInterleave(s1[1:],s2,s3[1:])
        if s3[0]!=s1[0] and s3[0]==s2[0]:
            return self.isInterleave(s1,s2[1:],s3[1:])
        else:
            if self.isInterleave(s1[1:],s2,s3[1:]):return True
            if self.isInterleave(s1,s2[1:],s3[1:]):return True
            return False

solu = Solution()
s1="bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
s2="babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
s3="babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
print solu.isInterleave(s1,s2,s3)