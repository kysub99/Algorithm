#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define ALP 26
#define INF 1e9

int t;
string w;
int k;
vector<int> idx[ALP];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		for (int i = 0;i < ALP;i++) {
			idx[i].clear();
		}

		cin >> w >> k;
		for (int i = 0;i < w.length();i++) {
			idx[w[i] - 'a'].push_back(i);
		}

		int r3 = INF;
		int r4 = -1;
		for (int i = 0;i < ALP;i++) {
			if (idx[i].size() < k)
				continue;
			for (int j = 0;j <= idx[i].size() - k;j++) {
				r3 = min(r3, idx[i][j + k - 1] - idx[i][j] + 1);
				r4 = max(r4, idx[i][j + k - 1] - idx[i][j] + 1);
			}
		}

		if (r3 == INF && r4 == -1)
			cout << "-1\n";
		else
			cout << r3 << " " << r4 << "\n";
	}

	return 0;
}