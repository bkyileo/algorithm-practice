__author__ = 'BK'
'''
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree
in which the depth of the two subtrees of every node never differ by more than 1.

'''


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root ==None:
            return True

        else:
            deeplistl=[]
            deeplistr=[]
            deepl=0
            deepr=0
            self.dfs(root.left,deepl,deeplistl)
            self.dfs(root.right,deepr,deeplistr)
            print deeplistl,deeplistr
            if abs(max(deeplistl)-max(deeplistr))>1:
                return False
            self.isBalanced(root.left)
            self.isBalanced(root.right)

            return True

    def dfs(self,root,deep,deeplist):
        if root == None:
            deeplist.append(deep)
            return
        else:
            #print root.val,deep
            deep=deep+1
            self.dfs(root.left,deep,deeplist)
            self.dfs(root.right,deep,deeplist)


#[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]
#[1,2,2,3,null,null,3,4,null,null,4]

if __name__=='__main__':
    solu = Solution()


    root=TreeNode(1)
    kid0=TreeNode(2)
    kid1=TreeNode(2)
    gradkid=TreeNode(3)


    root.left=kid0
    root.right=kid1
    kid0.right=gradkid


    print solu.isBalanced(root)
'''
                    1,
               2,       2,
            3,   3,    3, 3,
          4, 4, 4,4,  4, 4,null,null,
        5, 5
'''