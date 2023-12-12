#include <iostream>
#include <cmath>
using namespace std;

bool arr[7000][7000];

void star(int x, int y, int n) {
	if (n == 1) {
		arr[x][y] = true;
		return;
	}
	int d3 = n / 3;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (i != 1 || j != 1) {
				star(x + i * d3, y + j * d3, d3);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	star(0, 0, n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == true)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}