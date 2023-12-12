#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char arr[65][65];
int n;

void div(int a, int b, int n) {
	int cnt = 0;
	for (int i = a - n + 1;i <= a;i++) {
		for (int j = b - n + 1;j <= b;j++) {
			if (arr[i][j] == '1')
				cnt++;
		}
	}
	if (cnt == n * n) {
		cout << 1;
		return;
	}
	else if (cnt == 0) {
		cout << 0;
		return;
	}
	cout << "(";
	div(a - n / 2, b - n / 2, n / 2);
	div(a - n / 2, b, n / 2);
	div(a, b - n / 2, n / 2);
	div(a, b, n / 2);
	cout << ")";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	string str;
	for (int i = 1;i <= n;i++) {
		cin >> str;
		for (int j = 0;j < n;j++) {
			arr[i][j + 1] = str[j];
		}
	}
	div(n, n, n);
}
