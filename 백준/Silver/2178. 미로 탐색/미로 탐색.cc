#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define MAX 102

pair<int, int> dir[4] = { {-1,0}, {1,0}, {0,-1}, {0, 1} };
//상 하 좌 우
bool visit[MAX][MAX];
char graph[MAX][MAX];
int res[MAX][MAX];
int n, m;

void bfs(int a, int b) {
	queue<pair<int,int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	res[a][b] = 1;
	while (!q.empty()) {
		int tempa = q.front().first;
		int tempb = q.front().second;
		if (tempa == n && tempb == m)
			break;
		for (int i = 0;i < 4;i++) {
			int newa = tempa + dir[i].first;
			int newb = tempb + dir[i].second;
			if (!visit[newa][newb] && graph[newa][newb] == '1') {
				q.push({ newa, newb });
				visit[newa][newb] = true;
				res[newa][newb] = res[tempa][tempb] + 1;
			}
		}
		q.pop();
	}
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
	bfs(1, 1);
	cout << res[n][m];
}