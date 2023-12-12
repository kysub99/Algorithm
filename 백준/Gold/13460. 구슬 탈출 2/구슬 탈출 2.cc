#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Ball {
	int ri;
	int rj;
	int bi;
	int bj;
	int cnt;
};

int main() {
	int n, m;
	cin >> n >> m;
	char board[10][11];
	Ball start;
	pair<int, int> dir[4] = { {1,0},{-1,0},{0,-1},{0,1} };//아래 위 좌 우
	bool visit[10][10][10][10] = { false, };
	queue<Ball> q;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				start.ri = i;
				start.rj = j;
			}
			if (board[i][j] == 'B') {
				start.bi = i;
				start.bj = j;
			}
		}
	}
	start.cnt = 0;

	q.push(start);
	visit[start.ri][start.rj][start.bi][start.bj] = true;
	while (!q.empty()) {
		Ball cur = q.front();
		q.pop();
		if (cur.cnt > 10)
			break;
		if (board[cur.ri][cur.rj] == 'O' && board[cur.bi][cur.bj] != 'O') {
			cout << cur.cnt << "\n";
			return 0;
		}
		for (int k = 0; k < 4; k++) {
			int temp_ri = cur.ri;
			int temp_rj = cur.rj;
			int temp_bi = cur.bi;
			int temp_bj = cur.bj;

			while (1) {
				if (board[temp_ri][temp_rj] != '#' && board[temp_ri][temp_rj] != 'O') {
					temp_ri += dir[k].first;
					temp_rj += dir[k].second;
				}
				else {
					if (board[temp_ri][temp_rj] == '#') {
						temp_ri -= dir[k].first;
						temp_rj -= dir[k].second;
					}
					break;
				}
			}
			while (1) {
				if (board[temp_bi][temp_bj] != '#' && board[temp_bi][temp_bj] != 'O') {
					temp_bi += dir[k].first;
					temp_bj += dir[k].second;
				}
				else {
					if (board[temp_bi][temp_bj] == '#') {
						temp_bi -= dir[k].first;
						temp_bj -= dir[k].second;
					}
					break;
				}
			}


			if (temp_ri == temp_bi && temp_rj == temp_bj) {
				if (board[temp_ri][temp_rj] != 'O' || board[temp_bi][temp_bj] != 'O') {
					switch (k) {
					case 0://아래
						(cur.ri > cur.bi) ? (temp_bi -= dir[0].first) : (temp_ri -= dir[0].first);
						break;
					case 1://위
						(cur.ri > cur.bi) ? (temp_ri -= dir[1].first) : (temp_bi -= dir[1].first);
						break;
					case 2://좌
						(cur.rj > cur.bj) ? (temp_rj -= dir[2].second) : (temp_bj -= dir[2].second);
						break;
					case 3://우
						(cur.rj > cur.bj) ? (temp_bj -= dir[3].second) : (temp_rj -= dir[3].second);
						break;
					}
				}
			}

			if (visit[temp_ri][temp_rj][temp_bi][temp_bj] != true) {
				visit[temp_ri][temp_rj][temp_bi][temp_bj] = true;
				Ball next;
				next.ri = temp_ri;
				next.rj = temp_rj;
				next.bi = temp_bi;
				next.bj = temp_bj;
				next.cnt = cur.cnt + 1;
				q.push(next);
			}

		}
	}
	cout << "-1\n";

}