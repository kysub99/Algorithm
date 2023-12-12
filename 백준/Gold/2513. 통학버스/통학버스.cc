#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k, s;
	cin >> n >> k >> s;
	vector<pair<int, int>> narr, parr;
	vector<int> tarr;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a - s > 0)
			parr.push_back({ a - s, b });
		else
			narr.push_back({ s - a, b });
	}
	sort(narr.begin(), narr.end());
	sort(parr.begin(), parr.end());
	int temp = k;
	int res = 0;
	while (!narr.empty()) {
		temp = k;
		for (int i = narr.size()-1; i >= 0; i--) {
			if (temp == 0)
				break;
			if (temp >= narr[i].second) {//정원 미달
				if (temp == k) 
					res+=narr[i].first;
				temp -= narr[i].second;
				narr.pop_back();
			}
			else {//정원 초과
				if (temp == k)
					res+=narr[i].first;
				narr[i].second -= temp;
				break;
			}
		}
	}
	while (!parr.empty()) {
		temp = k;
		for (int i = parr.size() - 1; i >= 0; i--) {
			if (temp == 0)
				break;
			if (temp >= parr[i].second) {//정원 미달
				if (temp == k)
					res += parr[i].first;
				temp -= parr[i].second;
				parr.pop_back();
			}
			else {//정원 초과
				if (temp == k)
					res += parr[i].first;
				parr[i].second -= temp;
				break;
			}
		}
	}
	cout << res * 2 << "\n";
}