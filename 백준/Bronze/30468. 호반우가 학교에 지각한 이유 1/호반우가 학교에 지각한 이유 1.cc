#include <iostream>
#include <algorithm>
using namespace std;

int s, d, i, l, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> d >> i >> l >> n;
	int sum = s + d + i + l;
	cout << max(0, 4 * n - sum);
}