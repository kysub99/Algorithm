#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n, k;
vector<int> belt;
vector<int> robot;

void rotate() {
	int temp1 = belt[2 * n];
	int temp2 = robot[2 * n];
	for (int i = 2 * n;i >= 2;i--) {
		belt[i] = belt[i - 1];
		robot[i] = robot[i - 1];
	}
	belt[1] = temp1;
	robot[1] = temp2;
}

void move() {
	for (int i = n - 1;i >= 1;i--) {
		if (robot[i] == 1 && robot[i + 1] == 0 && belt[i + 1] >= 1) {
			robot[i + 1] = 1;
			robot[i] = 0;
			belt[i + 1]--;
		}
	}
}

void arrive() {
	robot[n] = 0;
}

void load() {
	if (belt[1] >= 1) {
		robot[1] = 1;
		belt[1]--;
	}
}

bool end() {
	int cnt = 0;
	for (int i = 1;i <= 2 * n;i++) {
		if (belt[i] == 0)
			cnt++;
	}
	if (cnt >= k)
		return true;
	else
		return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	belt.resize(2 * n + 1);
	robot.resize(2 * n + 1);
	for (int i = 1;i <= 2 * n;i++) {
		cin >> belt[i];
	}

	int res = 0;
	while (1) {
		res++;
		rotate();
		arrive();
		move();
		arrive();
		load();
		if (end())
			break;
	}
	cout << res;
}