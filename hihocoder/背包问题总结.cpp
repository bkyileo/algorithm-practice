// 背包问题

#include<bits/stdc++.h>
#define maxw 5
#define F 15
using namespace std;

int w[11];
int v[11];
int nativeDp[20][20];
int reduceDp[100];

// 0-1背包 native版本 
void knapsackN(int nums)
{
	memset(nativeDp,0,sizeof(nativeDp));
	for(int i=1;i<=nums;++i)
	{
		for(int j=1;j<=maxw;++j)
		{
			if(w[i]<=j)
				nativeDp[i][j]=max(nativeDp[i-1][j-w[i]]+v[i],nativeDp[i-1][j]);
			else
				nativeDp[i][j]=nativeDp[i-1][j];
		}
	}
	for(int i=1;i<=nums;++i)
	{
		for(int j=1;j<=maxw;++j)
		{
			cout<<nativeDp[i][j]<<" ";
		}
		cout<<endl;
	}
}

// 0-1背包 存储压缩版本 逆序 
void knapsackR(int nums)
{
	memset(reduceDp,0,sizeof(reduceDp));
	for(int i=1;i<=nums;++i)
	{
		for(int j=maxw;j>0;j--)
		{
			//w[i]<=j 可以为零 就是把所有的东西拿出来 
			if(w[i]<=j)
				reduceDp[j]=max(reduceDp[j],reduceDp[j-w[i]]+v[i]);
		}
	}
	for(int j=1;j<=maxw;++j)
	{
		cout<<reduceDp[j]<<" ";
	}
	cout<<endl;
}

// 完全背包 随便放物品
void  knapsackA(int nums)
{
	memset(reduceDp,0,sizeof(reduceDp));
	for(int i=1;i<=nums;++i)
	{
		for(int j=1;j<=maxw;++j)
		{
			if(w[i]<=j)
				reduceDp[j]=max(reduceDp[j],reduceDp[j-w[i]]+v[i]);
		}	
	} 
	for(int j=1;j<=maxw;++j)
	{
		cout<<reduceDp[j]<<" ";
	}
	cout<<endl;
}

//完全 反转 
void  knapsackRe1(int nums)
{
	reduceDp[0]=0;
	for(int i=1;i<=15;++i)
	{
		reduceDp[i]=100;
	}
	for(int i=1;i<=nums;++i)
	{
		for(int j=0;j<=15;++j)
			if(v[i]+j>=15)
				reduceDp[15]=min(reduceDp[15],w[i]+reduceDp[j]);
			else
				reduceDp[ v[i]+j ]=min(reduceDp[ v[i]+j ],w[i]+reduceDp[j]);	
	} 
	for(int j=1;j<=15;++j)
	{
		cout<<reduceDp[j]<<" ";
	}
	cout<<endl;
}

//0-1 反转 
void  knapsackRe2(int nums)
{
	
	for(int i=0;i<=15;++i)
	{
		reduceDp[i]=100;
	}
	reduceDp[0]=0;
	
	
	for(int i=1;i<=nums;++i)
	{
		for(int j=F;j>=0;--j)
			if(v[i]+j>=F)
				reduceDp[F]=min(reduceDp[F],w[i]+reduceDp[j]);
			else
				reduceDp[v[i]+j]=min(reduceDp[v[i]+j],w[i]+reduceDp[j]);
	}
	
	for(int i=1;i<=15;++i)
	{
		cout<<reduceDp[i]<<" ";
	}
	cout<<endl;
}

//给出 给出应有价值F 考虑背包达到F时候放入物品的最小重量的问题
/* 0-1 背包 和完全被曝两种情况 
完全背包：
	for(int i=1;i<=nums;++i)
	{
		for(int j=0;j<=15;++j)
			if(v[i]+j>=15)
				reduceDp[15]=min(reduceDp[15],w[i]+reduceDp[j]);
			else
				reduceDp[ v[i]+j ]=min(reduceDp[ v[i]+j ],w[i]+reduceDp[j]);	
	} 
				
0-1 背包 ps自己实现可能有问题 用二维dp图
	for(int i=1;i<=nums;++i)
	{
		for(int j=F;j>=0;--j)
			if(v[i]+j>=F)
				reduceDp[F]=min(reduceDp[F],w[i]+reduceDp[j]);
			else
				reduceDp[v[i]+j]=min(reduceDp[v[i]+j],w[i]+reduceDp[j]);
	}
*/ 
int main()
{
	w[1]=2;w[2]=3;w[3]=4;
	v[1]=6;v[2]=10;v[3]=13;
	knapsackRe1(3);
	knapsackRe2(3);
	
	return 0;
}
