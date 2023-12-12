#include <iostream>
#include <vector>
using namespace std;
#define MAX 100'001

int n, r, q;
int sr;//서브트리의 루트 U
int cnt[MAX];
vector<int> graph[MAX];

void cntNodes(int curNode) {
	cnt[curNode] = 1;
	for (int i = 0;i < graph[curNode].size();i++) {
		int next = graph[curNode][i];
		if (cnt[next] == 0) {
			cntNodes(next);
			cnt[curNode] += cnt[next];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r >> q;
	int u, v;
	for (int i = 0;i < n - 1;i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cntNodes(r);
	for (int i = 0;i < q;i++) {
		cin >> sr;
		cout << cnt[sr] << "\n";
	}
}