#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
#define MAX 10001

int n;
int rock[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> rock[i];
	}
	int l = rock[1];
	int r = rock[2];
	for (int i = 3;i <= n;i++) {
		if (l > r)
			r += rock[i];
		else
			l += rock[i];
	}
	int def = abs(l - r);
	int res = 0;
	int wei[7] = { 100,50,20,10,5,2,1 };
	for (int i = 0;i < 7;i++) {
		res += def / wei[i];
		def %= wei[i];
	}
	cout << res;
}