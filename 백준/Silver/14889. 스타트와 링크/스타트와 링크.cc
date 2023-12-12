#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std; 

int n;
int res = 2e9;
int arr[21][21];
bool check[21]; 

void func(int d, int idx) {
	if (d == n / 2) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (check[i] == true && check[j] == true) {
					sum1 += arr[i][j];
				}
				else if (check[i] != true && check[j] != true) {
					sum2 += arr[i][j];
				}
			}
		}
		res = min(res, abs(sum1 - sum2));
	}
	else {
		for (int i = idx;i <= n;i++) {
			if (check[i] != true) {
				check[i] = true;
				func(d + 1, i+1);
				check[i] = false;
			}
		}
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++)
			cin >> arr[i][j];
	}
	func(0, 1);
	cout << res;
}