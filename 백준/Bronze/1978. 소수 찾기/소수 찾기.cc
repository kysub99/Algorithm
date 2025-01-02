#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<bool> arr(1001, true);
	arr[0] = arr[1] = false;
	for (int i = 2;i <= 1000;i++) {
		if (arr[i]) {
			for (int j = i * i; j <= 1000;j += i) {
				arr[j] = false;
			}
		}
	}

	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;
		if (arr[num])
			sum++;
	}
	cout << sum;
}