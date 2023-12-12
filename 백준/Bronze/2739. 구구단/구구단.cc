#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= 9;i++) {
		cout << n << " * " << i << " = " << n * i << "\n";
	}
}