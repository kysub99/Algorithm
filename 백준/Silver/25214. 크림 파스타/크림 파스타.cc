#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001

int n;
int dp[MAX], minNum[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	dp[0] = 0;
	cin >> minNum[0];
	cout << "0 ";
	int num;
	for (int i = 1;i < n;i++) {
		cin >> num;
		dp[i] = max(dp[i - 1], num - minNum[i - 1]);
		minNum[i] = min(minNum[i - 1], num);
		cout << dp[i] << " ";
	}
}