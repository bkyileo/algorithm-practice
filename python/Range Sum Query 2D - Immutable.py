__author__ = 'BK'
class NumMatrix(object):
    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        row=len(matrix)
        if row==0:
            self.sum=[[0]]
        else:
            col=len(matrix[0])
            self.sum=[[0 for i in xrange(col+1)]for j in xrange(row+1)]
            self.sum[0][0]=matrix[0][0]

            for i in xrange(1,row):
                self.sum[i][0]=self.sum[i-1][0]+matrix[i][0]

            for i in xrange(1,col):
                self.sum[0][i]=self.sum[0][i-1]+matrix[0][i]

            for i in xrange(1,row):
                for j in xrange(1,col):
                    self.sum[i][j]=self.sum[i][j-1]+self.sum[i-1][j]-self.sum[i-1][j-1]+matrix[i][j]

    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        maxrow=max(row1,row2)
        minrow=min(row1,row2)

        maxcol=max(col1,col2)
        mincol=min(col1,col2)
        #print self.sum
        #print self.sum[maxrow][maxcol],self.sum[minrow-1][mincol-1],self.sum[maxrow][mincol-1],self.sum[minrow-1][maxcol]

        return self.sum[maxrow][maxcol]+self.sum[minrow-1][mincol-1]\
                -self.sum[maxrow][mincol-1]-self.sum[minrow-1][maxcol]



matrix=[[3,0,1,4,2],
        [5,6,3,2,1],
        [1,2,0,1,5],
        [4,1,0,1,7],
        [1,0,3,0,5]]
#sumRegion(1,1,2,2),sumRegion(1,2,2,4)
# Your NumMatrix object will be instantiated and called as such:
numMatrix = NumMatrix(matrix)
print numMatrix.sumRegion(2,1,4,3)

