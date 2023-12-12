#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int sum[26][200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int q;
	cin >> s >> q;
	for (int i = 0;i < 26;i++) {
		sum[i][0] = 0;
		for (int j = 0;j <= s.size();j++) {
			if (s[j] - 'a' == i) {
				sum[i][j + 1] = sum[i][j] + 1;//0부터j까지 누적합 j+1에 저장
			}
			else
				sum[i][j + 1] = sum[i][j];
		}
	}
	for (int i = 0;i < q;i++) {
		char a;
		int l, r;
		cin >> a >> l >> r;
		int temp = a - 'a';
		cout << sum[temp][r + 1] - sum[temp][l] << "\n";
	}
}