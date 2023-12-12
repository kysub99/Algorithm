#include <iostream>
using namespace std;

int n, m;
int res[8];

void func(int cnt) {
	if (cnt > m) {
		for (int i = 1;i <= m;i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1;i <= n;i++) {
			res[cnt] = i;
			func(cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	func(1);
}