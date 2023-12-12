#include <iostream>
using namespace std;

const int MAX = 301;
int m, n;
int arr[MAX][MAX];
int sum[MAX][MAX];

int getSub(int i, int j, int k, int l) {
	return sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i - 1][j - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> arr[i][j];
			sum[i][j] = arr[i][j];
		}
	}
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	int cnt = 0;

	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			for (int k = i;k <= m;k++) {
				for (int l = j;l <= n;l++) {
					int sub = getSub(i, j, k, l);
					if (sub == 10) {
						cnt++;
					}
					else if (sub >= 10) {
						break;
					}
				}
			}
		}
	}
	cout << cnt;
}