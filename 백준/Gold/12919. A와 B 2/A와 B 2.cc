#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

string s, t;
bool hasRes = false;

bool isSame(string ct) {
	for (int i = 0;i < s.length();i++) {
		if (s[i] != ct[i])
			return false;
	}
	return true;
}

void func(string ct) {
	if (hasRes)
		return;
	if (s.length() == ct.length()) {
		hasRes = isSame(ct);
		return;
	}

	int last = ct.length() - 1;
	if (ct[0] == 'A' && ct[last] == 'A') {
		string nt = ct.substr(0, last);
		func(nt);
	}
	else if (ct[0] == 'B' && ct[last] == 'A') {
		string nt = ct.substr(1, last);
		reverse(nt.begin(), nt.end());
		func(nt);
		nt = ct.substr(0, last);
		func(nt);
	}
	else if (ct[0] == 'B' && ct[last] == 'B') {
		string nt = ct.substr(1, last);
		reverse(nt.begin(), nt.end());
		func(nt);
	}
	else {
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> t;

	func(t);

	if (hasRes)
		cout << 1;
	else
		cout << 0;

	return 0;
}