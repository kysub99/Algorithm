#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dp[501][501];
int cost[501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int r, c;
	cin >> cost[0] >> cost[1];
	for (int i = 2;i <= n;i++) {
		cin >> r >> c;
		cost[i] = c;
	}
	/*for (int i = 0;i <= n;i++) {
		cout << cost[i] << " ";
	}*/
	for (int d = 1;d < n;d++) {
		for (int i = 1;i + d <= n;i++) {
			int j = i + d;
			dp[i][j] = INT_MAX;
			for (int k = i;k < j;k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost[i - 1] * cost[k] * cost[j]);
			}
		}
	}
	cout << dp[1][n];	
}