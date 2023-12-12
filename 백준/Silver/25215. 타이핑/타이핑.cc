#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define INF 1e9

struct mode {
	bool big;// 현재 대문자인지
	int mn;// 최소 횟수
};

string str, tempStr;
mode dp[3001][3];// 안누름, 활/비활, 마지막

void setting() {
	for (int j = 0; j < 3; j++) {
		dp[0][j].big = false;
		dp[0][j].mn = 0;
	}
	for (int i = 1; i < 3001; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j].big = false;
			dp[i][j].mn = INF;
		}
	}
}

bool isBig(char c) {
	if ('A' <= c && c <= 'Z')
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	setting();
	str = " ";
	cin >> tempStr;
	str += tempStr;
	for (int i = 1;i < str.length();i++) {
		for (int j = 0;j < 3;j++) {
			if (dp[i - 1][j].big == isBig(str[i])) {//안바꿔도 됨
				if (dp[i][0].mn > dp[i - 1][j].mn) {
					dp[i][0].mn = dp[i - 1][j].mn;
					dp[i][0].big = isBig(str[i]);
				}
			}
			else {//바꿔야 함
				if (dp[i][1].mn > dp[i - 1][j].mn) {
					dp[i][1].mn = dp[i - 1][j].mn + 1;
					dp[i][1].big = isBig(str[i]);
				}
				if (dp[i][2].mn > dp[i - 1][j].mn) {
					dp[i][2].mn = dp[i - 1][j].mn + 1;
					dp[i][2].big = dp[i - 1][j].big;// 대/소문자는 그대로
				}
			}
		}
	}
	int res = INF;
	for (int j = 0;j < 3;j++) {
		res = min(res, dp[str.length() - 1][j].mn);
	}
	cout << res + str.length() - 1;
}
