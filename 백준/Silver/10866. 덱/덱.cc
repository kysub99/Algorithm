#include <iostream>
#include <string>
using namespace std;

class deque {
private:
	int f;
	int t;
	int arr[20000];
public:
	deque() {
		f = t = 10000;
	}
	int size() {
		return t - f;
	}
	bool empty() {
		return size() == 0;
	}
	void push_back(int x) {
		arr[t] = x;
		t++;
	}
	void push_front(int x) {
		f--;
		arr[f] = x;
	}
	int pop_front() {
		if (empty())
			return -1;
		else {
			f++;
			return arr[f-1];
		}
	}
	int pop_back() {
		if (empty())
			return -1;
		else {
			t--;
			return arr[t];
		}
	}
	int front() {
		if (empty())
			return -1;
		else {
			return arr[f];
		}
	}
	int back() {
		if (empty())
			return -1;
		else {
			return arr[t-1];
		}
	}
};

int main() {
	int n;
	cin >> n;
	deque dq;
	for (int i = 0;i < n;i++) {
		string str;
		cin >> str;
		int x;
		if (str == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if (str == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if (str == "pop_front") {
			cout << dq.pop_front() << "\n";
		}
		else if (str == "pop_back") {
			cout << dq.pop_back() << "\n";
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
			cout << dq.front() << "\n";
		}
		else if (str == "back") {
			cout << dq.back() << "\n";
		}
	}
}