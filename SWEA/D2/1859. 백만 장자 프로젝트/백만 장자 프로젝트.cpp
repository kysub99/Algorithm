#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int t;

typedef long long ll;

int main() {
	cin >> t;
	for (int tc = 1;tc <= t;tc++) {
		stack<ll> st;
		int n;
		cin >> n;

		for (int i = 0;i < n;i++) {
			ll num;
			cin >> num;
			st.push(num);
		}

		ll res = 0;
		ll max = st.top();
		st.pop();

		while (!st.empty()) {
			ll cur = st.top();
			st.pop();
			if (cur < max) {
				res += max - cur;
			}
			else {
				max = cur;
			}
		}
		printf("#%d %lld\n", tc, res);
	}
}