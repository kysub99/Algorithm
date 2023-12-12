#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, b, c;
	cin >> n;
	vector<ll> arr(n);
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	cin >> b >> c;
	ll res = 0;
	for (ll val : arr) {
		val = max(ll(0), val - b);
		res++;
		res += val / c;
		if (val % c != 0)
			res++;
	}
	cout << res;
}