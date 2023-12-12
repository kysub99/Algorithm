#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[2][3];
int sum = 0;
int cnt = 0;

void bt(int depth, int pi, int pj, int pval) {
	if (depth == n) {
		if (sum >= m)
			cnt++;
		return;
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 3;j++) {
			int temp;
			if (j == pj)//장소 같음
				temp = arr[i][j] / 2;
			else
				temp = arr[i][j];
			sum += temp;
			bt(depth + 1, i, j, temp);
			sum -= temp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < 3;i++)
		cin >> arr[0][i];
	for (int i = 0;i < 3;i++)
		cin >> arr[1][i];
	bt(0, -1, -1, 0);

	cout << cnt;
}