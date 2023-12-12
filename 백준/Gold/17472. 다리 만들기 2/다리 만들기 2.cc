#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 11
#define BMAX 7
#define INF 1e9

bool island[MAX][MAX];
bool numbered[MAX][MAX];
int numbering[MAX][MAX];
vector<vector<int>> bridge(BMAX, vector<int>(BMAX, INF));
vector<bool> visit(BMAX, false);
pair<int, int> dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };

int n, m;
int num = 1;// 섬 번호

int getStart() {
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (island[i][j]) {
				return numbering[i][j];
			}
		}
	}
}

int MST() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int start = getStart();
	pq.push({ 0, start });
	int res = 0;
	while (!pq.empty()) {
		int curEdge = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (visit[curNode])
			continue;
		visit[curNode] = true;
		res += curEdge;
		//cout << curNode << " " << curEdge << "\n";
		for (int nextNode = 1;nextNode < BMAX;nextNode++) {
			int nextEdge = bridge[curNode][nextNode];
			if (!visit[nextNode] && nextEdge != INF && curNode != nextNode) { //방문하지 않고, 다리가 존재하고, 섬 내부의 다리가 아님
				pq.push({ nextEdge, nextNode });
			}
		}
	}
	bool isEnd = true;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (island[i][j] && !visit[numbering[i][j]])// 방문 안한 섬이 있음
				isEnd = false;
		}
	}
	if (isEnd)
		return res;
	else
		return -1;
}

bool isIn(int x, int y) {
	if (1 <= x && x <= n && 1 <= y && y <= m)
		return true;
	else
		return false;
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		if (numbered[curx][cury])
			continue;
		numbered[curx][cury] = true;
		numbering[curx][cury] = num;
		for (int i = 0;i < 4;i++) {
			int nextx = curx + dir[i].first;
			int nexty = cury + dir[i].second;
			if (isIn(nextx, nexty) && island[nextx][nexty] && !numbered[nextx][nexty]) {//범위 안이고, 섬이면서, 번호 안매긴 장소
				q.push({ nextx, nexty });
			}
		}
		
	}
	num++;
}

void setDis() {
	for (int i = 1;i <= n;i++) {
		int temp = 0;
		int len = 0;
		for (int j = 1;j <= m;j++) {
			if (island[i][j]) {//육지
				if (len > 1) {//다리 건설 가능
					bridge[temp][numbering[i][j]] = bridge[numbering[i][j]][temp] = min(bridge[numbering[i][j]][temp], len);
				}
				temp = numbering[i][j];
				len = 0;
			}
			else if (temp != 0) {
				len++;
			}
		}
	}
	for (int j = 1;j <= m;j++) {
		int temp = 0;
		int len = 0;
		for (int i = 1;i <= n;i++) {
			if (island[i][j]) {//육지
				if (len > 1) {//다리 건설 가능
					bridge[temp][numbering[i][j]] = bridge[numbering[i][j]][temp] = min(bridge[numbering[i][j]][temp], len);
				}
				temp = numbering[i][j];
				len = 0;
			}
			else if (temp != 0) {
				len++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> island[i][j];
		}
	}
	
	
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (island[i][j] && !numbered[i][j]) {//섬이고 번호 안매겼으면 bfs로 매김
				BFS(i, j);
			}
		}
	}
	/*for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cout << numbering[i][j] << " ";
		}
		cout << "\n";
	}*/
	setDis();
	//for (int i = 1;i < BMAX;i++) {
	//	for (int j = 1;j < BMAX;j++) {
	//		if (bridge[i][j] != INF) {
	//			cout << i << "->" << j << " : " << bridge[i][j] << "\n";
	//		}
	//	}
	//}
	int res = MST();
	cout << res;
}
