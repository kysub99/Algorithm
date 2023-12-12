#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	int num;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k / arr[i] != 0) {
			cnt += k / arr[i];
			k %= arr[i];
		}
	}
	cout << cnt << "\n";
}