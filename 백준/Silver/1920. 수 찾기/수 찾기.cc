#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int n, m;

bool find(int s, int e, int num) {
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == num) {
			return true;
		}
		else if (arr[mid] < num) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	arr.resize(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cin >> m;
	for (int i = 0;i < m;i++) {
		int num;
		cin >> num;
		bool check = find(0, n - 1, num);
		if (check)
			cout << "1\n";
		else
			cout << "0\n";
	}
}