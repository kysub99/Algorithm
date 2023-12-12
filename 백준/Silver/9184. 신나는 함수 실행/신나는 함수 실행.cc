#include <iostream>
using namespace std;

int dp[21][21][21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0;i < 21;i++) {
		for (int j = 0;j < 21;j++) {
			dp[0][i][j] = 1;
			dp[i][0][j] = 1;
			dp[i][j][0] = 1;
		}
	}
	for (int a = 1;a < 21;a++) {
		for (int b = 1;b < 21;b++) {
			for (int c = 1;c < 21;c++) {
				if (a < b && b < c) {
					dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
				}
				else {
					dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
				}
			}
		}
	}
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		if (a <= 0 || b <= 0 || c <= 0) {
			cout << 1 << "\n";
		}
		else if (a > 20 || b > 20 || c > 20) {
			cout << dp[20][20][20] << "\n";
		}
		else {
			cout << dp[a][b][c] << "\n";
		}
	}
}