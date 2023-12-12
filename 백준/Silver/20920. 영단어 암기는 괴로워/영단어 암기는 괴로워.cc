#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<string, int> mp;

bool compare(const string& str1, const string& str2) {
	if (mp[str1] == mp[str2]) {
		if (str1.size() == str2.size()) {
			return str1 < str2;
		}
		else
			return str1.size() > str2.size();
	}
	else
		return mp[str1] > mp[str2];
}

int main() {
	int n, m;
	cin >> n >> m;
	string str;
	vector<string> arr;
	for (int i = 0;i < n;i++) {
		cin >> str;
		arr.push_back(str);
		mp[str]++;
	}
	sort(arr.begin(), arr.end(), compare);
	arr.erase(unique(arr.begin(), arr.end()),arr.end());
	for (int i = 0;i < arr.size();i++) {
		if (arr[i].size() >= m)
			cout << arr[i] << "\n";
	}
}