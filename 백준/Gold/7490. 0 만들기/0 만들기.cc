#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <deque>
#include <string>
using namespace std;

int t, n;
char c[3] = { ' ', '+', '-' };

bool isZero(string s) {
    deque<int> dq;
    string temp = "";
    for (char ch : s) {
        if (ch == ' ') continue;
        if (ch == '+' || ch == '-') {
            if (!temp.empty()) {
                dq.push_back(stoi(temp));
                temp.clear();
            }
            dq.push_back(ch);
        }
        else {
            temp += ch;
        }
    }
    if (!temp.empty()) dq.push_back(stoi(temp));

    int cur = dq.front();
    dq.pop_front();
    while (!dq.empty()) {
        char op = dq.front();
        dq.pop_front();
        int num = dq.front();
        dq.pop_front();
        if (op == '+') cur += num;
        else if (op == '-') cur -= num;
    }

    return cur == 0;
}

void print(string s) {
    for (char ch : s) {
        cout << ch;
    }
    cout << "\n";
}

void bt(string s, int d) {
	s += to_string(d);
	if (d == n) {
		if (isZero(s)) {
			print(s);
		}
		return;
	}
	for (int i = 0;i < 3;i++) {
		s += c[i];
		bt(s, d + 1);
		s.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		string s = "";
		bt(s, 1);
		cout << "\n";
	}

	return 0;
}