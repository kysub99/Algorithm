#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> ds(n);
	for (int i = 0;i < n;i++) {
		cin >> ds[i];
	}
	deque<int> dq;
	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;
		if (ds[i] == 0) {//큐
			dq.push_back(num);
		}
	}
	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int x;
		cin >> x;
		dq.push_front(x);
		cout << dq.back() << " ";
		dq.pop_back();
	}
}