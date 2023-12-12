#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 11
#define INF (int)1e9

int w[MAX][MAX];
vector<bool> visit(MAX, false);
int n;
int res = INF;

void findMax(int cnt, int cur, int sum) {
	if (sum > res)
		return;
	if (cnt == n) {
		if (w[cur][1] != 0)
			res = min(res, sum + w[cur][1]);
		return;
	}
	for (int next = 1;next <= n;next++) {
		if (!visit[next] && w[cur][next] != 0) {
			visit[next] = true;
			findMax(cnt + 1, next, sum + w[cur][next]);
			visit[next] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> w[i][j];
		}
	}
	visit[1] = true;
	findMax(1, 1, 0);// cnt, cur, sum
	cout << res;
}