#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100001

int n, a, b;
vector<vector<int>> tree(MAX);
int par[MAX];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 2;i <= n;i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	q.push(1);
	par[1] = 1;
	while (!q.empty()) {
		int prev = q.front();
		q.pop();
		for (int i = 0;i < tree[prev].size();i++) {
			int cur = tree[prev][i];
			if (!par[cur]) {
				par[cur] = prev;
				q.push(cur);
			}
		}
	}
	for (int i = 2;i <= n;i++)
		cout << par[i] << "\n";
}