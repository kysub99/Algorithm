#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	arr.resize(n);
	for (int i = 0;i < n;i++) {	
		cin >> arr[i];
	}
	
	int f = 0;
	int e = n - 1;
	int rf = arr[f];
	int re = arr[e];
	int sum = abs(arr[f] + arr[e]);
	while (f < e) {
		int cur = abs(arr[f] + arr[e]);
		if (cur < sum) {
			sum = cur;
			rf = arr[f];
			re = arr[e];
		}
		if (arr[f] + arr[e] > 0)
			e--;
		else if (arr[f] + arr[e] < 0) {
			f++;
		}
		else {
			break;
		}
	}

	cout << rf << " " << re;

	return 0;
}