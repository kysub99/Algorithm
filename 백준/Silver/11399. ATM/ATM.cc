#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	int sum = 0;
	vector<int> rarr;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
		rarr.push_back(sum);
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += rarr[i];
	}
	cout << res << "\n";
}