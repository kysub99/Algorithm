#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	bool arr[1001] = { false, };
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i] != true) {
			for (int j = i; j <= n; j += i) {
				if (arr[j] != true) {
					arr[j] = true;
					cnt++;
					if (cnt == k) {
						cout << j << "\n";
						return 0;
					}
				}
			}
		}
	}
}