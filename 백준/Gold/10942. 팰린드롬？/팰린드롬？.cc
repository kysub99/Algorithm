#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAX 2001

int n, m, s, e;
vector<int> arr(MAX);
bool isPal[MAX][MAX];

bool isIn(int s, int e) {
	return 1 <= s && s <= n && 1 <= e && e <= n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}

	for (int i = 0;i <= n;i++) {
		isPal[i][i] = isPal[0][i] = isPal[i][0] = true;		
	}

	for (int i = 1;i < n;i++) {
		if (arr[i] == arr[i + 1])
			isPal[i][i + 1] = true;
	}

	for (int l = 0;l <= n;l++) {
		for (int i = 1;i + l <= n;i++) {
			if (isPal[i][i + l]) {
				int f = i - 1;
				int b = i + l + 1;
				if (isIn(f, b) && arr[f] == arr[b]) {
					isPal[f][b] = true;
				}
			}
		}
	}

	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> s >> e;
		cout << isPal[s][e] << "\n";
	}
}