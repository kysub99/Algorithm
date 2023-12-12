#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[301];
int dp[301];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1], arr[2])+arr[3];
	for (int i = 4;i <= n;i++) {
		dp[i] = arr[i] + max(dp[i - 2], dp[i - 3] + arr[i - 1]);
	}
	cout << dp[n];
}