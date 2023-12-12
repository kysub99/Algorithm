#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long a, b, c;

long long div(long long num) {
	if (num == 1)
		return a;
	if (num % 2 == 1)
		return ((div(num / 2) * div(num / 2) % c) * a) % c;
	else
		return (div(num / 2) * div(num / 2)) % c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b >> c;
	long long res = div(b) % c;
	cout << res;
}
