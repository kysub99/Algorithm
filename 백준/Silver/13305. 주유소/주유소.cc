	#include <iostream>
	using namespace std;

	#define UB 100001

	int price[UB];
	int load[UB];

	int main() {
		int n;
		cin >> n;
		int num;
		for (int i = 0;i < n - 1;i++) {
			cin >> num;
			load[i] = num;
		}
		for (int i = 0;i < n;i++) {
			cin >> num;
			price[i] = num;
		}
		long long sum = load[0];
		long long temp = price[0];
		long long res = 0;

		for (int i = 1;i < n;i++) {
			if (price[i] < temp) {
				res += temp * sum;
				temp = price[i];
				sum = 0;	
			}
			sum += load[i];
		}
		res += temp * sum;
		cout << res << "\n";
	}