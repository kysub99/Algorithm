#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> graph[10001];
vector<int> graphT[10001];
bool visit1[10001];
bool visit2[10001];
stack<int> finish;
int sccleader[10001];

bool cmp(const vector<int>& v1, const vector<int>& v2) {
	return v1[0] < v2[0];
}

void set() {
	for (int i = 0; i < 10001; i++) {
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
	sccleader[num]=leader;
	for (int i = 0; i < graphT[num].size(); i++) {
		if (visit2[graphT[num][i]] != true)
			DFS2(graphT[num][i], leader);
	}
	return;
}

int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graphT[v].push_back(u);
	}
	set();
	for (int i = 1; i <= v; i++) {
		if (!visit1[i])
			DFS1(i);
	}
	
	int cnt = 0;
	while (!finish.empty()) {
		if (!visit2[finish.top()]) {
			DFS2(finish.top(), finish.top());
			cnt++;
		}
		finish.pop();
	}
	cout << cnt << "\n";
	/*for (int i = 0; i < cnt; i++) {
		sort(sccleader[i].begin(), sccleader[i].end());
	}
	sort(sccleader, sccleader+sccleader->size(), cmp);
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < sccleader[i].size(); j++) {
			cout << sccleader[i][j] << " ";
		}
		cout << "-1\n";
	}*/
	for (int i = 1; i <= v; i++)
	{
		if (sccleader[i] > 0)
		{
			cout << i << ' ';
			for (int j = i + 1; j <= v; j++)
			{
				if (sccleader[i] == sccleader[j])
				{
					cout << j << ' ';
					sccleader[j] = 0;
				}
			}

			cout << -1 << '\n';
		}
	}
}