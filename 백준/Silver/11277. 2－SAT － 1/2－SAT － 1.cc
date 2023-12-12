#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> graph[20001];
vector<int> graphT[20001];
bool visit1[20001];
bool visit2[20001];
stack<int> finish;
int sccleader[20001];

void set() {
	for (int i = 0; i < 20001; i++) {
		visit1[i] = false;
		visit2[i] = false;
	}
}

void DFS1(int num) {
	visit1[num] = true;
	for (int i = 0; i < graph[num].size(); i++) {
		if (visit1[graph[num][i]] != true)
			DFS1(graph[num][i]);
	}
	finish.push(num);
	return;
}

void DFS2(int num, int leader) {
	visit2[num] = true;
	sccleader[num] = leader;
	for (int i = 0; i < graphT[num].size(); i++) {
		if (visit2[graphT[num][i]] != true)
			DFS2(graphT[num][i], leader);
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a * -1 + n].push_back(b + n);
		graph[b * -1 + n].push_back(a + n);
		graphT[b + n].push_back(a * -1 + n);
		graphT[a + n].push_back(b * -1 + n);
	}
	set();
	for (int i = 0; i <= 2*n; i++) {
		if (!visit1[i] && i != n)
			DFS1(i);
	}

	while (!finish.empty()) {
		if (!visit2[finish.top()]) {
			DFS2(finish.top(), finish.top());
		}
		finish.pop();
	}
	for (int i = 0; i < n; i++)
	{
		if (sccleader[i] == sccleader[2 * n - i]) {
			cout << "0\n";
			return 0;
		}
	}
	cout << "1\n";
	return 0;
}