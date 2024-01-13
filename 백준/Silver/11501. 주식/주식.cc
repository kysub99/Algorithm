#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int T, N;
vector<int> price;
vector<int> sell;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	
	while (T--) {
		cin >> N;
		price.clear();
		sell.clear();
		price.resize(N + 1);
		sell.resize(N + 1, false);

		for (int i = 1;i <= N;i++) {
			cin >> price[i];
		}

		int maxPrice = 0;
		for (int i = N;i >= 1;i--) {
			if (price[i] >= maxPrice) {
				maxPrice = price[i];
				sell[i] = true;
			}
		}

		int cnt = 0;
		ll buy = 0;
		ll res = 0;
		for (int i = 1;i <= N;i++) {
			if (sell[i]) {
				res += cnt * price[i] - buy;
				cnt = 0;
				buy = 0;
			}
			else {
				cnt++;
				buy += price[i];
			}
		}

		cout << res << "\n";
	}

	return 0;
}