#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e6+1

int n;
vector<int> dp;
vector<int> ord;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	dp.resize(n + 1, INF);
	ord.resize(n + 1, -1);
	dp[1] = 0;
	for (int i = 1;i < n;i++) {
		if (3 * i <= n && dp[i] + 1 < dp[3 * i]) {
			dp[3 * i] = dp[i] + 1;
			ord[3 * i] = i;
		}
		if (2 * i <= n && dp[i] + 1 < dp[2 * i]) {
			dp[2 * i] = dp[i] + 1;
			ord[2 * i] = i;
		}
		if (dp[i] + 1 < dp[i + 1]) {
			dp[i + 1] = dp[i] + 1;
			ord[i + 1] = i;
		}
	}
	cout << dp[n] << "\n" << n << " ";
	int i = n;
	while (ord[i] != -1) {
		cout << ord[i] << " ";
		i = ord[i];
	}
}