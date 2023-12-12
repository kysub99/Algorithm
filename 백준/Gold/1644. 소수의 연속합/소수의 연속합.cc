#include <iostream>
#include <vector>
using namespace std;

int n;

vector<int> getPrime(int n) {
	vector<int> temp(n + 1);
	for (int i = 2;i <= n;i++)
		temp[i] = i;
	for (int i = 2;i <= n;i++) {
		if (temp[i] == 0)
			continue;
		for (int j = 2 * i;j <= n;j += i)
			temp[j] = 0;
	}
	vector<int> res;
	for (int i = 2;i <= n;i++) {
		if (temp[i] != 0)
			res.push_back(i);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<int> prime = getPrime(n);
	int i = -1;
	int sum = 0;
	int cnt = 0;
	for (int j = 0;j < prime.size();j++) {
		sum += prime[j];
		while (sum > n && i <= j) {
			i++;
			sum -= prime[i];
		}
		if (n == sum)
			cnt++;
	}
	cout << cnt;
}