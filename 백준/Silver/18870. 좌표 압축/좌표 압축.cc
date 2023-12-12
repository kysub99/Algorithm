#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x;
	vector<pair<int,int>> arr;
	vector<pair<int, int>> idx;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back({ x,i });
	}
	sort(arr.begin(), arr.end());
	int cnt = 0;
	int temp = arr[0].first;
	idx.push_back({ arr[0].second, cnt});

	for (int i = 1; i < arr.size(); i++) {
		if (temp != arr[i].first)
			cnt++;
		temp = arr[i].first;
		idx.push_back({ arr[i].second, cnt});
	}
	sort(idx.begin(), idx.end());
	for (int i = 0; i < idx.size(); i++) {
		cout << idx[i].second << " ";
	}
	cout << "\n";
}