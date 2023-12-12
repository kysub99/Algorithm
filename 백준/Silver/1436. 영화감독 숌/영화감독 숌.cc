#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	int ans = 665;
	while (cnt != n) {
		ans++;
		int temp = ans;
		while (temp/100!=0) {
			if ((temp % 1000) / 666 !=0&&(temp%1000)%666==0) {
				cnt++;
				break;
			}
			temp /= 10;
		}
		
	}
	cout << ans << "\n";
}