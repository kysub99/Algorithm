#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll w, h, k, n, m;
vector<ll> wsub, hsub;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> w >> h >> k;
	cin >> n;//세로가 짤림
	ll prev = 0;
	ll cur;
	for (int i = 1;i <= n;i++) {
		cin >> cur;
		hsub.push_back(cur - prev);
		prev = cur;
	}
	hsub.push_back(h - prev);
	cin >> m;//가로가 짤림
	prev = 0;
	for (int i = 1;i <= m;i++) {
		cin >> cur;
		wsub.push_back(cur - prev);
		prev = cur;
	}
	wsub.push_back(w - prev);

	sort(hsub.begin(), hsub.end());
	sort(wsub.begin(), wsub.end());

	ll res = 0;
	for (ll val : hsub) {
		long double temp = (long double)k / val;
		ll idx = upper_bound(wsub.begin(), wsub.end(), temp) - wsub.begin();
		res += idx;
	}
	cout << res;
}