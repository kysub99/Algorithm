#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll getGcd(ll a, ll b) {
	if (b==0) {
		return a;
	}
	else {
		return getGcd(b, a % b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;
	ll gcd = getGcd(n, k);
	n /= gcd;
	k /= gcd;
	
	cout << n * (min(k, n - k) - 1);
}