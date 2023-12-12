#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MIN -1'000'000'001

int n;
vector<int> arr;
vector<int> tmp;// 길이
vector<int> ord;// 역추적
vector<int> res; // 답 저장

bool comp(const int& a, const int& b) {
	return arr[a] < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	arr.resize(n + 1);
	ord.resize(n + 1);
	arr[0] = MIN;
	tmp.push_back(0);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		if (arr[i] > arr[tmp.back()]) {
			tmp.push_back(i);
			ord[i] = tmp[tmp.size() - 2];
		}
		else {
			int idx = lower_bound(tmp.begin(), tmp.end(), arr[i], comp) - tmp.begin();
			ord[i] = tmp[idx - 1];
			tmp[idx] = i;
		}
	}
	cout << tmp.size() - 1 << "\n";
	int endIdx = tmp.back();

	while (endIdx) {
		res.push_back(arr[endIdx]);
		endIdx = ord[endIdx];
	}

	reverse(res.begin(), res.end());
	for (int val : res) {
		cout << val << " ";
	}
	cout << "\n";

	return 0;

}
