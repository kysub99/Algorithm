#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define MAX 101

pair<int, int> dir[4] = { {-1,0}, {1,0}, {0,-1}, {0, 1} };
//상 하 좌 우
bool visit[27][27];
char graph[27][27];
int cnt;

void dfs(int a, int b) {
	visit[a][b] = true;
	cnt++;
	for (int i = 0;i < 4;i++) {
		int newa = a + dir[i].first;
		int newb = b + dir[i].second;
		if (!visit[newa][newb]&&graph[newa][newb] == '1')//방문x, 집o
			dfs(newa, newb);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> graph[i][j];
		}
	}
	int res = 0;
	vector<int> resArr;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (!visit[i][j] && graph[i][j]=='1') {
				cnt = 0;
				dfs(i, j);
				resArr.push_back(cnt);
				res++;
			}
		}
	}
	sort(resArr.begin(), resArr.end());
	cout << res << "\n";
	for (int i = 0;i < resArr.size();i++) {
		cout << resArr[i] << "\n";
	}
}