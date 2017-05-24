//code chef CHEFTET: Chef and Tetris
#include<bits/stdc++.h>
using namespace std;
/*
1
4
1 2 1 2
6 4 2 6
*/
bool helper(vector<int> bs,vector<int> as,vector<bool> use,long long num)
{
	for(int i=1;i<as.size()-1;++i)
	{
		if(as[i]==num)
		{
			continue;
		} 
		else if(!use[i-1]&&(as[i]+bs[i-1]==num))
		{
			use[i-1]=true;
			continue;
		}
		else if(!use[i-1]&&!use[i]&&(as[i]+bs[i-1]+bs[i]==num))
		{
			use[i]=true;
			use[i-1]=true;
			continue;
		}
		else if(!use[i-1]&&!use[i+1]&&(as[i]+bs[i-1]+bs[i+1]==num))
		{
			use[i+1]=true;
			use[i-1]=true;
			continue;
		}
		else if(!use[i]&&(as[i]+bs[i]==num))
		{
			use[i]=true;
			continue;
		}
		else if(!use[i+1]&&(as[i]+bs[i+1]==num))
		{
			use[i+1]=true;
			continue;
		}
		else if(!use[i]&&!use[i+1]&&(as[i]+bs[i]+bs[i+1]==num))
		{
			use[i]=true;
			use[i+1]=true;
			continue;
		}
		else if(!use[i-1]&&!use[i]&&!use[i+1]&&(as[i]+bs[i-1]+bs[i]+bs[i+1]==num))
		{
			use[i-1]=true;
			use[i]=true;
			use[i+1]=true;
			continue;
		}
		else
		{
			return false;			
		}
	}
	if(as[as.size()-1]==num)
	{
		for(auto i:use)
			if(!i) return false;
		cout<<num<<endl;
		return true;		
	}
	else if(as[as.size()-1]+bs[as.size()-1]==num&&!use[as.size()-1])
	{
		use[as.size()-1]=true;
		for(auto i:use)
			if(!i) return false;
		cout<<num<<endl;
		return true;	
	}
	else if(as[as.size()-1]+bs[as.size()-2]==num&&!use[as.size()-2])
	{
		use[as.size()-2]=true;
		for(auto i:use)
			if(!i) return false;
		cout<<num<<endl;
		return true;		
	}
	else if(as[as.size()-1]+bs[as.size()-2]+bs[as.size()-1]==num&&!use[as.size()-2]&&!use[as.size()-1])
	{
		use[as.size()-2]=true;
		use[as.size()-1]=true;
		for(auto i:use)
			if(i==false) return false;
		cout<<num<<endl;
		return true;	
	}
	else
	{
		return false;
	}
}


void slove(long long res,vector<int> bs,vector<int> as)
{
	vector<bool> use(bs.size(),false);
	long long num;

	for(int i=0;i<as.size();++i)
	{
		if(bs[i]==0)
			use[i]=true;
		else
			use[i]=false;
	}	
	num=as[0];
	if(num==res)
	{
		if(helper(bs,as,use,num))
		{
			return ;	
		}
		else
		{
			cout<<-1<<endl; 
			return ;
		}
	}


	for(int i=0;i<as.size();++i)
	{
		if(bs[i]==0)
			use[i]=true;
		else
			use[i]=false;
	}
	num=as[0]+bs[0];
	use[0]=true;
	if(num==res)
	{
		if(helper(bs,as,use,num))
		{
			return ;	
		}
		else
		{
			cout<<-1<<endl; 
			return ;
		}
	}


	for(int i=0;i<as.size();++i)
	{
		if(bs[i]==0)
			use[i]=true;
		else
			use[i]=false;
	}
	num=as[0]+bs[1];
	use[1]=true;
	if(num==res)
	{
		if(helper(bs,as,use,num))
		{
			return ;	
		}
		else
		{
			cout<<-1<<endl; 
			return ;
		}
	}
	
	//case3
	for(int i=0;i<as.size();++i)
	{
		if(bs[i]==0)
			use[i]=true;
		else
			use[i]=false;
	}
	num=as[0]+bs[0]+bs[1];
	use[0]=true;
	use[1]=true;
	//cout<<num<<endl;
	if(num==res)
	{
		if(helper(bs,as,use,num))
		{
			return ;	
		}
		else
		{
			cout<<-1<<endl; 
			return ;
		}
	}
	
	cout<<-1<<endl;
	return ;
}


int main()
{
	int t;cin>>t;
	while(t--)
	{
		int num;cin>>num;
		vector<int> bs(num);
		vector<int> as(num);
		long long sums=0;
		for(int i=0;i<num;++i)
		{
			cin>>bs[i];
			sums+=bs[i];
		}	
		for(int i=0;i<num;++i)
		{
			cin>>as[i];
			sums+=as[i];
		}	
		if(num==1)
		{
			cout<<as[0]+bs[0]<<endl;
			continue;
		}
		long long res=sums/num;
		if(res*num!=sums)
		{
			cout<<-1<<endl;
			continue;
		}
		else
		{
			slove(res,bs,as);
		}
	}
	return 0;
}
