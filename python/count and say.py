__author__ = 'BK'
'''
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Subscribe to see which companies asked this question
'''

class Solution(object):

    def interpretor(self,s):
        s=s+'*'
        count=1
        target=''
        for i in xrange(1,len(s)):
            if s[i] == s[i-1]:
                count += 1
            else:
                target = target+str(count)+s[i-1]
                count = 1
        return target

    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s='1'
        for i in xrange(1,n):
            s=self.interpretor(s)
        return s

solu = Solution()
print solu.countAndSay(8)