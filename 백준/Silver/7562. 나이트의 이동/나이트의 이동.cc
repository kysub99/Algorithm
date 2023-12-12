#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define MAX 301

bool visit[MAX][MAX];
int graph[MAX][MAX];
int res[MAX][MAX];
int t, l, sa, sb, da, db;

pair<int, int> dir[8] = { {-2, 1},{-1,2},{1,2},{2,1},
	{2,-1},{1,-2},{-1,-2},{-2,-1} };
//그림 시계방향

bool isIn(int a, int b) {//체스판 내부인지
	if (a < 0 || l <= a || b < 0 || l <= b)
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> l >> sa >> sb >> da >> db;
		queue<pair<int, int>> q;
		for (int i = 0;i < MAX;i++) {
			for (int j = 0;j < MAX;j++) {
				visit[i][j] = false;
				res[i][j] = 0;
			}
		}
		q.push({ sa,sb });
		visit[sa][sb] = true;
		while (!q.empty()) {
			int tempa = q.front().first;
			int tempb = q.front().second;
			if (tempa == da && tempb == db)
				break;
			for (int i = 0;i < 8;i++) {
				int newa = tempa + dir[i].first;
				int newb = tempb + dir[i].second;
				if (isIn(newa, newb)&&!visit[newa][newb]) {
					q.push({ newa, newb });
					visit[newa][newb] = true;;
					res[newa][newb] = res[tempa][tempb] + 1;
				}
			}
			q.pop();
		}
		cout << res[da][db] << "\n";
	}
}