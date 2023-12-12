#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define MAX 1001
using namespace std;

int n, m;
char graph[MAX][MAX];
int res[MAX][MAX][2];
bool visit[MAX][MAX][2];
pair<int, int> dir[4] = { {-1,0},{1,0},{0,-1},{0,1} };

bool isIn(int r, int c) {
	if (1 <= r && r <= n && 1 <= c && c <= m)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> graph[i][j];
		}
	}
	res[1][1][0] = 1;
	queue<tuple<int, int, int>> q;
	q.push({ 1,1,0 });
	visit[1][1][0] = true;
	while (!q.empty()) {
		int tempr, tempc, wall;
		tie(tempr, tempc, wall) = q.front();
		q.pop();

		if (tempr == n && tempc == m)
			break;

		for (int i = 0;i < 4;i++) {
			int newr = tempr + dir[i].first;
			int newc = tempc + dir[i].second;

			if (isIn(newr, newc)) {
				if (graph[newr][newc] == '0' && !visit[newr][newc][wall]) {
					res[newr][newc][wall] = res[tempr][tempc][wall] + 1;
					visit[newr][newc][wall] = true;
					q.push(make_tuple(newr, newc, wall));
				}
				if (graph[newr][newc] == '1' && !wall && !visit[newr][newc][1]) {
					res[newr][newc][1] = res[tempr][tempc][0] + 1;
					visit[newr][newc][1] = true;
					q.push(make_tuple(newr, newc, 1));
				}
			}
		}
	}
	if (res[n][m][0] != 0 && res[n][m][1] != 0)
		cout << min(res[n][m][0], res[n][m][1]);
	else if (res[n][m][0] != 0)
		cout << res[n][m][0];
	else if (res[n][m][1] != 0)
		cout << res[n][m][1];
	else
		cout << -1;

	return 0;
}