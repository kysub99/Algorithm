#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n, s;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> s;
	arr.resize(n + 1);

	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}

	int i = 1;
	int sum = 0;
	int len = 1e5 + 1;
	for (int j = 1;j <= n;j++) {
		sum += arr[j];
		while (i <= j && s <= sum) {
			len = min(len, j - i + 1);
			sum -= arr[i];
			i++;
		}
	}
	if (len == 1e5 + 1)
		cout << 0;
	else
		cout << len;
}