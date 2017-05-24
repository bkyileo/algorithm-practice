__author__ = 'BK'
'''
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

Subscribe to see which companies asked this question
'''

class Solution(object):

    def helper(self,charset,checkset,res):

        if len(charset)==0:
            return True

        for i in charset:
            if res[-1]^i in checkset:
                res.append(i)
                charset.remove(i)
                if self.helper(charset,checkset,res):
                    return True
                else:
                    res.remove(i)
                    charset.append(i)

    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        charset=[i for i in xrange(1,1<<n)]
        checkset=[1<<i for i in xrange(n)]
        res = [0]
        self.helper(charset,checkset,res)
        return res

    def grayCode2(self,n):
        len = 1<<n
        res=[]
        for i in xrange(len):
            print i,i>>1
            res.append(i^i>>1)
        return res





solu = Solution()
print solu.grayCode2(3)