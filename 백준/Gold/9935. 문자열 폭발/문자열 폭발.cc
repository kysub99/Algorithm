#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string t, p;
	cin >> t >> p;
	stack<char> st;
	stack<char> temp;
	int n = t.length();
	int m = p.length();
	for (int i = 0;i < n;i++) {
		st.push(t[i]);
		if (t[i] == p[m-1]) {//맨뒤 같으면 일치하는지 확인
			int j = m - 1;//패턴 뒤
			while (!st.empty() && j >= 0) {
				if (st.top() == p[j]) {
					temp.push(st.top());
					st.pop();
					j--;
				}
				else {//다름
					break;
				}
			}
			if (j == -1) {//다 일치 - temp 스택 비워야함
				while (!temp.empty()) {
					temp.pop();
				}
			}
			else {//부분 일치-스택에 다시 넣어줌
				while (!temp.empty()) {
					st.push(temp.top());
					temp.pop();
				}
			}

		}
	}
	if (st.empty()) {
		cout << "FRULA\n";
	}
	else {
		stack<char> res;
		int len = st.size();
		for (int i = 0;i < len;i++) {
			res.push(st.top());
			st.pop();
		}
		for (int i = 0;i < len;i++) {
			cout << res.top();
			res.pop();
		}
	}
}