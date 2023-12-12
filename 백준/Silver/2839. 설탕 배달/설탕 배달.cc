#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int res = 5000;
	for (int i = 0;i <= 1666;i++) {//3
		for (int j = 0;j <= 1000;j++) {
			if (i * 3 + j * 5 == n)
				res = min(res, i + j);
		}
	}
	if (res == 5000)
		cout << -1 << "\n";
	else
		cout << res << "\n";
}