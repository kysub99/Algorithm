#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n[7];
	cin >> n[1] >> n[2];
	int o, t, h;
	o = n[2] % 10;
	t = (n[2] / 10) % 10;
	h = n[2] / 100;
	n[3] = n[1] * o;
	n[4] = n[1] * t;
	n[5] = n[1] * h;
	n[6] = n[3] + 10 * n[4] + 100 * n[5];
	for (int i = 3;i <= 6;i++)
		cout << n[i] << "\n";
}