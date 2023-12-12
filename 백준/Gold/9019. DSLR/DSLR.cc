#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define MOD 10000
#define MAX 10001

int t, a, b;


int D(int n) {
	return (2 * n) % MOD;
}

int S(int n) {
	return (n + MOD - 1) % MOD;
}

int L(int n) {
	int d1 = n / 1000;
	n %= 1000;
	n *= 10;
	n += d1;
	return n;
}

int R(int n) {
	int d4 = n % 10;
	n /= 10;
	n += d4 * 1000;
	return n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		vector<int> cnt(MAX, MAX);
		vector<int> ord(MAX);
		vector<char> dslr(MAX);
		queue<int> q;
		cin >> a >> b;
		q.push(a);
		cnt[a] = 0;
		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			int dtemp = D(temp);
			int stemp = S(temp);
			int ltemp = L(temp);
			int rtemp = R(temp);
;			if (cnt[temp] + 1 < cnt[dtemp]) {
				cnt[dtemp] = cnt[temp] + 1;
				q.push(dtemp);
				ord[dtemp] = temp;
				dslr[dtemp] = 'D';
			}
			if (cnt[temp] + 1 < cnt[stemp]) {
				cnt[stemp] = cnt[temp] + 1;
				q.push(stemp);
				ord[stemp] = temp;
				dslr[stemp] = 'S';
			}
			if (cnt[temp] + 1 < cnt[ltemp]) {
				cnt[ltemp] = cnt[temp] + 1;
				q.push(ltemp);
				ord[ltemp] = temp;
				dslr[ltemp] = 'L';
			}
			if (cnt[temp] + 1 < cnt[rtemp]) {
				cnt[rtemp] = cnt[temp] + 1;
				q.push(rtemp);
				ord[rtemp] = temp;
				dslr[rtemp] = 'R';
			}
		}
		vector<char> res;
		int idx = b;
		while (idx != a) {
			res.push_back(dslr[idx]);
			idx = ord[idx];
		}
		reverse(res.begin(), res.end());
		for (char val : res) {
			cout << val;
		}
		cout << "\n";
	}
}