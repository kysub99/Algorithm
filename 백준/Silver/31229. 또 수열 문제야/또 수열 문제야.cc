#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	int cur = 1;
	for (int i = 0;i < n;i++) {
		arr[i] = cur;
		cur += 2;
	}
	for (int num : arr) {
		cout << num << " ";
	}
}