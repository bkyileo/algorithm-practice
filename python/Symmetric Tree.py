__author__ = 'BK'

'''
Given a binary tree, check whether it is a mirror of itself
(ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
'''

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        pass


if __name__=='__main__':

    solu=Solution()

    #[1,2,3,3,null,2,null]
'''
           1
        2     3
      3  #  2   #
'''

