#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define MAX 100001

int n, k;
vector<int> dis(MAX, MAX);
vector<int> ord(MAX);
vector<int> res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	queue<int> q;
	q.push(n);
	dis[n] = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (temp * 2 < MAX && dis[temp] + 1 < dis[temp * 2]) {
			dis[temp * 2] = dis[temp] + 1;
			ord[temp * 2] = temp;
			q.push(temp * 2);
		}
		if (temp + 1 < MAX && dis[temp] + 1 < dis[temp + 1]) {
			dis[temp + 1] = dis[temp] + 1;
			ord[temp + 1] = temp;
			q.push(temp + 1);
		}
		if (temp - 1 >= 0 && dis[temp] + 1 < dis[temp - 1]) {
			dis[temp - 1] = dis[temp] + 1;
			ord[temp - 1] = temp;
			q.push(temp - 1);
		}
	}
	cout << dis[k] << "\n";
	int idx = k;
	while (1) {
		res.push_back(idx);
		if (idx == n)
			break;
		idx = ord[idx];
	}
	reverse(res.begin(), res.end());
	for (int val : res) {
		cout << val << " ";
	}
}