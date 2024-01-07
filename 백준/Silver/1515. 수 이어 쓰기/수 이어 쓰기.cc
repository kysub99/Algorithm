#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n = 1;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;

	int idx = 0;
	while (idx < str.length()) {
		string nstr = to_string(n);
		for (int i = 0;i < nstr.length();i++) {
			if (nstr[i] == str[idx]) {
				idx++;
			}
		}
		n++;
	}

	cout << n - 1;

	return 0;
}