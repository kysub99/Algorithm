#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
#define INF (int)1e9+1
#define MAX 51

int n;
int height[MAX];
int res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> height[i];
	}

	for (int i = 1;i <= n;i++) {
		int cnt = 0;
		for (int j = 1;j <= n;j++) {
			if (i == j)
				continue;

			int f = i;
			int e = j;
			if (i > j) {
				swap(f, e);
			}

			if (f + 1 == e) {
				cnt++;
				continue;
			}

			int dx = e - f;
			int dy = height[e] - height[f];
			double inc = double(dy) / double(dx);

			bool canSee = true;
			for (int k = f + 1;k < e;k++) {
				int kdx = k - f;
				int kdy = height[k] - height[f];
				double kinc = double(kdy) / double(kdx);

				if (kinc >= inc) {
					canSee = false;
					break;
				}					
			}
			if (canSee)
				cnt++;
		}
		res = max(res, cnt);
	}

	cout << res;

	return 0;
}