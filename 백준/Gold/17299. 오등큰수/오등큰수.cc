#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 1'000'001

int cnt[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	stack<pair<int, int>> st;//값, 인덱스
	vector<int> res(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	for (int i = 0;i < n;i++) {
		while (!st.empty() && cnt[st.top().first] < cnt[arr[i]]) {
			res[st.top().second] = arr[i];
			st.pop();
		}
		st.push({ arr[i], i });
	}
	while (!st.empty() && cnt[st.top().first] < MAX) {
		res[st.top().second] = -1;
		st.pop();
	}
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << " ";
	}
}