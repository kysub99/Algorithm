#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

double t, x1, y, r1, x2, y2, r2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> x1 >> y >> r1 >> x2 >> y2 >> r2;
		double dis = sqrt(pow(x1 - x2, 2) + pow(y - y2, 2));
		if (x1 == x2 && y == y2) {
			if (r1 == r2) {
				cout << "-1\n";
			}
			else
				cout << "0\n";	
		}
		else {
			if (r1 + r2 < dis || dis + r1 < r2 || dis + r2 < r1) {
				cout << "0\n";
			}
			else if (r1 + r2 == dis || dis + r1 == r2 || dis + r2 == r1)
				cout << "1\n";
			else
				cout << "2\n";
		}
	}
}