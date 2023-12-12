#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visit;
int res;
bool isTree;

void dfs(int cur, int bef) {
	visit[cur] = true;
	for (int i = 0;i < graph[cur].size();i++) {
		int next = graph[cur][i];
		if (next != bef) {
			if (visit[next]) {// 사이클 형성
				isTree = false;
			}
			else {
				dfs(next, cur);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc=1;
	while (1) {
		cin >> n >> m;
		if (!n && !m)
			break;
		graph.clear();
		visit.clear();
		graph.resize(n + 1);
		visit.resize(n + 1, false);
		for (int i = 0;i < m;i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		res = 0;
		for (int i = 1;i <= n;i++) {
			if (!visit[i]) {
				isTree = true;
				dfs(i, 0);
				if (isTree)
					res++;
			}
		}
		cout << "Case " << tc;
		if (res == 0) {
			cout << ": No trees.\n";
		}
		else if (res == 1) {
			cout << ": There is one tree.\n";
		}
		else {
			cout << ": A forest of " << res << " trees.\n";
		}
		tc++;
	}
}