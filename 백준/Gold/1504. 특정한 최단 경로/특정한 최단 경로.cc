#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX 801
#define INF 2400'001

int n, e, a, b, c, v1, v2;
vector<pair<int, int>> graph[MAX]; // 인접 정점, 가중치 

int func(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 비용, 정점
    vector<int> res(n + 1, INF);
    pq.push({ 0, start });
    res[start] = 0;

    while (!pq.empty()) {
        int tempCost = pq.top().first;
        int tempNode = pq.top().second;
        pq.pop();

        if (tempNode == end) {
            break;
        }

        for (int i = 0; i < graph[tempNode].size(); i++) {
            int disNode = graph[tempNode][i].first; // 인접 정점
            int wei = graph[tempNode][i].second; // 가중치

            if (res[disNode] > res[tempNode] + wei) {
                res[disNode] = res[tempNode] + wei;
                pq.push({ res[disNode], disNode });
            }
        }
    }
    return res[end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    cin >> v1 >> v2;
    int temp1 = func(1, v1) + func(v1, v2) + func(v2, n);
    int temp2 = func(1, v2) + func(v2, v1) + func(v1, n);
    int temp = min(temp1, temp2);
    if (temp >= INF)
        cout << -1;
    else
        cout << temp;
    return 0;
}
