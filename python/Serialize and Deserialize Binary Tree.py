__author__ = 'BK'
'''
Serialization is the process of converting a data structure or
object into a sequence of bits so that it can be stored in a file or memory buffer,
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no
restriction on how your serialization/deserialization algorithm should work.
 You just need to ensure that a binary tree can be serialized to a string
 and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree.
You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states.
Your serialize and deserialize algorithms should be stateless.
'''

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def bfs(self,root,seqlist):
        if root!=None:
            self.visit(root,seqlist)
            self.bfs(root.left,seqlist)
            self.bfs(root.right,seqlist)
        else:
            self.visit(root,seqlist)

    def visit(self,node,seqlist):
        if node==None:
            seqlist.append(None)
        else:
            seqlist.append(node.val)

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        seq=[]
        self.bfs(root,seq)
        return str(seq)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        data.reverse()
        print data
        return self.bfsT(data)


    def bfsT(self,seqlist):
        if len(seqlist)==0:
            return None
        if seqlist[-1]==None:
            seqlist.pop()
            return None
        #[None, None, 5, None, None, 4, 3, None, None, 2, 1]
        now=TreeNode(seqlist.pop())
        now.left=self.bfsT(seqlist)
        now.right=self.bfsT(seqlist)
        return now


    def func(self,root):
        open=[root]
        tree=[root.val]
        while len(open)>0:
            close=[]
            for i in xrange(len(open)):
                if open[i].left!=None or open[i].right !=None:
                    if open[i].left!=None and open[i].right ==None:
                        #tree & open
                        tree.append(open[i].left.val)
                        tree.append(None)
                        close.append(open[i].left)
                        pass
                    if open[i].left==None and open[i].roght!=None:
                        tree.append(None)
                        tree.append(open[i].right.val)
                        close.append(open[i].right)
                        #tree & open
                        pass
                    else:
                        tree.append(open[i].left.val)
                        tree.append(open[i].right.val)
                        close.append(open[i].left)
                        close.append(open[i].right)
                        #tree & open
                        pass
                else:
                    tree.append(None)
                    tree.append(None)
            open=close
        return tree

    def funcT(self,seq):
        #   aim at
        #   [1, 2, 3, None, None, 4, 5, None, None, None, None]
        Nodelist=[]

        for i in seq:
            if i != None:
                Nodelist.append(TreeNode(i))
            else:
                Nodelist.append(None)

        layer = 1
        lose = 0
        # seq [0:1]
        while pow(2,layer)<len(seq):
            tem = seq[pow(2,layer)-1:pow(2,layer+1)-1-2*lose]
            layer=layer+1
            for i in tem:
                if i == None:
                    lose=lose+1

root=TreeNode(1)
node1=TreeNode(2)
node2=TreeNode(3)
node3=TreeNode(4)
node4=TreeNode(5)

root.left=node1
root.right=node2

node2.left=node3
node2.right=node4

# Your Codec object will be instantiated and called as such:

codec = Codec()
#test=[1, 2, 3, None, None, 4, 5, None, None, None, None]
#print test[2:5]
print codec.serialize(root)
test=[1, 2, None, None, 3, 4, None, None, 5, None, None]
now= codec.deserialize(test)

print now.val
print now.left.val
print now.right.val
print now.left.left
print now.right.left.val
print now.right.right.val
print now.right.right.left
print now.right.right.right

