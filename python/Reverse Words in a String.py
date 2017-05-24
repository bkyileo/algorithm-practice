__author__ = 'BK'
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        temp=s.split()
        temp.reverse()
        res=''
        for i in temp:
            res += i
            res += ' '
        return res[:len(res)-1]
solu = Solution()
print solu.reverseWords('the sky is blue')