#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 32001

int n, m;
vector<int> graph[MAX];
bool visit[MAX];
vector<int> res;

void dfs(int cur) {
	visit[cur] = true;
	for (int i = 0;i < graph[cur].size();i++) {
		int next = graph[cur][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
	res.push_back(cur);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int a, b;
	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 1;i <= n;i++) {
		if (!visit[i]) {
			dfs(i);
		}
	}
	reverse(res.begin(), res.end());
	for (int i : res) {
		cout << i << " ";
	}
}
