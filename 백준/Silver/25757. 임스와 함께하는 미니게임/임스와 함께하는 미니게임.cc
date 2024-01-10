#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int N;
char game;
int cnt = 0;
int res;
set<string> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> game;

	string name;
	for (int i = 0;i < N;i++) {
		cin >> name;
		if (st.find(name) == st.end()) {//없음
			cnt++;
			st.insert(name);
		}
	}

	if (game == 'Y') {
		res = cnt;
	}
	else if (game == 'F') {
		res = cnt / 2;
	}
	else if (game == 'O') {
		res = cnt / 3;
	}

	cout << res;

	return 0;
}