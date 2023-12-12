#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#define INF 1e9

int v, e, a, b, c;
vector<vector<int>> graph(401, vector<int>(401, INF));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> v >> e;
	for (int i = 0;i < e;i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	for (int k = 1;k <= v;k++) {
		for (int i = 1;i <= v;i++) {
			for (int j = 1;j <= v;j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	int res = INF;
	for (int i = 1;i <= v;i++) {
		for (int j = 1;j <= v;j++) {
			res = min(res, graph[i][j] + graph[j][i]);
		}
	}
	if (res == INF)
		cout << -1;
	else
		cout << res;
}