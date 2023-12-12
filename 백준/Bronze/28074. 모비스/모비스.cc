#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	bool m = false, o = false, b = false, i = false, s = false;
	for (int alp = 0;alp < str.length();alp++) {
		if (str[alp] == 'M')
			m = true;
		if (str[alp] == 'O')
			o = true;
		if (str[alp] == 'B')
			b = true;
		if (str[alp] == 'I')
			i = true;
		if (str[alp] == 'S')
			s = true;

	}
	if (m && o && b && i && s) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}