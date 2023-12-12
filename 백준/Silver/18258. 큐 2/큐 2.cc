#include <iostream>
#include <string>
using namespace std;

class queue {
private:
	int f, t;
	int arr[2000000];
public:
	queue() {
		f = 0;
		t = 0;
		for (int i = 0;i < 2000000;i++)
			arr[i] = -1;
	}
	void push(int x) {
		arr[t] = x;
		t++;
	}
	int size() {
		return t - f;
	}
	bool empty() {
		return size() == 0;
	}
	int pop() {
		if (empty())
			return -1;
		else {
			f++;
			return arr[f - 1];
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
			return arr[t - 1];
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	queue q;
	string str;
	while (n--) {
		cin >> str;
		if (str == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (str == "pop") {
			cout << q.pop() << "\n";
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front") {
			cout << q.front() << "\n";
		}
		else
			cout << q.back() << "\n";
	}
}