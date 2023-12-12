#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, k;
int dpCur[10001];
int dpPrev[10001];
int coin[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		cin >> coin[i];
	}
	dpPrev[0] = 1;
	dpCur[0] = 1;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= k;j++) {
			if (coin[i] > j) {
				dpCur[j] = dpPrev[j];
			}
			else {
				dpCur[j] = dpPrev[j] + dpCur[j - coin[i]];
			}
		}
		for (int j = 1;j <= k;j++) {
			dpPrev[j] = dpCur[j];
		}
	}
	cout << dpCur[k];
}