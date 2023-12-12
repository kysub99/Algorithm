#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	long double x1, x2, x3, y1, y2, y3;
	x1 = arr[0].first;
	y1 = arr[0].second;
	long double res = 0;
	for (int i = 1;i < n - 1;i++) {
		x2 = arr[i].first;
		y2 = arr[i].second;
		x3 = arr[i + 1].first;
		y3 = arr[i + 1].second;
		long double temp = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
		res += temp / 2;
	}
	cout << fixed << setprecision(1) << abs(res);
}