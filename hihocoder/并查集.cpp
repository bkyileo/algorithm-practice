#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &fa,int t)
{
    if(fa[t]==t)return t;
    else {
        fa[t]=find(fa,fa[t]);
        return fa[t];
    }
}

int main()
{
    map<string,int> m;
    int n;
    cin>>n;
    vector<int> fa(2*n+5,0);
    for(int i=0;i<2*n+5;++i)
    {
        fa[i]=i;
    }
    int personId=1;
    while(n--)
    {
        int type;
        string name1,name2;
        cin>>type>>name1>>name2;


        if(m[name1]==0)
            m[name1]=personId++;
        if(m[name2]==0)
            m[name2]=personId++;


        if(type==1)
        {
            if(find(fa,m[name1])==find(fa,m[name2]))
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
        if(type==0)
        {
        	//这是存在父子关系的并差集 
            int a,b;
            a=find(fa,m[name1]);
            b=find(fa,m[name2]);
            fa[b]=a;
        }
    }
    return 0;
}
