__author__ = 'BK'
'''
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
'''


class Solution(object):

    def find(self,board,path,i,j,word):

        if word=='':
            return True
        if i<0 or i>len(board)-1 or j <0 or j>len(board[0])-1 or board[i][j] != word[0]:
            return False
        if (i,j) in path:
           return False

        if self.find(board,path+[(i,j)],i+1,j,word[1:]):return True
        if self.find(board,path+[(i,j)],i-1,j,word[1:]):return True
        if self.find(board,path+[(i,j)],i,j+1,word[1:]):return True
        if self.find(board,path+[(i,j)],i,j-1,word[1:]):return True
        return False


    def first_letter(self,board,word,temp):
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if word[0] == board[i][j]:
                    temp.append((i,j))

    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        temp=[]
        self.first_letter(board,word,temp)
        for i in temp:
            if self.find(board,[],i[0],i[1],word):
                return True
        return False


solu = Solution()
board=[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCB"
print solu.exist(board,word)
