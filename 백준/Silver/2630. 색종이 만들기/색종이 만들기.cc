#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[129][129];
int sum[129][129];

int blue = 0;
int white = 0;

bool isAll(int n, int x1, int y1, int x2, int y2) {
	int temp = sum[x2][y2] - sum[x1 - 1][y2] 
		- sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
	if (temp == n * n) {
		blue++;
		return true;
	}
	else if (temp == 0) {
		white++;
		return true;
	}
	return false;
}

void div(int n, int x1, int y1, int x2, int y2) {
	if (isAll(n,x1,y1,x2,y2))
		return;
	int n2 = n / 2;
	div(n2, x1, y1, x2 - n2, y2 - n2);//왼쪽위
	div(n2, x1+n2, y1+n2, x2, y2);//오른쪽아래
	div(n2, x1+n2, y1, x2, y2 - n2);//왼쪽아래
	div(n2, x1, y1+n2, x2-n2, y2);//오른쪽위
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> arr[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1]
				- sum[i - 1][j - 1] + arr[i][j];
		}
	}
	div(n, 1, 1, n, n);
	cout << white << "\n" << blue << "\n";
}