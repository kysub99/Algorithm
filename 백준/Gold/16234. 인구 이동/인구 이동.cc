#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 51

int N, L, R;
int arr[MAX][MAX];
pair<int,int> par[MAX][MAX];
int narr[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void setVisit() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			visit[i][j] = false;
		}
	}
}

bool isIn(int i, int j) {
	return 1 <= i && i <= N && 1 <= j && j <= N;
}

bool isAdj(int ci, int cj, int ni, int nj) {
	int dif = abs(arr[ci][cj] - arr[ni][nj]);
	return L <= dif && dif <= R;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> arr[i][j];
		}
	}

	int res = 0;

	while (1) {
		queue<pair<int, int>> q;
		setVisit();
		bool noMove = true;

		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (!visit[i][j]) {
					q.push({ i,j });
					visit[i][j] = true;
					par[i][j] = { i,j };
					narr[i][j] = arr[i][j];
					int sum = arr[i][j];
					int cnt = 1;
					while (!q.empty()) {
						int ci, cj;
						tie(ci, cj) = q.front();
						q.pop();
						for (int k = 0;k < 4;k++) {
							int ni = ci + dx[k];
							int nj = cj + dy[k];
							if (isIn(ni, nj) && isAdj(ci, cj, ni, nj)&&!visit[ni][nj]) {
								q.push({ ni,nj });
								visit[ni][nj] = true;
								par[ni][nj] = { i,j };
								sum += arr[ni][nj];
								cnt++;
								noMove = false;
							}
						}
					}
					narr[i][j] = sum / cnt;
				}

			}
		}

		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				int pi, pj;
				tie(pi, pj) = par[i][j];
				arr[i][j] = narr[pi][pj];
			}
		}
		if (noMove)
			break;
		res++;
	}

	cout << res;

	return 0;
}