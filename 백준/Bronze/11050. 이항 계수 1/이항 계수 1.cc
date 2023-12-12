#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	int j = n;
	int u = 1;
	int d = 1;
	for (int i = 0;i < k;i++) {
		u *= j;
		j--;
	}
	for (int i = 1;i <= k;i++) {
		d *= i;
	}
	cout << u / d;
}