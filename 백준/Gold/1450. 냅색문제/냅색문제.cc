#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> arr;

void  bt(vector<long long>& res, int s, int e, long long sum) {
	if (s > e) {
		res.push_back(sum);
		return;
	}
	bt(res, s + 1, e, sum);// 포함x
	bt(res, s + 1, e, sum + arr[s]);// 포함o
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
	arr.resize(n);
	for (int i = 0;i < n;i++)
		cin >> arr[i];

	vector<long long> res1, res2;
	bt(res1, 0, n / 2, 0);
	bt(res2, n / 2 + 1, n - 1, 0);
	sort(res2.begin(), res2.end());
	
	int cnt = 0;
	for (int i = 0;i < res1.size();i++) {
		cnt += upper_bound(res2.begin(), res2.end(), c - res1[i]) - res2.begin();
	}
	cout << cnt;
}