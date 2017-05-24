__author__ = 'BK'
'''
Implement pow(x, n).

Subscribe to see which companies asked this question
'''

class Solution(object):

    def helper(self,num,re):
        if num <1:
            return

        start=1
        pow=0
        while start*2<=num:
            start *= 2
            pow += 1
        re.append(pow)
        self.helper(num-start,re)

    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        flag=True

        if n<0:
            n = -n
            flag=False

        temparr=[]
        self.helper(n,temparr)
        res = 1

        for i in temparr:
            temp=x
            for j in xrange(i):
                temp *= temp
            res *=temp

        if flag==True:
            return res
        else:
            return 1/float(res)


solu = Solution()
print solu.myPow(3,-3)