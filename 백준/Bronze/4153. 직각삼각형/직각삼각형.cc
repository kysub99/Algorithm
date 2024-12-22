#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	while (1) {
		vector<int> arr(3);
		for (int i = 0;i < 3;i++) {
			cin >> arr[i];
		}
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			return 0;
		sort(arr.begin(), arr.end());
		if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2)) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
}