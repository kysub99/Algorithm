#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100'001

int v;
vector<pair<int,int>> tree[MAX];
int res;

int bfs(int n) {
	queue<int> q;
	vector<int> cost(v + 1, 0);
	q.push(n);
	cost[n] = 0;
	while (!q.empty()) {
		int prev = q.front();
		q.pop();
		for (int i = 0;i < tree[prev].size();i++) {
			int curNode = tree[prev][i].first;
			int curCost = tree[prev][i].second;
			if (!cost[curNode]&&curNode!=n) {
				cost[curNode] = cost[prev] + curCost;
				q.push(curNode);
			}
		}
	}
	int maxIdx = 0;
	int maxVal = 0;
	for (int i = 1;i <= v;i++) {
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

	cin >> v;
	for (int i = 0;i < v;i++) {
		int a, b, c;
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1)
				break;
			cin >> c;
			tree[a].push_back({ b,c });
			tree[b].push_back({ a,c });
		}
	}
	int start = bfs(1);
	bfs(start);
	cout << res;
}