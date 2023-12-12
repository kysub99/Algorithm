#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	int sum = 0;
	for (int i = 1;i <= k;i++) {
		sum += arr[i];
	}
	int res = sum;
	for (int i = k + 1;i <= n;i++) {
		sum += arr[i];
		sum -= arr[i - k];
		res = max(res, sum);
	}
	cout << res;
}