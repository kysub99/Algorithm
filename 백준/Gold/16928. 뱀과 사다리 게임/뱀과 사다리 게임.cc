#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
#define MAX 101

int graph[MAX];
int res[MAX];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x] = y;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u] = v;
    }
    queue<int> q;
    q.push(1);
    int next;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        if (temp == 100) {
            break;
        }
        for (int i = 1; i <= 6; i++) {
            next = temp + i;
            if (next <= 100 && graph[next] != 0) {
                next = graph[next];
            }
            if (next <= 100 && res[next] == 0) {
                q.push(next);
                res[next] = res[temp] + 1;
            }
        }
    }

    cout << res[100];
}
