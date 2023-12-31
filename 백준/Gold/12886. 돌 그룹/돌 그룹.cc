#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 501

vector<int> abc(3);
int sum = 0;
set<pair<int, int>> visit;
queue<pair<int, int>> q;

void func(int a, int b) {
	int na = a + a;
	int nb = b - a;
	if (na > nb) {
		swap(na, nb);
	}
	if (visit.find({ na,nb })==visit.end()) {
		q.push({ na,nb });
		visit.insert({ na,nb });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0;i < 3;++i) {
		cin >> abc[i];
		sum += abc[i];
	}

	sort(abc.begin(), abc.end());
	q.push({ abc[0], abc[1] });
	visit.insert({ abc[0], abc[1] });

	bool hasRes = false;
	while (!q.empty()) {
		tie(abc[0], abc[1]) = q.front();
		q.pop();
		abc[2] = sum - abc[0] - abc[1];
		if (abc[0] == abc[1] && abc[1] == abc[2]) {
			hasRes = 1;
			break;
		}
		sort(abc.begin(), abc.end());
		int a = abc[0];
		int b = abc[1];
		int c = abc[2];

		func(a, b);
		func(a, c);
		func(b, c);
	}

	cout << hasRes;
}