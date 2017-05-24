__author__ = 'BK'

'''
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along
the longest path from the root node down to the farthest leaf node.
'''

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        deeplist=[]
        deep=0
        self.dfs(root,deep,deeplist)
        return max(deeplist)

    def dfs(self,root,deep,deeplist):
        if root == None:
            deeplist.append(deep)
            return
        else:
            #print root.val,deep
            deep=deep+1
            self.dfs(root.left,deep,deeplist)
            self.dfs(root.right,deep,deeplist)



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

    #kid23.right=kid33

    deep=0
    deeplist=[]
    #print solu.dfs(root,deep,deeplist)

    print solu.maxDepth(root)
