#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MOD 1000000007

int n, k;
long long kf;

long long fac(int k) {
	long long res = 1;
	for (int i = 1;i <= k;i++) {
		res = (res * i) % MOD;
	}
	return res;
}

long long div(int p) {
	if (p == 1)
		return kf;
	if (p % 2 == 1) {
		return (((div(p / 2) * div(p / 2)) % MOD) * kf) % MOD;
	}
	else {
		return ((div(p / 2) * div(p / 2)) % MOD) % MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	long long numerator = 1;
	for (int i = n; i > n - k; i--) {
		numerator = (numerator * i) % MOD;
	}
	kf = fac(k)%MOD;
	long long temp = div(MOD - 2)%MOD;
	cout << (numerator * temp) % MOD;
}