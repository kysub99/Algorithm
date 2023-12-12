#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	deque<pair<int,int>> dq;// 번호, 숫자
	for (int i = 1;i <= n;i++) {
		int num;
		cin >> num;
		dq.push_back({ i,num });
	}
	int temp = dq.front().second;
	dq.pop_front();
	cout << "1 ";
	while (!dq.empty()) {
		if (temp > 0) {
			for (int i = 0;i < temp-1;i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cout << dq.front().first << " ";
			temp = dq.front().second;
			dq.pop_front();
			
		}
		else {
			for (int i = 0;i < -temp-1;i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cout << dq.back().first << " ";
			temp = dq.back().second;
			dq.pop_back();
		}
	}
}