#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int x, y, w, h;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> w >> h;
	cout << min({ abs(x - 0), abs(x - w), abs(y - 0), abs(y - h) });
}