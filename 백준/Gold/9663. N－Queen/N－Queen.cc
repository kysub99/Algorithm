#include <iostream>
using namespace std;

bool r[31];
bool l[31];
bool ud[16];
int n;
int cnt = 0;

void func(int d) {
	if (d > n) {
		cnt++;
	}
	else {
		for (int i = 1;i <= n;i++) {
			if (r[i - d + 15] != true && l[i + d] != true && ud[i] != true) {
				r[i - d + 15] = true;
				l[i + d] = true;
				ud[i] = true;
				func(d + 1);
				r[i - d + 15] = false;
				l[i + d] = false;
				ud[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	func(1);
	cout << cnt;
}