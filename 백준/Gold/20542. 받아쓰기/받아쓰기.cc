#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s1 = " ", s2 = " ", temp;
vector<vector<int>> dp;
int n, m;

bool isSame(char c1, char c2) {
	if (c1 == c2)
		return true;
	if (c1 == 'i') {
		if (c2 == 'j' || c2 == 'l') {
			return true;
		}
	}
	if (c1 == 'v') {
		if (c2 == 'w')
			return true;
	}
	if (c2 == 'i') {
		if (c1 == 'j' || c2 == 'l') {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> temp;
	s1 += temp;
	cin >> temp;
	s2 += temp;

	dp.resize(n + 1, vector<int>(m + 1));
	for (int i = 1;i <= n;i++) {
		dp[i][0] = i;
	}
	for (int j = 1;j <= m;j++) {
		dp[0][j] = j;
	}

	for (int i = 1;i <= n ;i++) {
		for (int j = 1;j <= m;j++) {
			if (isSame(s1[i], s2[j])) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min({ dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] }) + 1;
			}
		}
	}
	cout << dp[n][m];
}