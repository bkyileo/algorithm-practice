# coding=utf-8
__author__ = 'BK'
'''
Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

  1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
'''

'''

将n个数字 分成有限的两部分
左边乘以右边

'''

class Solution:
    # @param {integer} n
    # @return {integer}

    def numTrees(self, n):

        if n==0:
            return 1

        res=0

        for i in xrange(n):
            res += self.numTrees(i)*self.numTrees(n-i-1)

        return res

    def numTrees1(self, n):
        res = [0] * (n+1)
        res[0] = 1
        for i in xrange(1, n+1):
            for j in xrange(i):
                res[i] += res[j] * res[i-1-j]
        return res[n]


if __name__=='__main__':

    solu = Solution()

    print solu.numTrees(3)