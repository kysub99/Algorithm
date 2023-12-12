#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	vector<pair<int, string>> arr;
	for (int i = 0; i < n; i++) {
		cin >> str;
		arr.push_back({ str.size(), str });
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].second << "\n";
	}
}