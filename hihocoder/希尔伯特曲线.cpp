//hihocoder ϣ����������
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	long long res=0;
	bool c1,c2;
	for(int i=n;i>=0;--i)
	{
		long long side=(long long)pow(2,i);
		long long half=side/2;
		if(x>half)c1=true;
		else c1=false;
		if(y>half)c2=true;
		else c2=false;
		if(c1&&c2)
		{
			res+=(long long)pow(2,i-1)*(long long)pow(2,i-1)*2;
			x-=half;
			y-=half;
		}
		if(c1&&!c2)
		{
			res+=(long long)pow(2,i-1)*(long long)pow(2,i-1)*3;
			x-=half;
			//˳ʱ��90��
			int temp=x;
			x=y;
			y=(int)pow(2,i-1)+1-temp;
			//���ҷ�ת 
			x=(int)pow(2,i-1)+1-x;
		}
		if(!c1&&c2)
		{
			res+=(long long)pow(2,i-1)*(long long)pow(2,i-1);
			y-=half; 
		}
		if(!c1&&!c2)
		{ 
			//˳ʱ��90��
			int temp=x;
			x=y;
			y=(long long)pow(2,i-1)+1-temp;
			//���·�ת 
			y=(long long)pow(2,i-1)+1-y;
		}
		
	} 
	cout<<res+1<<endl;
	
	return 0;
}
