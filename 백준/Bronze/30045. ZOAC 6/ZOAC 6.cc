#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int res = 0;
	for (int i = 0;i < n;i++) {
		cin >> s;
		int l = s.length();
		for (int j = 0;j < l-1;j++) {
			if (s[j] == '0' && s[j + 1] == '1' ||
				s[j] == 'O' && s[j + 1] == 'I') {
				res++;
				break;
			}
		}
	}
	cout << res;
}