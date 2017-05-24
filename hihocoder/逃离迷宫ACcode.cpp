#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
const int maxn = 105;
bool visited[maxn][maxn][32];
int keys[maxn][maxn];
char mat[maxn][maxn];
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };
int main() {
	int n, m, k, a, b, c, d;
	cin >> n >> m >> k >> a >> b >> c >> d;
	for (int i = 0; i < n; ++i)
		scanf("%s", mat[i]);
	int tx, ty, x, y;
	memset(keys, 0, sizeof(keys));
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &x, &y);
		keys[x][y] |= 1 << i;
	}
	queue<ppp> q;
	ppp cur;
	memset(visited, 0, sizeof(visited));
	q.push(make_pair(make_pair(a, b), make_pair(keys[a][b], 0)));
	visited[a][b][keys[a][b]] = true;
	bool ok = false;
	int res = -1;
	int ks, steps;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		x = cur.first.first;
		y = cur.first.second;
		ks = cur.second.first;
		steps = cur.second.second;
		if (x == c && y == d) {
			res = steps ;
			ok = true;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			tx = x + dirx[i];
			ty = y + diry[i];
			if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
				if (mat[tx][ty] == '#')
					continue;
				if (mat[tx][ty] == '.') {					
					if (!visited[tx][ty][ks]) {
						q.push(make_pair(make_pair(tx, ty), make_pair(ks | keys[tx][ty], steps + 1)));						
						visited[tx][ty][ks] = true;
						visited[tx][ty][ks | keys[tx][ty]] = true;
					}
				}
				else {					
					if (!visited[tx][ty][ks] && ((ks >> (mat[tx][ty] - 'A')) & 1)) {
						visited[tx][ty][ks] = true;
						visited[tx][ty][ks | keys[tx][ty]] = true;
						q.push(make_pair(make_pair(tx, ty), make_pair(ks | keys[tx][ty], steps + 1)));	
					}
				}
			}
		}		
		if (ok)
			break;
	}
	cout << res << endl;
}
