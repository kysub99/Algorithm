#include <iostream>
using namespace std;


int res = 0;
void GCD(int a, int b) {
	if (a % b == 0)
		res = b;
	else
		GCD(b, a % b);
}

int main() {
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int a, b;
	b = b1 * b2;
	a = a1 * b2 + a2 * b1;
	GCD(a, b);
	a /= res;
	b /= res;
	cout << a << " " <<  b << "\n";
}