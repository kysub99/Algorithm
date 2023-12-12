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
	vector<pair<int, int>> arr(n);
	vector<int> dp(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i].first >> arr[i].second;
		dp[i] = 1;
	}
	sort(arr.begin(), arr.end());
	int res = 1;
	for (int i = 0;i < n;i++) {
		int temp = 0;
		for (int j = 0;j < i;j++) {
			if (arr[i].second > arr[j].second) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp + 1;
		res = max(res, dp[i]);
	}
	cout << n - res;
}