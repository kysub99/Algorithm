#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	queue<int> q;
	vector<int> res;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int i = 0;i < k-1;i++) {
			q.push(q.front());
			q.pop();
		}
		res.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0;i < res.size() - 1;i++) {
		cout << res[i] << ", ";
	}
	cout << res[res.size() - 1] << ">\n";
}