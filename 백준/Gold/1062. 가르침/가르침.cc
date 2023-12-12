#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int word[50];
string s;
int bit;
int cnt = 0;
int res = 0;

void func(int w) {
	if (cnt == k) {
		int resCnt = 0;
		for (int i = 0; i < n; i++) {
			if ((word[i] & bit) == word[i])
				resCnt++;
		}
		res = max(res, resCnt);
		return;
	}
	for (int i = w; i < 26; i++) {
		if ((bit&(1<<i))==0) {
			bit |= (1 << i);
			cnt++;
			func(i);
			bit &= ~(1 << i);
			cnt--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> s;
		word[i] = 0;
		for (int j = 0; j < s.size(); j++) {
			word[i] |= (1 << (s[j]-'a'));
		}
	}
	bit |= (1 << ('a' - 'a'));
	bit |= (1 << ('c' - 'a'));
	bit |= (1 << ('i' - 'a'));
	bit |= (1 << ('n' - 'a'));
	bit |= (1 << ('t' - 'a'));
	if (k < 5) {
		cout << "0\n";
		return 0; 
	}
	else if (k == 26) {
		cout << n << "\n";
		return 0;
	}
	k -= 5;
	func(0);
	cout << res << "\n";
}