#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 10'001

int dp[MAX][2];//  정점 포함여부
int n;
int wei[MAX];//가중치
int nextNode[MAX][2];// idx가 최대치일때 포함하는 다음 노드
vector<int> graph[MAX];
bool visit1[MAX];
bool visit2[MAX];
vector<int> child[MAX];
vector<int> res;

void setChild(int cur) {
	visit1[cur] = true;
	for (int i = 0;i < graph[cur].size();i++) {
		int next = graph[cur][i];
		if (!visit1[next]) {
			child[cur].push_back(next);
			setChild(next);
		}
	}
}

void dfs(int cur) {
	visit2[cur] = true;
	for (int i = 0;i < graph[cur].size();i++) {
		int next = graph[cur][i];
		if (!visit2[next]) {
			dfs(next);
		}
	}
	for (int i = 0;i < child[cur].size();i++) {
		int childNode = child[cur][i];
		dp[cur][0] += max(dp[childNode][0], dp[childNode][1]);
		dp[cur][1] += dp[childNode][0];
	}
	dp[cur][1] += wei[cur];
}

void trace(int cur, bool flag) {
	if (dp[cur][0] < dp[cur][1]&&flag) {//이전 노드 포함 안했고, 해당 노드 포함하는게 큼
		res.push_back(cur);
		for (int i = 0;i < child[cur].size();i++) {
			int next = child[cur][i];
			trace(next, false);//다음노드 포함 불가
		}
	}
	else {//이전 노드 포함했으므로 건너뜀
		for (int i = 0;i < child[cur].size();i++) {
			int next = child[cur][i];
			trace(next, true);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> wei[i];
	}
	int u, v;
	for (int i = 1;i < n;i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	setChild(1);
	dfs(1);
	trace(1, true);
	sort(res.begin(), res.end());
	cout << max(dp[1][0], dp[1][1]) << "\n";
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << " ";
	}
}
