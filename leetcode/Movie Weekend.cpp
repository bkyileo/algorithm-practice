//code chef

#include<bits/stdc++.h>
using namespace std;

struct movie
{
	int len;
	int score;
	movie():len(0),score(0){
	} 
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int count;
		int len;
		int score;
		int index=0;
		int square=0;
	
		cin>>count;
		vector<movie> movies(count,movie());
		for(int i=0;i<count;++i)
		{
			cin>>len;
			movies[i].len=len;
		}
		for(int i=0;i<count;++i)
		{
			cin>>score;
			movies[i].score=score;
		}
		
//		for(auto i:movies)
//		{
//			cout<<i.len<<"~"<<i.score<<endl;
//		}
		
		for(int i=0;i<movies.size();++i)
		{
			if(movies[i].len * movies[i].score > square)
			{
				index=i;
				square=movies[i].len * movies[i].score;
			}
			if(movies[i].len * movies[i].score == square)
			{
				if(movies[i].len < movies[index].len)
				{
					index=i;
				}
			}
		}
		cout<<index+1<<endl;
	}
	return 0;
}
