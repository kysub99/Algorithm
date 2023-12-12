#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[2188][2188];

int moRes = 0, zRes = 0, oRes = 0;

void div(int a, int b, int n) {
	int mo = 0, z = 0, o = 0;
	for (int i = a;i < a+n;i++) {
		for (int j = b;j < b+n;j++) {
			if (arr[i][j] == 1)
				o++;
			else if (arr[i][j] == -1)
				mo++;
			else
				z++;
		}
	}
	if (o == n * n){
		oRes++;
		return;
	}
	if(mo == n * n) {
		moRes++;
		return;
	}
	if(z == n * n) {
		zRes++;
		return;
	}
	int d3 = n / 3;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			div(a + i * d3, b + j * d3, d3);
		}
	}
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
		}
	}
	div(1, 1, n);
	cout << moRes << "\n" << zRes << "\n" << oRes;
}
