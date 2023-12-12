#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000000

long long dp[101][10];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	dp[1][0] = 0;
	for (int j = 1;j <= 9;j++) {
		dp[1][j] = 1;
	}
	for (int i = 2;i <= n;i++) {
		for (int j = 0;j <= 9;j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1])%MOD;
			}
		}
	}
	long long sum = 0;
	for(int i=0;i<=9;i++){
		sum += dp[n][i]%MOD;
	}
	cout << sum%MOD;
}