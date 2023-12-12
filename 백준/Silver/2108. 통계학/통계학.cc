#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int check[8001];

int main() {
	int n;
	cin >> n;
	int num;
	vector<int> arr;
	priority_queue<int, vector<int>, greater<int>> q;
	int res = 0;
	for (int i = 0; i < 8001; i++) {
		check[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> num;
		res += num;
		arr.push_back(num);
		check[num + 4000]++;
	}
	int max = 0;
	for (int i = 0; i < 8001; i++) {
		if (check[i] > max)
			max = check[i];
	}
	for (int i = 0; i < 8001; i++) {
		if (check[i] == max) {
			q.push(i);
		}
	}
	if (q.size() > 1)
		q.pop();

	sort(arr.begin(), arr.end());
	int temp = round(double(res) / double(n));
	if (temp == -0)
		temp = 0;
	cout << temp << "\n";
	cout << arr[n / 2] << "\n";
	cout << q.top() - 4000 << "\n";
	cout << arr[n - 1] - arr[0] << "\n";
}