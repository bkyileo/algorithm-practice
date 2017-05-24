# coding=utf-8
__author__ = 'BK'
'''
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.
'''

# 需要封装一个函数 来确认这个是否成立

class Solution(object):


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


board=[".87654321",
       "2........",
       "3........",
       "4........",
       "5........",
       "6........",
       "7........",
       "8........",
       "9........"]
solu = Solution()
print solu.isValidSudoku(board)


board=[".87654321",
       "2........",
       "3........",
       "4........",
       "5........",
       "6........",
       "7........",
       "8........",
       "9........"]
