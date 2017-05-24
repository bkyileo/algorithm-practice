//TS 方法求解RMQ问题 
/*
7 6

1 1
2 1
4 3
4 4
4 5
6 9
7 9

1 7
1 2
6 7
3 3
4 4
5 5
*/
#include<bits/stdc++.h>
using namespace std;
int P=100005;
int f[100005][25];//动规数组
int N,M; 
inline void build();//预处理ST算法数组 
inline int get(int b,int e);
int main(){
	memset(f,0,sizeof(f));
    int i;
	int s,e;
    int k,v;
    int res;
    cin >> N >> M;
    for (i=1;i<=N;i++)
    {
    	cin>>k>>v;
    	f[k][0]=max(f[k][0],v);
	}
         
    build();
    
    for (i=1;i<=M;i++) {
        cin >> s >> e;
        res=get(s,e);
        if(res==0)
        	cout <<"None"<< endl;
        else
        	cout<<res<<endl;
        }
    return 0;
    }
inline void build(){
       int i,j;
           /*l=(int)log2(N)*/
       for (j=1;(1<<j)<=P;j++)//区域大小(2^j)没必要超过整个区间 
           for (i=1;i+(1<<j)-1<=P;i++)
               f[i][j]=f[i][j-1] > f[i+ (1<<(j-1)) ][j-1]?f[i][j-1] : f[i+ (1<<(j-1)) ][j-1];
       }
inline int get(int b,int e){
       int j=(int)log2(e - b+1);//区域长度的j,使得(2^j)大于等于请求区间的一半即可
       return f[b][j] > f[e-(1<<j)+1][j] ? f[b][j] : f[e-(1<<j)+1][j];//f[e-(1<<j)+1][j] 表示以e为中点长为2^j的区间 
       }
