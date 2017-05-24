//code chef Akhil And Colored Balls

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[100005];
		char b[100005];
		//cin>>a>>b;
		/*
		1
		WBWB
		WBBB
		*/
		//scanf("%s",a);
		//scanf("%s",b);
		cin>>a;
		cin>>b;
//		gets(a);
//		gets(b);
		for(int i=0;a[i]!='\0';++i)
		{
			if(a[i]!=b[i])
				//res=res+"B";
				printf("B");
			else
			{
				if(a[i]=='W')
					printf("B");
				else
					printf("W");
			}
		}
		printf("\n");
	}
 } 
