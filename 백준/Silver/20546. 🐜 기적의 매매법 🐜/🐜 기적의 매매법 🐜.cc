#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cash;
int price[15];
int b = 0, t = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cash;
	for (int i = 1;i <= 14;i++)
		cin >> price[i];

	int bTemp = cash;
	for (int i = 1;i <= 14;i++) {
		b += bTemp / price[i];
		bTemp %= price[i];
	}

	int rcnt = 0, fcnt = 0;//연속 상승, 하락
	int tTemp = cash;
	for (int i = 2;i <= 14;i++) {
		if (price[i - 1] < price[i]) {
			rcnt++;
			fcnt = 0;
		}
		else if (price[i - 1] > price[i]) {
			fcnt++;
			rcnt = 0;
		}
		else {
			rcnt = 0;
			fcnt = 0;
		}
		if (rcnt >= 3) {
			tTemp += price[i] * t;
			t = 0;
		}
		else if (fcnt >= 3) {
			t += tTemp / price[i];
			tTemp %= price[i];
		}
	}
	int bSum = bTemp + b * price[14];
	int tSum = tTemp + t * price[14];
	if (bSum < tSum)
		cout << "TIMING";
	else if (bSum > tSum)
		cout << "BNP";
	else
		cout << "SAMESAME";
}