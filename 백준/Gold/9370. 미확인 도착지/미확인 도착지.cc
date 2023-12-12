#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9

int n, m, t, s, g, h, a, b, d, x;

vector<int> func(vector<vector<pair<int, int>>> graph, int start) {
	vector<int> tot(n + 1, INF);//최단거리
	vector<bool> visit(n + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });
	tot[start] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		visit[cur] = true;
		pq.pop();
		for (int i = 0;i < graph[cur].size();i++) {
			int next = graph[cur][i].first;
			int nextCost = cost + graph[cur][i].second;
			//if (nextCost < tot[next]&&!visit[next]) {
			if (nextCost < tot[next]) {
				tot[next] = nextCost;
				pq.push({ tot[next], next });
			}
		}
	}
	return tot;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		vector<vector<pair<int, int>>> graph(n + 1);//인접정점, 가중치
		cin >> s >> g >> h;
		for (int i = 0;i < m;i++) {
			cin >> a >> b >> d;
			graph[a].push_back({ b,d });
			graph[b].push_back({ a,d });
		}
		vector<int> res;
		vector<int>sStart = func(graph, s);
		vector<int>gStart = func(graph, g);
		vector<int>hStart = func(graph, h);
		for (int i = 0;i < t;i++) {
			cin >> x;

			int temp1 = sStart[g] + gStart[h] + hStart[x];
			int temp2 = sStart[h] + hStart[g] + gStart[x];

 			if (sStart[x] == temp1 || sStart[x] == temp2)
				res.push_back(x);
		}
		sort(res.begin(), res.end());
		for (int i = 0;i<res.size();i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}
}