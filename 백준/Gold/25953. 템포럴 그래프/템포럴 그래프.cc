#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF (int)1e9+1

int n, t, m;
int s, e;
int cost[1001][10000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> t >> m;
	cin >> s >> e;

	for (int i = 0;i < n;i++) {
		cost[0][i] = INF;
	}
	cost[0][s] = 0;

	for (int i = 0;i < t;i++) {
		for (int j = 0;j < n;j++)
			cost[i + 1][j] = cost[i][j];
		for (int j = 0;j < m;j++) {
			int u, v, w;
			cin >> u >> v >> w;
			cost[i + 1][u] = min(cost[i + 1][u], cost[i][v] + w);
			cost[i + 1][v] = min(cost[i + 1][v], cost[i][u] + w);
		}
	}
	cout << (cost[t][e] == INF ? -1 : cost[t][e]);
}