#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	int dr[4] = { 0,1,0,-1 };
	int dc[4] = { 1,0,-1,0 };
	for (int tc = 1;tc <= t;tc++) {
		int n;
		cin >> n;
		vector<vector<int>> arr(n + 2, vector<int>(n + 2, 0));
		for (int i = 0;i < n + 2;i++) {
			arr[0][i] = arr[i][0] = arr[n + 1][i] = arr[i][n + 1] = -1;
		}
		int dir = 0;
		int r = 1;
		int c = 1;
		for (int i = 1;i <= n * n;i++) {
			arr[r][c] = i;
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			if (arr[nr][nc] != 0) {
				dir = (dir + 1) % 4;
			}
			r = r + dr[dir];
			c = c + dc[dir];
		}

		cout << "#" << tc << "\n";
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
}