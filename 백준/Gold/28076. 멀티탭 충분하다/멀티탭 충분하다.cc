#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	cin >> n;
	arr.resize(n+1);
	for (int i = 1;i <= n;i++)
		cin >> arr[i];
	arr[0] = -1;
	sort(arr.begin(), arr.end());
	int res = 0;
	if (n == 1) {
		res = arr[1];
	}
	else if (n == 2) {
		res = arr[1] + arr[2] - 1;
	}
	else {
		res = arr[n] + arr[(2 * n) / 3] + arr[n / 3] - 3;
	}
	cout << res;
}