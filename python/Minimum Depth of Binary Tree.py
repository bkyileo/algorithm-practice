# coding=utf-8
__author__ = 'BK'
'''
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along
the shortest path from the root node down to the nearest leaf node.
'''

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
'''
            [             0,
                   1,           2,
              3,     null,  null,  6,
        null,  null,              null,  10]
'''
class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root==None:
            return 0

        depth=1
        open=[root]
        while len(open)>0:
            close=[]
            for i in xrange(len(open)):
                if open[i].left != None or open[i].right!=None:
                    if open[i].left != None:
                        close.append(open[i].left)
                    if open[i].right != None:
                        close.append(open[i].right)
                else:
                    return depth
            open=close
            depth=depth+1


if __name__=='__main__':

    solu=Solution()

    root=TreeNode(0)

    kid10=TreeNode(1)
    kid11=TreeNode(2)

    kid20=TreeNode(3)
    kid21=TreeNode(4)
    kid22=TreeNode(5)
    kid23=TreeNode(6)

    kid30=TreeNode(7)
    kid31=TreeNode(8)
    kid32=TreeNode(9)
    kid33=TreeNode(10)

    root.left=kid10
    root.right=kid11

    kid10.left=kid20
    kid11.right=kid23

    kid23.right=kid33
    print solu.minDepth(root)