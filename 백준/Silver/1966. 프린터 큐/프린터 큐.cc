#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t, n, m;
	cin >> t;
	while (t--) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		cin >> n >> m;
		int num;
		for (int i = 0;i < n;i++) {
			cin >> num;
			if (i == m)
				q.push({ num, 1 });
			else
				q.push({ num, 0 });
			pq.push(num);
		}
		int cnt = 0;
		while (1) {
			
			if (pq.top() == q.front().first) {
				if (q.front().second == 1) {
					cout << cnt + 1 << "\n";
					break;
				}
				pq.pop();
				q.pop();
				cnt++;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}
}