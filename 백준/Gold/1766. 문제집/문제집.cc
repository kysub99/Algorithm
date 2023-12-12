#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 32001

int n, m;
vector<int> order[MAX];
int inDegree[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n >> m;
	int a, b;
	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		order[a].push_back(b);
		inDegree[b]++;
	}
	for (int i = 1;i <= n;i++) {
		if (inDegree[i] == 0)
			pq.push(i);
	}
	while (!pq.empty()) {
		int cur = pq.top();
		cout << cur << " ";
		pq.pop();
		for (int i = 0;i < order[cur].size();i++) {
			int next = order[cur][i];
			inDegree[next]--;
			if (inDegree[next] == 0) {
				pq.push(next);
			}
		}
	}
}