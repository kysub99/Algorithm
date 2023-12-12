#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 50000001

int V, E, P;
int a, b, c;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> graph[5001];
bool visit[5001];


int func(int start, int end) {
	int cost[5001];
	for (int i = 1; i <= V; i++) {
		cost[i] = INF;
	}
	cost[start] = 0;
	int cnt = 1;
	pq.push({ cost[start],start });
	while (!pq.empty()) {

		int wtemp = pq.top().first;//간선 비용(거리)
		int vtemp = pq.top().second;//정점
		pq.pop();
		for (int i = 0; i < graph[vtemp].size(); i++) {
			int wtemp2 = graph[vtemp][i].first;//간선 비용
			int vtemp2 = graph[vtemp][i].second;//정점
			if (cost[vtemp2] > cost[vtemp] + wtemp2) {
				cost[vtemp2] = cost[vtemp] + wtemp2;
				pq.push({ cost[vtemp2], vtemp2 });
				cnt++;
				if (cnt == V)
					break;
			}
			
		}
	}

	return cost[end];
}

int main() {
	cin >> V >> E >> P;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}
	int geonwoo = func(1, P) + func(P, V);
	int masan = func(1, V);
	if (geonwoo == masan)
		cout << "SAVE HIM\n";
	else
		cout << "GOOD BYE\n";

}