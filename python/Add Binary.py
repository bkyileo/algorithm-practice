__author__ = 'BK'
'''
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

Subscribe to see which companies asked this question
'''
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        lenth = len(a)-len(b)
        if lenth<0:
            a,b=b,a
            lenth = -lenth
        for i in xrange(lenth):
            b='0'+b

        carry = 0
        res=''
        for i in xrange(len(a)-1,-1,-1):
            if int(a[i])+int(b[i])+carry==3:
                res = '1' + res
                carry = 1
            elif int(a[i])+int(b[i])+carry==2:
                res = '0' + res
                carry = 1
            elif int(a[i])+int(b[i])+carry==1:
                res = '1' + res
                carry = 0
            elif int(a[i])+int(b[i])+carry==0:
                res = '0' + res
                carry = 0
        if carry==1:
            res = '1' + res

        return res

solu = Solution()
print solu.addBinary("1010","1011")

