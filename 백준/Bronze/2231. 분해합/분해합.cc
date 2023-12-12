#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string str;
	cin >> str;
	int n = 0;;
	for (int i = 0; i < str.size(); i++) {
		n += (str[i]-'0') * (pow(10, str.size()-i-1));
	}
	int temp = n;
	for (int i = 0; i < n; i++) {
		int res = i;
		string stri = to_string(i);
		for (int j = 0; j < stri.size(); j++) {
			res += stri[j] - '0';
		}
		if (res == n) {
			temp = min(temp, i);
		}
	}
	if (temp == n)
		temp = 0;
	cout << temp << "\n";
}