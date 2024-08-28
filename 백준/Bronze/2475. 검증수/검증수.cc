#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int temp = 0;
	int n;
	for (int i = 0;i < 5;i++) {
		cin >> n;
		temp += n * n;
	}
	cout << temp % 10;
}