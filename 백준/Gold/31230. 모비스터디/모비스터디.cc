#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 200'001
typedef long long ll;

int n, m, a, b;
vector<pair<int, ll>> graph[MAX];
vector<ll> distA(MAX, LLONG_MAX), distB(MAX, LLONG_MAX);

void dijkstra(int start, vector<ll>& dist) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		ll cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (cost > dist[node])
			continue;

		for (int i = 0;i < graph[node].size();i++) {
			int nextNode = graph[node][i].first;
			ll nextCost = cost + graph[node][i].second;
			if (nextCost < dist[nextNode]) {
				dist[nextNode] = nextCost;
				pq.push({ nextCost, nextNode });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> a >> b;
	
	for (int i = 0;i < m;i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}

	dijkstra(a, distA);
	dijkstra(b, distB);

	vector<int> result;
	ll path = distA[b];
	for (int i = 1;i <= n;i++) {
		if (distA[i] + distB[i] == path) {
			result.push_back(i);
		}
	}

	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (int city : result) {
		cout << city << " ";
	}
}