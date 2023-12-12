#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 1;i <= n;i++) {
		int num;
		cin >> num;
		if (arr.empty() || arr.back() < num) {
			arr.push_back(num);
		}
		else {
			auto idx = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
			arr[idx] = num;
		}
	}
	cout << arr.size();
}