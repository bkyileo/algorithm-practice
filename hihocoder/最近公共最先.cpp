//hihocoder 最近公共最先
#include<bits/stdc++.h>
using namespace std;

struct man
{
	string name;
	//保存在数组里的id; 
	int father;
	man(string n):name(n),father(-1){
	}
};

int find(vector<man> people,string curr)
{
	for(int i=0;i<people.size();++i)
	{
		if(people[i].name==curr)
			return i;
	}
	return -1;
}

void dfs(string man1,string man2,vector<man> people,vector<bool> visit)
{
	if(man1==man2)
	{
		cout<<man1<<endl;
		return ;
	}
	int index=find(people,man1);
	
	while(index != -1)
	{
		visit[index]=true;
		index=people[index].father;
	}
	
	index=find(people,man2);
	
	while(index!=-1 && visit[index]==false)
	{
		index=people[index].father;
	}
	
	if(index==-1) 
		cout<<-1<<endl;
	else{
		cout<<people[index].name<<endl;
	}
	return ;
}

int main()
{
	int N;
	cin>>N;
	vector<man> people; 
	while(N--)
	{
		string fa,son;
		cin>>fa>>son;
		int faindex=find(people,fa);
		int sonindex=find(people,son);
		if(faindex==-1 && sonindex==-1)
		{
			man currFather(fa);
			people.push_back(currFather);
			man currSon(son);
			people.push_back(currSon);
			people[people.size()-1].father=people.size()-2;
		}
		else if(faindex!=-1 && sonindex==-1)
		{
			man currSon(son);
			people.push_back(currSon);
			people[people.size()-1].father=faindex;
		}
		else if(faindex==-1 && sonindex!=-1)
		{
			man currFather(fa);
			people.push_back(currFather);
			people[sonindex].father=people.size()-1;
		}
		else if(faindex!=-1 && sonindex!=-1)
		{
			people[sonindex].father=faindex;
		}
	}
	
//	for(auto i:people)
//	{
//		cout<<i.name;
//		if(i.father==-1)
//			cout<<"先祖"<<endl;
//		else
//			cout<<" father :"<<people[i.father].name<<endl;
//	}
//	cout<<endl;

	int M;
	cin>>M;
	while(M--)
	{
		string man1;
		string man2;
		cin>>man1>>man2;
		vector<bool> visit(people.size(),false);
		dfs(man1,man2,people,visit);
	}
}
 
