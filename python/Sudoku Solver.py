__author__ = 'BK'
'''
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
'''

class Solution(object):

    def solveSudoku(self, board):
        if not board or len(board)==0:
            return
        self.solve(board)

    def solve(self,board):
        for row in xrange(9):
            for col in xrange(9):
                if board[row][col]=='.':
                    for c in ['1','2','3','4','5','6','7','8','9']:
                        if self.unvalid(board,row,col,c):
                            board[row]=board[row][:col]+c+board[row][col+1:]
                            if self.solve(board):
                                return True
                            else:
                                board[row]=board[row][:col]+'.'+board[row][col+1:]
                    return False
        return True

    def unvalid(self,board,i,j,c):
        for row in xrange(9):
            if board[row][j]==c:
                return False
        for col in xrange(9):
            if board[i][col]==c:
                return False
        for row in xrange((i/3)*3,(i/3)*3+3):
            for col in xrange((j/3)*3,(j/3)*3+3):
                if board[row][col]==c:
                    return False
        return True

    '''
    def helper(self,board,x1,x2,y1,y2):
        charSet = []
        for i in xrange(x1,x2):
            for j in xrange(y1,y2):
                if board[i][j] != '.':
                    if charSet.count(board[i][j])>0:
                        return False
                    charSet.append(board[i][j])
        return True

    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        for i in xrange(9):
            if self.helper(board,i,i+1,0,9)==False:
                return False
        for i in xrange(9):
            if self.helper(board,0,9,i,i+1)==False:
                return False
        for i in [0,3,6]:
            for j in [0,3,6]:
                if self.helper(board,i,i+3,j,j+3)==False:
                    return False

        return True

    def isover(self,board):
        for i in xrange(9):
            for j in xrange(9):
                if board[i][j]=='.':
                    return i,j
        return -1,-1

    def putnum(self,board,i,j,k):

        board[i]=board[i][:j]+k+board[i][j+1:]
        if self.isValidSudoku(board)==True:
            return True
        else:
            board[i]=board[i][:j]+'.'+board[i][j+1:]
            return False

    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        i,j = self.isover(board)

        if i==-1 and j==-1:
            return True

        for k in['1','2','3','4','5','6','7','8','9']:
            if self.putnum(board,i,j,k)==True:
                self.putnum(board,i,j,k)
                if self.solveSudoku(board)==True:
                    return True
    '''

solu =Solution()

board=["..9748...","7........",".2.1.9...",
       "..7...24.",".64.1.59.",".98...3..",
       "...8.3.2.","........6","...2759.."]

print solu.solveSudoku(board)
print board

