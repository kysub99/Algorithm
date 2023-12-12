#include <iostream>
using namespace std;

long long int res = 0;

void GCD(long long int a, long long int b) {
	if (a % b == 0) {
		res = b;
	}
	else {
		GCD(b, a % b);
	}
}

int main() {
	long long int a, b;
	cin >> a >> b;
	GCD(a, b);
	cout << a * b / res << "\n";
}

