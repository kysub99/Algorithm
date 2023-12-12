#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	stack<int> st;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	int num = 1;
	vector<char> res;
	for (int i = 0;i < n;) {

		if (num < arr[i]) {
			st.push(num);
			res.push_back('+');
			if (num <= n)
				num++;
		}
		else if (num > arr[i]) {
			if (st.top() == arr[i]) {
				st.pop();
				res.push_back('-');
				i++;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
		else {
			st.push(num);
			res.push_back('+');
			if (num <= n)
				num++;
			st.pop();
			res.push_back('-');
			i++;
		}
	}
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << "\n";
	}
}