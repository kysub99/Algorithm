#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, d;
vector<int> a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	a.resize(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0;i < m;i++) {
		cin >> d;
		int idx = lower_bound(a.begin(), a.end(), d) - a.begin();
		if (idx == n || a[idx] != d)
			cout << -1 << "\n";
		else
			cout << idx << "\n";
	}
}