#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define MAX 1001

bool visit[MAX][MAX];
int graph[MAX][MAX];
int day[MAX][MAX];
int n, m;
pair<int, int> dir[4] = { {-1,0}, {1,0}, {0,1}, {0,-1} };

bool isIn(int a, int b) {//범위는 1이상 n,m이하
	if (1 <= a && a <= n && 1 <= b && b <= m)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	queue<pair<int, int>> q;
	int tot = 0;//익어야하는 토마토 수
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				q.push({ i,j });
			}
			else if (graph[i][j] == 0) {
				tot++;
			}
		}
	}
	int cnt = 0;//현재까지 익은거 개수
	int res = MAX;
	while (!q.empty()) {
		if (cnt == tot)
			break;
		int tempa = q.front().first;
		int tempb = q.front().second;
		for (int i = 0;i < 4;i++) {
			int newa = tempa + dir[i].first;
			int newb = tempb + dir[i].second;
			if (isIn(newa, newb) && graph[newa][newb] == 0) {
				q.push({ newa, newb });
				graph[newa][newb] = 1;//익은거로 바꿈
				day[newa][newb] = day[tempa][tempb] + 1;
				cnt++;
			}
		}
		q.pop();
	}
	/*for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cout << day[i][j] << " ";
		}
		cout << "\n";
	}*/
	if (cnt == tot) {//다 익음
		int res = 0;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				if (graph[i][j] == 1)
					res = max(res, day[i][j]);
			}
		}
		cout << res << "\n";
	}
	else {
		cout << "-1\n";
	}
}