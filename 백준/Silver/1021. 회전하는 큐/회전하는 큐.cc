#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	deque<int> dq;
	for (int i = 1;i <= n;i++) {
		dq.push_back(i);
	}
	int num;
	int res = 0;
	for (int i = 0;i < m;i++) {
		cin >> num;
		int cnt = 0;
		while (dq.front() != num) {
			dq.push_back(dq.front());
			dq.pop_front();
			cnt++;
		}
		dq.pop_front();
		int temp = dq.size()+1;
		res += min(cnt, temp - cnt);
	}
	cout << res;
}