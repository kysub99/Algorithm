#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define MAX 101

pair<int, int> dir[4] = { {-1,0}, {1,0}, {0,-1}, {0, 1} };
//상 하 좌 우
bool visit[52][52];
int graph[52][52];
int cnt;

void dfs(int a, int b) {
	visit[a][b] = true;
	cnt++;
	for (int i = 0;i < 4;i++) {
		int newa = a + dir[i].first;
		int newb = b + dir[i].second;
		if (!visit[newa][newb] && graph[newa][newb])
			dfs(newa, newb);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				graph[i][j] = 0;
				visit[i][j] = false;
			}
		}
		for (int i = 0;i < k;i++) {
			int a, b;
			cin >> a >> b;
			graph[a + 1][b + 1] = 1;
		}
		int res = 0;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				if (!visit[i][j] && graph[i][j]) {
					dfs(i, j);
					res++;
				}
			}
		}
		cout << res << "\n";
	}
}