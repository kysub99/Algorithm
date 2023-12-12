#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int>* arr;
queue<int> q;
bool* visit;
int n, m, v;

void DFS(int num) {
	if (!visit[num]) {
		cout << num << " ";
		visit[num] = true;
	}
	for (int i = 0; i < arr[num].size(); i++) {
		int temp = arr[num][i];
		if (!visit[temp])
			DFS(temp);
	}
}

int main() {
	cin >> n >> m >> v;
	arr = new vector<int>[n+1];
	visit = new bool[n+1];
	int n1, n2;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		arr[n1].push_back(n2);
		arr[n2].push_back(n1);
	}
	for (int i = 0; i <= n; i++) {
		sort(arr[i].begin(), arr[i].end());
		visit[i] = false;
	}
	DFS(v);
	cout << "\n";

	for (int i = 0; i <= n; i++) {
		visit[i] = false;
	}

	q.push(v);
	visit[v] = true;
	while (!q.empty()) {
		int temp = q.front();
		cout << temp << " ";
		q.pop();
		for (int i = 0; i < arr[temp].size(); i++) {
			if (visit[arr[temp][i]] == false) {
				visit[arr[temp][i]] = true;
				q.push(arr[temp][i]);
			}
		}
	}
	cout << "\n";
}