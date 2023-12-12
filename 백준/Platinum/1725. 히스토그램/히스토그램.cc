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
	vector<int> arr(n + 2);
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	stack<int> st;
	st.push(0);
	int res = 0;
	for (int i = 1;i <= n + 1;i++) {
		if (arr[st.top()] <= arr[i]) {//새로 들어오는게 더 높으면 그냥 push
			st.push(i);
		}
		else {
			while (arr[st.top()] > arr[i]) {// 새로 들어오는거 보다 높은것들을 기준높이로 한 넓이 계산
				int h = arr[st.top()];
				st.pop();
				res = max(res, h * (i - st.top() - 1));
			}
			st.push(i);
		}
	}
	cout << res;
}
