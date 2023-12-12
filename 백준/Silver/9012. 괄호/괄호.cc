#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	while (t--) {
		stack<int> st;
		string str;
		cin >> str;
		bool yes = true;
		for (int i = 0;i < str.size();i++) {
			if (str[i] == '(')
				st.push(1);
			else {
				if (st.empty()) {
					yes = false;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty()) {
			yes = false;
		}
		if (yes)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}