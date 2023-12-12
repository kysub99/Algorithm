#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	char** arr;
	arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[m];
	}
	int cnt = 0;
	int minNum = 64;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			cnt = 0;
			for (int k = i; k < 8+i; k++) {
				for (int z = j; z < 8+j; z++) {
					if ((k + z - i - j) % 2 == 0 && arr[k][z] == 'W') 
						cnt++;
					if ((k + z - i - j) % 2 == 1 && arr[k][z] == 'B') 
						cnt++;
				}
			}
			minNum = min(cnt, minNum);
		}
	}
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			cnt = 0;
			for (int k = i; k < 8 + i; k++) {
				for (int z = j; z < 8 + j; z++) {
					if ((k + z - i - j) % 2 == 0 && arr[k][z] == 'B')
						cnt++;
					
					if ((k + z - i - j) % 2 == 1 && arr[k][z] == 'W')
						cnt++;
				}
			}
			minNum = min(cnt, minNum);
		}
	}
	cout << minNum << "\n";
}