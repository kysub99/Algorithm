#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr[501];
vector<int> dp[501];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	int cnt = 1;
	for (int i = 1;i <= n;i++) {
		arr[i].push_back(0);
		dp[i].push_back(0);
		for (int j = 1;j <= cnt;j++) {
			int num;
			cin >> num;
			arr[i].push_back(num);
			dp[i].push_back(0);
		}
		cnt++;
	}
	dp[1][1] = arr[1][1];
	cnt = 1;
	for (int i = 2;i <= n;i++) {
		for (int j = 1;j <= cnt;j++) {
			dp[i][j] = max(dp[i][j], arr[i][j] + dp[i - 1][j]);
			dp[i][j+1] = max(dp[i][j+1], arr[i][j+1] + dp[i - 1][j]);
		}
		cnt++;
	}
	int res = 0;
	for (int i = 1;i <= n;i++) {
		res = max(res, dp[n][i]);
	}
	cout << res;
}