#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int t, n, m;
vector<bool> visit;
vector<vector<bool>> order; // i,j가 true이면 i->j
vector<int> ranking;
vector<int> team;//i팀이 value등
vector<int> res;

void setOrder() {
	for (int i = 1;i < n;i++) {
		for (int j = i + 1;j <= n;j++) {
			int prev = ranking[i];
			int next = ranking[j];
			order[prev][next] = true;
		}
	}
}

void dfs(int cur) {
	visit[cur] = true;
	for (int next = 1;next <= n;next++) {
		if (cur != next && !visit[next] && order[cur][next]) {//자기 자신이 아니고, 방문한적 없고, cur->next순임
			dfs(next);
		}
	}
	res.push_back(cur);
}

bool sense() {
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (order[i][j]&&team[i]>team[j]) {//i->j 이어야하는데 i의 등수가 더 큼
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;

		visit.clear();
		order.clear();
		ranking.clear();
		team.clear();
		res.clear();
		visit.resize(n + 1, false);
		order.resize(n + 1, vector<bool>(n + 1, false));
		ranking.resize(n + 1);
		team.resize(n + 1);
		
		for (int i = 1;i <= n;i++) {
			cin >> ranking[i];
		}

		setOrder();

		cin >> m;
		int a, b;
		for (int i = 0;i < m;i++) {
			cin >> a >> b;
			order[a][b] = !order[a][b];
			order[b][a] = !order[b][a];
		}
		for (int i = 1;i <= n;i++) {
			if (!visit[i]) {
				dfs(i);
			}
		}
		reverse(res.begin(), res.end());
		for (int i = 0;i < res.size();i++) {
			team[res[i]] = i + 1;
		}
		if (sense()) {
			for (int i : res) {
				cout << i << " ";
			}
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << "\n";
	}
}
