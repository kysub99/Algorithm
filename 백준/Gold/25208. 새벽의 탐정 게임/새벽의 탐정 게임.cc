#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
#define MAX 501
#define INF 1e9

int n, m;
int sn, sm;
char board[MAX][MAX];
bool visit[MAX][MAX][6];// 현재 구멍이 어디에 위치해있는지

pair<int,int> dir[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
// 상 하 좌 우
int hole[6][4] = { {2,3,4,1},{1,1,0,5},{5,0,2,2},{0,5,3,3},{4,4,5,0},{3,2,1,4} };
// 구멍이 i에 위치했을때 상하좌우로 움직이면 구멍이 어디로 가는지

struct state {
	int n;
	int m;
	int h;//구멍 어디
	int cnt;//몇번 굴렸는지
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];
			if (board[i][j] == 'D') {
				sn = i;
				sm = j;
			}
		}
	}

	queue<state> q;
	state start;
	start.n = sn;
	start.m = sm;
	start.h = 0;
	start.cnt = 0;
	q.push(start);
	visit[sn][sm][0] = true;
	int res = INF;
	while (!q.empty()) {
		state cur = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nn = cur.n + dir[i].first;
			int nm = cur.m + dir[i].second;
			int nh = hole[cur.h][i];
			if (board[nn][nm] == 'R' && nh==0) {// 도둑이 있는곳에 구멍
				res = min(res, cur.cnt + 1);
			}
			else if ((board[nn][nm] == '.'|| board[nn][nm] == 'D') && !visit[nn][nm][nh]) {// 길이 있을때
				state next;
				next.n = nn;
				next.m = nm;
				next.h = nh;
				next.cnt = cur.cnt + 1;
				q.push(next);
				visit[nn][nm][nh] = true;
			}
		}
	}
	if (res == INF)
		cout << -1;
	else
		cout << res;
}