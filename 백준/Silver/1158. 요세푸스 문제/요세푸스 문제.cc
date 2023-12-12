#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1;i <= n;i++) {
		q.push(i);
	}
	int cnt = 0;
	cout << "<";
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cnt++;
		if (cnt == k) {
			cout << temp;
			if (!q.empty()) {
				cout << ", ";
			}
			cnt = 0;
		}
		else {
			q.push(temp);
		}
	}
	cout << ">\n";
}