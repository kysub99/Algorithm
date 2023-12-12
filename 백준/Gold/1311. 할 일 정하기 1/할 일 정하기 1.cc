#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 20
#define INF (int)1e9

int n;
int d[MAX][MAX];
int dp[MAX+1][1 << MAX];//  마지막으로 배정한 사람, 지금까지 배정한 일 (0번 부터)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0;i <= n;i++) {
		for (int j = 0;j < (1 << n);j++) {
			dp[i][j] = INF;
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> d[i][j];
		}
	}
	dp[0][0] = 0;
	for (int i = 0;i < n;i++) {// 마지막으로 배정한 사람
		for (int j = 0;j < (1 << n);j++) {// 지금까지 배정한 일
			if (dp[i][j] == INF)// j상태 만드는거 불가능
				continue;
			for (int k = 0;k < n;k++) {// 새로 배정할 사람의 k번째 일 대한 비용
				if (((j >> k) & 1) == 1)//이미 k번째 일 배정함
					continue;
				dp[i + 1][j + (1 << k)] = min(dp[i + 1][j + (1 << k)], 
					dp[i][j] + d[i][k]);
			}
		}
	}
	cout << dp[n][(1<<n)-1];
}