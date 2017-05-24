#include<map>  
#include<set>  
#include<cmath>  
#include<queue>  
#include<math.h>  
#include<cstdio>  
#include<vector>  
#include<string>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
const int N=10010;  
const int MAX=151;  
const int MOD1=100000007;  
const int MOD2=100000009;  
const double EPS=0.00000001;  
typedef long long ll;  
const ll MOD=1000000007;  
const ll INF=10000000010;  
typedef unsigned long long ull;  
double a[5],b[5],f[25][25][50],ans[50];  
void add(int x,int y,double z[],double w[]) {  
    int i,j;  
    f[x][y][0]=max(f[x][y][0],z[0]+w[0]-1);  
    for (i=1;i<=z[0]+EPS;i++)  
        for (j=1;j<=w[0]+EPS;j++) f[x][y][i+j-1]+=z[i]*w[j];  
}  
double getPre(int x,int y) {  
    double ret=0;  
    for (int i=1;i<=f[x][y][0];i++) ret+=f[x][y][i]/i;  
    return ret;  
}  
int main()  
{  
    int i,j,x,y;  
    double out=0;  
    scanf("%d%d", &x, &y);  
    memset(f,0,sizeof(f));  
    f[0][0][0]=f[0][0][1]=1;  
    a[0]=2;a[1]=0;a[2]=1;//p  
    b[0]=2;b[1]=1;b[2]=-1;//1-p  
    for (i=0;i<y;i++)  
        for (j=0;j<x;j++) {  
            if (i>0) add(i,j,f[i-1][j],b);  
            if (j>0) add(i,j,f[i][j-1],a);  
        }  
    memset(ans,0,sizeof(ans));  
    for (i=0;i<y;i++) {  
        add(i,x,f[i][x-1],a);out+=getPre(i,x)*x;  
    }  
    for (i=0;i<x;i++) {  
        add(y,i,f[y-1][i],b);out+=getPre(y,i)*i;  
    }  
    printf("%f\n", out);  
    return 0;  
} 
