#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	set<string> st;
	string c;
	for (int i = 0;i < n;i++) {
		cin >> c;
		st.insert(c);
	}
	int cnt = 0;
	for (int i = 0;i < m;i++) {
		cin >> c;
		if (st.find(c) != st.end())
			cnt++;
	}
	cout << cnt << "\n";

}