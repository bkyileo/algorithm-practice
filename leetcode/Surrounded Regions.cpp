#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x;
	int y;
	point(int a,int b):x(a),y(b){}
};
void dfs(vector< vector<char> >& board,int x,int y,vector<point> &temp,vector< vector<int> >& visit)
{
	int H = board.size();
	int W = board[0].size();
	//cout<<"H,W: "<<H<<" "<<W<<endl; 
	//cout<<"x,y :"<<x<<" "<<y<<endl;
	if(x<0 || x>=H || y<0 || y>=W) return;
	if(visit[x][y]==0) return;
	if(board[x][y] == 'X') return;
	if(board[x][y] == 'O')
	{
		temp.push_back(point(x,y));
		visit[x][y]=0;
		dfs(board,x+1,y,temp,visit);
		dfs(board,x-1,y,temp,visit);
		dfs(board,x,y+1,temp,visit);
		dfs(board,x,y-1,temp,visit);
	}
}

void solve(vector< vector<char> >& board) {
		if(board.size()==0) return;
        vector<point> temp;
        vector< vector<int> >visit(board.size(),vector<int>(board[0].size(),1));
        
        for(int i=0;i<board.size();++i)
        {
        	for(int j=0;j<board[0].size();++j)
        	{
        		if(i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1 )
        		{
        			if(visit[i][j]=1)
        				dfs(board,i,j,temp,visit);
        		}
			}
		}
		
		for(int i=0;i<board.size();++i)
        {
        	for(int j=0;j<board[0].size();++j)
        	{
        		board[i][j]='X';
			}
		}
		for(int i=0;i<temp.size();++i)
		{
			board[temp[i].x][temp[i].y]='O';
		}
} 
int main()
{
	vector< vector<char> > board;
	vector<char> a,b,c;
	a.push_back('X');
	a.push_back('X');
	a.push_back('X');
	a.push_back('X');
	b.push_back('X');
	b.push_back('O');
	b.push_back('O');
	b.push_back('X');
	c.push_back('X');
	c.push_back('O');
	c.push_back('X');
	c.push_back('X');
	board.push_back(a);
	board.push_back(b);
	board.push_back(c);
	solve(board);
	for(int i=0;i<board.size();++i)
        {
        	for(int j=0;j<board[0].size();++j)
        	{
        		cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	
	
}
