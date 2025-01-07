#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	int maxNum = arr[1];
	int res = 1;
	int len = 1;
	int idx = 1;
	for (int i = 2;i <= n;i++) {
		if (maxNum <= arr[i]) {
			maxNum = arr[i];	
			res = max(res, len);
			len = 1;
		}
		else {
			len++;
		}
	}
	cout << max(res, len);
	
}