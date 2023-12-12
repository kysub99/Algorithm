#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 10001

int n, u, v;
int dp[MAX][2];
bool visit[MAX];
int weight[MAX];
vector<int> graph[MAX];


void dfs(int cur) {
	visit[cur] = true;
	for (int i = 0;i < graph[cur].size();i++) {
		int next = graph[cur][i];
		if (!visit[next]) {
			dfs(next);
			dp[cur][0] += max(dp[next][0], dp[next][1]);
			dp[cur][1] += dp[next][0];
		}
	}
	dp[cur][1] += weight[cur];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> weight[i];
	}
	for (int i = 1;i < n;i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
}
