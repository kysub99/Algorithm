#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string* str = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	string nStr = str[0];
	int length = str[0].length();
	for (int i = 0; i < length; i++) {
		for (int j = 1; j < n; j++) {
			if (str[0][i] != str[j][i]) {
				nStr[i] = '?';
				break;
			}
			nStr[i] = str[0][i];
		}
	}
	cout << nStr << endl;
}