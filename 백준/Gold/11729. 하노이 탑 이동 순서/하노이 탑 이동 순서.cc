#include <iostream>
using namespace std;

void move(int s, int d) {
	cout << s << " " << d << "\n";
}

void honoi(int s, int m, int d, int n) {
	if (n < 1)
		return;
	honoi(s, d, m, n-1);
	move(s, d);
	honoi(m, s, d, n-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int k = 1;
	for (int i = 1;i < n;i++) {
		k = 2 * k + 1;
	}
	cout << k << "\n";
	honoi(1, 2, 3, n);
}