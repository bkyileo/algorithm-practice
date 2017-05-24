__author__ = 'BK'
'''
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
'''

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root==None:
            return True
        res=[]
        self.helper(root,res)
        for i in xrange(1,len(res)):
            if res[i-1]>res[i]:
                return False
        return True

    def helper(self,root,res):
        if root==None:return
        self.helper(root.left,res)
        res.append(root.val)
        self.helper(root.right,res)

#[10,5,15,null,null,6,20]

a = TreeNode(10)
b = TreeNode(5)
c = TreeNode(15)
d = TreeNode(13)
e = TreeNode(20)

solu = Solution()
a.left = b
a.right = c
c.left = d
c.right = e
print solu.isValidBST(a)