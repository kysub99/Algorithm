#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<tuple<int, int, string>> arr;
	int age;
	string name;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		arr.push_back({ age, i, name });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << get<0>(arr[i]) << " " << get<2>(arr[i]) << "\n";
	}
}