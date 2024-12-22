#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	while (1) {
		string str;
		cin >> str;
		if (str == "0")
			return 0;

		bool pal = true;
		for (int i = 0;i < str.size() / 2;i++) {
			if (str[i] != str[str.size() - i - 1]) {
				pal = false;
				break;
			}
		}
		if (pal) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}