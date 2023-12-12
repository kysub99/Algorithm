#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, num, dir;//수, 번호, 방향
int gear[4][8];
int rDir[4];

void rotate() {
	for (int i = 0;i < 4;i++) {
		if (rDir[i] == -1) {//반시계
			int temp = gear[i][0];
			for (int j = 1;j < 8;j++) {
				gear[i][j - 1] = gear[i][j];
			}
			gear[i][7] = temp;
		}
		else if (rDir[i] == 1) {
			int temp = gear[i][7];
			for (int j = 7;j >= 1;j--) {
				gear[i][j] = gear[i][j - 1];
			}
			gear[i][0] = temp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	char c;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 8;j++) {
			cin >> c;
			gear[i][j] = c - '0';
		}
	}
	cin >> k;
	for (int i = 0;i < k;i++) {
		for (int l = 0;l < 4;l++) {
			rDir[l] = 0;
		}
		cin >> num >> dir;
		num--;
		rDir[num] = dir;
		int cur = num - 1;
		while (cur >= 0) {// 왼쪽
			if (gear[cur][2] != gear[cur + 1][6]) {
				rDir[cur] = rDir[cur + 1] * -1;
			}
			cur--;
		}
		cur = num + 1;
		while (cur < 4) {
			if (gear[cur - 1][2] != gear[cur][6]) {
				rDir[cur] = rDir[cur - 1] * -1;
			}
			cur++;
		}
		rotate();
	}

	int res = 0;
	if (gear[0][0])
		res += 1;
	if (gear[1][0])
		res += 2;
	if (gear[2][0])
		res += 4;
	if (gear[3][0])
		res += 8;

	cout << res;
}