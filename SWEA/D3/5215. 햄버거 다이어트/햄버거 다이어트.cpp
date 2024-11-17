#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 1;c <= t;c++) {
		int n, l;
		cin >> n >> l; // 재료, 칼로리

		vector<int> tarr(n+1); // 점수
		vector<int> karr(n+1); // 칼로리
		vector<vector<int>> dp(n + 1, vector<int>(l + 1, 0));

		for (int i = 1;i <= n;i++) {
			cin >> tarr[i] >> karr[i];
		}

		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= l;j++) {
				dp[i][j] = dp[i - 1][j];
				if (karr[i] < j) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - karr[i]] + tarr[i]);
				}
			}
		}

		cout << "#" << c << " " << dp[n][l] << "\n";
	}
}