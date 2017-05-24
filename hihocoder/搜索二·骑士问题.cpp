#include<bits/stdc++.h>
using namespace std;
bool visit[9][9];
bool ok(int x,int y)
{
    if( x>0 && x<9 && y>0 && y<9 && !visit[x][y] )
        return true;
    return false;
}
void whatis()
{
    for(int i=1;i<9;++i)
    {
        for(int j=1;j<9;++j)
            cout<<visit[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int steps(string loc,int desx,int desy)
{
    memset(visit,false,sizeof(visit));
    queue<pair<int,int>>q;
    q.push( make_pair(loc[0]-'A'+1,loc[1]-'0') );
    int step=0;
    visit[q.front().first][q.front().second]=true;
    while(!q.empty())
    {
        queue<pair<int,int>> temp;
        //whatis();
        while(!q.empty())
        {
            pair<int,int> curr=q.front();

            if(curr.first==desx && curr.second==desy)
            {
                return step;
            }

            if(ok(curr.first-1,curr.second-2))
            {
                temp.push(make_pair(curr.first-1,curr.second-2));
                visit[curr.first-1][curr.second-2]=true;
            }
            if(ok(curr.first-2,curr.second-1))
            {
                temp.push(make_pair(curr.first-2,curr.second-1));
                visit[curr.first-2][curr.second-1]=true;
            }

            if(ok(curr.first+1,curr.second-2))
            {
                temp.push(make_pair(curr.first+1,curr.second-2));
                visit[curr.first+1][curr.second-2]=true;
            }
            if(ok(curr.first+2,curr.second-1))
            {
                temp.push(make_pair(curr.first+2,curr.second-1));
                visit[curr.first+2][curr.second-1]=true;
            }

            if(ok(curr.first+1,curr.second+2))
            {
                temp.push(make_pair(curr.first+1,curr.second+2));
                visit[curr.first+1][curr.second+2]=true;
            }

            if(ok(curr.first+2,curr.second+1))
            {
                temp.push(make_pair(curr.first+2,curr.second+1));
                visit[curr.first+2][curr.second+1]=true;
            }
            if(ok(curr.first-1,curr.second+2))
            {
                temp.push(make_pair(curr.first-1,curr.second+2));
                visit[curr.first-1][curr.second+2]=true;
            }
            if(ok(curr.first-2,curr.second+1))
            {
                temp.push(make_pair(curr.first-2,curr.second+1));
                visit[curr.first-2][curr.second+1]=true;
            }
            q.pop();
        }
        step++;
        q=temp;
    }
}
int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        string loc1,loc2,loc3;
        cin>>loc1>>loc2>>loc3;
        int ans=INT_MAX;
        for(int i=1;i<9;++i)
            for(int j=1;j<9;++j)
            {
                ans = min(ans,steps(loc1,i,j)+steps(loc2,i,j)+steps(loc3,i,j));
                //cout<<"i,j: "<<i<<" "<<j<<" "<<steps(loc1,i,j)<<" "<<steps(loc2,i,j)<<" "<<steps(loc3,i,j)<<endl;
            }

        cout<<ans<<endl;

    }
    //steps("A1",1,1);
    return 0;
}
