#include<bits/stdc++.h>
using namespace std;
int trapRainWater(vector<vector<int>>& heightMap) {
	if(heightMap.size()<2||heightMap[0].size()<2)return 0;
	
        if(heightMap.size()==0) return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        int row = heightMap.size(), col = heightMap[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        int ans = 0, Max = INT_MIN;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(!(i==0 || i==row-1 || j==0 || j==col-1)) continue;
                que.push(make_pair(heightMap[i][j], i*col+j));
                visited[i][j] = 1;
            }
        }
        vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!que.empty())
        {
            auto val = que.top(); que.pop();
            int height = val.first, x = val.second/col, y = val.second%col;
            Max = max(Max, height);
            cout<<x<<" "<<y<<endl;
            cout<<Max<<endl<<endl;
            for(auto d: dir)
            {
                int x2 = x + d[0], y2 = y + d[1];
                if(x2>=row || x2<0 || y2<0 || y2>=col || visited[x2][y2]) continue;
                visited[x2][y2] = 1;
                if(heightMap[x2][y2] < Max) ans += Max - heightMap[x2][y2];
                que.push(make_pair(heightMap[x2][y2], x2*col+y2));
            }
        }
        

	return 0;   
}
int main()
{
	vector<vector<int>> heightMap;
	heightMap.push_back({1,4,3,1,3,2});
	heightMap.push_back({3,2,1,3,2,4});
	heightMap.push_back({2,3,3,2,3,1});
	trapRainWater(heightMap);
	return 0;
}
