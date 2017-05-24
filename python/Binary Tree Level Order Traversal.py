# coding=utf-8
__author__ = 'BK'

'''
Given a binary tree, return the level order traversal of its nodes' values.
(ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
'''

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root==None:
            return []

        res=[[root.val]]
        open=[root]
        while len(open)>0:
            close=[]
            nums=[]
            for i in xrange(len(open)):
                #print open[i].val
                if open[i].left != None or open[i].right!=None:
                    if open[i].left != None:
                        close.append(open[i].left)
                        nums.append(open[i].left.val)
                    if open[i].right != None:
                        close.append(open[i].right)
                        nums.append(open[i].right.val)
            res.append(nums)
            open=close

        res.pop()
        return res

if __name__=='__main__':
    solu = Solution()


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

    print solu.levelOrder(root)
