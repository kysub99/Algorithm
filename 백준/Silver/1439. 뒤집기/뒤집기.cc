#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.length();
	int cnt1 = 0;
	int cnt2 = 0;
	bool check = true;
	for (int i = 0; i < len-1; i++) {
		if (s[i] != s[i + 1]) {
			if (check) {
				check = false;
				cnt1++;
			}
			else
				check = true;
			cnt2++;
		}
	}
	int min = (cnt1 < cnt2 ? cnt1 : cnt2);
	cout << min << "\n";
}