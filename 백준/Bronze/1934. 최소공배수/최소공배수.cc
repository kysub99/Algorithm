#include <iostream>
using namespace std;

int res = 0;

void GCD(int a, int b) {
	if (a % b == 0) {
		res = b;
	}
	else {
		GCD(b, a % b);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		GCD(a, b);
		cout << a * b / res << "\n";
	}
}

