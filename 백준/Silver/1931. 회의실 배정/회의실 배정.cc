#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, s, f;
vector<pair<int, int>> arr;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> f;
		arr.push_back({ f,s });
	}
	sort(arr.begin(), arr.end());
	int temp = arr[0].first;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i].second >= temp) {
			cnt++;
			temp = arr[i].first;
		}
	}
	cout << cnt << "\n";
}