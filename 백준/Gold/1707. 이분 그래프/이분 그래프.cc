#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define MAX 20001

int k, v, e;

string bfs(vector<vector<int>>& graph) {
    vector<int> pos(v + 1, 0);

    for (int start = 1; start <= v; start++) {
        if (pos[start] == 0) {
            queue<int> q;
            q.push(start);
            pos[start] = 1;

            while (!q.empty()) {
                int temp = q.front();
                q.pop();
                for (int i = 0; i < graph[temp].size(); i++) {
                    int newn = graph[temp][i];
                    if (pos[newn] == pos[temp]) {
                        return "NO";
                    }
                    else if (pos[newn] == 0) {
                        pos[newn] = pos[temp] * -1;
                        q.push(newn);
                    }
                }
            }
        }
    }
    return "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    while (k--) {
        cin >> v >> e;
        vector<vector<int>> graph(v + 1);
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        cout << bfs(graph) << "\n";
    }
}
