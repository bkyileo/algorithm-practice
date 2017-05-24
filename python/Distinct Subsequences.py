# coding=utf-8
__author__ = 'BK'

'''
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original
string by deleting some (can be none) of the characters without disturbing the relative
positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
'''
'''
count
for  i in T:
  count = count + count (if(T[i] in S))
remember any index of last
'''
class Solution:
    # @param {string} s
    # @param {string} t
    # @return {integer}
    def numDistinct(self, s, t):
        pass


if __name__=='__main__':
    solu = Solution()
    S = 'rabbbit'
    T = 'rabbit'


    print solu.numDistinct(S,T)