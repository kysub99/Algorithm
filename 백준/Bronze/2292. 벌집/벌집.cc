#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 1;
	int cur = 1;
	while (cur < n) {
		cur += 6 * cnt++;
	}
	cout << cnt;
}