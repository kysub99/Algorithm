#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	int num;
	set<int> st;
	for (int i = 0;i < a;i++) {
		cin >> num;
		st.insert(num);
	}
	int cnt = 0;
	for (int i = 0;i < b;i++) {
		cin >> num;
		if (st.find(num) != st.end())
			cnt++;
	}
	cout << a + b - 2 * cnt << "\n";
}