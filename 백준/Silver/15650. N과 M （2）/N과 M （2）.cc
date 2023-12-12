#include <iostream>
using namespace std;

int n, m;
int res[9];
bool visit[9];

void func(int cnt, int f) {
	if (cnt > m) {
		for (int i = 1;i <= m;i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = f;i <= n;i++) {
			if (visit[i] != true) {
				visit[i] = true;
				res[cnt] = i;
				func(cnt + 1, i);
				visit[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	func(1, 1);
}