#include <iostream>
#include <string>
using namespace std;

class stack {
private:
	int num;
	int arr[10001];
public:
	stack() {
		num = 0;
	}
	bool empty() {
		return num == 0;
	}
	void push(int n) {
		arr[num] = n;
		num++;
	}
	void pop() {
		if (empty()) {
			cout << "-1\n";
		}
		else {
			cout << arr[num-1] << "\n";
			num--;
		}
	}
	int size() {
		return num;
	}
	void top() {
		if (empty()) {
			cout << "-1\n";
		}
		else {
			cout << arr[num-1] << "\n";
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack st;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int num;
		string str;
		cin >> str;
		if (str == "push") {
			cin >> num;
			st.push(num);
		}
		else if (str == "top") {
			st.top();
		}
		else if (str == "size") {
			cout << st.size() << "\n";
		}
		else if (str == "empty") {
			if (st.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else {
			st.pop();
		}
	}
}