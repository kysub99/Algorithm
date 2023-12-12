#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100001

bool visit[MAX];
vector<int> graph[MAX];
int res[MAX];

int cnt = 1;

void dfs(int n) {
	visit[n] = true;
	res[n] = cnt;
	cnt++;
	for (int i = 0;i < graph[n].size();i++) {
		if (!visit[graph[n][i]])
			dfs(graph[n][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 0;i < m;i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1;i <= n;i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(r);
	for (int i = 1;i <= n;i++) {
		cout << res[i] << "\n";
	}
}
