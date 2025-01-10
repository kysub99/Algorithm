#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	int n = str.length();
	vector<vector<bool>> isPal(n, vector<bool>(n, false));

	for (int i = 0;i < n;i++) {
		isPal[i][i] = true;

	}

	for (int i = 0;i < n - 1;i++) {
		if (str[i] == str[i + 1]) {
			isPal[i][i + 1] = true;
		}
	}

	for (int l = 3;l <= n;l++) {
		for (int i = 0;i + l <= n;i++) {
			int j = i + l - 1;
			if (str[i] == str[j] && isPal[i + 1][j - 1]) {
				isPal[i][j] = true;
			}
		}
	}

	vector<int> dp(n, INT_MAX);
	for (int i = 0;i < n;i++) {
		if (isPal[0][i]) {
			dp[i] = 1;
		}
		else {
			for (int j = 0;j < i;j++) {
				if (isPal[j + 1][i]) {
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}
	}

	cout << dp[n - 1];
}