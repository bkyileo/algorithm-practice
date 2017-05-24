// ��������

#include<bits/stdc++.h>
#define maxw 5
#define F 15
using namespace std;

int w[11];
int v[11];
int nativeDp[20][20];
int reduceDp[100];

// 0-1���� native�汾 
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

// 0-1���� �洢ѹ���汾 ���� 
void knapsackR(int nums)
{
	memset(reduceDp,0,sizeof(reduceDp));
	for(int i=1;i<=nums;++i)
	{
		for(int j=maxw;j>0;j--)
		{
			//w[i]<=j ����Ϊ�� ���ǰ����еĶ����ó��� 
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

// ��ȫ���� ������Ʒ
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

//��ȫ ��ת 
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

//0-1 ��ת 
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

//���� ����Ӧ�м�ֵF ���Ǳ����ﵽFʱ�������Ʒ����С����������
/* 0-1 ���� ����ȫ����������� 
��ȫ������
	for(int i=1;i<=nums;++i)
	{
		for(int j=0;j<=15;++j)
			if(v[i]+j>=15)
				reduceDp[15]=min(reduceDp[15],w[i]+reduceDp[j]);
			else
				reduceDp[ v[i]+j ]=min(reduceDp[ v[i]+j ],w[i]+reduceDp[j]);	
	} 
				
0-1 ���� ps�Լ�ʵ�ֿ��������� �ö�άdpͼ
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
