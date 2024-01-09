#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define INF 1e9

int H, W;
vector<int> arr;
int res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> st;
	cin >> H >> W;

	arr.resize(W);
	for (int i = 0;i < W;i++) {
		cin >> arr[i];
	}

	for (int i = 1;i < W - 1;i++) {
		int lidx = i - 1;
		int ridx = i + 1;
		int lh = 0;
		int rh = 0;
		int h = INF;
		while (0 <= lidx) {
			lh = max(lh, arr[lidx]);
			lidx--;
		}
		while (ridx < W) {
			rh = max(rh, arr[ridx]);
			ridx++;
		}
		h = min(lh, rh);
		if (h > arr[i])
			res += h - arr[i];
	}

	cout << res;

	return 0;
}