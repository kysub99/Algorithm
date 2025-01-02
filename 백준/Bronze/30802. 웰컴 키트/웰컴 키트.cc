#include <iostream>
using namespace std;

int getT(int size, int t) {
	int shirt = size / t;
	if (size % t != 0)
		shirt++;
	return shirt;
}

int main() {
	int n;
	cin >> n;
	int s, m, l, xl, xxl, xxxl;
	cin >> s >> m >> l >> xl >> xxl >> xxxl;
	int t, p;
	cin >> t >> p;
	int shirt = getT(s, t) + getT(m, t) + getT(l, t) + getT(xl, t) + getT(xxl, t) + getT(xxxl, t);
	cout << shirt << "\n" << n / p << " " << n % p;
}