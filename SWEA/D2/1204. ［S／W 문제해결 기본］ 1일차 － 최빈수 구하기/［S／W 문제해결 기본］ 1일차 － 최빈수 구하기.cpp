#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 1;c <= t;c++) {
		int tc;
		cin >> tc;

		vector<int> arr(101, 0);
		for (int i = 0;i < 1000;i++) {
			int num;
			cin >> num;
			arr[num]++;
		}

		int maxNum = -1;
		int res = -1;
		for (int i = 1;i <= 100;i++) {
			if (maxNum <= arr[i]) {
				maxNum = arr[i];
				res = i;
			}
		}
		cout << "#" << tc << " " << res << "\n";
	}
}