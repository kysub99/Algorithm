#include <iostream>
#include <string>
#include <deque>
using namespace std;



int main() {
	int n;
	deque<int> dq;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string str;
		int num;
		cin >> str;
		if (str == "push") {
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "pop") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (str == "size") {
			cout << dq.size() << "\n";
		}
		else if (str == "empty") {
			if (dq.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		else if (str == "back") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
	}
}