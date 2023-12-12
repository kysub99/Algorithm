#include <iostream>
using namespace std;
#define MAX (int)1e6+1

int n, m;
int arr[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	m = 0;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
		m += arr[i];
	}
	int row = m / n;
	int high = row+1;
	int hCnt = m % n;

	int res = 0;
	for (int i = 1;i <= n;i++) {
		if (arr[i] > row) {
			if (hCnt != 0) {
				hCnt--;
				res += arr[i] - high;
			}
			else
				res += arr[i] - row;
		}
	}
	cout << res;
}