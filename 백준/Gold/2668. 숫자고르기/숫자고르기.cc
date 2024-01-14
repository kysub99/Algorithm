#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int n;
vector<int> arr;
vector<bool> res;
vector<bool> visit;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	arr.resize(n + 1);
	res.resize(n + 1, false);
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}

	for (int i = 1;i <= n;i++) {
		visit.clear();
		visit.resize(n + 1, false);
		
		visit[i] = true;
		int cur = arr[i];
		while (1) {			
			if (cur == i) {
				for (int j = 1;j <= n;j++) {
					if (visit[j]) {
						res[j] = true;
					}
				}
				break;
			}

			if (res[cur] || visit[cur])
				break;
			visit[cur] = true;
			
			cur = arr[cur];
		}
	}

	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		if (res[i])
			cnt++;
	}
	
	cout << cnt << "\n";

	for (int i = 1;i <= n;i++) {
		if (res[i])
			cout << i << "\n";
	}

	return 0;
}