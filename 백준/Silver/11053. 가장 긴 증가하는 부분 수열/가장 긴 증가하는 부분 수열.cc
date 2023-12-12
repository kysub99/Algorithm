#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 2;i <= n;i++) {
		int temp = 0;
		for (int j = 1;j < i;j++) {
			if (arr[i] > arr[j]) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp + 1;
	}
	int res = 0;
	for (int i = 1;i <= n;i++) {
		res = max(res, dp[i]);
	}
	cout << res;
}