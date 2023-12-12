#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 1001

int dp[MAX][MAX];
pair<int, int> ord[MAX][MAX];
vector<char> res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string temp , str1 = " ", str2 = " ";
	cin >> temp;
	str1 += temp;
	cin >> temp;
	str2 += temp;
	int n = str1.size();
	int m = str2.size();
	for (int i = 1;i < n;i++) {
		for (int j = 1;j < m;j++) {
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ord[i][j] = { i - 1, j - 1 };
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					ord[i][j] = { i - 1, j };
				}
				else {
					dp[i][j] = dp[i][j - 1];
					ord[i][j] = { i, j - 1 };
				}
			}
		}
	}

	cout << dp[n - 1][m - 1] << "\n";
	pair<int, int> cur = { n - 1, m - 1 };
	int a = n - 1;
	int b = m - 1;
	while (a && b) {
		if (str1[a] == str2[b])
			res.push_back(str1[a]);
		int tempa = ord[a][b].first;
		int tempb = ord[a][b].second;
		a = tempa;
		b = tempb;
	}
	reverse(res.begin(), res.end());
	for (char sol : res) {
		cout << sol;
	}
}