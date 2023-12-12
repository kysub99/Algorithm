#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<long long> arr(n + 1);
	vector<long long> sum(n + 1);
	vector<long long> cnt(m, 0);
	sum[0] =0;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
		sum[i] = (sum[i - 1] + arr[i]) % m;
	}
	for (int i = 0;i <= n;i++) {
		cnt[sum[i]]++;
	}
	long long res = 0;
	for (int i = 0;i < m;i++) {
		if (cnt[i] >= 2) {
			long long temp = cnt[i] * (cnt[i]-1) / 2;
			res += temp;
		}
	}
	cout << res << "\n";
}