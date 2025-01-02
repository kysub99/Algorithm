#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getGcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	return getGcd(b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;
	int gcd = getGcd(a, b);
	cout << gcd << "\n" << a * b / gcd;
}