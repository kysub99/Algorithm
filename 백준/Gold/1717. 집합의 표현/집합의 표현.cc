#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1'000'001

int n, m;
int group[MAX];

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
	for (int i = 0;i <= n;i++) {
		group[i] = i;
	}

	int w, a, b;
	for (int i = 0;i < m;i++) {
		cin >> w >> a >> b;
		if (w) {// 확인
			if (Find(a)==Find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {// 합침
			Union(a, b);
		}
	}
}