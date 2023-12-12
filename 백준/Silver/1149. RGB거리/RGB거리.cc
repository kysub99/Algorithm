#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int arr[1000][3];
	int dp[1000][3];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> arr[i][j];
		}
	}
	for (int j = 0;j < 3;j++) {
		dp[0][j] = arr[0][j];
	}
	for (int i = 1;i < n;i++) {
		for (int j = 0;j < 3;j++) {
			dp[i][j] = arr[i][j] +
				min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
		}
	}
	int res = 2e9;
	for (int j = 0;j < 3;j++) {
		if (res > dp[n - 1][j])
			res = dp[n - 1][j];
	}
	cout << res;
}