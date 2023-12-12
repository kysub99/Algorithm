#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<double> c;
double sum = 0;
int cnt = 0;

void bt(int idx, double sum) {
	if (0.99 <= sum && sum <= 1.01) {
		cnt++;
	}
	if (sum > 1.01)
		return;
	for (int i = idx + 1;i < n;i++) {
		bt(i, sum + c[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	c.resize(n);
	double temp;
	for (int i = 0;i < n;i++) {
		cin >> temp;
		c[i] = 1 / temp;
	}
	bt(-1, 0);
	cout << cnt;
}