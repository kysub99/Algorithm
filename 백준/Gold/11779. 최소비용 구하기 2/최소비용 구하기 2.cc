#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <queue>
using namespace std;
#define MAX 1001
#define INF 1e9

int n, m, a, b, c, s, e;
int city[MAX];
vector<int> cost(MAX, INF);
vector<vector<int>> bus(MAX, vector<int>(MAX, INF));
int ord[MAX];
vector<int> res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		bus[a][b] = min(bus[a][b], c);
	}
	cin >> s >> e;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;//비용, 도시
	pq.push({ 0, s });
	cost[s] = 0;
	while (!pq.empty()) {
		int tempCost = pq.top().first;
		int tempCity = pq.top().second;
		pq.pop();
		for (int i = 1;i <= n;i++) {
			if (bus[tempCity][i] != INF && bus[tempCity][i] + tempCost < cost[i]) {
				cost[i] = bus[tempCity][i] + tempCost;
				ord[i] = tempCity;
				pq.push({ cost[i], i });
			}
		}
	}
	cout << cost[e] << "\n";
	int idx = e;
	while (1) {
		res.push_back(idx);
		if (idx == s)
			break;
		idx = ord[idx];
	}
	reverse(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int val : res) {
		cout << val << " ";
	}
}