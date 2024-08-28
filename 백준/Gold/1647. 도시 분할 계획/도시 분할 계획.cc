#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100'001

int n, m;
int a, b, c;
vector<pair<int, int>> graph[MAX];
bool visit[MAX];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });
	long long res = 0;
	int temp = 0;
	while (!pq.empty()) {
		int curEdge = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (visit[curNode]) {
			continue;
		}
		res += curEdge;
		temp = max(temp,curEdge);
		visit[curNode] = true;
		for (int i = 0;i < graph[curNode].size();i++) {
			int nextNode = graph[curNode][i].first;
			int nextEdge = graph[curNode][i].second;
			if (!visit[nextNode]) {
				pq.push({ nextEdge, nextNode });
			}
		}
	}
	cout << res - temp;
}