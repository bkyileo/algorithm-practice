__author__ = 'BK'
'''
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
'''

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):

    def helper(self,start,end):
        if start==end:
            return None
        res=[]
        for i in xrange(start,end):
            for l in self.helper(start,i) or [None]:
                for r in self.helper(i+1,end) or [None]:
                    node = TreeNode(i)
                    node.left=l
                    node.right=r
                    res.append(node)
        return res


    def tral(self,root):
        if root==None:
            return
        print root.val
        self.tral(root.left)
        self.tral(root.right)

    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        return self.helper(1,n+1)
        # for i in self.helper(1,n+1):
        #     self.tral(i)
        #     print 'over'

solu = Solution()
solu.generateTrees(3)