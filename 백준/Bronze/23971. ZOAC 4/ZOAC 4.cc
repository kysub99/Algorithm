#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h, w, n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> h >> w >> n >> m;

	int hei = (h - 1) / (n + 1) + 1;
	int wid = (w - 1) / (m + 1) + 1;
	
	cout << wid * hei;

	return 0;
}