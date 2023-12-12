#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
#define MAX 101

int graph[MAX][MAX][MAX];
int day[MAX][MAX][MAX];
int n, m, h;
tuple<int, int, int> dir[6] = { {0,-1,0}, {0,1,0}, {0,0,1}, {0,0,-1},{1,0,0},{-1,0,0} };

bool isIn(int a, int b, int c) {//범위는 1이상 h,n,m이하
	if (1 <= a && a <= h && 1 <= b && b <= n && 1 <= c && c <= m)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;
	queue<tuple<int, int, int>> q;
	int tot = 0;//익어야하는 토마토 수
	for (int k = 1;k <= h;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				cin >> graph[k][i][j];
				if (graph[k][i][j] == 1) {
					q.push({ k, i,j });
				}
				else if (graph[k][i][j] == 0) {
					tot++;
				}
			}
		}
	}
	int cnt = 0;//현재까지 익은거 개수
	while (!q.empty()) {
		if (cnt == tot)
			break;
		int tempa = get<0>(q.front());//높이
		int tempb = get<1>(q.front());//세로
		int tempc = get<2>(q.front());//가로
		for (int i = 0;i < 6;i++) {
			int newa = tempa + get<0>(dir[i]);
			int newb = tempb + get<1>(dir[i]);
			int newc = tempc + get<2>(dir[i]);
			if (isIn(newa, newb, newc) && graph[newa][newb][newc] == 0) {
				q.push({ newa, newb, newc });
				graph[newa][newb][newc] = 1;//익은거로 바꿈
				day[newa][newb][newc] = day[tempa][tempb][tempc] + 1;
				cnt++;
			}
		}
		q.pop();
	}
	//for (int k = 1;k <= h;k++) {
	//	for (int i = 1;i <= n;i++) {
	//		for (int j = 1;j <= m;j++) {
	//			cout << day[k][i][j] << " ";
	//		}
	//		cout << "\n";
	//	}
	//	cout << "--------------------\n";
	//}


	if (cnt == tot) {//다 익음
		int res = 0;
		for (int k = 1;k <= h;k++) {
			for (int i = 1;i <= n;i++) {
				for (int j = 1;j <= m;j++) {
					res = max(res, day[k][i][j]);
				}
			}
		}
		cout << res << "\n";
	}
	else {
		cout << "-1\n";
	}
}