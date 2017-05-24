__author__ = 'BK'
'''
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
'''
class Solution(object):
    def dfsold(self,matrix,visit,x,y,res):
        if visit[x][y] == 0:
            return
        print x,y
        visit[x][y]=0
        res.append(matrix[x-1][y-1])
        self.dfsold(matrix,visit,x,y+1,res)
        self.dfsold(matrix,visit,x+1,y,res)
        self.dfsold(matrix,visit,x,y-1,res)
        self.dfsold(matrix,visit,x-1,y,res)


    def dfsnew(self,matrix,visit,x,y,dir,res):

        if visit[x][y] == 0:
            return

        res.append(matrix[x-1][y-1])
        visit[x][y]=0

        if visit[x+dir[0][0]][y+dir[0][1]]==1:
            self.dfsnew(matrix,visit,x+dir[0][0],y+dir[0][1],dir,res)
        else:
            dir[0],dir[1],dir[2],dir[3]=dir[1],dir[2],dir[3],dir[0]
            self.dfsnew(matrix,visit,x+dir[0][0],y+dir[0][1],dir,res)


    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if len(matrix)==0:
            return[]
        res=[]
        lenth=len(matrix[0])
        width=len(matrix)
        visit=[[0 for i in xrange(lenth+2)]for j in xrange(width+2)]
        for i in xrange(1,lenth+1):
            for j in xrange(1,width+1):
                visit[j][i]=1

        dir = [(0,1),(1,0),(0,-1),(-1,0)]
        self.dfsnew(matrix,visit,1,1,dir,res)

        return res

solu = Solution()
data =[
 [ 1,2,3,4],
 [ 5,6,7,8],
 [ 9,10,11,12]
]
print solu.spiralOrder(data)
