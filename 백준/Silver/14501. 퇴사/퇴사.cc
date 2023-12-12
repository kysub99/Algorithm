#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[17], t[16], p[16];
int n;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> t[i] >> p[i];
	}

	dp[0] = 0;
	for (int i = 1;i <= n;i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		if (i + t[i] <= n + 1)
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
	}
	cout << max(dp[n + 1], dp[n]);
}