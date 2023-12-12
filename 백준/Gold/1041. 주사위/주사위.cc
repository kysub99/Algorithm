#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF (int)1e9

long long n;
vector<long long> dice(6);
vector<long long> minDice(3);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	long long res = 0;
	long long maxNum = 0;
	for (int i = 0;i < 6;i++) {
		cin >> dice[i];
		res += dice[i];
		maxNum = max(maxNum, dice[i]);
	}
	if (n == 1) {
		cout << res - maxNum;
	}
	else {
		res = 0;
		long long one, two, three;
		minDice[0] = min(dice[0], dice[5]);
		minDice[1] = min(dice[1], dice[4]);
		minDice[2] = min(dice[2], dice[3]);
		one = min({ minDice[0], minDice[1], minDice[2] });
		three = minDice[0] + minDice[1] + minDice[2];
		two = three - max({ minDice[0], minDice[1], minDice[2] });

		long long cnt1 = 5 * (n - 2) * (n - 2) + 4 * (n - 2);
		long long cnt3 = 4;
		long long cnt2 = (5 * n * n - (cnt1 + cnt3 * 3)) / 2;
		
		res = cnt1 * one + cnt2 * two + cnt3 * three;
		cout << res;
	}
}