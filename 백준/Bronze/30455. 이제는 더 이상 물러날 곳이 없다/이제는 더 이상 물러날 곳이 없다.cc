#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	if (n % 2 == 0)
		cout << "Duck";
	else
		cout << "Goose";
}