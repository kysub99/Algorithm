#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 201

int n, m;
int graph[MAX][MAX];
int group[MAX];
int city[1001];

int Find(int x) {
	if (group[x] == x)
		return x;
	return group[x] = Find(group[x]);
}

void Union(int a, int b) {
	int aLeader = Find(a);
	int bLeader = Find(b);
	int newLeader = min(aLeader, bLeader);
	group[aLeader] = group[bLeader] = newLeader;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int num;
	for (int i = 1;i <= n;i++) {
		group[i] = i;
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> num;
			if (num) {
				Union(i, j);
			}
		}
	}
	for (int i = 1;i <= m;i++) {
		cin >> city[i];
	}
	int before = group[city[1]];
	for (int i = 1;i <= m;i++) {
		if (before != group[city[i]]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}