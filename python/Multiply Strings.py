# coding=utf-8
__author__ = 'BK'
'''
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

Subscribe to see which companies asked this question
'''

class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1=='0' or num2=='0':
            return '0'

        if len(num1)>len(num2):num1,num2=num2,num1
        space=[[0 for i in xrange(len(num1)+len(num2)-1)]for j in xrange(len(num1))]
        for i in xrange(len(num1)):
            for j in xrange(len(num2)):
                space[len(num1)-i-1][-i-j-1]=int(num1[i])*int(num2[j])

        final = []
        carry = 0

        print space

        for i in xrange(len(space[0])):
            current = 0
            for j in xrange(len(space)):
                current += space[j][i]
            current += carry
            final.append(current%10)
            carry=current/10

        if carry>0:
            final.append(carry)

        re=''
        for i in xrange(len(final)):
            re += str(final.pop())
        return re


solu = Solution()
num1='9133'
num2='1'
print solu.multiply(num1,num2)

'''
[
[30, 24, 18, 12,  6, 0, 0, 0],
[0,  25, 20, 15, 10, 5, 0, 0],
[0,   0, 20, 16, 12, 8, 4, 0],
[0,   0,  0, 15, 12, 9, 6, 3]
]
'''
# karatsuba 算法
def karatsuba(num1, num2):
    num1Str = str(num1)
    num2Str = str(num2)
    if (num1 < 10) or (num2 < 10):
        return num1*num2

    maxLength = max(len(num1Str), len(num2Str))
    splitPosition = maxLength / 2
    high1, low1= int(num1Str[:-splitPosition]), int(num1Str[-splitPosition:])
    high2, low2= int(num2Str[:-splitPosition]), int(num2Str[-splitPosition:])
    z0 = karatsuba(low1, low2)
    z1 = karatsuba((low1 + high1), (low2 + high2))
    z2 = karatsuba(high1, high2)

    return (z2*10**(2*splitPosition)) + ((z1-z2-z0)*10**(splitPosition))+z0