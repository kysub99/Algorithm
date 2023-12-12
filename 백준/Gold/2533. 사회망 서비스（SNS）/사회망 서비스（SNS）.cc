#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 1'000'001

int n, u, v;
int dp[MAX][2];
vector<int> graph[MAX];
vector<int> child[MAX];
vector<bool> visit(MAX, false);


void dfs(int cur) {
	visit[cur] = true;
	for (int i = 0;i < graph[cur].size();i++) {
		int next = graph[cur][i];
		if (!visit[next]) {
			dfs(next);
			dp[cur][0] += dp[next][1];
			dp[cur][1] += min(dp[next][0], dp[next][1]);
		}
	}
	dp[cur][1]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i < n;i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
}
