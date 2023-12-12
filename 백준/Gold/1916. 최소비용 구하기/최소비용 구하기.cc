#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 100'000'002
using namespace std;

int n, m;
int s, d, w;
int graph[1001][1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int value[1001];
bool check[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> d >> w;
		graph[s][d] = min(graph[s][d],w);
	}
	for (int i = 1; i <= n; i++) {
		value[i] = INF;
	}
	cin >> s >> d;
	value[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int wtemp1 = pq.top().first;
		int vtemp1 = pq.top().second;
		pq.pop();
		for (int i = 1; i <= n; i++) {
			
			int wtemp2 = graph[vtemp1][i];
			int vtemp2 = i;
			if (wtemp1 + wtemp2 < value[vtemp2]) {
				value[vtemp2] = wtemp1 + wtemp2;
				pq.push({ value[vtemp2],vtemp2 });
			}
		}
	}
	cout << value[d] << "\n";
}