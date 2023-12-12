#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int arr[502][502];
int dp[502][502];
pair<int, int> dir[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
// 상, 하, 좌, 우
int n, m;

int dfs(int r, int c) {
	if (r == n && c == m) {
		return 1;
	}
	if (dp[r][c] != -1)// 이미 왔던 지점
		return dp[r][c];
	dp[r][c] = 0;
	for (int i = 0;i < 4;i++) {
		int newr = r + dir[i].first;
		int newc = c + dir[i].second;
		if (arr[r][c] > arr[newr][newc])
			dp[r][c] += dfs(newr, newc);
	}
	return dp[r][c];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i <= n + 1;i++) {
		arr[i][0] = arr[i][m + 1] = INT_MAX;
	}
	for (int i = 0;i <= m + 1;i++) {
		arr[0][i] = arr[n + 1][i] = INT_MAX;
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(1, 1);
}