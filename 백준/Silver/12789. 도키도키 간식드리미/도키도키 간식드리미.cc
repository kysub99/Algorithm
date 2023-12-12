#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	stack<int> st;
	vector<int> arr(n);
	int ord = 1;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	for (int i = 0;i < n;) {
		if (ord == arr[i]) {
			i++;
			ord++;
		}
		else {
			if (st.empty()) {
				st.push(arr[i]);
				i++;
			}
			else {
				if (st.top() == ord) {
					st.pop();
					ord++;
				}
				else {
					st.push(arr[i]);
					i++;
				}
			}
		}
	}
	while (!st.empty()) {
		if (ord == st.top()) {
			st.pop();
			ord++;
		}
		else
			break;
	}
	if (ord == n + 1)
		cout << "Nice" << "\n";
	else
		cout << "Sad" << "\n";
}
