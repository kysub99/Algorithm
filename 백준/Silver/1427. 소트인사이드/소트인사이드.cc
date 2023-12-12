#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	string n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n.size(); i++) {
		arr.push_back(n[i] - '0');
	}
	sort(arr.begin(), arr.end(), greater<>());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}
	cout << "\n";
}