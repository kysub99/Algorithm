#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001
#define INF 1e9

int n, m;
int a, b, c;
vector<vector<int>> city(MAX, vector<int>(MAX, INF));
int ord[MAX][MAX];

void getOrd(vector<int>& res, int i, int j) {
	int k = ord[i][j];
	if (k == 0) {
		res.push_back(i);
		res.push_back(j);
		return;
	}
	getOrd(res, i, k);
	res.pop_back();
	getOrd(res, k, j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		city[a][b] = min(city[a][b], c);
	}
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (city[i][k] + city[k][j] < city[i][j]) {
					city[i][j] = city[i][k] + city[k][j];
					ord[i][j] = k;
				}
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (city[i][j] == INF || i == j)
				cout << "0 ";
			else
				cout << city[i][j] << " ";
		}
		cout << "\n";
	}
	/*for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cout << ord[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (city[i][j] == INF || i == j)
				cout << "0\n";
			else {
				vector<int> res;
				getOrd(res, i, j);
				cout << res.size() << " ";
				for (int val : res) {
					cout << val << " ";
				}
				cout << "\n";
			}
			
		}
	}
}