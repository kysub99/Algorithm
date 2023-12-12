#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> arr;
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < t; i++) {
		cout << arr[i] << "\n";
	}
}