#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100'001

int n;
vector<pair<int, int>> tree[MAX];
int res;

int bfs(int num) {
	queue<int> q;
	vector<int> cost(n + 1, 0);
	q.push(num);
	cost[num] = 0;
	while (!q.empty()) {
		int prev = q.front();
		q.pop();
		for (int i = 0;i < tree[prev].size();i++) {
			int curNode = tree[prev][i].first;
			int curCost = tree[prev][i].second;
			if (!cost[curNode] && curNode != num) {
				cost[curNode] = cost[prev] + curCost;
				q.push(curNode);
			}
		}
	}
	int maxIdx = 0;
	int maxVal = 0;
	for (int i = 1;i <= n;i++) {
		if (maxVal < cost[i]) {
			maxIdx = i;
			maxVal = cost[i];
		}
	}
	res = maxVal;
	return maxIdx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int a, b, c;
	for (int i = 1;i < n;i++) {
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	int start = bfs(1);
	bfs(start);
	cout << res;
}