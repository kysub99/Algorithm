#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int num;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	int maxNum = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] + arr[j] > m)
				break;
			for (int k = j+1; k < n; k++) {
				int temp = arr[i] + arr[j] + arr[k];
				if (temp > m)
					break;
				maxNum = max(maxNum, temp);
			}
		}
	}
	cout << maxNum << "\n";
}