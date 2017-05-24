#include<bits/stdc++.h>
using namespace std;
//Empty cells are indicated by the character '.'.
const string chars = "123456789";
bool isValidSudoku(vector< vector<char> >& board) {
    bool c1[9][9]={false}, c2[9][9]={false}, c3[9][9]={false};
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]!='.'){
                int temp=board[i][j]-'1';
                int index=(i/3)*3+j/3;
                if(c1[i][temp] || c2[j][temp] || c3[index][temp])  return false;
                c1[i][temp]=c2[j][temp]=c3[index][temp]=true;
            }
        }
    }
    return true;
}
bool helper(vector< vector<char> >& board)
{
    for(int i=0;i<9;++i)
    {
    	for(int j=0;j<9;++j)
    	{
    		if(board[i][j]=='.')
    		{
    			for(int k=0;k<9;++k)
    			{
    				board[i][j]==chars[k];
    				if(helper(board))
    					return true;
    				else board[i][j]=='.';
				}
				return false;
			}
		}
	}
	return true;
}
void solveSudoku(vector< vector<char> >& board) {
	helper(board);
}
int main()
{
//	board=["..9748...","7........",".2.1.9...",
//       "..7...24.",".64.1.59.",".98...3..",
//       "...8.3.2.","........6","...2759.."]
	return 0;
}
