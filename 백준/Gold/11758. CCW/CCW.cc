#include <iostream>
#include <algorithm>
using namespace std;

int x[4], y[4];

int CrossProduct() {
	return (x[1] * y[2] + x[2] * y[3] + x[3] * y[1])
		- (x[2] * y[1] + x[3] * y[2] + x[1] * y[3]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1;i <= 3;i++) {
		cin >> x[i] >> y[i];
	}
	int cp = CrossProduct();
	if (cp < 0)
		cout << -1;
	else if (cp > 0)
		cout << 1;
	else
		cout << 0;

}