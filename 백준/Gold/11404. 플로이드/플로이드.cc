#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#define INF 1e9

int n, m, a, b, c;
vector<vector<int>> graph(101, vector<int>(101, INF));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (graph[i][j] == INF||i==j)
				cout << "0 ";
			else
				cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}