#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
#define MAX 16
#define INF (int)1e9

int w[MAX][MAX];
int dp[1 << MAX][MAX];
int n;
int res = INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> w[i][j];
		}
	}
	for (int i = 0;i < (1 << n);i++) {
		for (int j = 0;j < n;j++) {
			dp[i][j] = INF;
		}
	}
	dp[1][0] = 0;
	for (int i = 0;i < (1 << n);i++) {
		for (int j = 0;j < n;j++) {
			if (((i >> j) & 1) == 0) {// j정점이 path에 포함 안됐음
				continue;
			}
			for (int k = 0;k < n;k++) {
				if (((i >> k) & 1) == 1) {// k정점에 path에 포함
					continue;
				}
				if (w[j][k] == 0)// j->k 못감
					continue;
				dp[(1 << k) + i][k] = min(dp[(1 << k) + i][k], dp[i][j] + w[j][k]);
			}
		}
	}

	int res = INF;
	for (int i = 0;i < n;i++) {
		if (w[i][0]==0)// 출발점으로 돌아갈 수 없음
			continue;
		int temp = dp[(1 << n) - 1][i] + w[i][0];
		res = min(res, temp);
	}
	cout << res;
}