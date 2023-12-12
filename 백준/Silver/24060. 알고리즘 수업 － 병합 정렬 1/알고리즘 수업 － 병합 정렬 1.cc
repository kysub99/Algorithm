#include <iostream>
#include <vector>
using namespace std;

int arr[500000];
int tmp[500000];
int cnt = 0;
int res = -1;
int n, k;

void merge(int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 1;
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j])
			tmp[t++] = arr[i++];
		else
			tmp[t++] = arr[j++];
	}
	while (i <= q)
		tmp[t++] = arr[i++];
	while (j <= r)
		tmp[t++] = arr[j++];
	i = p;
	t = 1;
	while (i <= r) {
		arr[i++] = tmp[t++];
		cnt++;
		if (cnt == k) {
			res = arr[i-1];
		}
	}
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	merge_sort(0, n - 1);
	cout << res;
}