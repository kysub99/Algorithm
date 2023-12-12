#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int a[100][100];
int b[100][100];
int c[100][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> a[i][j];
		}
	}
	cin >> m >> k;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < k;j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < k;j++) {
			for (int z = 0;z < m;z++) {
				c[i][j] += a[i][z] * b[z][j];
			}
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < k;j++) {
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}
}