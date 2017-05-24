#coding=utf-8
__author__ = 'BK'
'''
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem
"Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
'''

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:return False
        s=str(x)
        if s[0]=='-':
            s=s[1:]
        lenth=len(s)
        for i in xrange(lenth/2):
            if s[i]!=s[lenth-1-i]:
                return False
        return True

solu = Solution()
print solu.isPalindrome(-2147447412)

# -2147447412
# -2147483648
