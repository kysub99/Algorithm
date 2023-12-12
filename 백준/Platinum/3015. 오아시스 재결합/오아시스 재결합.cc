#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	stack<pair<int,int>> st;
	long long res = 0;
	for (int i = 1;i <= n;i++) {
		int cnt = 1;
		while (!st.empty() && st.top().first <= arr[i]) {
			res += st.top().second;
			if (st.top().first == arr[i]) {
				cnt += st.top().second;
			}
			st.pop();
		}
		if (!st.empty())
			res++;
		st.push({ arr[i], cnt });
	}
	cout << res;
}
