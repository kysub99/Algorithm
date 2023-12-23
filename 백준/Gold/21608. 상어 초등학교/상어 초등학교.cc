#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MAX 21
#define STU 401

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
//상 하 좌 우
int n;
int arr[MAX][MAX];
int ord[STU];
int pref[STU][4];

bool isIn(int r, int c) {
	return 1 <= r && r <= n && 1 <= c && c <= n;
}

bool isPref(int s1, int s2) {
	for (int i = 0;i < 4;i++) {
		if (pref[s1][i] == s2)
			return true;
	}
	return false;
}

pair<int, int> getPlace(int num) {
	int pcnt = 0;//호감수
	int bcnt = 0;//공백수
	int mp = 0, mb = 0;
	int mi = 0, mj = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (arr[i][j] != 0)
				continue;
			pcnt = 0;
			bcnt = 0;
			for (int k = 0;k < 4;k++) {
				int ni = i + di[k];
				int nj = j + dj[k];
				if (isIn(ni, nj)) {
					if (isPref(num, arr[ni][nj])) {
						pcnt++;
					}
					if (arr[ni][nj] == 0) {
						bcnt++;
					}
				}
			}
			if (pcnt > mp) {
				mp = pcnt;
				mb = bcnt;
				mi = i;
				mj = j;
			}
			else if (pcnt == mp) {
				if (bcnt > mb) {
					mp = pcnt;
					mb = bcnt;
					mi = i;
					mj = j;
				}
			}
			if (mi == 0 && mj == 0) {
				mp = pcnt;
				mb = bcnt;
				mi = i;
				mj = j;
			}
		}
	}
	return { mi,mj };
}

int getSum() {
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			int cnt = 0;
			for (int k = 0;k < 4;k++) {
				int ni = i + di[k];
				int nj = j + dj[k];
				if (isIn(ni, nj) && isPref(arr[i][j], arr[ni][nj])) {
					cnt++;
				}
			}
			if (cnt == 1) {
				sum += 1;
			}
			else if (cnt == 2) {
				sum += 10;
			}
			else if (cnt == 3) {
				sum += 100;
			}
			else if (cnt == 4) {
				sum += 1000;
			}
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0;i < n * n;i++) {
		cin >> ord[i];
		for (int j = 0;j < 4;j++) {
			cin >> pref[ord[i]][j];
		}
	}
	for (int i = 0;i < n * n;i++) {
		pair<int, int> temp = getPlace(ord[i]);
		arr[temp.first][temp.second] = ord[i];
	}

	cout << getSum();
}