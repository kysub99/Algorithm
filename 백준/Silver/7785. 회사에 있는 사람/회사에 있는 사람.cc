#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	string str1, str2;
	set<string> st;
	for (int i = 0;i < n;i++) {
		cin >> str1 >> str2;
		if (str2 == "enter") {
			st.insert(str1);
		}
		else {
			st.erase(str1);
		}
	}
	for (auto iter = --st.end();;iter--) {
		cout << *iter << "\n";
		if (iter == st.begin())
			break;
	}
}