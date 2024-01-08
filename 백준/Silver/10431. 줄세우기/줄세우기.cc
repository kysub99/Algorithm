#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int P, T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> P;
	while (P--) {
		cin >> T;
		vector<int> arr;
		int res = 0;
		int num;
		for (int i = 0;i < 20;i++) {			
			cin >> num;
			int idx = upper_bound(arr.begin(), arr.end(), num) - arr.begin();
			res += arr.size() - idx;
			arr.push_back(num);
			sort(arr.begin(), arr.end());
		}
		cout << T << " " << res << "\n";
	}

	return 0;
}