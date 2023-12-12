#include <iostream>
using namespace std;
#define MAX 41

int t, n;
pair<int,int> dp[MAX];//0,1

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0] = { 1,0 };
	dp[1] = { 0,1 };
	for (int i = 2;i < MAX;i++) {
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n].first << " " << dp[n].second << "\n";
	}
}