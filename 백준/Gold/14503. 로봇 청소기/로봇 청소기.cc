#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r, c, d;
int room[50][50];
// 청소x 벽 청소o
pair<int, int> dir[4] = { {-1,0},{0,1},{1,0}, {0,-1} };
//북 동 남 서

void Input() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> room[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	bool cantGo = true;
	int res = 0;
	while (1) {
		cantGo = true;
		if (room[r][c] == 0) {
			room[r][c] = 2;
			res++;
		}
		for (int i = 1;i <= 4;i++) {
			int tempd = (d - i + 4) % 4;
			int nr = r + dir[tempd].first;
			int nc = c + dir[tempd].second;
			if (room[nr][nc] == 0) {
				r = nr;
				c = nc;
				d = tempd;
				cantGo = false;
				break;
			}
		}
		if (cantGo) {
			int tempd = (d + 2) % 4;//후진방향
			int nr = r + dir[tempd].first;
			int nc = c + dir[tempd].second;
			if (room[nr][nc] == 1)// 벽이면 작동 멈춤
				break;
			else {
				r = nr;
				c = nc;
			}
		}
	}
	cout << res;
}