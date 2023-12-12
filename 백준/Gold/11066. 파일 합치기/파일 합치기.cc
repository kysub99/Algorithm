#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		vector<int> arr(k + 1);
		vector<int> sum(k + 1);
		for (int i = 1;i <= k;i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		
		for (int d = 1;d < k;d++) {
			for (int i = 1;i + d <= k;i++) {
				int j = i + d;
				dp[i][j] = INT_MAX;
				for (int m = i;m < j;m++) {
					dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}
		cout << dp[1][k] << "\n";
	}
}