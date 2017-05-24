#include<bits/stdc++.h>
using namespace std;
bool diff(string a,string b)
{
	//cout<<a<<" "<<b<<endl;
	int df=0;
	for(int i=0;i<a.length();++i)
	{
		if(a[i]!=b[i])df++;
	}
	return df==1?true:false;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	vector<bool> mask(wordList.size(),false);
	queue<string> q;
	q.push(beginWord);
	int step=1;
	while(!q.empty())
	{
		queue<string> next;
		while(!q.empty())
		{
			string curr=q.front();
			q.pop();
			if(curr==endWord)return step;
			for(int i=0;i<wordList.size();++i)
			{
				if(!mask[i]&&diff(curr,wordList[i]))
				{
					mask[i]=true;
					next.push(wordList[i]);
				}
			}
		}
		q=next;
		step++;
	}
}
int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
	cout<<ladderLength(beginWord,endWord,wordList)<<endl;
}
