// spoj ANARC05B - The Double HeLiX
#include<bits/stdc++.h>
using namespace std;
int main()
{
	while(1)
	{
		int x,y;
		cin>>x;
		if(x==0)break;
		else
		{
			vector<int> path1(x);
			for(int i=0;i<x;++i)cin>>path1[i];
			int y;cin>>y;vector<int> path2(y);
			for(int i=0;i<y;++i)cin>>path2[i];
			
			int a=0,b=0;
			int index1=0,index2=0;
			while(index1<x&&index2<y)
			{
				if(path1[index1]<path2[index2])
				{
					a+=path1[index1++];
					continue;
				}
				if(path1[index1]>path2[index2])
				{
					b+=path2[index2++];
					continue;
				}
				if(path1[index1]==path2[index2])
				{
					int temp=max(a,b)+path1[index1];
					a=temp;b=temp;
					index1++;index2++;
					continue;
				}
			}
			for(int i=index1;i<x;++i)
				a+=path1[i];
			for(int i=index2;i<y;++i)
				b+=path2[i];
			cout<<max(a,b)<<endl;
		}
	}
	return 0;
}
