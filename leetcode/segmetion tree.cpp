#include<bits/stdc++.h>
using namespace std;

const int MAXNUM = 400005;
struct SegTreeNode
{
    int val;
}segTree[MAXNUM];//定义线段树

/*
功能：构建线段树
root：当前线段树的根节点下标
arr: 用来构造线段树的数组
istart：数组的起始位置
iend：数组的结束位置
*/
void build(int root, int arr[], int istart, int iend)
{
    if(istart == iend)//叶子节点
        segTree[root].val = arr[istart];
    else
    {
        int mid = (istart + iend) / 2;
        build(root*2+1, arr, istart, mid);//递归构造左子树
        build(root*2+2, arr, mid+1, iend);//递归构造右子树
        //根据左右子树根节点的值，更新当前根节点的值
        segTree[root].val = max(segTree[root*2+1].val, segTree[root*2+2].val);
    }
}

/*
功能：线段树的区间查询
root：当前线段树的根节点下标
[nstart, nend]: 当前节点所表示的区间
[qstart, qend]: 此次查询的区间
*/
int query(int root, int nstart, int nend, int qstart, int qend)
{
    //查询区间和当前节点区间没有交集
    if(qstart > nend || qend < nstart)
        return 0;
    //当前节点区间包含在查询区间内
    if(qstart <= nstart && qend >= nend)
        return segTree[root].val;
    //分别从左右子树查询，返回两者查询结果的较大值
    int mid = (nstart + nend) / 2;
    return max(query(root*2+1, nstart, mid, qstart, qend),
               query(root*2+2, mid + 1, nend, qstart, qend));
}

int main()
{
	int tickets[100001];
	memset(tickets,0,sizeof(tickets));
	
	int n,m,time;
	int price;int start;int end;
	int res;
	cin>>n>>m;
	while(n--)
	{
		cin>>time;
		cin>>price;
		tickets[time]=max(tickets[time],price);
	}
	
	build(0,tickets,0,100001);
	
	while(m--)
	{
		cin>>start;
		cin>>end;
		res=query(1,1,400005,start,end);
		if(res==0)
			cout<<"None"<<endl;
		else
			cout<<res<<endl;
	}
	return 0;
}
