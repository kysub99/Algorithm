#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<long long> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	long long res = 0;
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			long long ts = arr[i] + arr[j];
			long long sn = ts * -1;
			long long fi = lower_bound(arr.begin(), arr.end(), sn) - arr.begin();
			long long li = upper_bound(arr.begin(), arr.end(), sn) - arr.begin();
			li--;
			int sum = 0;
			if (fi < n && arr[fi] == sn) {
				sum = li - fi + 1;
				if (fi <= i && i <= li)
					sum--;
				if (fi <= j && j <= li)
					sum--;
			}
			res += sum;
		}
	}
	cout << res / 3;
}