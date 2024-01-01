#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <queue>
#include <tuple>
using namespace std;
#define AMAX 101
#define CMAX 10'001
#define INF (int)1e9+1

int dp[AMAX][CMAX];
int n, m;
int sum = 0;
vector<int> marr(AMAX);
vector<int> carr(AMAX);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;	
	for (int i = 1;i <= n;i++) {
		cin >> marr[i];
	}
	for (int i = 1;i <= n;i++) {
		cin >> carr[i];
		sum += carr[i];
	}	
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= sum;j++) {
			if (j - carr[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - carr[i]] + marr[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	int res = INF;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= sum;j++) {
			if (dp[i][j] >= m) {
				res = min(res, j);
			}
		}
	}
	cout << res;
}