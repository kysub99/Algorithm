#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool hasRes(string str, char c) {
	for (int i = 0;i <=6 ;i+=3) {
		if (str[i] == c && str[i + 1] == c && str[i + 2] == c) {
			return true;
		}
	}
	for (int i = 0;i < 3;i++) {
		if (str[i] == c && str[i + 3] == c && str[i + 6] == c)
			return true;
	}
	if (str[4] == c) {
		if (str[0] == c && str[8] == c || str[2] == c && str[6] == c)
			return true;
	}
	return false;
}

bool func(string str) {
	int x = 0, o = 0;
	for (int i = 0;i < 9;i++) {
		if (str[i] == 'X')
			x++;
		else if (str[i] == 'O')
			o++;
	}

	if (x > 5 || o > 4)
		return false;

	bool hasX = hasRes(str, 'X');
	bool hasO = hasRes(str, 'O');

	if (x == o + 1) {
		if (x == 5 && o == 4) {
			if (!hasO)
				return true;
		}
		else {
			if (hasX && !hasO)
				return true;
		}
	}
	else if (x == o) {
		if (!hasX && hasO)
			return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	while (1) {
		cin >> str;
		if (str == "end")
			break;

		if (func(str))
			cout << "valid\n";
		else
			cout << "invalid\n";
	}

	return 0;
}