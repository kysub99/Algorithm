#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define INF 1e9

int n, m;
vector<pair<int, int>> store, house;
vector<int> arr;
vector<int> dis;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int num;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> num;
			if (num == 1) {
				house.push_back({ i,j });
			}
			else if (num == 2) {
				store.push_back({ i,j });
				arr.push_back(0);
			}
		}
	}
	for (int i = arr.size() - m;i < arr.size();i++) {
		arr[i] = 1;
	}

	int res = INF;
	do {
		dis.clear();
		dis.resize(house.size(), INF);
		for (int i = 0;i < arr.size();i++) {
			if (arr[i] == 1) {// 선택한 치킨집
				for (int j = 0;j < house.size();j++) {
					dis[j] = min(dis[j], abs(house[j].first - store[i].first) + abs(house[j].second - store[i].second));
				}
			}
		}
		int sum = 0;
		for (int i = 0;i < dis.size();i++) {
			sum += dis[i];
		}
		res = min(res, sum);

	} while (next_permutation(arr.begin(), arr.end()));

	cout << res;
}