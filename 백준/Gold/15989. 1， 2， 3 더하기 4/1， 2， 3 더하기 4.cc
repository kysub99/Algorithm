#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10'001

int t;
int dp[4][MAX];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][3] = 1;

	for (int i = 2;i < MAX;i++) {
		dp[1][i] = dp[1][i - 1];
	}
	for (int i = 3;i < MAX;i++) {
		dp[2][i] = dp[1][i - 2] + dp[2][i - 2];
	}
	for (int i = 4;i < MAX;i++) {
		dp[3][i] = dp[1][i - 3] + dp[2][i - 3] + dp[3][i-3];
	}

	cin >> t;
	int num;
	while (t--) {
		cin >> num;
		cout << dp[1][num]+dp[2][num]+dp[3][num] << "\n";
	}
}