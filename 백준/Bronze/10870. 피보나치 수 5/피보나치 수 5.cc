#include <iostream>
using namespace std;

int fib(int n) {
	if (n == 0||n==1)
		return n;
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << fib(n);
}