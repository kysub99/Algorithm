#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define MOD 1000000007

long long n;
unordered_map<long long, long long> dp;

long long fib(long long num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	if (dp.count(num)>0)
		return dp[num];
	else if (num % 2 == 0) {
		dp[num] = (fib(num / 2) * ((fib(num / 2)
			+ 2 * fib(num / 2 - 1)) % MOD) % MOD) % MOD;
		return dp[num];
	}
	else {
		dp[num] = ((fib(num / 2 + 1) * fib(num / 2 + 1)) % MOD
			+ (fib(num / 2) * fib(num / 2)) % MOD) % MOD;
		return dp[num];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cout << fib(n);
}