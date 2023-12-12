#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	long long dp[101];
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int i = 6;i <= 100;i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}