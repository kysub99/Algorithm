#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int warr[101];
int varr[101];
int dp[101][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		cin >> warr[i] >> varr[i];
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= k;j++) {
			dp[i][j] = dp[i - 1][j];
			if (warr[i] <= j) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - warr[i]] + varr[i]);
			}
		}
	}
	cout << dp[n][k];
}