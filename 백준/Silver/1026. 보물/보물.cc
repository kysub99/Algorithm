#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for (int i = 0;i < n;i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());
	int res = 0;
	for (int i = 0;i < n;i++) {
		res += a[i] * b[i];
	}
	cout << res;
}