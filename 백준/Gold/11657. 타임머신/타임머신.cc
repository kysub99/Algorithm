#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#define INF 1e9

int n, m, a, b, c;
vector<long long> res;
vector<tuple<int, int, int>> edge;

bool b_f(int start) {
	res[start] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j < m;j++) {
			tie(a, b, c) = edge[j];
			if (res[a] != INF && res[a] + c < res[b]) {
				if (i == n)
					return false;
				res[b] = res[a] + c;
			}
		}
	}
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	res.resize(n + 1, INF);
	edge.resize(m);
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		edge[i] = { a,b,c };
	}
	bool check = b_f(1);
	if (check) {
		for (int i = 2;i <= n;i++) {
			if (res[i] == INF)
				cout << "-1\n";
			else
				cout << res[i] << "\n";
		}
	}
	else
		cout << "-1\n";
}