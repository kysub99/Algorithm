#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	set<int> st;
	int num;
	for (int i = 0;i < n;i++) {
		cin >> num;
		st.insert(num);
	}
	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> num;
		if (st.find(num) == st.end()) {
			cout << "0 ";
		}
		else
			cout << "1 ";
	}
	cout << "\n";
}