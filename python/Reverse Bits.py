__author__ = 'BK'
'''
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
'''

class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        res=0
        temp=''
        for i in xrange(32):
            res=res<<1
            a = n%2
            temp+=str(a)
            n = n>>1
            res+=a
            print res

        return res
solu=Solution()
a= solu.reverseBits(2147483648)
print a