#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2001

int arr[MAX][MAX];
int sum[MAX][MAX];
int white[MAX][MAX];
int black[MAX][MAX];
int n, m, k;

void set() {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			black[i][j] = (i + j) % 2;
			white[i][j] = (i + j + 1) % 2;
		}
	}
}

int getMin(int comp[MAX][MAX]) {
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1]
				- sum[i - 1][j - 1];
			if (arr[i][j] != comp[i][j]) {
				sum[i][j]++;
			}
		}
	}
	int res = 2e9;
	for (int i = k;i <= n;i++) {
		for (int j = k;j <= m;j++) {
			int temp = sum[i][j] - sum[i - k][j]
				- sum[i][j - k] + sum[i - k][j - k];
			res = min(res, temp);
		}
	}
	return res;
}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	set();
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			char c;
			cin >> c;
			if (c == 'W')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
	int res = min(getMin(white), getMin(black));
	cout << res;
}