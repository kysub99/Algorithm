#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x, y;
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr.push_back({ x,y });
	}
	for (int i = 0; i < n; i++) {
		int k = 1;
		for (int j = 0; j < n; j++) {
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
				k++;
		}
		cout << k << " ";
	}
} 