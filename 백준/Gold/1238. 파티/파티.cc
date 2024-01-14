#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 1001
#define INF 1e9

int n, m, x;
vector<vector<int>> graph;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> x;
	graph.resize(n + 1, vector<int>(n + 1, INF));

	int a, b, t;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> t;
		graph[a][b] = t;
	}

	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int res = 0;
	for (int i = 1;i <= n;i++) {
		if (i == x)
			continue;
		int time = graph[i][x] + graph[x][i];
		res = max(time, res);
	}

	cout << res;

	return 0;
}