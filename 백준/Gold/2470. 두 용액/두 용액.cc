#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n, x;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	arr.resize(n);
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int i = 0;
	int j = n - 1;
	int a, b;
	int res = 2e9+1;
	while (i < j) {
		int sum = arr[i] + arr[j];
		if (abs(sum) < res) {
			res = abs(sum);
			a = arr[i];
			b = arr[j];
		}
		if (sum > 0) {
			j--;
		}
		else if (sum < 0) {
			i++;
		}
		else
			break;
	}
	cout << a << " " << b;
}