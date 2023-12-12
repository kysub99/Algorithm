#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;

void func(vector<char> &arr, int l, int r) {
	int s = r - l + 1;
	if (s == 1)
		return;
	int lTemp = l + s / 3;
	int rTemp = r - s / 3;
	for (int i = lTemp;i <= rTemp;i++) {
		arr[i] = ' ';
	}
	func(arr, l, lTemp-1);
	func(arr, rTemp+1, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	while (cin >> n) {
		int s = pow(3, n);
		vector<char> arr(s, '-');
		func(arr, 0, s - 1);
		for (int i = 0;i < s;i++) {
			cout << arr[i];
		}
		cout << "\n";
	}
}