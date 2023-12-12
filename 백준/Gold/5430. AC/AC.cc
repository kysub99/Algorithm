#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string p;
		cin >> p;
		int n;
		cin >> n;
		deque<int> dq;
		string str;
		cin >> str;
		int num = 0;
		for (int i = 0;i < str.size();i++) {
			if ('0' <= str[i] && str[i] <= '9') {
				num = num * 10 + int(str[i]-'0');
			}
			else {
				if (num != 0) {
					dq.push_back(num);
					num = 0;
				}
			}
		}
		bool ltr = true;
		bool check = false;
		for (int i = 0;i < p.size();i++) {
			if (p[i] == 'R') {
				ltr = ltr ^ true;
			}
			else {
				if (dq.empty()) {
					cout << "error\n";
					check = true;;
					break;
				}
				if (ltr) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		if (check)
			continue;
		cout << '[';
		if (!dq.empty()) {
			while (dq.size() > 1) {
				if (ltr) {
					cout << dq.front() << ",";
					dq.pop_front();
				}
				else {
					cout << dq.back() << ",";
					dq.pop_back();
				}
			}

			cout << dq.front();
		}
		cout << "]\n";

	}
}