#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 101

bool visit[MAX];
vector<int> graph[MAX];
int res = -1;

void dfs(int n) {
	visit[n] = true;
	res++;
	for (int i = 0;i < graph[n].size();i++) {
		if (!visit[graph[n][i]])
			dfs(graph[n][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1);
	cout << res;
}