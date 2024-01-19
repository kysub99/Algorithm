#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
#define MAX 21
#define ALP 26

int R, C;
char board[MAX][MAX];
bool visit[ALP];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int res = 0;

bool isIn(int r, int c) {
    return (1 <= r && r <= R && 1 <= c && c <= C);
}

void dfs(int r, int c, int d) {
    visit[board[r][c] - 'A'] = true;
    res = max(res, d);

    for (int i = 0;i < 4;i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (isIn(nr, nc) && !visit[board[nr][nc] - 'A']) {
            dfs(nr, nc, d + 1);
        }
    }
    visit[board[r][c] - 'A'] = false;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    for (int i = 1;i <= R;i++) {
        for (int j = 1;j <= C;j++) {
            cin >> board[i][j];
        }
    }

    dfs(1, 1, 1);

    cout << res;

    return 0;
}