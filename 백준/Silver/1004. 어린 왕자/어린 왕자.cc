#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int t, n, r;
double x1, y_1, x2, y2, cx, cy;

double getDis(double x, double y, double cx, double cy) {
	return sqrt(pow(x - cx, 2) + pow(y - cy, 2));
}

bool isIn(double x, double y, double cx, double cy, int r) {
	double dis = getDis(x, y, cx, cy);
	if (dis < r)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> x1 >> y_1 >> x2 >> y2;
		cin >> n;
		int start = 0;
		int end = 0;
		for (int i = 0;i < n;i++) {
			cin >> cx >> cy >> r;	
			if (isIn(x1, y_1, cx, cy, r)&&!isIn(x2, y2, cx, cy, r)) {
				start++;
			}
			if (isIn(x2, y2, cx, cy, r)&&!isIn(x1, y_1, cx, cy, r)) {
				end++;
			}
		}
		cout << start + end << "\n";
	}
}
