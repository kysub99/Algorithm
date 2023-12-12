#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> dp;
vector<int> ord;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	arr.resize(n + 1);
	dp.resize(n + 1, 1);
	ord.resize(n + 1);
	for (int i = 1;i <= n;i++)
		cin >> arr[i];

	for (int i = 2;i <= n;i++) {
		for (int j = 1;j < i;j++) {//이전 것들
			if (arr[j]<arr[i] && dp[j] + 1>dp[i]) {
				dp[i] = dp[j] + 1;
				ord[i] = j;
			}
		}
	}
	int idx;// 가장 긴 부분수열 끝 인덱스
	int temp = 0;
	for (int i = 1;i <= n;i++) {
		if (dp[i] > temp) {
			temp = dp[i];
			idx = i;
		}
	}
	vector<int> res;
	while (idx != 0) {
		res.push_back(arr[idx]);
		idx = ord[idx];
	}
	cout << temp << "\n";
	for (int i = res.size() - 1;i >= 0;i--) {
		cout << res[i] << " ";
	}
}