#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dp[31][15001];//못만드는 무게는 0으로 나옴
int warr[31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int w;
	cin >> w;
	int wsum=0;
	for (int i = 1;i <= w;i++) {
		cin >> warr[i];
		wsum += warr[i];
	}
	for (int i = 0;i <= w;i++)
		dp[i][0] = 1;
	for (int i = 1;i <= w;i++) {
		for (int j = 1;j <= wsum;j++) {
			if (warr[i] > j) {//추의 무게가 구하려는 무게보다 큼-포함x
				dp[i][j] = dp[i - 1][j];
			}
			else {// 포함o
				dp[i][j] = dp[i-1][j] || dp[i - 1][j - warr[i]];//이 추를 포함하지 않았을때 가능하면 포함해도 가능
			}
		}
	}
	/*for (int i = 1;i <= w;i++) {
		for (int j = 1;j <= wsum;j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		bool check = true;
		for (int j = 0;j <= wsum-num;j++) {
			if (dp[w][j] && dp[w][j + num]) {//이 무게 가능할 때 이 무게에 구슬 무게 더한 거도 가능하면 Y
				cout << "Y ";
				check = false;
				break;
			}
		}
		if (check)
			cout << "N ";
	}
}