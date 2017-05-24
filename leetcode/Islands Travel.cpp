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
	vec[id-1].visit=true;
	temp.push_back(vec[id-1]);
}

int findmindis(vector<node> &vec)
{
	int mindis=INT_MAX;
	int minid;
	
	for(int i=1;i<vec.size();++i)
	{
		if(!vec[i].visit && mindis>vec[i].dis)
			{
				minid=i;
				mindis=vec[i].dis;
			}
	}
	return minid+1;
}

void look(vector<node> vec)
{
	cout<<"-------------"<<endl;
	for(int i=0;i<vec.size();++i)
	{
		cout<<"i,id,dis,visit : "<<i<<" "<<vec[i].id<<" "<<vec[i].dis<<" "<<vec[i].visit<<endl;
	}
	cout<<"-------------"<<endl;
}
int main()
{
	int nums;
	cin>>nums;
	vector<node> vec;
	int N=nums;
	while(nums)
	{
		int x,y;
		cin>>x>>y;
		vec.push_back(node(x,y,N-nums+1));
		nums--; 
	}
	
	vector<node> temp;
	op(temp,vec,1);
	temp[0].dis=0;
	
//	cout<<"look vec"<<endl;
//	look(vec);
//	cout<<"look temp"<<endl;
//	look(temp);

	while(temp[temp.size()-1].id!=N)
	{
		int index = temp.size()-1;
		for(int i=1;i<vec.size();++i)
		{
			if(!vec[i].visit)
			{
			vec[i].dis=min(caldis(temp[index],vec[i])+temp[index].dis,vec[i].dis);
		
			}
		}
		int minid = findmindis(vec);
		op(temp,vec,minid);
		
//		cout<<"look vec"<<endl;
//		look(vec);
//		cout<<"look temp"<<endl;
//		look(temp);
	}
	cout<<temp[temp.size()-1].dis<<endl;
	return 0;
}
