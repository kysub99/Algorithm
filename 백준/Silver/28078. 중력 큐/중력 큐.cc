#include <iostream>
#include <string>
#include <vector>
#include <deque>
#define MOD 4

using namespace std;

int q;
string str1, str2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> q;
	deque<char> dq;
	int bcnt = 0, wcnt = 0;
	int dir = 0;// 뒤가 l u r d (시계방향
	for (int i = 0;i < q;i++) {
		cin >> str1;
		if (str1 == "push") {
			char c;
			cin >> c;
			dq.push_front(c);

			if (c == 'b')
				bcnt++;
			else
				wcnt++;
		}
		else if (str1 == "pop") {
			if (dq.size() != 0) {
				if (dq.back() == 'b')
					bcnt--;
				else
					wcnt--;
				dq.pop_back();
			}
		}
		else if (str1 == "rotate") {
			cin >> str2;
			if (str2 == "l") {
				dir = (dir + MOD - 1) % MOD;
			}
			else {
				dir = (dir + 1) % MOD;
			}
		}
		else if (str1 == "count") {
			cin >> str2;
			if (str2 == "b")
				cout << bcnt << "\n";
			else
				cout << wcnt << "\n";
		}

		if (dir == 1) {
			while (!dq.empty() && dq.back() == 'b') {
				dq.pop_back();
				bcnt--;
			}
		}
		if (dir == 3) {
			while (!dq.empty() && dq.front() == 'b') {
				dq.pop_front();
				bcnt--;
			}
		}
	}
}