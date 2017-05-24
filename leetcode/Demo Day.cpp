#include<bits/stdc++.h>
using namespace std;
struct Direction
{
	int x;
	int y;
};

Direction cal(vector<string> maze,int x,int y,int sizex,int sizey)
{
	Direction d;
	for(int i=x;i<sizex;++i)
	{
		if(maze[i][y]=='b' ) 
		{
			d.x=i-x-1;
			break;
		}
		if(i==sizex-1)
		{
			d.x=i-x;
			break;
		}
	}
	for(int i=y;i<sizey;++i)
	{
		if(maze[x][i]=='b') 
		{
			d.y=i-y-1;
			break;
		}
		if(i==sizey-1) 
		{
			d.y=i-y;
			break;
		}
	}
	return d;
}

bool can(vector<string> maze,int x,int y,int sizex,int sizey)
{
	if(x==sizex-1 && y==sizey-1)
		return true;
	Direction d = cal(maze,x,y,sizex,sizey);
	
	if(d.x==0 && d.y==0) return false;
	if(d.x!=0 && d.y==0 && can(maze,x+d.x,y,sizex,sizey) )return true;
	if(d.y!=0 && d.x==0 && can(maze,x,y+d.y,sizex,sizey) ) return true;
	if(d.x!=0 && d.y!=0 && (can(maze,x+d.x,y,sizex,sizey) || can(maze,x,y+d.y,sizex,sizey))) 
		return true;
	return false;
} 

int main()
{
	vector<string> maze;
	maze.push_back("....bb..");
	maze.push_back("........");
	maze.push_back(".....b..");
	maze.push_back("...b....");
	
	int x=maze.size();
	int y=maze[0].length();
	vector< vector<int> > dp(x, vector<int>(y,0));
	cout<<can(maze,0,0,x,y)<<endl;
}
