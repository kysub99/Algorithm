#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#define INF 100000
using namespace std;

struct node {
	bool s;
	int x, y;
};

int n, t, m;
int graph[1001][1001];
int s, x, y;
vector<node> arr;

int getDis(int i,int j) {
	return abs(arr[i].x - arr[j].x) + abs(arr[i].y - arr[j].y);
}

int main() {
	cin >> n >> t;

	node firstNode;
	arr.push_back(firstNode);
	for (int i = 0; i < n; i++) {
		cin >> s >> x >> y;
		node newNode;
		newNode.s = s;
		newNode.x = x;
		newNode.y = y;
		arr.push_back(newNode);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				graph[i][j] = 0;
				graph[j][i] = 0;
				continue;
			}
			if (arr[i].s && arr[j].s) {
				graph[i][j] = min(getDis(i, j), t);
				graph[j][i] = min(getDis(i, j), t);
			}
			else {
				graph[i][j] = getDis(i, j);
				graph[j][i] = getDis(i, j);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << graph[a][b] << "\n";
	}
}