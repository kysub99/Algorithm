#include <iostream>
#include <vector>
#include <algorithm>
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
	cin >> x;
	int i = 0;
	int j = n - 1;
	int cnt = 0;
	while (i < j) {
		if (arr[i] + arr[j] == x) {
			cnt++;
			i++;
			j--;
		}
		else if (arr[i] + arr[j] < x)
			i++;
		else
			j--;
	}
	cout << cnt;
}