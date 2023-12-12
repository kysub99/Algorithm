#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;
vector<int> arr;
int res = 0;

void divide(int s, int e) {
	if (s == e)
		return;
	long long sum = 1;
	int mid = (s + e) / 2;
	int last = arr[0];
	for (int i = 1;i < n;i++) {
		if (arr[i] - last >= mid) {
			sum++;
			last = arr[i];
		}
	}
	if (sum >= c) {//거리 늘려야 함-mid 증가
		res = max(res, mid);
		divide(mid + 1, e);
	}
	else {
		divide(s, mid);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> c;
	arr.resize(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	divide(0, 1e9 + 1);
	cout << res;
}