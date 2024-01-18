#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int n, k, p, x;
bool num[10][7] = {
	{1,1,1,0,1,1,1},//0
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},//5
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
int revCnt[10][10];

void setCnt() {
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			int cnt = 0;
			for (int k = 0;k < 7;k++) {
				if (num[i][k] != num[j][k])
					cnt++;
			}
			revCnt[i][j] = cnt;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	setCnt();
	cin >> n >> k >> p >> x;

	int res = 0;

	for (int i = 1;i <= n;i++) {
		if (i == x)
			continue;

		int cnt = 0;
		int tempi = i;
		int tempx = x;
		int mod = pow(10, k - 1);
		for (int j = 0;j < k;j++) {
			int curi = tempi / mod;
			int curx = tempx / mod;
			tempi %= mod;
			tempx %= mod;
			mod /= 10;

			cnt += revCnt[curx][curi];
		}
		if (cnt <= p) {
			res++;
		}
			
	}

	cout << res;

	return 0;
}