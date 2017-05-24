#include<bits/stdc++.h>
using namespace std;

const int MAXNUM = 400005;
struct SegTreeNode
{
    int val;
}segTree[MAXNUM];//�����߶���

/*
���ܣ������߶���
root����ǰ�߶����ĸ��ڵ��±�
arr: ���������߶���������
istart���������ʼλ��
iend������Ľ���λ��
*/
void build(int root, int arr[], int istart, int iend)
{
    if(istart == iend)//Ҷ�ӽڵ�
        segTree[root].val = arr[istart];
    else
    {
        int mid = (istart + iend) / 2;
        build(root*2+1, arr, istart, mid);//�ݹ鹹��������
        build(root*2+2, arr, mid+1, iend);//�ݹ鹹��������
        //���������������ڵ��ֵ�����µ�ǰ���ڵ��ֵ
        segTree[root].val = max(segTree[root*2+1].val, segTree[root*2+2].val);
    }
}

/*
���ܣ��߶����������ѯ
root����ǰ�߶����ĸ��ڵ��±�
[nstart, nend]: ��ǰ�ڵ�����ʾ������
[qstart, qend]: �˴β�ѯ������
*/
int query(int root, int nstart, int nend, int qstart, int qend)
{
    //��ѯ����͵�ǰ�ڵ�����û�н���
    if(qstart > nend || qend < nstart)
        return 0;
    //��ǰ�ڵ���������ڲ�ѯ������
    if(qstart <= nstart && qend >= nend)
        return segTree[root].val;
    //�ֱ������������ѯ���������߲�ѯ����Ľϴ�ֵ
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
