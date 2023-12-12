#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	int res = 0;
	set<string> st;
	st.insert("ChongChong");
	for (int i = 0;i < n;i++) {
		string str1, str2;
		cin >> str1 >> str2;
		if (st.find(str1) != st.end()) {
			st.insert(str2);
		}
		else if (st.find(str2) != st.end()) {
			st.insert(str1);
		}
	}
	cout << st.size();
}