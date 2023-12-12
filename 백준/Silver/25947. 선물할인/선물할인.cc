#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, b, a;
vector<int> cost;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> b >> a;
	cost.resize(n);
	
	for (int i = 0;i < n;i++) {
		cin >> cost[i];
	}
	sort(cost.begin(), cost.end());
	int cnt = a;
	int sum = 0;
	int last = 0;
	int i;
	for (i = 0;i < n;i++) {
		if (cnt != 0) {//할인 가능
			if (sum + cost[i] / 2 <= b) {
				sum += cost[i] / 2;
				cnt--;
			}
			else {
				break;
			}
		}
		else {//할인 불가
			sum += cost[last] / 2;
			last++;
			if (sum + cost[i] / 2 <= b) {
				sum += cost[i] / 2;
			}
			else {
				break;
			}
		}
	}
	cout << i;
}