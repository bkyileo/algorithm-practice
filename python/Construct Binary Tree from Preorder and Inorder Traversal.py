__author__ = 'BK'
'''
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Subscribe to see which companies asked this question
'''

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder)==0:
            return None
        stack = []
        res=TreeNode(preorder[0])
        stack.append(res)
        now=stack[0]


        for i in xrange(1,len(preorder)):
            if inorder.index(preorder[i])<inorder.index(stack[-1].val):
                temp=TreeNode(preorder[i])
                now.left=temp
                stack.append(temp)
                now=stack[-1]
            else:
                temp=TreeNode(preorder[i])
                while len(stack)!=0 and inorder.index(preorder[i])>inorder.index(stack[-1].val) :
                    now=stack.pop()
                now.right=temp
                stack.append(temp)
                now=stack[-1]
        return res

def inorder(root):
    if (root==None):
        return
    inorder(root.left)
    print root.val
    inorder(root.right)

def preorder(root):
    if (root==None):
        return
    print root.val
    preorder(root.left)
    preorder(root.right)


solu = Solution()
P=[6,2,1,4,3,5,7,9,8]
I=[1,2,3,4,5,6,7,8,9]
res=solu.buildTree(P,I)
preorder(res)