//Right Triangle
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		double h,s;
		cin>>h>>s;
		if(h*h-4*s<0)
		{
			cout<<-1<<endl;
			continue;
		}
		double a =sqrt(h*h+4*s);
		double b =sqrt(h*h-4*s);
		double x=(a+b)/2;
		double y=(a-b)/2;
		if(x<h&&x+y>h)
		{
			printf ("%f %f %f\n",y,x,h);
			continue;	
		}
		else
		{
			cout<<-1<<endl;
			continue;
		}
	}	
	return 0;
} 
