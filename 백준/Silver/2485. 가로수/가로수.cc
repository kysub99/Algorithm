#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	vector<int> temp(n - 1);
	for (int i = 0;i < n - 1;i++) {
		temp[i] = arr[i + 1] - arr[i];
	}
	int res = temp[0];
	for (int i = 1;i < n-1;i++) {
		res = gcd(res, temp[i]);
	}
	int ans = 0;
	for (int i = 0;i < n - 1;i++) {
		ans += temp[i] / res - 1;
	}
	cout << ans << "\n";
}