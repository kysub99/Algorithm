#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
int ltr[1001];
int rtl[1001];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
		ltr[i] = rtl[i] = 1;
	}
	for (int i = 2;i <= n;i++) {
		int temp = 0;
		for (int j = 1;j < i;j++) {
			if (arr[i] > arr[j]) {
				temp = max(temp, ltr[j]);
				ltr[i] = temp + 1;
			}
		}
	}
	for (int i = n;i >= 1;i--) {
		int temp = 0;
		for (int j = n;j > i;j--) {
			if (arr[i] > arr[j]) {
				temp = max(temp, rtl[j]);
				rtl[i] = temp + 1;
			}
		}
	}
	int res = 0;
	for (int i = 1;i <= n;i++) {
		int temp = ltr[i] + rtl[i] - 1;
		res = max(res, temp);
	}
	cout << res;
}