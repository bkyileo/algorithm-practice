//TS �������RMQ���� 
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
int f[100005][25];//��������
int N,M; 
inline void build();//Ԥ����ST�㷨���� 
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
       for (j=1;(1<<j)<=P;j++)//�����С(2^j)û��Ҫ������������ 
           for (i=1;i+(1<<j)-1<=P;i++)
               f[i][j]=f[i][j-1] > f[i+ (1<<(j-1)) ][j-1]?f[i][j-1] : f[i+ (1<<(j-1)) ][j-1];
       }
inline int get(int b,int e){
       int j=(int)log2(e - b+1);//���򳤶ȵ�j,ʹ��(2^j)���ڵ������������һ�뼴��
       return f[b][j] > f[e-(1<<j)+1][j] ? f[b][j] : f[e-(1<<j)+1][j];//f[e-(1<<j)+1][j] ��ʾ��eΪ�е㳤Ϊ2^j������ 
       }
