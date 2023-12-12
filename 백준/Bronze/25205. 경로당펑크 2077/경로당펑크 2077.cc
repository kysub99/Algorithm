#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	int n;
	cin >> n >> s;
	char c = s[n - 1];
	if (c == 'q' || c == 'w' || c == 'e' || c == 'r' || c == 't' || c == 'a' || c == 's' || c == 'd' || c == 'f' || c == 'g' || c == 'z' ||
		c == 'x' || c == 'c' || c == 'v')
		cout << 1;
	else
		cout << 0;
}