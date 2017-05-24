# coding=utf-8
__author__ = 'BK'
'''
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000,
and there exists one unique longest palindromic substring.
'''
#最长回文字串

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        maxlens=0
        re=''
        for i in xrange(len(s)):
            left,right=self.findP(i,s)
            if maxlens<(right-left):
                maxlens=right-left
                re=s[left:right+1]
        return re

    def findP(self,i,s):

        leftFinal1=i
        rightFinal1=i

        leftFinal2=i
        rightFinal2=i

        for j in xrange(1,len(s)-1):
            if i-j>-1 and i+j<len(s):
                if s[i-j]==s[i+j]:
                    leftFinal1=leftFinal1-1
                    rightFinal1=rightFinal1+1
                else:
                    break


        for j in xrange(1,len(s)-1):
            if i-j+1>0 and i+j<len(s):
                if s[i-j+1]==s[i+j]:
                    leftFinal2=leftFinal2-1
                    rightFinal2=rightFinal2+1
                else:
                    break

        if (rightFinal2-leftFinal2+1)>(rightFinal1-leftFinal1):
            return leftFinal2+1,rightFinal2
        else:
            return leftFinal1,rightFinal1


solu=Solution()
s='bcccb'
print solu.longestPalindrome(s)