#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if(a.length()<b.length()){
		return true;
	}
	else if (a.length() > b.length()) {
		return false;
	}
	else {
		int asum = 0, bsum = 0;
		for (int i = 0;i < a.length();i++) {
			if ('0' <= a[i] && a[i] <= '9') {
				asum += a[i] - '0';
			}
			if ('0' <= b[i] && b[i] <= '9') {
				bsum += b[i] - '0';
			}
		}
		if (asum < bsum) {
			return true;
		}
		else if (asum > bsum) {
			return false;
		}
		else {
			if (a <= b)
				return true;
			else
				return false;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), compare);

	for (string str : arr) {
		cout << str << "\n";
	}
}