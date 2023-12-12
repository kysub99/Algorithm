#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100001

bool visit[MAX];
vector<int> graph[MAX];
int res[MAX];

int cnt = 1;

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visit[n] = true;
	res[n] = cnt++;
	while (!q.empty()) {
		for (int i = 0;i < graph[q.front()].size();i++) {
			int temp = graph[q.front()][i];
			if (!visit[temp]) {
				q.push(temp);
				visit[temp] = true;
				res[temp] = cnt++;
			}
		}
		q.pop();
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
		sort(graph[i].begin(), graph[i].end(), greater<>());
	}
	bfs(r);
	for (int i = 1;i <= n;i++) {
		cout << res[i] << "\n";
	}
}
