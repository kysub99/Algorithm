#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define MAX 51

int n, m;
int arr[MAX][MAX];
bool cld[MAX][MAX];
bool temp[MAX][MAX];
int d, s;
int dr[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dc[9] = { 0,-1,-1,0,1,1,1,0,-1 };
//대각선 2 4 6 8

bool isIn(int r, int c) {
	return 0 <= r && r < n && 0 <= c && c < n;
}

void move(int d,int s) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int nr = (i + dr[d] * s + n*s) % n;
			int nc = (j + dc[d] * s + n*s) % n;
			temp[nr][nc] = cld[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cld[i][j] = temp[i][j];
		}
	}
}

void rain() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (cld[i][j]) {
				arr[i][j]++;
			}
		}
	}
}

void magic() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (cld[i][j]) {
				int cnt = 0;
				for (int k = 2;k <= 8;k += 2) {
					int nr = i + dr[k];
					int nc = j + dc[k];
					if (isIn(nr, nc) && arr[nr][nc] > 0) {
						cnt++;
					}
				}
				arr[i][j] += cnt;
			}
		}
	}
}

void makeCloud() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (!cld[i][j] && arr[i][j] >= 2) {
				cld[i][j]=true;
				arr[i][j] -= 2;
			}
			else {
				cld[i][j] = false;
			}
		}
	}
}

void show() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (cld[i][j])
				cout << "c ";
			else
				cout << "x ";
		}
		cout << "\n";
	}
	cout << "------------------------\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}
	cld[n - 1][0] = true;
	cld[n - 1][1] = true;
	cld[n - 2][0] = true;
	cld[n - 2][1] = true;
	for (int i = 0;i < m;i++) {
		cin >> d >> s;
		move(d, s);
		rain();
		magic();
		makeCloud();
	}
	int res = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			res += arr[i][j];
		}
	}
	cout << res;
}