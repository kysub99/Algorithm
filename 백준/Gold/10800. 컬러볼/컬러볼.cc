#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Ball {
	int size;
	int color;
	int idx;
};

bool cmp(const Ball& a, const Ball& b) {
	if (a.size == b.size)
		return a.color < b.color;
	else
		return a.size < b.size;
}

int main() {
	int n;
	cin >> n;
	vector<Ball> barr;
	vector<int> all;
	vector<int> sameColor;
	vector<int> sameSize;
	unordered_map<int, int> check;
	vector<pair<int, int>> res;//idx, result
	for (int i = 0; i < n; i++) {
		int c, s;
		cin >> c >> s;
		Ball B;
		B.color = c;
		B.size = s;
		B.idx = i;
		barr.push_back(B);
	}
	sort(barr.begin(), barr.end(), cmp);

	all.push_back(0);
	for (int i = 1; i < n; i++) {
		all.push_back(all[i - 1] + barr[i-1].size);
	}

	for (int i = 0; i < n; i++) {
		if (check.find(barr[i].color) == check.end()) {	//없음
			sameColor.push_back(0);
			check[barr[i].color] = barr[i].size;
		}
		else {	// 있음
			sameColor.push_back(check[barr[i].color]);
			check[barr[i].color] += barr[i].size;
		}
	}
	
	sameSize.push_back(0);
	for (int i = 1; i < n; i++) {
		if (barr[i - 1].size == barr[i].size)
			sameSize.push_back(sameSize[i - 1] + barr[i].size);
		else
			sameSize.push_back(0);
	}
	
	for (int i = 0; i < n; i++) {
		res.push_back({ barr[i].idx, (all[i] - sameColor[i] - sameSize[i])});
	}

	for (int i = 1; i < n; i++) {
		if (barr[i - 1].color == barr[i].color && barr[i - 1].size == barr[i].size)
			res[i].second = res[i - 1].second;
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < n; i++) {
		cout << res[i].second << "\n";
	}
}