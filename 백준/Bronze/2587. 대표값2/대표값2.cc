#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> arr;
	int n;
	int res = 0;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		arr.push_back(n);
		res += n;
	}
	sort(arr.begin(), arr.end());
	cout << res / 5 << "\n" << arr[2] << "\n";
}