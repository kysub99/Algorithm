#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001

string s1 = " ", s2 = " ", temp;
int dp[MAX][MAX];
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> temp;
	s1 += temp;
	cin >> temp;
	s2 += temp;
	n = s1.length();
	m = s2.length();
	for (int i = 1;i < MAX;i++) {
		dp[0][i] = dp[i][0] = i;
	}

	for (int i = 1;i < n;i++) {
		for (int j = 1;j < m;j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min({ dp[i - 1][j - 1],
					dp[i - 1][j], dp[i][j - 1] }) + 1;
			}
		}
	}
	cout << dp[n - 1][m - 1];
}