#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int num;
	priority_queue<int, vector<int>, greater<int>> pq;
	//priority_queue<int> pq;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.push(num);
		}
		while (pq.size() > n) {
			pq.pop();
		}
	}
	cout << pq.top() << "\n";
}