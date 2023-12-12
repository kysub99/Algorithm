#include <iostream>
#include <string>
using namespace std;

int k;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> s;
	for (int i = 0;i < s.length();i++) {
		if (i % k == 0)
			cout << s[i];
	}
}