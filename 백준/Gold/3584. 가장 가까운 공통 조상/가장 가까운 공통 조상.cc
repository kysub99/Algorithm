#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10'001

vector<int> tree[MAX];
int parent[MAX];
int depth[MAX];
int t, n, a, b;

void clearSet() {
	for (int i = 0;i < MAX;i++) {
		tree[i].clear();
		parent[i] = 0;
		depth[i] = 0;
	}
}

int getRoot() {
	for (int i = 1;i <= n;i++) {
		if (parent[i]==0)
			return i;
	}
}

void setDepth(int root) {
	queue<int> q;
	depth[root] = 1;
	q.push(root);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0;i < tree[cur].size();i++) {
			int next = tree[cur][i];
			depth[next] = depth[cur] + 1;
			q.push(next);
		}
	}
}

void makeSame() {
	while (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) {
			a = parent[a];
		}
		else {
			b = parent[b];
		}
	}
}

int getLCA(int root) {
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	if (a == 0)
		return root;
	else
		return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		clearSet();
		cin >> n;
		for (int i = 1;i < n;i++) {
			cin >> a >> b;
			tree[a].push_back(b);
			parent[b] = a;
		}
		int root = getRoot();
		setDepth(root);

		cin >> a >> b;
		makeSame();
		cout << getLCA(root) << "\n";
	}
}