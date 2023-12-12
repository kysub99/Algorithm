#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define MAX 100'001

bool visit[MAX];
int res[MAX];
int n, k;
queue<int> q;

void set(int n, int temp) {
	q.push(n);
	visit[n] = true;
	res[n] = res[temp] + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	
	q.push(n);
	visit[n] = true;
	while (!q.empty()) {
		int temp = q.front();
		if (temp == k)
			break;
		if (temp - 1 >= 0 && !visit[temp - 1]) {
			set(temp - 1, temp);
		}
		if (temp + 1 < MAX && !visit[temp + 1]) {
			set(temp + 1, temp);
		}
		if (temp * 2 < MAX && !visit[temp * 2]) {
			set(temp * 2, temp);
		}
		q.pop();
	}
	cout << res[k];
}