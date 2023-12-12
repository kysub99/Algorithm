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
	string str;
	cin >> str;
	set<string> st;
	for (int i = 0;i < str.size();i++) {
		string temp = "";
		for (int j = i;j < str.size();j++) {
			temp += str[j];
			st.insert(temp);
		}
	}
	cout << st.size() << "\n";
}