#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> maxpq;
	priority_queue<int, vector<int>, greater<int>> minpq;

	cin >> n;

	int num;
	for (int i = 0;i < n;i++) {		
		cin >> num;

		if (maxpq.size() <= minpq.size()) {
			maxpq.push(num);
		}
		else {
			minpq.push(num);
		}
		
		if (maxpq.size() && minpq.size()) {
			int maxTop = maxpq.top();
			int minTop = minpq.top();

			if (maxTop > minTop) {
				maxpq.pop();
				minpq.pop();
				maxpq.push(minTop);
				minpq.push(maxTop);
			}
		}
		cout << maxpq.top() << "\n";
	}

	return 0;
}