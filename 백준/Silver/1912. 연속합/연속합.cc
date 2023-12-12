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
	vector<int> arr(n);
	vector<int> dp(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	for (int i = 1;i < n;i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
	}
	int res = -2e9;
	for (int i = 0;i < n;i++) {
		res = max(res, dp[i]);
	}
	cout << res;
}