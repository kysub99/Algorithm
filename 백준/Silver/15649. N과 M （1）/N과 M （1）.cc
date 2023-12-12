#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool check[9];
int res[9];

void func(int d) {
	if (d == m) {
		for (int i = 1;i <= m;i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1;i <= n;i++) {
			if (check[i] != true) {
				res[d + 1] = i;
				check[i] = true;
				func(d + 1);
				check[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	func(0);
}