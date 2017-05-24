#include <iostream>
#include <vector>
#include <cstring>
// suzhou adventure AC code 
using namespace std;

int N, K, M;
int value[101], dp[101][101];
bool visited[101];
vector<int> e[101];

void dfs(int now)
{
	visited[now] = true;
	dp[now][1] = value[now];
	for(int i = 0; i < e[now].size(); i++)
	{
		if(visited[e[now][i]] == true) continue;
		dfs(e[now][i]);
		for(int x = M; x >= 1; x--) 
			for(int y = 0; y <= M - x; y++) 
				dp[now][x+y] = max(dp[now][x+y],dp[now][x] + dp[e[now][i]][y]);
	}
	return;
}

int main()
{
	cin >> N >> K >> M;
	for(int i = 1; i <= N; i++) cin >> value[i];
	int temp, e1, e2;
	for(int i = 1; i <= K; i++)
	{
		cin >> temp;
		value[temp] += 20000;
	}
	for(int i = 1; i < N; i++)
	{
		cin >> e1 >> e2;
		e[e1].push_back(e2);
		e[e2].push_back(e1);
	}
	if(K > M)
	{
		cout << -1 << endl;
		return 0;
	}
	memset(dp, 0, sizeof(dp));
	memset(visited, false, sizeof(visited));
	dfs(1);
	cout<< dp[1][M] - 20000 * K <<endl;
	return 0;
}
