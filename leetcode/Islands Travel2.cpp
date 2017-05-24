#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int y;
	int id;
	int dis;
	bool visit;
	node(int a,int b,int z):x(a),y(b),id(z),dis(INT_MAX),visit(false){
	} 
};

int caldis(node a,node b)
{
	return abs(a.x-b.x)>abs(a.y-b.y)?abs(a.y-b.y):abs(a.x-b.x);
}

void op(vector<node> &temp,vector<node> &vec,int id)
{
	vec[id].visit=true;
	temp.push_back(vec[id]);
}

bool Xsort(node a,node b)
{
	return a.x>b.x;	
}

bool Ysort(node a,node b)
{
	return a.y>b.y;	
}

void look(vector<node> vec)
{
	cout<<"-------------"<<endl;
	for(int i=0;i<vec.size();++i)
	{
		cout<<"i,id,dis,visit,x,y: "<<i<<" "<<vec[i].id<<" "<<vec[i].dis<<" "<<vec[i].visit<<" "<<vec[i].x<<" "<<vec[i].y<<endl;
	}
	cout<<"-------------"<<endl;
}

int main()
{
	int N;
	cin>>N;
	
	vector<node> nodes;
	int id=0;
	while(N--)
	{
		int x,y;
		cin>>x>>y;
		nodes.push_back(node(x,y,id));
		id++;
	}
	vector<node> temp;
	nodes[0].dis=0;
	nodes[0].visit=true;
	op(temp,nodes,0);
	
	sort(nodes.begin(),nodes.end(),Xsort);
	vector<node> Xbase(nodes);
	sort(nodes.begin(),nodes.end(),Ysort);
	vector<node> Ybase(nodes);
	
	cout<<"look x base"<<endl;
	look(Xbase);
	cout<<"look y base"<<endl;
	look(Ybase);
	
	id--;
	while(temp[temp.size()-1].id!=id-1)
	{
		int index = temp.size()-1;
		//¶ÓÎ²µÄ x ºÍ y 
		temp[index].x;
		temp[index].y;
		
		int dis=INT_MAX;
		
		 
		op(temp,vec,minid);
		
	}
	
	
	return 0;
} 
