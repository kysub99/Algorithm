#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> c;

	ll res = 0;
	ll dig = 1;
	while (c) {
		res += (c % 7) * dig;
		c /= 7;
		dig *= 3;
	}
	cout << res;
}